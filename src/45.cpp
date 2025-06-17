#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> mins(nums.size() + 1);
        // mins.reserve(nums.size());
        mins[nums.size()] = 0;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            mins[i] = mins[i + 1] + 1000;
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++)
            {
                mins[i] = min(mins[i], 1 + mins[j]);
            }
        }
        // printVector(mins);
        return mins[0];
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
        print(sol.jump(input));
    }
}