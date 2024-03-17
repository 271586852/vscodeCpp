#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        std::vector<ListNode *> copy;
        while (head != NULL)
        {
            // std::find(copy.begin(), copy.end(), head) 是在 copy 向量的全部范围内查找 head
            if (std::find(copy.begin(), copy.end(), head) != copy.end())
            {
                return true;
            }
            else
            {
                copy.push_back(head);
            }
            head = head->next;
        }
        return false;
    }
};

// 原代码存在多个错误：

// int vector<ListNode> copy;：这行代码试图声明一个 std::vector，但是类型和语法都是错误的。应该是 std::vector<ListNode*> copy;，这样才能创建一个用于存储 ListNode 指针的向量。

// if(vector.find copy){：这行代码试图在 vector 中查找 copy，但是语法错误。std::vector 没有 find 方法。你可能需要使用 std::find 算法，或者使用迭代器遍历 vector。

// return pos;：这行代码试图返回一个名为 pos 的变量，但是 pos 在此上下文中并未定义。

// vector.add(ListNode);：这行代码试图将 ListNode 类型添加到 vector 中，但是 std::vector 没有 add 方法，应该使用 push_back 方法。此外，你应该添加一个 ListNode 的实例，而不是 ListNode 类型。

// 函数没有在所有路径上返回值：如果 head -> next 为 NULL，那么函数没有返回值。在 C++ 中，如果一个函数声明了返回类型（在这种情况下是 bool），那么它必须在所有路径上返回一个值。