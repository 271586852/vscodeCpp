#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        std::vector<ListNode *> visited;
        ListNode *copyA = headA;
        ListNode *copyB = headB;
        while (copyA != nullptr)
        {
            visited.push_back(copyA);
            copyA = copyA->next;
        }
        while (copyB != nullptr)
        {
            if (std::find(visited.begin(), visited.end(), copyB) != visited.end())
            {
                return copyB;
            }
            copyB = copyB->next;
        }
        return nullptr;
    }
};