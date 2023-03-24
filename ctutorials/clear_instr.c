// Fases de Compilación
// gcc -save-temps clear.c -lgomp
// ls -lt

// Preprocesador (cpp)
// gcc -E clear.c > clear.i
// Compilador (cc1)
// gcc -S clear.i
// Ensamblador (as)
// gcc -c clear.s
// Linker (collect2/ld)
// gcc clear.o

// Ver todas las etapas intermadias
// gcc -v clear.c -lgomp

// Generación de todo lo intermedio, es una bocha!!!!
// gcc -save-temps -fdump-tree-all -fdump-rtl-all -fdump-ipa-all clear.c -lgomp
// ls -lt

// Mirando el código intermedio GIMPLE
// gcc -c -O0 -fdump-tree-gimple clear.c
// ...
// gcc -c -O3 -fdump-tree-gimple clear.c

// Tiempos
// gcc -O0 clear.c -lgomp && ./a.out
// ...
// gcc -O3 clear.c -lgomp && ./a.out
// Script:
// for i in {0..3}; do gcc -O$i clear.c -lgomp && ./a.out; echo; done

// Ojo con el *system noise*, repetir las mediciones 4 veces al menos para estimar promedio.

// Y si intercambiamos el órden de ejecución para que sea 3, 2, 1?
// ...
// Bueno, hay un problema de warm-up que se vé claramente.
// Solución hacer un recorrido con clear1() sin medir tiempo solo para calentar las cachés, la TLB y los predictores.
// ...
// Modificar que código para que quede
// clear1, clear1, clear2, clear3

// Volver a probar las optimizaciones!
// for i in {0..3}; do gcc -O$i clear.c -lgomp && ./a.out; echo; done

// Hay más optimizaciones, -Os (size), -Ofast (adivinen)
// for i in 0 1 2 3 fast s; do gcc -O$i clear.c -lgomp && ./a.out; echo; done

// Mirando el assembler, genera archivos *.S
// Buscar el loop principal de clear1, clear2 y clear3
// gcc -S -O0 clear.c
// ...
// gcc -S -O3 clear.c
//
// ¿Qué pasa con -O3 y clear1? Chachaaaannnnn

// Otro compilador
// for i in {0..3}; do clang -O$i clear.c -lgomp && ./a.out; done 


// Instalar otras versiones de gcc o clang
// sudo apt install gcc-5 gcc-6 gcc-7 gcc-8 gcc-9 gcc-10 clang-4 clang-5 clang-6 clang-7 clang-8
//
// Para usarlas, ejemplo:
// clang-4 -O1 clear.c -lgomp && ./a.out

// Instalar cross compilers interesantes
// sudo apt install gcc-aarch64-linux-gnu gcc-riscv64-linux-gnu
// aarch64-linux-gnu-gcc -O1 clear.c -S
// riscv64-linux-gnu-gcc -O1 clear.c -S

// En diferentes variaciones de x86_64, ARMv7 y ARMv8.
// En diferentes subarquitecturas! gcc -m32 genera código de 32 bits :)
// Con diferentes compiladores!
