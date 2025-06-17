#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "../include/utils.hpp"
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        quickSort(citations, 0, citations.size());
        int hIdx = 0;
        while (hIdx < citations.size() && citations[hIdx] > hIdx)
        {
            hIdx++;
        }
        return hIdx;
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
        print(sol.hIndex(input));
        printVector(input);
    }
}