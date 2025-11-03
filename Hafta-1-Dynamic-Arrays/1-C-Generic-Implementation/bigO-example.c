    
#include <stdio.h>
#include <time.h>

int main(){
    // volatile keywordu derleyici iyileştirme yapmasın diye yazdık
    volatile unsigned long long sayi = 0; 

    double Ns[] = {1e2,1e3,1e4,1e5}; // inputlarımız

    for (size_t ti = 0; ti < sizeof(Ns)/sizeof(Ns[0]); ++ti) {
        int N = Ns[ti];
        printf("=== N = %d ===\n", N);

        // O(1) -- constant time work
        {
            clock_t t0 = clock();
            sayi += N;
            double secs = (double)(clock() - t0) / CLOCKS_PER_SEC;
            printf("O(1)   : %lf s \n", secs);
        }

        // O(N) -- single loop
        {
            clock_t t0 = clock();
            for (int i = 0; i < N; ++i) sayi += i;
            double secs = (double)(clock() - t0) / CLOCKS_PER_SEC;
            printf("O(N)   : %lf s\n", secs);
        }

        // O(N^2) -- nested loops
        {
            clock_t t0 = clock();
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    sayi += (i ^ j) & 1;
            double secs = (double)(clock() - t0) / CLOCKS_PER_SEC;
            printf("O(N^2) : %lf s\n", secs);
        }

    }

    return 0;

}