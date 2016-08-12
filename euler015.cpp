#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 501
#define MODULO 1000000007

/* 
 * This solution precomputes the maximum path for each element in a 500x500 lattice.
 *
 * This solution is basically an incomplete Pascal triangle. Vizualisation:
 *
 * 1 1 1          1
 * 1 2 3         1 1
 * 1 3 6        1 2 1
 *               3 3
 *                6
 */

int main() {
    int lattice[MAX_SIZE][MAX_SIZE] = {0};
    
    for (int i = 0; i < MAX_SIZE; i++) {
        lattice[0][i] = 1;
        lattice[i][0] = 1;
    }
    
    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j < MAX_SIZE; j++) {
            lattice[i][j] = (lattice[i-1][j] + lattice[i][j-1]) % MODULO;
        }
    }
    
    int T, N, M;
    std::cin >> T;
    
    while (T--) {
        std::cin >> N >> M;
        std::cout << lattice[N][M] << std::endl;
    }
    
    return 0;
}
