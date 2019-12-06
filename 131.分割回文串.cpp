/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (63.97%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 26.4K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmpres;
    vector<vector<string>> partition(string s) {
        int start = 0;;
        int part = 0;
        int end = s.length()-1;
        while(part <= end){
            iterate(s, start, part, end);
            part++;
        }

        return res;
    }

    void iterate(string s, int start, int part, int end){
        if(start == end){
            tmpres.push_back(s.substr(end, 1));
            res.push_back(tmpres);
            tmpres.pop_back();
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
        tmpres.push_back(s.substr(start, part-start+1));

        first = part+1;
        if(first > end){
            res.push_back(tmpres);
        }
        while(first <= end){
            iterate(s, part+1, first, end);
            first++;
        }

        tmpres.pop_back();
    }
};
// @lc code=end

