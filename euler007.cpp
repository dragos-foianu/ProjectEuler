#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define SIEVE_SIZE 104730

int main() {
    int T, N;
    bool *sieve = new bool[SIEVE_SIZE];
    std::vector<int> primes;
    
    /* Generate the first 10000 primes using Sieve of Eratosthenes */
    std::fill(sieve, sieve + SIEVE_SIZE, true);
    for (int i = 2; i < SIEVE_SIZE; i++) {
        if (sieve[i] == true) {
            sieve[i] = false;
            primes.push_back(i);
            for (long j = (long) i * i; j < SIEVE_SIZE; j += i) {            
                sieve[j] = false;
            }
        }
    }
    
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::cout << primes[N - 1] << std::endl;
    }
    return 0;
}
