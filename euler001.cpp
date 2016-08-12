#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    unsigned long long sum;
    
    std::cin >> T;

    unsigned long long mults3, mults5, mults15;
    
    while (T--) {
        std::cin >> N;

        /* We want only "less than" N */
        N--;
        
        /* There are N / 3 multiples of 3 */
        mults3 = std::floor(N / 3);
        
        /* N / 5 multiples of 5 */
        mults5 = std::floor(N / 5);
        
        /* N / 15 multiples of 15 (both 3 and 5) */
        mults15 = std::floor(N / 15);
     
        sum  = ( 3 * mults3  * ( mults3 + 1)) / 2;
        sum += ( 5 * mults5  * ( mults5 + 1)) / 2;
        sum -= (15 * mults15 * (mults15 + 1)) / 2; /* multiples of 15 are counted twice */
        
        std::cout << sum << std::endl;
    }
    
    return 0;
}
