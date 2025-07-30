#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    vector<string> ones = {"I", "V"};
    vector<string> tens = {"X", "L"};
    vector<string> hundreds = {"C", "D"};
    vector<string> thousands = {"M", "OOPS"};
    vector<vector<string>> rankVec = {ones, tens, hundreds, thousands};

    string strRepr = "";
    int rank = 0;
    while (num > 0) {
      string rankRepr = "";
      int digit = num % 10;
      bool g5 = digit >= 5;
      digit = digit % 5;

      if (digit == 4) {
        rankRepr += rankVec[rank][0];
        rankRepr += (g5) ? rankVec[rank + 1][0] : rankVec[rank][1];
      } else {
        rankRepr += (g5) ? rankVec[rank][1] : "";
        while (digit > 0) {
          rankRepr += rankVec[rank][0];
          digit--;
        }
      }

      strRepr = rankRepr + strRepr;
      rank++;
      num /= 10;
    }

    return strRepr;
  }
};

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
    print(sol.intToRoman(input[0]));
  }
  return 0;
}
