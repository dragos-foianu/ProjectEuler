#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * This solution is based on the fact that a prime decomposition of n:
 * n = Pi(p_i ^ e_i)
 * Yields a number of unique divisors equal to the product Pi(e_i + 1).
 *
 * Example:
 * The number 28 = 2^2 * 7
 * Has 6 divisors: [1, 2, 4, 7, 14, 28]
 * Can be calculated using the exponents of the prime factorization (2 + 1) * (1 + 1) = 6
 */

/*
 * Gives the number of unique divisors of a given number.
 * input(n) given number
 * returns number of unique divisors of n
 */
int divisors(int n);

int main() {
    int T, N;
    int triangles[1001];
    std::fill(triangles, triangles + 1001, 0);
   
    /*
     * A triangle number is (n * (n + 1)) / 2.
     * The number of divisors of this triangle number can be factored in the number
     * of divisors of n and (n + 1), because they don't have prime factors in common
     * and only one of them will be a factor of 2.
     */

    int i = 1;
    int div1 = divisors(i);
    int div2 = divisors(i+1);
    int divs = div1 * div2;
    
    while (divs <= 1001) {
        div1 = div2;            /* previously calculated */
        div2 = divisors(i+2);
        divs = div1 * div2;
        
        i++;

        for (int j = 1; j < 1001; j++) {
            if (triangles[j] == 0 && divs > j) {
                triangles[j] = i * (i + 1) / 2;
            }
        }
    }    
    
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        
        std::cout << triangles[N] << std::endl;
    }
    
    return 0;
}

int divisors(int n) {
    /* We want unique divisors */
    if (!(n & 1)) {
        n >>= 1;
    }
    int divisors = 1;
    
    /* factors of 2 */
    int count = 0;
    while (!(n & 1)) {
        n >>= 1;
        count++;
    }
    divisors *= (count + 1); /* exponent e_i + 1 */
    
    /* factors of primes */
    for (int i = 3; i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        divisors *= (count + 1); /* exponent e_i + 1 */
    }

    return divisors;
}
