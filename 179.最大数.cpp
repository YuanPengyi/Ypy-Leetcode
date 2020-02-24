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
        vector<string> record;
        int size = nums.size();
        for(int i=0; i<size; i++){
            record.push_back(to_string(nums[i]));
        }
        /*
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(!compare(record[i], record[j])){
                    string tmp = record[i];
                    record[i] = record[j];
                    record[j] = tmp;
                }
            }
        }*/

        QSort(record, 0, size-1);

        if(record[0] == "0") return "0";

        string res = "";
        for(int i=0; i<size; i++){
            res += record[i];
        }

        return res;
    }

    void QSort(vector<string> &rec, int low, int high){
        if(low < high){
            int index = getIndex(rec, low, high);
            // cout << low << "|" << high << "|" << rec[low] << "|" << rec[high] << endl;

            QSort(rec, low, index-1);
            QSort(rec, index+1, high);
        }
    }

    int getIndex(vector<string> &rec, int low, int high){
        string pivot = rec[low];
        while(low < high){
            if(compare(pivot, rec[high])){
                high--;
                continue;
            }else{
                rec[low] = rec[high];
                low++;
            }
            while(low < high){
                if(!compare(pivot, rec[low])){
                    low++;
                }else{
                    rec[high] = rec[low];
                    high--;
                    break;
                }
            }
        }
        rec[low] = pivot;
        // cout << rec[0] << "|" << rec[1] << endl;

        return low;
    }

    bool compare(string a, string b){
        string mix1 = a + b;
        string mix2 = b + a;
        if(mix1 >= mix2){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end

