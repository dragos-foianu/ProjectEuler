#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int fact[10] = { 1 };
    for (int i = 1; i < 10; i++) {
        fact[i] = fact[i - 1] * i;
    }
    
    int N;
    std::cin >> N;
    
    unsigned long long total = 0;
    for (int i = 10; i < N; i++) {
        int tmp = i, sum = 0;
        while (tmp) {
            sum += fact[tmp % 10];
            tmp /= 10;
        }
        if (sum % i == 0) {
            total += i;
        }
    }
    
    std::cout << total << std::endl;
    
    return 0;
}
