/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (28.26%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 40.4K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [2,4,1], k = 2
 * 输出: 2
 * 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,6,5,0,3], k = 2
 * 输出: 7
 * 解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4
 * 。
 * 随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp;
        int size = prices.size();

        if(k >= size/2){
            int res = 0;
            for(int i=0; i<size-1; i++){
                if(prices[i+1] > prices[i]) res += prices[i+1] - prices[i];
            }
            return res;
        }

        vector<int> tmp;
        tmp.push_back(0);
        tmp.push_back(0);
        vector<vector<int>> tmp1;
        for(int i=0; i<=1; i++) tmp1.push_back(tmp);
        for(int i=0; i<=size; i++) dp.push_back(tmp1);
        /*for(int i=0; i<=size; i++){
            for(int j=0; j<=k; j++){
                cout << dp[i][j][0] << "|" << dp[i][j][1] << " ";
            }
            cout << endl;
        }*/

        for(int i=0; i<=1; i++){
            dp[0][i][1] = INT_MIN; 
        }
        
        int jj, jjj;
        for(int j=1; j<=k; j++){
            jj = j%2;
            jjj = 1 - jj;
            for(int i=1; i<=size; i++){
                dp[i][jj][0] = max(dp[i-1][jj][0], dp[i-1][jj][1] + prices[i-1]);
                dp[i][jj][1] = max(dp[i-1][jjj][0] - prices[i-1], dp[i-1][jj][1]);
            }
        }
        
        return dp[size][jj][0];
    }
};
// @lc code=end

