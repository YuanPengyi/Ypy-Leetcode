/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // cout << s1 << " " << s2 << endl;
        if(s1.length() != s2.length()) return false;

        if(s1 == s2) return true;

        int size = s1.length();
        int letters[26] = {0};
        for(int i=0; i<size; i++){
            letters[s1[i] - 'a']++;
            letters[s2[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(letters[i] != 0) return false;
        }

        for(int i=1; i<size; i++){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && 
                isScramble(s1.substr(i,size-i), s2.substr(i,size-i))){
                    return true;
                }
            else if(isScramble(s1.substr(0,i), s2.substr(size-i,i)) && 
                isScramble(s1.substr(i,size-i), s2.substr(0,size-i))){
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

