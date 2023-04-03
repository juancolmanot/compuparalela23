#include <stdio.h>
#include <stdlib.h>


int main() {
FILE *metrics = fopen("../datafiles/test_headless.dat", "r");

FILE *results = fopen("../datafiles/results.dat", "w");

if (metrics == NULL) {
    printf("Error opening file\n");
    return 1;
}

double ns_total, ns_react, ns_vel, ns_dens;
float total_ac, react_ac, vel_ac, dens_ac;
int count = 0;

total_ac = react_ac = vel_ac = dens_ac = 0.0f;

while (fscanf(metrics, "%lf %lf %lf %lf", &ns_total, &ns_react, &ns_vel, &ns_dens) == 4) {
    total_ac += ns_total;
    react_ac += ns_react;
    vel_ac += ns_vel;
    dens_ac += ns_dens;
    count++;
}

fclose(metrics);

total_ac = total_ac / (float) count;
react_ac = react_ac / (float) count;
vel_ac = vel_ac / (float) count;
dens_ac = dens_ac / (float) count;

fprintf(results, "%10.4E %10.4E %10.4E %10.4E\n", total_ac, react_ac, vel_ac, dens_ac);

fclose(results);

return 0;

}