#include "normal.h"

/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class LRUCache {   // 超时了
public:
    LRUCache(int capacity) {
        max = capacity;
        cur_p = 0;
        cnt = 0;        
    }

    int get(int key) {
        map<int, int>::iterator iter = cache.find(key);

        if (iter == cache.end())
            return -1;
        else {
            priority[key] = ++cur_p;
            return cache[key];
        }            
    }

    void put(int key, int value) {
        map<int, int>::iterator iter = cache.find(key);

        if (iter == cache.end()) {
            if (cnt == max) {
                deleteMin();
                cache[key] = value;
                priority[key] = ++cur_p;
            }
            else {
                cache[key] = value;
                priority[key] = ++cur_p;
                cnt++;
            }
        }
        else {
            cache[key] = value;
            priority[key] = ++cur_p;
        }
    }

private:
    map<int, int> cache;
    int max;       // 最大缓存数
    int cur_p;     // 此时最大优先级
    map<int, int> priority;   // 记录优先级
    int cnt;       // 缓存中数据量

    void deleteMin() {
        int min = priority.begin()->first;
        map<int, int>::iterator iter = priority.begin();
        iter++;

        while (iter != priority.end()) {
            if (priority[min] > iter->second)
                min = iter->first;

            iter++;
        }

        priority.erase(min);
        cache.erase(min);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCache {  // 利用map的有序性 通过了 但是并不快
public:
    LRUCache(int capacity) {
        cnt = 0;
        max = capacity;
        cur_p = 0;
    }

    int get(int key) {
        map<int, int>::iterator iter = cache.find(key);

        if (iter == cache.end())
            return -1;
        else {
            int pri = helper[key];
            priority.erase(pri);
            priority[++cur_p] = key;
            helper[key] = cur_p;
            return cache[key];
        }
    }

    void put(int key, int value) {
        map<int, int>::iterator iter = cache.find(key);

        if (iter == cache.end()) {
            if (cnt == max) {
                map<int, int>::iterator iter = priority.begin();
                cache.erase(iter->second);
                helper.erase(iter->second);
                priority.erase(iter);

                cache[key] = value;
                helper[key] = ++cur_p;
                priority[cur_p] = key;
            }
            else {
                cache[key] = value;
                helper[key] = ++cur_p;
                priority[cur_p] = key;
                cnt++;
            }
        }
        else {
            int pri = helper[key];
            priority.erase(pri);
            priority[++cur_p] = key;
            helper[key] = cur_p;
            cache[key] = value;
        }
    }

private:
    map<int, int> cache;
    int cnt;
    int max;
    int cur_p;
    map<int, int> priority; // 和之前实现不同，此处将first作为优先级second作为cache的key值
    map<int, int> helper;   // 和priority相反，用来通过key得到优先级
};


// map + 双向链表