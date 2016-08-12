#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000001

int main() {
    int T;
    int N;
    int *cache = new int[MAX];    
    
    int max_chain = 0;
    int max_producer = 1;
    for (int i = 2; i < MAX; i++) {
        int crt_chain = 1;
        unsigned long long num = i;
        
        while (num != 1) {
            if (!(num & 1)) {
                num /= 2;
            } else {
                num = num * 3 + 1;
            }
            crt_chain++;
        }
        
        if (crt_chain >= max_chain) {
            max_chain = crt_chain;
            max_producer = i;
            cache[i] = max_producer;
        } else {
            cache[i] = cache[i - 1];
        }
    }
    
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::cout << cache[N] << std::endl;
    }
    
    return 0;
}
