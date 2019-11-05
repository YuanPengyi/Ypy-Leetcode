/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = (struct ListNode*)malloc(sizeof(struct ListNode));
        ListNode* after = (struct ListNode*)malloc(sizeof(struct ListNode));
        ListNode* bb = before;
        ListNode* aa = after;
        if(head == NULL || head->next == NULL) return head;
        ListNode* current = head;
        while(current->next != NULL){
            if(current->val < x){
                bb->next = current;
                bb = current;
            }else{
                aa->next = current;
                aa = current;
            }
            current = current->next;
        }
        if(current->val < x){
            bb->next = current;
            bb = current;
            aa->next = NULL;
        }else{
            aa->next = current;
        }
        bb->next = after->next;

        return before->next;
    }
};
// @lc code=end

