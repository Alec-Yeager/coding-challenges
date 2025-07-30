#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string lcp = strs[0];
        for (size_t strIdx = 1; strIdx < strs.size(); ++strIdx) {

            string tempLcp = "";
            auto compstr = strs[strIdx];
            for (size_t lettIdx = 0;
                 lettIdx < lcp.length() && lettIdx < compstr.length() && compstr[lettIdx] == lcp[lettIdx]; ++lettIdx) {
                tempLcp += lcp[lettIdx];
            }
            lcp = tempLcp;
            if (tempLcp == "") {
                return "";
            }
        }
        return lcp;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string x;
        vector<string> input;
        while (ss >> x) {
            input.push_back(x);
        }

        printVector(input);
        print(sol.longestCommonPrefix(input));
    }
}
