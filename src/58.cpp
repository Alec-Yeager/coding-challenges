#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lwl = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (*it == ' ') {
                if (lwl > 0) {
                    return lwl;
                }
            } else {
                lwl++;
            }
        }
        return lwl;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        print(sol.lengthOfLastWord(line));
    }
}
