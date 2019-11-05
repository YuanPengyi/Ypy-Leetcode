/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.95%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 83.8K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int dp[50000] = {0};
        if(s.length() == 0) return 0;
        else if(s.length() == 1 && s[0] != '0') return 1;
        else if(s[0] == '0') return 0;
        dp[0] = 1;
        if((s[0] == '1' || (s[0] == '2' && s[1] <= '6')) && s[1] > '0'){
            dp[1] = 2;
        }else if(s[1] == '0' && s[0] != '1' && s[0] != '2'){
            return 0;
        }else{
            dp[1] = 1;
        }
        // cout << dp[0] << " " << dp[1] << " ";
        for(int i=2; i<s.length(); i++){
            if((s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) && s[i] > '0'){
                dp[i] = dp[i-2] + dp[i-1];
            }else if(s[i] == '0'){
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                dp[i] = dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
            // cout << s[i-1] << " " << s[i] << " " << dp[i] << endl;
        }

        return dp[s.length()-1];
    }
};
// @lc code=end

