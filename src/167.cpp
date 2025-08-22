#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int lowIdx = 0;
        int highIdx = numbers.size() - 1;
        int low = numbers[lowIdx];
        int high = numbers[highIdx];
        while (true) {
            int sum = low + high;
            if (sum > target) {
                high = numbers[--highIdx];
            } else if (sum < target) {
                low = numbers[++lowIdx];
            } else {
                return vector<int>({lowIdx + 1, highIdx + 1});
            }
        }
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

        input.pop_back();

        printVector(input);
        print(x);
        printVector(sol.twoSum(input, x));
    }
    return 0;
}
