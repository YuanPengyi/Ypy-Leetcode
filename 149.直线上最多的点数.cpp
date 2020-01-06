/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (19.86%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 35.7K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        int res = 0;
        unordered_map<string, int> map;
        for(int i=0; i<size; i++){
            int repeat = 1;
            int max = 0;
            for(int j=i+1; j<size; j++){
                int a = points[j][0] - points[i][0];
                int b = points[j][1] - points[i][1];
                if(a == 0 && b == 0){
                    repeat++;
                    continue;
                }
                int g = gcd(a, b);
                a = a/g;
                b = b/g;
                if(a < 0){
                    a = 0-a;
                    b = 0-b;
                }
                // 用 string 保存分数
                string key = to_string(a) + "@" + to_string(b);
                if(map.find(key) == map.end()){
                    map[key] = 1;
                    if(max < map[key]) max = map[key];
                }else{
                    map[key]++;
                    if(max < map[key]) max = map[key];
                }
            }
            map.clear();
            /* for(unordered_map<string, int> ::iterator x = map.begin(); x!=map.end(); x++){
                cout << x->first << " " << x->second << endl;
            }
            cout << "-----" << endl; */
            if(max+repeat > res) res = max+repeat;
        }

        return res;
    }

    // 求公约数
    int gcd(int a, int b){
        while(b != 0){
            int tmp1 = a % b;
            a = b;
            b = tmp1;
        }

        return a;
    }
};
// @lc code=end

