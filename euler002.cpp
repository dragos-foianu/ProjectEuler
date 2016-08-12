#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int T;
    unsigned long long N;
    
    std::cin >> T;
    
    /*
      [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...]
      
      Even-valued terms are on positions 0, 3, 6, 9, ... .
      F(n) = F(n-1) + F(n-2) = 2F(n-2) + F(n-3) = 3F(n-3) + 2F(n-4) =>
      (I) => F(n) = 3F(n-3) + 2F(n-5) + 2F(n-6)
      
      F(n-3) = F(n-4) + F(n-5) = 2F(n-5) + F(n-6) =>
      (II) => 2F(n-5) = F(n-3) - F(n-6)
      
      (I) an (II) => F(n) = 4F(n-3) + F(n-6)
      => EvenF(n) = 4 * EvenF(n-1) + EvenF(n-2)
      
      This progression generates every 3rd Fibonacci number.
     */
    
    unsigned long long a, b, c, sum;
    while (T--) {
        std::cin >> N;
        
        sum = 0;
        a = 0; /* F(0) */
        b = c = 2; /* F(3) */

        while (c <= N) {
            sum += c;
            c = 4 * b + a;
            a = b;
            b = c;
        }

        std::cout << sum << std::endl;
    }
    
    return 0;
}
