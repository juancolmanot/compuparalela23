#!/bin/bash

help_panel(){
    echo -e "DEPLOY_NS"
	echo -e "\tdeploy_ns: Es una herramienta que facilita la recopilacion de informacion importante\n\trelacionada con el rendimiento del proyecto navier_stokes"
	echo -e "SINOPSIS"
	echo -e "\tdeploy_ns [-f \"lista_de_flags\"] [-o archivo_de_salida]"
	echo -e "OPCIONES"
	echo -e "\t-f \"lista_de_flags\""
	echo -e "\t\tLista de flags encerrados entre comillas dobles, para incorporar a la compilacion"
	echo -e "\t-o archivo_de_salida"
    echo -e "\t\tNombre del archivo de salida"
}

add_flags(){
	flags=$@
	sed -i "1s/.*/CFLAGS=-std=c11 -Wall -Wextra -Wno-unused-parameter $flags/" Makefile
}

add_average_and_desviation(){
	awk '{
    for(i=1;i<=NF;i++) {
        if (NR==1) {
            colnames[i]=$i;
        } else {
            sum[i]+=$i;
            sumsq[i]+=($i)^2;
        }
    }
	} END {
		for(i=1;i<=NF;i++) {
			printf "%s: media = %f, desviación estándar = %f\n", colnames[i], sum[i]/NR, sqrt(sumsq[i]/NR - (sum[i]/NR)^2);
			}
	}' "$1" >> $1
}

speed_gain(){
	standard_time=$(grep "seconds time elapsed" with-flags-O0-standard | awk '{print $1}' | tr ',' '.' | awk '{printf "%.4f", $1}')
	current_time=$(grep "seconds time elapsed" "$1" | awk '{print $1}' | tr ',' '.' | awk '{printf "%.4f", $1}')
	gain=$(echo "scale=2; $standard_time / $current_time" | bc -l | tr '.' ',')
	printf "speed gain: %.2f\n" "$gain">> $1
}

exec_ns(){
	echo "[+] Make command info"
	make
	echo "ns_per_cell react vel_step dens_step" > metricas.tmp
	echo -e "\n[+] Simulation info"
	cache_metrics="L1-dcache-loads,L1-dcache-load-misses,L1-icache-loads,L1-icache-load-misses,"
	cpu_metrics="instructions,cycles"
	perf stat -e $cache_metrics$cpu_metrics -o perf.tmp taskset 0x1 ./headless >> metricas.tmp
	cat metricas.tmp | awk -F ":" '{print $1}'| tr -d "," | column -t > $1
	add_average_and_desviation $1
	cat perf.tmp | tail -n+5 >> $1
	speed_gain $1
	rm metricas.tmp perf.tmp
	make clean > /dev/null
}

# Main

if [ -z $1 ]; then help_panel; exit 1; fi
declare -i parameter_counter=0
while getopts ":f:o:h" arg; do
	case $arg in
		f)
            flags=$OPTARG
			add_flags $flags
			parameter_counter+=1
			;;
        o)
            output_file=$OPTARG
			parameter_counter+=1
            ;;
		h)
            help_panel
			exit 0
            ;;
        *)
            help_panel
            exit 1
        esac
done

if [ $parameter_counter == 2 ]; then
	exec_ns $output_file
else
	help_panel
	exit 1
fi
exit 0

