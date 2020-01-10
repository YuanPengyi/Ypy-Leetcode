/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 *
 * https://leetcode-cn.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (37.51%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 26K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * 比较两个版本号 version1 和 version2。
 * 如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
 * 
 * 你可以假设版本字符串非空，并且只包含数字和 . 字符。
 * 
 * . 字符不代表小数点，而是用于分隔数字序列。
 * 
 * 例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
 * 
 * 你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和
 * 4。其第三级和第四级修订号均为 0。
 * 
 * 
 * 示例 1:
 * 
 * 输入: version1 = "0.1", version2 = "1.1"
 * 输出: -1
 * 
 * 示例 2:
 * 
 * 输入: version1 = "1.0.1", version2 = "1"
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: version1 = "7.5.2.4"\n"7.5.3"
 * 输出: -1
 * 
 * 示例 4：
 * 
 * 输入：version1 = "1.01"\n"1.001"
 * 输出：0
 * 解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
 * 
 * 示例 5：
 * 
 * 输入：version1 = "1.0"\n"1.0.0"
 * 输出：0
 * 解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
 * 版本字符串不以点开始或结束，并且其中不会有两个连续的点。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cnt = 1;
        while(cnt < version1.length()){
            if(version1[cnt-1] == '.' && version1[cnt] == '0'){
                version1.erase(cnt, 1);
            }else{
                cnt++;
            }
        }
        cnt = 1;
        while(cnt < version2.length()){
            if(version2[cnt-1] == '.' && version2[cnt] == '0'){
                version2.erase(cnt, 1);
            }else{
                cnt++;
            }
        }

        while(version1[0] == '0'){
            version1.erase(0, 1);
        }

        while(version2[0] == '0'){
            version2.erase(0, 1);
        }

        cnt = version1.length()-1;
        while(version1[cnt] == '.'){
            version1.erase(cnt, 1);
            cnt--;
        }

        cnt = version2.length()-1;
        while(version2[cnt] == '.'){
            version2.erase(cnt, 1);
            cnt--;
        }
        
        // cout << version1 << " " << version2 << endl;
        if(version1 == version2) return 0;

        int pre1 = 0, pre2 = 0, v1 = 0, v2 = 0;
        while(v1 < version1.length() && v2 < version2.length()){
            while(version1[v1] != '.' && v1 < version1.length()) v1++;
            while(version2[v2] != '.' && v2 < version2.length()) v2++;
            
            if(v1 == pre1 && v2 == pre2){
                // do nothing
            }else if(v1 == pre1 || v1 - pre1 < v2 - pre2){
                return -1;
            }else if(v2 == pre2 || v1 - pre1 > v2 - pre2){
                return 1;
            }else{
                while(pre1 != v1){
                    if(version1[pre1] > version2[pre2]){
                        return 1;
                    }else if(version1[pre1] < version2[pre2]){
                        return -1;
                    }else{
                        pre1++; pre2++;
                    }
                }
            }

            pre1++; pre2++;
            v1++; v2++;

        }

        if(v1 >= version1.length() && v2 >= version2.length()){
            return 0;
        }else if(v1 >= version1.length()){
            return -1;
        }else{
            return 1;
        }

        return 0;
    }
};
// @lc code=end

