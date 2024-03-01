#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c:s)
        {
            if(c=='('||c=='['||c=='{')
            {
                stk.push(c);
            }
            else
            {
                if(stk.empty())          // 注意输入字符串以闭合括号开始，或者包含不匹配的闭合括号

                {
                    return false;
                }

                if(c==')'&&stk.top()!='(')
                {
                    return false;
                }
                if(c==']'&&stk.top()!='[')
                {
                    return false;
                }
                if(c=='}'&&stk.top()!='{')
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};

