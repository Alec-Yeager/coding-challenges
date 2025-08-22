#include "../include/utils.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        for (auto c : s) {
            if (!isalnum(c)) {
                if (word.length() > 0)
                    words.push_back(word);
                word = "";

            } else {
                word += c;
            }
        }
        if (word.length() > 0)
            words.push_back(word);
        word = "";

        for (auto it = words.rbegin(); it < words.rend() - 1; it++) {
            word += *it + " ";
        }
        word += *(words.rend() - 1);
        return word;
    }
};

int main() {
    Solution sol;
    string line;
    while (getline(cin, line)) {
        print(line);
        print(sol.reverseWords(line));
    }

    return 0;
}
