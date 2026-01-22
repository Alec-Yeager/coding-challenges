#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (! head)
        {
            return nullptr;
        }
        unordered_map<Node*, Node*> refmap {{nullptr,nullptr}};
        
        Node* copyHead = new Node(head->val);
        copyHead->random = head->random;
        refmap[head] = copyHead;
        
        Node* copyCur = copyHead;
        Node* cur = head->next;

        

        while (cur) {
            copyCur->next = new Node(cur->val);
            copyCur = copyCur->next;

            copyCur->random = cur->random;
            refmap[cur] = copyCur;
            cur = cur->next;
        }

        copyCur = copyHead;
        while (copyCur)
        {
            copyCur->random = refmap[copyCur->random];
            copyCur = copyCur->next;
        }

        return copyHead;
    }
};
