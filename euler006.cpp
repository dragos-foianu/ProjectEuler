#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
    Square of sum:
        sq_of_sum = ( n * (n + 1) / 2 ) ^ 2
        
    Sum of squares
        sum_of_sq = n * (n + 1) * (2n + 1) / 2
  
    => sq_of_sum - sum_of_sq = n^4 / 4 + n^3 / 6 - n^2 / 4 - n/6

 */


int main() {
    int T;
    unsigned long long result, N;
    
    std::cin >> T;
    while (T--) {
        std::cin >> N;

        unsigned long long sq_of_sum = N * (N + 1) / 2;
        sq_of_sum *= sq_of_sum;
 
        unsigned long long sum_of_sq = (N * (N + 1) * (2 * N + 1)) / 6;
 
        result = std::abs(sq_of_sum - sum_of_sq);
        std::cout << result << std::endl;
    }
    
    return 0;
}
