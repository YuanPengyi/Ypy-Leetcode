/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (36.04%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    18.3K
 * Total Submissions: 50.4K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n != 0){
            int num1 = n%26;
            int num2 = n/26;

            if(num1 == 0){
                res.insert(0, "Z");
                n = num2-1;
            }else{
                string tmp = "A";
                tmp[0] = tmp[0] + num1 - 1;
                res.insert(0, tmp);
                n = num2;
            }
        }

        return res;
    }
};
// @lc code=end

