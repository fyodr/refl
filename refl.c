/**
 * refl.c
 * by Ted Morin
 * 
 * a simple program to compute optical reflection at the command line
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // only one input given - assume incident index is 1.0
        double ni = 1.0;
        double nt = atof(argv[1]);
        double r = (ni-nt)/(ni+nt);
        double R = r*r;
        printf("%f\n", R);

    } else if (argc == 3) {
        // two inputs given - incident and transmitted indices
        double ni = atof(argv[1]);
        double nt = atof(argv[2]);
        double r = (ni-nt)/(ni+nt);
        double R = r*r;
        printf("%f\n", R);

    } else if (argc == 5) {
        // four inputs given - last two indices are theta_i and pol
        double ni = atof(argv[1]);
        double nt = atof(argv[2]);
        double ti = atof(argv[3]);
        char pol = argv[4][0];

        if (sin(ti)*ni/nt >= 1.0) {
            // total internal reflection
            printf("%f\n", 1.0);
            exit(0);
        } else if ((pol != 's') && (pol != 'p')) {
            // check that s or p is indicated
            printf("INVALID POLARIZATION - USAGE: refl [ni] nt [theta s/p]\n");
            exit(0);
        }

        // valid input
        double tt = asin(sin(ti)*ni/nt);
        double cos_ti = cos(ti);
        double cos_tt = cos(tt);
        double r;
        if (pol == 's') {
            r = (ni*cos_ti-nt*cos_tt)/(ni*cos_ti+nt*cos_tt);
        } else {
            r = (ni*cos_tt-nt*cos_ti)/(ni*cos_tt+nt*cos_ti);
        }
        double R = r*r;
        printf("%f\n", R);
    } else {
        printf("USAGE: refl [ni] nt [theta s/p]\n");
    }

}
