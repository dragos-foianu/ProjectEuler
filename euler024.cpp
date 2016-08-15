#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * This solution creates a factoradic representation of N and uses it to
 * generate the N-th permutation. See factorial number theory for explanation
 * on factoradic representation.
 */

int main() {
    std::vector<int> factoradic;
    std::vector<char> permutation;
    std::vector<char> str;
    
    int T;
    unsigned long long N;
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        N--;    /* Index correction */
        
        /* Create factoradic representation of N */
        int i = 1;
        while (i <= 13) {
            factoradic.push_back(N % i);
            N = N / i;
            i++;
        }

        /* Auxiliary vector for permutation elements */
        for (char c = 'a'; c <= 'm'; c++) {
            str.push_back(c);
        }
        
        /* Generate permutation using factoradic representation of N */
        permutation.clear();
        while (!factoradic.empty()) {
            int index = factoradic.back();
            factoradic.pop_back();
            permutation.push_back(str[index]);
            str.erase(str.begin() + index);
        }
        
        std::cout << std::string(permutation.begin(), permutation.end()) << std::endl;
    }
    
    return 0;
}
