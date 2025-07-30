#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0;
        int p2 = s.length() - 1;
        while (p2 > p1) {
            char c1 = tolower(s[p1]);
            char c2 = tolower(s[p2]);
            if (!isalnum(c1)) {
                p1++;
            } else if (!isalnum(c2)) {
                p2--;
            } else if (c1 == c2) {
                p1++;
                p2--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        print(line);
        print(sol.isPalindrome(line));
    }
}