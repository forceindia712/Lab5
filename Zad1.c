#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double function(double x)
 {
    return 4 * x - 6 * x + 5;
}

double count(double a, double b, int IloscTrap)
 {
    double h = (b - a) / IloscTrap, S = 0;
    
    S += (function(a) + function(b)) / 2;
    for(int i = 1; i < IloscTrap; i++)
    {
        S += function(a + i * h);
    }

    return S * h;
}

int main()
 {
    int p;
    printf("Ilosc procesow: ");
    scanf("%d", &p);

    for (int i = 0; i < p; i++)
        {
        if (fork() == 0) {
            srand(time(NULL) ^ (getpid() << 16));

            double a = rand() % 30;
            double b = rand() % 30;

            while (b <= a)
            {
                b = rand() % 30;
            }
            
            int IloscTrap = (rand() % (20 - 1 + 1)) + 1;


            printf("a: %f, b: %f, ilosc trapezow: %d\n", a, b, IloscTrap);
            printf("Wartosc: %f\n\n", count(a, b, IloscTrap));

            exit(0);
        }

    }

    return 0;

}