/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (56.79%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    24.5K
 * Total Submissions: 43.1K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * [64,40,49,73,72,35,68,83,35,73,84,88,96,43,74,63,41,95,48,46,89,72,34,85,72,59,87,49,30,32,47,34,74,58,31,75,73,88,64,92,83,64,100,99,81,41,48,83,96,92,82,32,35,68,68,92,73,92,52,33,44,38,47,88,71,50,57,95,33,65,94,44,47,79,41,74,50,67,97,31,68,50,37,70,77,55,48,30,77,100,31,100,69,60,47,95,68,47,33,64]
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        vector<int> res(size, 0);
        if(size == 1) return res;
        res[size-1] = 0;

        for(int i=size-2; i>=0; i--){
            for(int j=i+1; j<size; j+=res[j]){
                if(T[j] > T[i]){
                    res[i] = j - i;
                    break;
                }else if(res[j] == 0){
                    res[i] = 0;
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

