/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (55.38%)
 * Likes:    3772
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 *
 * 实现 LRUCache 类：
 *
 *
 *
 *
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value
 ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 *
 *
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 *
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 *
 *
 */

// @lc code=start
// class LRUCache {
//    private:
//     struct valuenode {
//         int value;
//         int time_update;
//     };
//     unordered_map<int, valuenode> mp;
//     int cap_max;    //  可存入的最大数量
//     int cap_count;  //  当前存入的数量
//     int time;       //  用作时间戳

//    public:
//     LRUCache(int capacity) {
//         cap_max = capacity;
//         cap_count = 0;
//         time = 0;
//     }

//     int get(int key) {
//         ++time;
//         auto it = mp.find(key);
//         if (it != mp.end()) {
//             it->second.time_update = time;
//             return it->second.value;
//         }
//         return -1;
//     }

//     void put(int key, int value) {
//         ++time;
//         if (mp.find(key) != mp.end()) {
//             mp[key] = {value, time};
//             return;
//         }
//         if (cap_count < cap_max) {
//             mp[key] = {value, time};
//             cap_count++;
//         } else {
//             int changekey;
//             int mintime = INT_MAX;
//             for (auto& [key1, val1] : mp) {  // C++17 结构化绑定
//                 if (val1.time_update < mintime) {
//                     mintime = val1.time_update;
//                     changekey = key1;
//                 }
//             }
//             mp.erase(changekey);
//             mp[key] = {value, time};
//         }

        
//     }
// };
// 设计思路：双向链表 + 哈希表
//
// 链表 l：维护访问顺序，头部 = 最近使用，尾部 = 最久未使用
//   链表中每个节点存 pair<key, value>
//
// 哈希表 m：key -> 链表迭代器（书签），实现 O(1) 定位任意节点
//
// 两者联动：
//   访问某个 key 时，通过 m[key] 拿到迭代器，O(1) 找到链表节点，
//   再用 splice 把它移到链表头部，O(1) 完成"标记为最近使用"
//
// 示意图：
//   链表：[最近] (3,3) → (1,1) → (2,2) [最久]
//   哈希：{ 3→指向(3,3), 1→指向(1,1), 2→指向(2,2) }
class LRUCache {
   public:
    // 双向链表，每个节点存 {key, value}
    // 头部 = 最近访问，尾部 = 最久未访问
    list<pair<int, int>> l;

    // 哈希表：key -> 该 key 在链表中的迭代器（相当于书签/指针）
    // 有了迭代器就能 O(1) 定位到链表中的节点，避免遍历查找
    // 注意：list 的迭代器在节点未被删除时永久有效，即使链表重排也不失效
    unordered_map<int, list<pair<int, int>>::iterator> m;

    int size;  // 容量上限

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        // key 不存在，直接返回 -1
        if (m.find(key) == m.end()) return -1;

        // splice(目标位置, 源链表, 源迭代器)
        // 把 m[key] 指向的节点从当前位置"剪切"并"粘贴"到链表头部
        // 这是纯指针操作，O(1)，节点地址不变，所以 m[key] 迭代器依然有效
        l.splice(l.begin(), l, m[key]);

        // m[key] 现在指向链表头部节点，->second 取出 value
        return m[key]->second;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // key 已存在：移到头部（标记为最近使用），再更新值
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }

        // key 不存在，需要插入新节点
        if (l.size() == size) {
            // 已满：淘汰尾部节点（最久未使用的）
            auto d_key = l.back().first;  // 取出尾部节点的 key
            l.pop_back();                 // 从链表删除尾部节点
            m.erase(d_key);              // 同步从哈希表删除对应记录
        }

        // 新节点插入链表头部（最近使用）
        l.push_front({key, value});

        // 在哈希表中记录该 key 对应的迭代器（l.begin() 就是刚插入的头节点）
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
