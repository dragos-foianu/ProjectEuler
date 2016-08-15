#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_N 28123

/*
 * This solution uses a sieve to calculate the sum of divisors for each number
 * up to MAX_N. Having the sum of divisors for each number, finding abundant numbers
 * becomes fairly trivial.
 */

int main() {
    int sums[MAX_N] = { 1 };
    
    std::fill(sums, sums + MAX_N, 1);
    
    /* Sieve - calculate sum of divisors */
    for (int i = 2; i <= MAX_N / 2; i++) {
        for (int j = 2 * i; j < MAX_N; j += i) {
            sums[j] += i;
        }
    }
    
    /* Abundant numbers */
    std::vector<int> abundant;
    for (int i = 2; i <= MAX_N; i++) {
        if (sums[i] > i) {
            abundant.push_back(i);
        }
    }
    
    /* Numbes that can be written as sum of 2 abundant numbers */
    std::vector<int> possible_numbers;
    for (auto it = abundant.begin(); it != abundant.end(); it++) {
        for (auto it2 = abundant.begin(); it2 != abundant.end(); it2++) {
            possible_numbers.push_back(*it + *it2);
        }
    }

    int T, N;
    std::cin >> T;

    while (T--) {
        std::cin >> N;
        
        if (N > MAX_N) {
            std::cout << "YES" << std::endl;
            continue;
        }
        
        bool can = std::find(possible_numbers.begin(), possible_numbers.end(), N) != possible_numbers.end();
        if (can) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
