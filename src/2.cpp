#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

     void printSelf()
     {
        cout << this->stringRep() << endl;
     }

     string stringRep()
     {
        return this->next ? to_string(this->val) + this->next->stringRep() : to_string(this->val);
     }

 };

 ListNode* from_int(int xyz)
 {
    return new ListNode(xyz % 10, xyz / 10 ? from_int(xyz / 10) : nullptr);
 }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headNode = new ListNode();
        ListNode* curNode = headNode;

        while (l1 || l2)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            curNode->val += sum;
            int carry = curNode->val / 10;
            curNode->val = curNode->val % 10;
            
            if (l1 || l2 || carry)
            {
                curNode->next = new ListNode(carry);
                curNode = curNode->next;
            }
        }

        return headNode;
    }
};

int main()
{
    Solution sol;
    string line;

    while (getline(cin, line))
    {
        // cout << line << endl;
        int n1;
        int n2;
        stringstream ss(line);
        ss >> n1;
        ss >> n2;
        cout << n1 << " " << n2 << endl;

        ListNode* ln1 = from_int(n1);
        ListNode* ln2 = from_int(n2);

        ln1->printSelf();
        ln2->printSelf();
        sol.addTwoNumbers(ln1,ln2)->printSelf();
    }

    return 0;
}
