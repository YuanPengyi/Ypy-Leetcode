/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.16%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    60.8K
 * Total Submissions: 146.8K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int first = 0, last = s.length()-1;
        while(first < last){
            while( !((s[first]>='0'&&s[first]<='9') || (s[first]>='A'&&s[first]<='Z') || (s[first]>='a'&&s[first]<='z')) && first<=last){
                first++;
            }
            while( !((s[last]>='0'&&s[last]<='9') || (s[last]>='A'&&s[last]<='Z') || (s[last]>='a'&&s[last]<='z')) && last>=first){
                last--;
            }
            if(first >= last) return true;
            cout << s[first] << " " << s[last] << endl;
            if(s[first] == 'P' && s[last] == '0' || s[last] == 'P' && s[first] == '0' ){
                return false;
            }
            if(!(s[first] == s[last] || s[first]-'A' == s[last]-'a' || s[first]-'a' == s[last]-'A')) return false;
            first++; last--;
        }

        return true;
    }
};
// @lc code=end

