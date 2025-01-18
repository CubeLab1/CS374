#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Function prototypes
double calculate_total_surface_area(double R, double ha, double hb);
double calculate_volume(double R, double ha, double hb);

int main() {
    int n; // Number of spherical segments

    // Prompt user for the number of spherical segments
    do {
        printf("How many spherical segments you want to evaluate [2-10]? \n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    double total_surface_area_sum = 0.0;
    double total_volume_sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double R, ha, hb;

        printf("Obtaining data for spherical segment number %d\n", i);

        while (1) {
            printf("What is the radius of the sphere (R)? \n");
            scanf("%lf", &R);
            printf("What is the height of the top area of the spherical segment (ha)? \n");
            scanf("%lf", &ha);
            printf("What is the height of the bottom area of the spherical segment (hb)? \n");
            scanf("%lf", &hb);

            // Print entered data
            printf("Entered data: R = %.2f ha = %.2f hb = %.2f.\n", R, ha, hb);

            // Validate inputs
            if (R <= 0 || ha <= 0 || hb <= 0) {
                printf("Invalid Input: All parameters must be positive real values.\n");
            } else if (ha > R || hb > R) {
                printf("Invalid Input: ha and hb must not be greater than R.\n");
            } else if (ha < hb) {
                printf("Invalid Input: ha must be greater than or equal to hb.\n");
            } else {
                break;
            }
        }

        // Calculate total surface area and volume
        double total_surface_area = calculate_total_surface_area(R, ha, hb);
        double volume = calculate_volume(R, ha, hb);

        // Print results for the current segment
        printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface_area, volume);

        // Accumulate totals
        total_surface_area_sum += total_surface_area;
        total_volume_sum += volume;
    }

    // Calculate and print averages
    double average_surface_area = total_surface_area_sum / n;
    double average_volume = total_volume_sum / n;

    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f.\n", average_surface_area, average_volume);

    return 0;
}

// Function to calculate the total surface area
double calculate_total_surface_area(double R, double ha, double hb) {
    double top_surface_area = 2 * PI * R * ha;
    double bottom_surface_area = 2 * PI * R * hb;
    double lateral_surface_area = 2 * PI * R * (ha - hb);
    return top_surface_area + bottom_surface_area + lateral_surface_area;
}

// Function to calculate the volume
double calculate_volume(double R, double ha, double hb) {
    return (PI / 6.0) * (3 * pow(R, 2) * (ha - hb) + pow(ha, 3) - pow(hb, 3));
}
