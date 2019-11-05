/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (45.28%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 35.2K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135" "11111"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    string tmpres = "";
    vector<string> restoreIpAddresses(string s) {
        /*if(s.length() == 12){
            res.push_back(s.substr(0,3) + "." + s.substr(3,3) + "." +
                             s.substr(6,3) + "." + s.substr(9,3));
            return res;
        }*/
        if(s.length() > 12) return res;

        iterate(s, 0, 1, 1);
        iterate(s, 0, 2, 1);
        iterate(s, 0, 3, 1);

        return res;
    }

    void iterate(string s, int pos, int len, int num){
        if(pos + len > s.length() || s.length()-pos-len > (4-num)*3){
            return;
        }
        string cut = s.substr(pos, len);
        if(
            (
                len == 3 && 
                (
                    (cut[0] == '1') 
                    || (cut[0] == '2' && cut[1] < '5')
                    || (cut[0] == '2' && cut[1] == '5' && cut[2] <= '5')
                )
            ) ||
            (
                len == 2 && cut[0] != '0'
            ) || 
            len == 1
        ){
            tmpres += cut + ".";
            if(num == 4 && pos+len == s.length()){
                res.push_back(tmpres.substr(0,tmpres.length()-1));
            }else{
                iterate(s, pos+len, 1, num+1);
                iterate(s, pos+len, 2, num+1);
                iterate(s, pos+len, 3, num+1);
            }
            tmpres = tmpres.substr(0, tmpres.length()-len-1);
        }else{
            return;
        }
    }
};
// @lc code=end

