/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (37.95%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 38.1K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的深拷贝。 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * 解释：
 * 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
 * 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你必须返回给定头的拷贝作为对克隆列表的引用。
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* cur = head;
        while(cur != NULL){
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        
        cur = head;
        while(cur != NULL){
            Node* tmp = cur->next;
            if(cur->random != NULL){
                tmp->random = cur->random->next;
            }else{
                tmp->random = NULL;
            }
            cur = tmp->next;
        }
        
        cur = head;
        Node* res = cur->next;
        while(cur != NULL){
            Node* tmp = cur->next;
            if(tmp->next != NULL){
                cur->next = tmp->next;
                tmp->next = tmp->next->next;
            }else{
                cur->next = NULL;
            }
            
            cur = cur->next;
        }

        return res;
    }
};
// @lc code=end

