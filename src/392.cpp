#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int subIter = 0;
        for (int fulIter = 0; fulIter < t.length(); fulIter++) {
            if (t[fulIter] == s[subIter]) {
                if (++subIter == s.length()) {
                    return true;
                }
            }
        }
        return (subIter == s.length());
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        string t;
        ss >> s;
        ss >> t;
        print(line);
        print(sol.isSubsequence(s, t));
    }
    return 0;
}
