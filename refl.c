/**
 * refl.c
 * by Ted Morin
 * 
 * a simple program to compute optical reflection at the command line
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // only one input given - assume incident index is 1.0
        double ni = 1.0;
        double nf = atof(argv[1]);
        double R = (ni-nf)*(ni-nf)/((ni+nf)*(ni+nf));
        printf("%f\n", R);

    } else if (argc == 3) {
        // two inputs given - incident and transmitted indices
        double ni = atof(argv[1]);
        double nf = atof(argv[2]);
        double R = (ni-nf)*(ni-nf)/((ni+nf)*(ni+nf));
        printf("%f\n", R);

    } else if (argc == 5) {
        // four inputs given - last two indices are pol and angle
        // TODO
        printf("USAGE: refl [ni] nt [s/p theta]\n");
    } else {
        printf("USAGE: refl [ni] nt [s/p theta]\n");
    }

}
