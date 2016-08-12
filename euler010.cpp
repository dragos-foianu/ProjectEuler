#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * This solution generates the all prime numbers smaller than 10^6 using the Sieve of Eratosthenes.
 * The sums array holds the sum of primes smaller than the index.
 * For example:
 * sums[2] = 2
 * sums[3] = 2 + 3
 * sums[4] = 2 + 3
 * sums[5] = 2 + 3 + 5
 *
 * In this case, each test is a simple query in this array.
 */

int main() {
    bool *sieve = new bool[1000001];
    unsigned long long *sums = new unsigned long long[1000001];
    
    std::fill(sieve, sieve + 1000001, true);
    std::fill(sums, sums + 1000001, 0);
    
    sieve[1] = true;
    sums[1] = 0;
    
    for (int i = 2; i < 1000001; i++) {
        if (sieve[i] == true) {
            sums[i] += sums[i-1] + i;
            if (i <= 1000) {
                for (unsigned long long j = i * i; j < 1000001; j += i) {
                    sieve[j] = false;
                }
            }
        } else {
            sums[i] = sums[i-1];
        }
    }
    
    int T, N;
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        std::cout << sums[N] << std::endl;
    }
    
    delete[] sieve;
    delete[] sums;
    
    return 0;
}
