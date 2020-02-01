/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (25.28%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 28.5K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(denominator == 0) return "";

        string result = "";

        if((numerator < 0 && denominator > 0) || 
            (numerator > 0 && denominator < 0)){
                result.append("-");
            }           

        long a = abs(long(numerator));
        long b = abs(long(denominator));
        long num1 = a / b;
        long num2 = a % b;

        result.append(to_string(num1));

        if(num2 == 0) return result;

        result.append(".");
        int pos = result.length()-1;
        unordered_map<int, int> record;
        while(num2 != 0 && record.count(num2) == 0){
            record[num2] = ++pos;
            num2*=10;
            result.append(to_string(num2/b));
            num2%=b;
        }
        if(num2 != 0){
            result.insert(record[num2], "(");
            result.append(")");
        }

        return result;
    }
};
// @lc code=end

