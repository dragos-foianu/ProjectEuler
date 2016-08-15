#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_N 15

/*
 * This solution uses DP. The triangle matrix holds the current maximum
 * at each step of the way. The last line in the triangle matrix represents
 * each "leaf" node. We simply have to select a maximum from this row to get
 * the maximum sum.
 * Example:
 *
 * 3            =>  3
 * 7 4          => 10  7
 * 2 4 6        => 12 14 16
 * 8 5 9 3      => 20 19 23 19
 *
 * The last line contains the maximum.
 */

int main() {
    int T, N, e;
    int triangle[MAX_N+1][MAX_N+1] = { 0 };
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        std::cin >> triangle[1][1];
        
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                std::cin >> e;
                triangle[i][j] = std::max(triangle[i-1][j-1], triangle[i-1][j]) + e;
            }
        }
        
        int max = triangle[1][1];
        for (int i = 1; i <= N; i++) {
            max = std::max(max, triangle[N][i]);
        }
        
        std::cout << max << std::endl;
    }
    
    return 0;
}
