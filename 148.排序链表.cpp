/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (62.97%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    35.1K
 * Total Submissions: 55.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
class Solution {
public: 
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* fast = head->next, * slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(head1);
        ListNode* head0 = new ListNode(0);
        ListNode* h = head0;
        while(left!=NULL && right != NULL){
            if(left->val < right->val){
                head0->next = left;
                left = left->next;
            }else{
                head0->next = right;
                right = right->next;
            }
            head0 = head0->next;
        }
        head0->next = (left != NULL ? left : right);

        return h->next;
    }
};
// @lc code=end

