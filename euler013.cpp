#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define TO_INT(buffer, i) (buffer[i] - '0')
#define TO_DIGIT(i) (i + '0')

/*
 * This solution uses larger buffers to add leading '0's in order to
 * make working with the arrays easier.
 *
 * Example:
 * 00074324986199524741059474233309513058123726617309629 +
 * 00091942213363574161572522430563301811072406154908250
 * =====================================================
 * 001662671995.........................................
 */

int main() {
    int N;
    char buffer[53];
    char sum[53];
    
    std::fill(sum, sum + 53, '0');
    
    std::cin >> N;
    while (N--) {
        std::fill(buffer, buffer + 53, '0');
        std::cin >> &buffer[3];
        
        /* summation logic */
        int carry = 0;
        for (int i = 52; i >= 0; i--) {
            int addition = TO_INT(sum, i) + TO_INT(buffer, i) + carry;
            carry = addition / 10;
            sum[i] = TO_DIGIT(addition % 10);
        }
    }
    
    /* skip leading 0's */
    int i = 0;
    while (sum[i] == '0') {
        i++;
    }
    
    /* print 10 digits */
    int remaining = 10;
    while (remaining--) {
        std::cout << sum[i++];
    }
    std::cout << std::endl;
    
    return 0;
}
