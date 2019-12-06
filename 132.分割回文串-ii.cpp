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
    int cut = INT_MAX;
    int cnt = 0;
    int minCut(string s) {
        if(s.length() == 0) return 0;
        int start = 0;;
        int part = 0;
        int end = s.length()-1;
        while(part <= end){
            iterate(s, start, part, end);
            part++;
        }

        return cut;
    }

    void iterate(string s, int start, int part, int end){
        if(start == end){
            if(cnt < cut) cut = cnt;
            return;
        }
        int first = start;
        int last = part;
        while(last > first){
            if(s[first] != s[last]) return;
            first++;
            last--;
        }
        // cout << start << " " << part << " " << end << endl;
        cnt++;
        if(cnt > cut){
            cnt--;
            return;
        }

        first = part+1;
        if(first > end){
            if(cnt-1 < cut) cut = cnt-1;
        }
        while(first <= end){
            iterate(s, part+1, first, end);
            first++;
        }

        cnt--;
    }
};
// @lc code=end

