/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (47.13%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 46.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n){
            return head;
        }
        ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));
        ListNode *x,*y,*z,*l,*r;
        x = first;
        first->next = head;
        y = x->next;
        if(y == NULL || y->next == NULL) return head;
        z = y->next;
        int pos = 0;

        while(z != NULL){
            pos++;
            // cout << pos << " " << x->next->val << " " << y->next->val << " " << z->val << "|";
            if(pos < m){
                x = y;
                y = z;
                z = z->next;
                continue;
            }else if(pos == m){
                l = x;
                r = y;
            }else if(pos == n){
                y->next = x;
                x = y;
                y = z;
                z = z->next;

                l->next = x;
                r->next = y;
                break;
            }
            y->next = x;
            x = y;
            y = z;
            z = z->next;
        }

        if(pos < n){
            y->next = x;
            x = y;
            y = z;
            l->next = x;
            r->next = y;
        }

        return first->next;
    }
};
// @lc code=end [1,2,3,4,5]\n1\n5

