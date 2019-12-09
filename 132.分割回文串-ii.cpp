/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (40.59%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 13.7K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的最少分割次数。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int size = s.length();
        vector<int> min_cut(size, INT_MAX);
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                dp[i][j] = false;
        for(int i=0; i<size; i++){
            dp[i][i] = true;
            min_cut[i] = i;
        }

        for(int i=size-1; i>=0; i--){
            for(int j=size-1; j>i; j--){
                if(s[i] == s[j] && j-i>2){
                    dp[i][j] = dp[i+1][j-1];
                }else if(s[i] == s[j]){
                    dp[i][j] = true;
                }else{
                    continue;
                }
            }
        }

        for(int i=0; i<size; i++){
            for(int j=i; j<size; j++){
                if(dp[i][j] == false){
                    min_cut[j] = min(min_cut[j], min_cut[j-1]+1);
                }else if(i == 0 && dp[i][j] == true){
                    min_cut[j] = 0;
                }else{
                    min_cut[j] = min(min_cut[j], min_cut[i-1]+1);
                }
            }
        }

        return min_cut[size-1];
    }
};
// @lc code=end

