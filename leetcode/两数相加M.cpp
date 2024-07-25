struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* m = l1;
        ListNode* n = l2;
        
        int lengthL1 = listLength(m);
        int lengthL2 = listLength(n);

        
        
    };

private :
    int listLength(ListNode* l){
        //已知链表非空
        int num = 1;
        while (l->next != nullptr)
        {
            num++;
            l = l->next;
        }
        return num;
    };

    void listAdd(int m,int n,ListNode* l1, ListNode* l2){
        int x = m - n;
        if(x>0){
            
        }
    };
};