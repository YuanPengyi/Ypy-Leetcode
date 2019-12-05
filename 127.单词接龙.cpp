/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 36.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dok", "xok", "xog","lot","log","cog"]

 * "hit"\n"cog"\n["hot","dot","dok", "xok", "xog","lot","log","cog"]
 "a"\n"c"\n["a","b","c"]
 "hot"\n"dog"\n["hot","dog"]
 "qa"\n"sq"\n["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]

 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> visited;
    unordered_map<string, vector<string>> map;
    int res = INT_MAX;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList[0].length();
        int size = wordList.size();

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                for(int k=0; k<len; k++){
                    bool flag = true;
                    for(int l=0; l<len; l++){
                        if(l == k) continue;
                        if(wordList[i][l] != wordList[j][l]) flag = false;
                    }
                    if(flag){
                        map[wordList[i]].push_back(wordList[j]);
                        map[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
        }

        vector<string> start;

        for(int i=0; i<size; i++){
            for(int k=0; k<len; k++){
                bool flag = true;
                for(int l=0; l<len; l++){
                    if(l == k) continue;
                    if(wordList[i][l] != beginWord[l]) flag = false;
                }

                if(flag){ // 是子节点
                    start.push_back(wordList[i]);
                }

            }
        }

        /*
        for(int i=0; i<size; i++){
            cout << wordList[i] << ": [";
            for(int j=0; j<map[wordList[i]].size(); j++){
                cout << map[wordList[i]][j] << " ";
            }cout << "]" << endl;
        }
        */

        for(int i=0; i<size; i++){
            visited[wordList[i]] = true;
        }

        for(int i=0; i<start.size(); i++){
            if(start[i] == endWord) return 2;
            visited[start[i]] = false;
            iterate(start[i], endWord, 2);
            visited[start[i]] = true;
        }

        if(res == INT_MAX) return 0;

        return res;
    }

    void iterate(string cur, string endWord, int deep){
        if(deep >= res) return;
        for(int i=0; i<map[cur].size(); i++){
            string next = map[cur][i];
            if(!visited[next]) continue;
            if(next == endWord && deep+1 < res){
                res = deep+1;
                return;
            }
        }

        for(int i=0; i<map[cur].size(); i++){
            string next = map[cur][i];
            if(!visited[next]) continue;
            visited[next] = false;
            iterate(next, endWord, deep+1);
            visited[next] = true;
        }
    }
};
// @lc code=end

