/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 76.9K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> sub;
        int cnt0 = 0;
        int pre = 0;
        int len = s.length();
        while(s[0] == ' '){
            len = len - 1;
            s = s.substr(1, len);
        }
        while(s[len-1] == ' '){
            len = len - 1;
            s = s.substr(0, len);
        }
        cout << "|" << s << "|" << endl;
        for(int i=0; i<s.length(); i++){
            if(cnt0 == 0 && s[i] == ' '){
                cnt0 = 1;
                sub.push_back(s.substr(pre, i-pre+1));
                pre = i+1;
            }else if(cnt0 = 1 && s[i] == ' '){
                pre++;
                continue;
            }else if(s[i] != ' '){
                cnt0 = 0;
            }
        }

        string res = s.substr(pre, s.length()-pre) + " ";
        for(int i=sub.size()-1; i>=0; i--){
            res = res + sub[i];
        }

        return res.substr(0, res.length()-1);
    }
};
// @lc code=end

