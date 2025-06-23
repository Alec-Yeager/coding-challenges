#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalSum = 0;
        int runningSum = 0;
        int startPos = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            totalSum += (gas[i] - cost[i]);
            if (runningSum < 0)
            {
                startPos = i;
                runningSum = 0;
            }
            runningSum += (gas[i] - cost[i]);
        }
        if (totalSum < 0)
        {
            return -1;
        }
        else
        {
            return startPos;
        }
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
    }
}