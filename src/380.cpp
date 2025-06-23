#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "../include/utils.hpp"
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet()
    {
        mStoredPos = 0;
    }

    bool insert(int val)
    {
        if (mValToPos.count(val))
        {
            return false;
        }
        mValToPos[val] = mStoredPos;
        mPosToVal[mStoredPos] = val;
        mStoredPos++;
        return true;
    }

    bool remove(int val)
    {
        if (!mValToPos.count(val))
        {
            return false;
        }

        int pos = mValToPos.at(val);
        mValToPos.erase(val);
        mPosToVal.erase(pos);

        if (pos < mStoredPos - 1)
        {
            int oldFinalVal = mPosToVal.at(mStoredPos - 1);
            mPosToVal[pos] = oldFinalVal;
            mValToPos.at(oldFinalVal) = pos;
        }

        mStoredPos--;

        return true;
    }

    int getRandom()
    {
        int randPos = rand() % mStoredPos;

        cout << "Getting number at pos " << randPos << endl;
        return mPosToVal.at(randPos);
    }

    map<int, int> getValToPos()
    {
        return mValToPos;
    }

    map<int, int> getPosToVal()
    {
        return mPosToVal;
    }

private:
    map<int, int> mValToPos;
    map<int, int> mPosToVal;
    int mStoredPos;
};

class Solution
{
};

int main()
{
    srand(time(0));

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

    RandomizedSet *obj = new RandomizedSet();
    print(obj->remove(3));
    print(obj->insert(3));
    print(obj->remove(3));
    print(obj->insert(4));
    print(obj->insert(2));
    // printMap(obj->getValToPos());
    // printMap(obj->getPosToVal());
    print(obj->getRandom());
    print(obj->getRandom());
    print(obj->getRandom());
    obj->remove(4);
    print(obj->getRandom());
}