#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>

/*
 * Is given number Pandigital or not?
 * input(n) given number
 * returns true if n is pandigital, false otherwise
 */
bool isPandigital(int x);

/*
 * Concatenates 3 integers:
 * a = 123, b = 456, c = 789 into 123456789
 *
 * input(a, b, c) three integers
 * returns concatenation of the 3 integers into a single integer
 */
long concatenate(int a, int b, int c);

/* Ugly, but whatever */

int main() {
    int N;
    unsigned long long sum = 0;
    std::set<int> prods;
    std::cin >> N;
    
    int max = std::pow(10, N);
    for (int i = 2; i < 100; i++) {
        for (int j = i; j < 10000 / (i + 1); j++) {
            if (i * j > max) {
                break;
            }
            long concat = concatenate(i * j, i, j);
            if (concat < max) {
                int len = 0, tmp = concat;
                while (tmp) {
                    len++;
                    tmp /= 10;
                }
                if (len == N && isPandigital(concat)) {
                    prods.insert(i * j);
                }
            }
        }
        
        if (i * i > max) {
            break;
        }
    }

    for (auto it = prods.begin(); it != prods.end(); it++) {
        sum += *it;
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}

long concatenate(int a, int b, int c) {
    long tmp = b;
    while (tmp > 0) {
        a *= 10;
        tmp /= 10;
    }
    long ab = a + b;
    
    tmp = c;
    while (tmp > 0) {
        ab *= 10;
        tmp /= 10;
    }
    return ab + c;
}

bool isPandigital(int x) {
    long tmp, digits = 0, count = 0;
 
    while (x > 0) {
        tmp = digits;
        digits |= 1 << (int)((x % 10) - 1);
        if (tmp == digits) {
            return false;
        }
 
        count++;
        x /= 10;
    }
    return digits == (1 << count) - 1;
}
