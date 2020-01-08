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
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        map<int, vector<int>> m;
        vector<int> res;

        for(int i=0; i<T.size(); i++){
            if(m.find(T[i]) == m.end()){
                m[T[i]] = res;

            }
            m[T[i]].push_back(i);
        }

        /*
        for(map<int, vector<int>> ::iterator cur=m.begin(); cur!=m.end(); cur++){
            cout << cur->first << " ";
            for(int j=0; j<cur->second.size(); j++){
                cout << cur->second[j] << " ";
            }
        }cout << endl; */

        for(int i=0; i<T.size(); i++){
            map<int, vector<int>> ::iterator cur = m.find(T[i]);
            int tmpres = INT_MAX;
            // cout << cur->first << " ";
            cur++;
            while(cur != m.end()){
                if(cur->second.back() > i){
                    for(int j=0; j<cur->second.size(); j++){
                        if(cur->second[j] > i){
                            tmpres = min(cur->second[j] - i, tmpres);
                            break;
                        }
                    }
                }
                cur++;
            }
            if(tmpres == INT_MAX) tmpres = 0;
            res.push_back(tmpres);
        }

        return res;
    }
};
// @lc code=end

