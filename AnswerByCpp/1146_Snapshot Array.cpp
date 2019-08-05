#include<bits\stdc++.h>
using namespace std;
/*
1146. 快照数组

实现支持下列接口的「快照数组」- SnapshotArray：
SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。

示例： 输入：["SnapshotArray","set","snap","set","get"]
            [[3],[0,5],[],[0,6],[0,0]]
输出：        [null,null,0,null,5]

解释： SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5

提示： 1 <= length <= 50000      题目最多进行50000 次set，snap，和 get的调用 。
0 <= index < length             0 <= snap_id < 我们调用 snap() 的总次数    0 <= val <= 10^9
*/

class SnapshotArray {
private:
    int snap_id = 0;
    vector<vector<int>> change;
    vector<vector<int>> value;
public:
    SnapshotArray(int length) {
        change.resize(length);
        value.resize(length);
        for(auto &it:change) it.push_back(0);
        for(auto &it:value) it.push_back(0);
    }
    
    void set(int index, int val) {
        if(snap_id == change[index].back())
            value[index].back() = val;
        else {
            change[index].push_back(snap_id);
            value[index].push_back(val);
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if(snap_id >= change[index].back()) 
            return value[index].back();
        int ind = upper_bound(change[index].begin(), change[index].end(), snap_id) - change[index].begin()-1;
        return value[index][ind];
    }
};

class SnapshotArray {
    vector<unordered_map<int,int>> vv;
public:
    SnapshotArray(int length) {
        vv.push_back(unordered_map<int,int>());
    }
    
    void set(int index, int val) {
        vv.back()[index]=val;
    }
    
    int snap() {
        vv.push_back(unordered_map<int,int>());
        return vv.size()-2;
    }
    
    int get(int index, int snap_id) {
        for(int i=snap_id;i>=0;i--){
            if(vv[i].find(index)!=vv[i].end()) return vv[i][index];
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */