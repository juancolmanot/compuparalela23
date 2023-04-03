#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static float mean(int n, float* x) {

    float avg = 0.0f;

    for (unsigned int i = 0; i < n; i++) {
        avg += x[i];
    }

    avg = avg / (float) n;

    return avg;
}

static float variance(int n, float* x) {

    float var = 0.0f;
    float avg = 0.0f;

    avg = mean(n, x);
    
    for (unsigned int i = 0; i < n; i++) {
        var = var + x[i] * x[i] - avg;
    }

    var = var / (float) (n - 1);

    return var;
}

static void allocate_data(int n, float* x1, float* x2, float* x3, float* x4) {

    x1 = (float*)malloc(n * sizeof(float));
    x2 = (float*)malloc(n * sizeof(float));
    x3 = (float*)malloc(n * sizeof(float));
    x4 = (float*)malloc(n * sizeof(float));
}

static void clear_data(int n, float* x1, float* x2, float* x3, float* x4) {

    int i;

    for (i = 0; i < n; i++){
        x1[i] = x2[i] = x3[i] = x4[i] = 0.0f;
    }
}

int main(int argc, char *argv[]) {

    int iteration = atoi(argv[1]);
    int stage = atoi(argv[2]);
    int n_data = atoi(argv[3]);

    if (stage == 0) {
        FILE *metrics = fopen("../datafiles/test_headless.dat", "r");
        FILE *results;

        if (iteration == 1) {
            results = fopen("../datafiles/results.dat", "w");
            fclose(results);
            results = fopen("../datafiles/results.dat", "a");
        }
        else {
            results = fopen("../datafiles/results.dat", "a");
        }


        if (metrics == NULL) {
            printf("Error opening file\n");
            return 1;
        }

        float* total;
        float* react;
        float* vel;
        float* dens;

        float mean_tot, mean_react, mean_vel, mean_dens;
        float var_tot, var_react, var_vel, var_dens;

        char format[] = "%10.4E %10.4E %10.4E %10.4E"
                        "%10.4E %10.4E %10.4E %10.4E"
                        "%10.4E %10.4E %10.4E %10.4E";


        allocate_data(n_data, total, react, vel, dens);
        clear_data(n_data, total, react, vel, dens);

        for (unsigned int i = 0; i < n_data; i++) {
            fscanf(metrics, "%lf %lf %lf %lf", total[i], react[i], vel[i], dens[i]);
        }

        fclose(metrics);

        mean_tot = mean(n_data, total);
        mean_react = mean(n_data, react);
        mean_vel = mean(n_data, vel);
        mean_dens = mean(n_data, dens);

        var_tot = variance(n_data, total);
        var_react = variance(n_data, react);
        var_vel = variance(n_data, vel);
        var_dens = variance(n_data, dens);

        fprintf(results, format, mean_tot, var_tot, sqrt(var_tot), \
                                 mean_react, var_react, sqrt(var_react), \
                                 mean_vel, var_vel, sqrt(var_vel), \
                                 mean_dens, var_dens, sqrt(var_dens));
        fclose(results);

        return 0;
    }
    else if (stage == 1) {

    }
    
}