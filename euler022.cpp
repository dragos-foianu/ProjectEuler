#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

/*
 * This solution calculates the value for each name and stores it in a dictionary.
 * When queried, the value can simply be found in the dictionary.
 */

int main() {
    int N, Q;
    std::map<char, int> values;
    for (char c = 'A'; c <= 'Z'; c++) {
        values.insert(std::pair<char, int>(c, c - 'A' + 1));
    }

    std::vector<std::string> names;    
    std::cin >> N;
    while (N--) {
        std::string str;
        std::cin >> str;
        names.push_back(str);
    }
    std::sort(names.begin(), names.end(), std::less<std::string>());
    
    std::map<std::string, int> name_values;
    for (auto it = names.begin(); it != names.end(); it++) {
        int sum = 0, pos = it - names.begin() + 1;
        for_each(it->begin(), it->end(), [&](char c) { sum += values.at(c); });
        name_values.insert(std::pair<std::string, int>(*it, sum * pos));
    }

    std::cin >> Q;
    while (Q--) {
        std::string q;
        std::cin >> q;
        std::cout << name_values.at(q) << std::endl;
    }
    
    return 0;
}
