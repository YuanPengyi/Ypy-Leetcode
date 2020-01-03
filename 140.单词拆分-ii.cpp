/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (37.17%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 23.9K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"\n["apple", "pen", "applepen", "pine", "pineapple"]
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 * 
 * 
 */

/*
思路：
    记录每个位置后面的字符串的组合
    不在进入递归的时候组合，在递归回溯的时候，进行字符串组合
*/


// @lc code=start
class Solution {
public:
    int size = 0;
    int len = 0;
    int maxlen = 0;
    unordered_map<int, vector<string>> map;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        size = wordDict.size();
        len = s.length();
        for(int i=0; i<size; i++){
            if(wordDict[i].length() > maxlen) maxlen = wordDict[i].length();
        }

        return iterate(0, s, wordDict);
    }

    vector<string> iterate(int start, string s, vector<string> wordDict){
        if(map.count(start) > 0) return map[start];
        vector<string> vec;
        if(start == len) vec.push_back("");
        for(int i=1; i<=len-start; i++){
            if(i > maxlen) break;
            // cout << s.substr(start, i) << endl;
            if(find(wordDict.begin(), wordDict.end(), s.substr(start, i)) != wordDict.end()){
                vector<string> tmpvec = iterate(start + i, s, wordDict);
                for(int j=0; j<tmpvec.size(); j++){
                    if(tmpvec[j] != "")
                        vec.push_back(s.substr(start, i) + " " + tmpvec[j]);
                    else
                        vec.push_back(s.substr(start, i));
                }
            }
        }

        map[start] = vec;

        return vec;
    }
};
// @lc code=end

