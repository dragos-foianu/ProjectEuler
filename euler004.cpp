#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

/*
 * Checks if a given number is a palindrome.
 * input(int N) given number
 * returns true if N is palindrome, false otherwise
 */
bool isPalindrome(int N);

int main() {
    int T, N;
    std::set<int> allPalindromes;

    /* Generate all palindromes */
    int i, j;
    for (i = 101; i < 1000; i++) {
        for (j = 101; j < 1000; j++) {
            int potential = i * j;
            if (isPalindrome(potential)) {
                allPalindromes.insert(potential);
            }
        }
    }

    std::cin >> T; 
    while (T--) {
        std::cin >> N;
        
        /* Find largest palindrome smaller than N */
        std::set<int>::iterator it;
        for (it = allPalindromes.begin(); it != allPalindromes.end() && *it < N; it++) {
        }
        it--;
        
        std::cout << *it << std::endl;
        
        continue;
    }
    
    return 0;
}

bool isPalindrome(int N) {
    int rev = 0, tmp = N;
    
    while (tmp > 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    
    return rev == N;
}
