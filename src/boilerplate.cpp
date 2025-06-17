#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
};

int main()
{
    Solution sol;
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        int x;
        vector<int> input;
        while (ss >> x)
        {
            input.push_back(x);
        }

        printVector(input);
    }
}