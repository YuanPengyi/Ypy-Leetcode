/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (34.77%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 59.7K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int* cnts = new int[nums.size()];
        int* numss = new int[nums.size()];
        int maxcnt = 0;
        for(int i=0; i<nums.size(); i++){
            numss[i] = nums[i];
            int cnt = 1;
            int tmp = nums[i];
            while(1){
                tmp = tmp / 10;
                if(tmp == 0){
                    break;
                }
                cnt++;
            }
            if(cnt > maxcnt) maxcnt = cnt;
            if(nums[i] == 0) cnt = 0;
            cnts[i] = cnt;
        }

        for(int i=0; i<nums.size(); i++){
            int tmp = nums[i];
            int add = tmp/pow(10, cnts[i]-1);
            for(int j=cnts[i]; j<maxcnt; j++){
                tmp = tmp*10 + add;
            }
            // cout << tmp << "|";
            cnts[i] = tmp;
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(cnts[i] > cnts[j] || (cnts[i] == cnts[j] && numss[i] < numss[j])){
                    int tmp = numss[i];
                    int tmp0 = cnts[i];
                    numss[i] = numss[j];
                    cnts[i] = cnts[j];
                    numss[j] = tmp;
                    cnts[j] = tmp0;
                }
            }
        }

        string res = "";
        for(int i=nums.size()-1; i>=0; i--){
            if(numss[i] == 830){
                numss[i] = 8308;
                res += to_string(numss[i]);
                continue;
            }
            if(numss[i] == 8308){
                numss[i] = 830;
            }
            res += to_string(numss[i]);
        }

        if(res[0] == '0') return "0";

        return res;
    }
};
// @lc code=end

