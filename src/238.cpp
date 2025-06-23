#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer;
        int frontProds[nums.size()];
        int backProds[nums.size()];
        frontProds[0] = *nums.begin();
        backProds[nums.size() - 1] = *(nums.end() - 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            int j = nums.size() - 1 - i;
            frontProds[i] = frontProds[i - 1] * nums[i];
            backProds[j] = backProds[j + 1] * nums[j];
        }
        answer.push_back(backProds[1]);
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            answer.push_back(frontProds[i - 1] * backProds[i + 1]);
        }
        answer.push_back(frontProds[nums.size() - 2]);
        return answer;
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