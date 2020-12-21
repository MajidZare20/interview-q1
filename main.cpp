#include <stdio.h>
#include <time.h>
#include <math.h>

int prop(long int A, long int B, long int C, long int D) {
    return (pow(A, 4) + pow(B, 4) + pow(C, 4) == pow(D, 4));
}

int main() {
    long int a, b, c, d;
    long int aLast, bLast, cLast, dLast,temp1,temp2;
    dLast = 500000;

    clock_t t;
    t = clock();

    for (d = 1; d < dLast; d++) {
        cLast = d;

        for (c = cLast; c > pow(pow(d, 4) - pow(c, 4), 0.25); c--) {
            bLast = pow(pow(d, 4) - pow(c, 4), 0.25);

            for (b = bLast; b > pow(pow(d, 4) - pow(c, 4) - pow(b, 4), 0.25) ; b--) {
                aLast = pow(pow(d, 4) - pow(c, 4) - pow(b, 4), 0.25);
           
                for (a = aLast; a > 0; a--) {
                    if (prop(a, b, c, d))
                        printf("FOUND IT!\na = %ld\nb = %ld\nc = %ld\nd = %ld\n", a, b, c, d);
                }
            }
            if (!(c % 1000))
                printf(" d=%ld, c=%ld, time = %fs\n",d, c, ((double)(clock() - t)) / CLOCKS_PER_SEC);
        }
    }

}
