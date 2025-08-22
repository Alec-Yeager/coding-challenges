#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                bool tryAgain = false;
                if (haystack[i + j] == needle[0])
                    tryAgain = true;

                while (j < needle.length() && haystack[i + j] == needle[j]) {
                    if (haystack[i + j] == needle[0])
                        tryAgain = true;
                    j++;
                }
                if (haystack[i + j] == needle[0])
                    tryAgain = true;
                if (j == needle.length()) {
                    return i;
                } else {
                    if (!tryAgain)
                        i += j;

                    continue;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string hay;
        string needle;
        ss >> hay;
        ss >> needle;
        print(line);
        print(sol.strStr(hay, needle));
    }
    return 0;
}
