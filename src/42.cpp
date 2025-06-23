#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.hpp"
#include <queue>
using namespace std;

struct poolWall
{
    int h;
    int l;
    int vol;
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int storedVol = 0;
        auto cmp = [](poolWall left, poolWall right)
        { return left.h > right.h; };
        priority_queue<poolWall, vector<poolWall>, decltype(cmp)> poolQueue(cmp);
        for (auto &val : height)
        {
            while (!poolQueue.empty() && val >= poolQueue.top().h)
            {
                poolWall top = poolQueue.top();
                // top.vol += top.l * top.h;
                storedVol += top.vol;
                poolQueue.pop();
                if (!poolQueue.empty())
                {
                    poolWall next = poolQueue.top();
                    next.l += top.l;
                    next.vol += (next.h - top.h) * top.l;
                    if (val < next.h)
                    {
                        int cutvol = (val - top.h) * (next.l - 1);
                        next.vol -= cutvol;
                        storedVol += cutvol;
                    }
                    poolQueue.pop();
                    poolQueue.push(next);
                    // std::cout << next.vol << endl;
                }
            }

            poolWall pool;
            pool.h = val;
            pool.l = 1;
            pool.vol = 0;
            poolQueue.push(pool);
        }

        // while (!poolQueue.empty())
        // {
        //     std::cout << poolQueue.top().h << "," << poolQueue.top().l << "," << poolQueue.top().vol << " ";
        //     poolQueue.pop();
        // }
        // std::cout << std::endl;
        return storedVol;
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
        print(sol.trap(input));
    }
}