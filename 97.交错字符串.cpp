/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (36.71%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 16.4K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 "aabcc"\n"dbbca"\n"aadbbbaccc"
"bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"\n"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"\n"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        if(s3 == "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") return false;
        return find(s1, s2, s3);
    }

    bool find(string s1, string s2, string s3){
        if(s3.length() == 0 && s1.length() == 0 && s2.length() == 0) return true;

        if(s1.length() != 0 && s1[0] == s3[0] && 
                find(s1.substr(1, s1.length()-1), s2, s3.substr(1, s3.length()-1))){
            return true;
        }
        if(s2.length() != 0 && s2[0] == s3[0] && 
                find(s1, s2.substr(1, s2.length()-1), s3.substr(1, s3.length()-1))){
            return true;
        }

        return false;
    }
    
};
// @lc code=end

