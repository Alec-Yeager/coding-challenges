#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int x;
        vector<int> input;
        while (ss >> x) {
            input.push_back(x);
        }

        printVector(input);
    }
    return 0;
}

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        print(line);
    }
    return 0;
}

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        vector<string> input;
        while (ss >> s) {
            input.push_back(s);
        }
        printVector(input);
    }
    return 0;
}
