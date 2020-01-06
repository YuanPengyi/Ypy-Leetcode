/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (44.89%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 62K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 ）  //缓存容量 
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */

// @lc code=start
class LRUCache {
public:
    unordered_map<int, int> map;
    unordered_map<int, int> record;
    int num = 0;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }else{
            record[key] = 0;
            for(unordered_map<int,int> ::iterator i=record.begin(); i!=record.end(); i++) i->second++;
            return map[key];
        }
    }
    
    void put(int key, int value) {
        for(unordered_map<int,int> ::iterator i=record.begin(); i!=record.end(); i++) i->second++;
        if(map.find(key) == map.end() && num < cap){
            map[key] = value;
            record[key] = 0;
            num++;
        }else if(map.find(key) == map.end() && num == cap){
            int lru = -1;
            int lrukey = 0;
            for(unordered_map<int,int> ::iterator i=record.begin(); i!=record.end(); i++){
                if(i->second > lru){
                    lru = i->second;
                    lrukey = i->first;
                }
            }            
            map.erase(lrukey);
            map[key] = value;
            record.erase(lrukey);
            record[key] = 0;
        }else{
            map[key] = value;
            record[key] = 0;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

