#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int tp = 0;
        int prev = prices.back();
        int sv = prices.back();
        for (auto it = prices.rbegin(); it != prices.rend(); ++it)
        {
            if (*it > prev)
            {
                tp += sv - prev;
                sv = *it;
            }
            prev = *it;
        }
        tp += sv - prev;
        return tp;
    }
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
        print(sol.maxProfit(input));
    }
}