#include "../include/utils.hpp"
#include <cstdint>
#include <iostream>
#include <span>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> lines;
        int charCount = 0;
        int rowStart = 0;

        auto generateRow = [&](int start, int end, int count) {
            string gennedRow;
            if (end - start == 0) {
                gennedRow += words[start];
                for (int j = 0; j < maxWidth - words[start].length(); j++) {
                    gennedRow += " ";
                }
                return gennedRow;
            }

            int remainingSpaces = maxWidth - count;
            int nWords = end - start + 1;
            int baseSpaces = remainingSpaces / (nWords - 1);
            string spaceString;
            for (int j = 0; j < baseSpaces; j++) {
                spaceString += " ";
            }
            int remSpaces = remainingSpaces % (nWords - 1);
            for (int j = start; j < end; j++) {
                gennedRow += words[j];
                gennedRow += spaceString;
                if (j - start < remSpaces) {
                    gennedRow += " ";
                }
            }
            gennedRow += words[end];
            return gennedRow;
        };

        for (int i = 0; i < words.size(); i++) {
            if (charCount == maxWidth) {
                lines.push_back(words[i - 1]);
                charCount = 0;
                rowStart = i;
            } else if (charCount + words[i].length() + (i - rowStart) > maxWidth)

            {
                string row = generateRow(rowStart, i - 1, charCount);
                lines.push_back(row);
                charCount = 0;
                rowStart = i;
            }
            charCount += words[i].length();
        }
        string finalRow;
        for (int j = rowStart; j < words.size(); j++) {
            finalRow += words[j];
            if (j != words.size() - 1) {
                finalRow += " ";
            }
        }
        int remaining = maxWidth - finalRow.length();
        if (finalRow != "") {
            for (int j = 0; j < remaining; j++) {
                finalRow += " ";
            }
            lines.push_back(finalRow);
        }
        return lines;
    }
};

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
        int width = stoi(*(input.end() - 1));
        input.pop_back();
        printVector(input);
        for (auto r : sol.fullJustify(input, width)) {
            print(r);
        }
    }
    return 0;
}
