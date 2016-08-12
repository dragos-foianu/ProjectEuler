#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * Naive implementation. Just calculate every subsequence in the number.
 * [1234567] K=4
 *     1 * 2 * 3 * 4
 *     2 * 3 * 4 * 5
 *     3 * 4 * 5 * 6
 *     4 * 5 * 6 * 7 => max
 *
 * Could be improved by using the previous multiplication result:
 *     1 * 2 * 3 * 4
 *     / 1 * 5
 *     / 2 * 6
 *     / 3 * 7 => max
 *
 * Also when getting a 0 we can skip sequences:
 * [1230456], K=3
 *     1 * 2 * 3
 *     0 => skip K
 *     4 * 5 * 6 = max
 */

int main() {
    int T, N, K;
    char buffer[1001];
    int max;
    
    std::cin >> T;
    while (T--) {
        std::cin >> N >> K >> buffer;
        max = 0;

        int offset;
        for (int i = 0; i < N - K; i++) {
            int newmax = 1;
            for (int j = i; j < i + K; j++) {
                newmax *= (buffer[j] - '0');
            }
            
            if (newmax > max)
                max = newmax;
        }

        std::cout << max << std::endl;
    }
    
    return 0;
}
