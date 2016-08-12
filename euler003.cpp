#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int T;
    unsigned long long N;
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        
        /* Remove even factor 2 */
        while (!(N & 1))
            N >>= 1;
        if (N == 1) {
            std::cout << 2 << std::endl;
            continue;
        }

        unsigned long long sqrtN = std::sqrt(N);
        
        /* Remove prime factors [3, 5, 7, ...] up to sqrt(N) */
        int i = 3;
        while (i <= sqrtN) {
            while (N % i == 0) {
                N /= i;
                sqrtN = std::sqrt(N);
            }
            i += 2;
        }
        i -= 2; /* Last increment is not needed */
        
        if (N != 1) {
            /* N is prime */
            std::cout << N << std::endl;
        } else {
            /* i is the largest factor */
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
