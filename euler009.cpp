#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * (1) a^2 + b^2 = c^2
 * a + b + c = n => (2) c = n - a - b
 *
 * (1) and (2) => a^2 + b^2 = (n - a - b)^2 => (3) b = n(2a - N) / 2(a - N)
 *
 * We use (3) and (2) to calculate b and c, respectively, from a.
 */

int main() {
    int T, N;
    long a, b, c;
    long max;
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        
        max = -1;
        for (a = 2; a < N; a++) {
            b = N * (2 * a - N) / (a - N) / 2;
            c = N - a - b;
            
            if (b > 0 && c > 0 && c * c == b * b + a * a) {
                if (a * b * c > max)
                    max = a * b * c;
            }
        }
        
        std::cout << max << std::endl;
    }
    
    return 0;
}
