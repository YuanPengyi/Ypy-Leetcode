/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (42.71%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 62.8K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog"\n["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> record;
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        int num = wordDict.size();
        vector<bool> unuse(size, true);
        for(int i=0; i<size; i++){
            record.push_back(unuse);
        }

        bool res = iterate(s, wordDict, -1, size, num);

        return res;
    }

    bool iterate(string s, vector<string> wordDict, int y, int size, int num){
        if(y == size-1){
            return true;
        } 
        bool res = false;
        for(int i=y+1; i<size; i++){
            for(int j=0; j<num; j++){
                if(!record[y+1][i]) continue;
                // cout << y+1 << " " << i << " " << s.substr(y+1, i-y) << " " << wordDict[j] << endl;
                if(s.substr(y+1, i-y) == wordDict[j]){
                    record[y+1][i] = true;
                    res = res || iterate(s, wordDict, i, size, num);
                }
            }
            if(!res) record[y+1][i] = false;
            else return true;
        }

        return false;
    }
};
// @lc code=end

