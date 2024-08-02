#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <bitset>


#include <queue> // Include the <queue> header file

class Solution {
public:
    int hammingDistance(int x, int y) {
        std::stack<int> xStack, yStack; // Change 'std::queue<int>' to 'std::stack<int>'
        std::bitset<sizeof(int) * 8> binary(x); // 使用 bitset 将整数转换为二进制表示
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            xStack.push(binary[i]); // 将二进制位逐个存入栈
        }

        binary = std::bitset<sizeof(int) * 8>(y); // 使用 bitset 将整数转换为二进制表示
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            yStack.push(binary[i]); // 将二进制位逐个存入栈
        }

        int count = 0;
        while (!xStack.empty() && !yStack.empty()) {
            if (xStack.top() != yStack.top()) {
                count++;
            }
            xStack.pop();
            yStack.pop();
        }
        if(!xStack.empty())
        {
            while (!xStack.empty()) {
                if (xStack.top() != 0) {
                    count++;
                }
                xStack.pop();
            }
        }
        else if(!yStack.empty())
        {
            while (!yStack.empty()) {
                if (yStack.top() != 0) {
                    count++;
                }
                yStack.pop();
            }
        }
        return count;
    }
};