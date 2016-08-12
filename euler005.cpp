#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
  Sorry for ugly code. :(
  This solution iterates through the numbers N = 2..40.
  
  For each number we find its prime factors:
  2 = 2
  3 = 3
  4 = 2^2
  5 = 5
  6 = 2 * 3
  7 = 7
  8 = 2^3
  
  If you can divide by 8, you can divide by 4 and 2. For example, 8 is 2^3,
  which means it also covers all previous cases: 2 and 2^2.
  We are interested in the highest power value for each prime factor.
  
  Our solution becomes: 2^3 * 3 * 5 * 7 = 840.
 */

int main() {
    int T, N;
    unsigned long long largest;
    int factor[41];
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;

        /* Reset factor table and result buffer */
        std::fill(factor, factor + 41, 0);
        largest = 1;

        int i;
        /* For each number in 2..N */
        for (i = 2; i <= N; i++) {
            int tmpi = i;
            
            /* 2's */
            int count = 0;
            while (!(tmpi & 1)) {
                tmpi >>= 1;
                count++;
            }
            /* Keep the largest */
            factor[2] = count > factor[2] ? count : factor[2];
            
            /* Other prime factors */
            int j = 3;
            int sqrti = sqrt(tmpi);
            while (j <= sqrti) {
                count = 0;
                while (tmpi % j == 0) {
                    tmpi /= j;
                    sqrti = std::sqrt(tmpi);
                    count++;
                }
                factor[j] = count > factor[j] ? count : factor[j];
                j += 2;
            }
            
            /* Last prime factor */
            if (tmpi != 1) {
                factor[tmpi] = factor[tmpi] == 0 ? 1 : factor[tmpi];
            }
        }
        
        for (int j = 1; j <= N; j++) {
            largest *= std::pow(j, factor[j]);
        }
        std::cout << largest << std::endl;
    }

    return 0;
}
