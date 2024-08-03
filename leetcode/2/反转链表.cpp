
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while(head != nullptr){
            ListNode* newNode = new ListNode(head->val);
            newNode->next = newHead;
            newHead = newNode;
            head = head->next;
        }
        return newHead; 
    }
};