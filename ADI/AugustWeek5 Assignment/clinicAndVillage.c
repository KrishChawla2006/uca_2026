#include <stdio.h>
#include <math.h>

double minMaxLoad(int population[], int n, int k) {
    int maxPopulation = population[0];

    for (int i = 1; i < n; i++) {
        if (population[i] > maxPopulation) {
            maxPopulation = population[i];
        }
    }

    double low = 0.0;
    double high = maxPopulation;

    for (int iteration = 0; iteration < 100; iteration++) {
        double mid = (low + high) / 2.0;

        int clinics = 0;

        for (int i = 0; i < n; i++) {
            clinics += (int)ceil(population[i] / mid);

            if (clinics > k)
                break;
        }

        if (clinics <= k) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {
    int population[] = {200, 20, 50};
    int n = 3;
    int k = 5;

    double answer = minMaxLoad(population, n, k);

    printf("%.2f\n", answer);

    return 0;
}
