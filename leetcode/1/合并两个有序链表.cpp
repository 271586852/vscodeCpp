#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode dummy;
        ListNode *p3 = &dummy;

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                p3->next = p1;

                p1 = p1->next;
                
            }
            else
            // if (p1->val > p2->val)  //使用该语句为何陷入死循环？
            {
                p3->next = p2;
                
                p2 = p2->next;
                
            }
            p3 = p3->next;
        }
        
        if (p1 == nullptr)
        {
            p3->next = p2;
        }
        if (p2 == nullptr)
        {
            p3->next = p1;
        }
        return dummy.next;
    }
};