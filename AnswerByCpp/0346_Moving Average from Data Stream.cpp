#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
346. 数据流中的移动平均值

给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。

示例:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class MovingAverage {
private:
    int len;
    bool flag;
    int idx;
    int sum;
    vector<int> arr;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        arr.resize(size);
        len = size;
        flag = false;
        idx = 0;
        sum = 0;
    }
    
    double next(int val) {
        if (flag) sum = sum - arr[idx];
        sum += val;
        arr[idx] = val;
        idx = (idx + 1) % len;
        if (!flag && idx == 0) flag = true;
        return flag ? sum * 1.0 / len : sum * 1.0 / idx;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */