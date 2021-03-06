#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
341. 扁平化嵌套列表迭代器

给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的项或者为一个整数，或者是另一个列表。

示例 1:
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    queue<int> que;
    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList);
    }
    
    void init(vector<NestedInteger> &list){
        for(int i=0;i<list.size();i++){
            if(list[i].isInteger())que.push(list[i].getInteger());
            else init(list[i].getList());
        }
    }

    int next() {
        int top = que.front();
        que.pop();
        return top;
    }

    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
