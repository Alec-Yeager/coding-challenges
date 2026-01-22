
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head) {
            while (head->next) {
                if (head->next == head) {
                    return true;
                } else {
                    ListNode *trueNext{head->next};
                    head->next = head;
                    head = trueNext;
                }
            }
        }
        return false;
    }
};