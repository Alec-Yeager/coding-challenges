#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> result(ratings.size(), 1);
        int n = ratings.size();
        int finalSum = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                result[i] = result[i - 1] + 1;
            }
        }

        finalSum += result.back();

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && result[i] <= result[i + 1])
            {
                result[i] = result[i + 1] + 1;
            }
            finalSum += result[i];
        }
        return finalSum;
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
        print(sol.candy(input));
    }
}