/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (53.80%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 25.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 思路：
        可以用栈，从头遍历一半，出栈一半
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> visited;
        ListNode* p = head;
        while(p != NULL){
            visited.push_back(p);
            p = p->next;
        }
        int num = visited.size();
        int start = 0, end = num-1;
        while(end > start){
            visited[start]->next = visited[end];
            start++;
            if(end > start) visited[end]->next = visited[start];
            else visited[end]->next = NULL;
            end--;
            if(start == end) visited[start]->next = NULL;
            // cout << start << " " << end << endl;
        }
    }
};
// @lc code=end

