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
        int mp = 0;
        int mv = 0;
        for (auto it = prices.rbegin(); it != prices.rend(); ++it)
        {
            if (*it > mv)
            {
                mv = *it;
            }
            if (mv - *it > mp)
            {
                mp = mv - *it;
            }
        }
        return mp;
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