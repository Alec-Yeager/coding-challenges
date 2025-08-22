#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int currentRow = 1;
        int diff = 1;
        vector<string> rows(numRows);
        rows[0] += s[0];
        for (auto c = s.begin() + 1; c < s.end(); c++) {
            rows[currentRow] += *c;
            if (currentRow == numRows - 1) {
                diff = -1;
            } else if (currentRow == 0) {
                diff = 1;
            }
            currentRow += diff;
        }
        string ret;
        for (auto rs : rows) {
            ret += rs;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        int rows;
        print(line);
        ss >> word;
        ss >> rows;
        print(sol.convert(word, rows));
    }
    return 0;
}
