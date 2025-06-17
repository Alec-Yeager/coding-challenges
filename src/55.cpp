#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lastReacher = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i + nums[i] >= lastReacher)
            {
                lastReacher = i;
            }
        }
        return lastReacher == 0;
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
        print(sol.canJump(input));
    }
}