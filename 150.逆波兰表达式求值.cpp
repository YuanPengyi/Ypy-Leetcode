/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (48.19%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 47.1K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 * 
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 
 * 说明：
 * 
 * 
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 
 * 
 * 示例 1：
 * 
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        vector<int> tmp;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+") tmp.push_back(1);
            else if(tokens[i] == "*") tmp.push_back(2);
            else if(tokens[i] == "-") tmp.push_back(3);
            else if(tokens[i] == "/") tmp.push_back(4);
            else tmp.push_back(5);
        }
        for(int i=0; i<tokens.size(); i++){
            int a,b;
            switch(tmp[i]){
                case 1:
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(a+b);
                    break;
                case 2:
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(a*b);
                    break;
                case 3:
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b-a);
                    break;
                case 4:
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b/a);
                    break;
                default:
                    s.push(stoi(tokens[i]));
            }
            
        }

        return s.top();
    }
};
// @lc code=end

