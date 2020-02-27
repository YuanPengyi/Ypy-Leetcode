/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (43.21%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 26.9K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() <= 10) return res;
        unordered_map<string, int> record;
        for(int i=0; i<s.length()-9; i++){
            string tmp = s.substr(i, 10);
            //cout << tmp << "|";
            if(record.find(tmp) != record.end() && record[tmp] == 1){
                res.push_back(tmp);
                record[tmp] = 0;
            }else if(record.find(tmp) == record.end()){
                record[tmp] = 1;
            }
        }

        return res;
    }
};
// @lc code=end

