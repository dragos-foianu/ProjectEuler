#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
 * This solution uses 3 grids:
 * grid   = the input grid (for left-right maximum and diagonal maximum)
 * grid_T = the input grid transposed (for up-down maximum)
 * grid_M = the input grid mirrored horizontally (for secondary diagonal maximum)
 *
 * grid_T will be exceptionally useful to avoid cache misses when going up-down the grid.
 * grid_M will be useful for doing both diagonals in the same way and in the same loop.
 */

int main() {
    int grid[20][20], grid_T[20][20], grid_M[20][20];
    int v;
    int lr_max = 0, ud_max = 0, d1_max = 0, d2_max = 0;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cin >> v;
            grid[i][j] = grid_T[j][i] = grid_M[i][19-j] = v;
        }
    }
    
    for (int i = 0; i < 20; i++) {
        /* left-right maximum */
        for (int j = 0; j < 17; j++) {
            int tmp_lr = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
            if (tmp_lr > lr_max)
                lr_max = tmp_lr;
        }
        
        /* up-down maximum */
        for (int j = 0; j < 17; j++) {
            int tmp_ud = grid_T[i][j] * grid_T[i][j+1] * grid_T[i][j+2] * grid_T[i][j+3];
            if (tmp_ud > ud_max)
                ud_max = tmp_ud;
        }
    }

    for (int i = 0; i < 17; i++) {
        /* primary diagonal maximum */
        for (int j = 3; j < 20; j++) {
            int tmp_d1 = grid[i][j-3] * grid[i+1][j-2] * grid[i+2][j-1] * grid[i+3][j];
            if (tmp_d1 > d1_max)
                d1_max = tmp_d1;
        }
        
        /* secondary diagonal maximum */        
        for (int j = 3; j < 20; j++) {
            int tmp_d2 = grid_M[i][j-3] * grid_M[i+1][j-2] * grid_M[i+2][j-1] * grid_M[i+3][j];
            if (tmp_d2 > d2_max)
                d2_max = tmp_d2;
        }
        
    }
    
    std::cout << std::max(std::max(lr_max, ud_max), std::max(d1_max, d2_max));
    
    return 0;
}
