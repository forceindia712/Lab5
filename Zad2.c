#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double PI(int N)
 {
    double S = 0, F;
    for(int i = 1; i <= N; i++)
    {
        F = pow(-1, i - 1) / (2 * i - 1);
        S += F;
    }
    S=S*4;

    return S;
}

int main()
{
    int proces;
    printf("Ilosc procesow: ");
    scanf("%d", &proces);

    for (int i = 0; i < proces; i++)
    {
        if (fork() == 0)
        {
            srand(time(NULL) ^ (getpid() << 16));
            int N = (rand() % (5000 - 100 + 1)) + 100;

            printf("N = %d, PI: %f\n", N, PI(N));
            exit(0);
        }

    }


    return 0;

}