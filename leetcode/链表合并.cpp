/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // list1若空，则返回list2；list2若空，则返回list1
        ListNode list3;
        if (list1 && list2 == nullptr)
        return nullptr;
        if (list1 == nullptr)
        return list2;
        if (list2 == nullptr)
        return list1;
        // list1节点与list2节点比较，若小于，则list1.next节点与l2节点比较，若大于，则l2节点插入，l1.next节点成为当前节点。
        if (list1.val < list2.val)
        {
           if (list1.next.val < list2.val)
           {
               list2.next = list1;
           }
        }
        if (list1.val >= list2.val)
        {
            list2.next = list1;
        }
        if (list1.next == nullptr )
           list1.next == list2;
        return list2;
    }
};