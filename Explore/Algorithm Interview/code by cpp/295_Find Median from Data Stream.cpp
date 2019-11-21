#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
295. 数据流的中位数

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:
如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/

class MedianFinder {
private:
    priority_queue<int> big_heap;
    priority_queue<int,vector<int>,greater<int> > small_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    // 通过维持大顶堆和小顶堆来快速查找中位数
    void addNum(int num) {
        if(big_heap.size()==small_heap.size()){
            if(big_heap.empty() || num<big_heap.top())
                big_heap.push(num);
            else small_heap.push(num);
        }else if(big_heap.size()>small_heap.size()){
            if(num<big_heap.top()){
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }else small_heap.push(num);
        }else {
            if(num<small_heap.top())
                big_heap.push(num);
            else{
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(big_heap.size()==small_heap.size()){
            return (double)(big_heap.top()+small_heap.top())/2;
        }else if(big_heap.size()>small_heap.size()){
            return big_heap.top();
        }else {
            return small_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */