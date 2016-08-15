#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100001

/*
 * This solution uses a sieve to calculate the sum of divisors for each number
 * up to MAX_N. Having the sum of divisors for each number, finding amicable pairs
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
    
    std::vector<int> amicable;
    for (int i = 1; i < MAX_N; i++) {
        /*
         * 1) Do not index out of upper bound.
         * 2) Does i form an amicable pair with anyone?
         * 3) The pair is of 2 distinct numbers.
         */
        if (sums[i] < MAX_N && sums[sums[i]] == i && sums[i] != i) {
            amicable.push_back(sums[sums[i]]);
        }
    }
    
    int T, N;
    std::cin >> T;

    while (T--) {
        std::cin >> N;
        
        int asum = 0;
        for (auto it = amicable.begin(); it != amicable.end() && *it < N; it++) {
            asum += *it;
        }
        std::cout << asum << std::endl;
    }
    
    return 0;
}
