#include<bits\stdc++.h>
using namespace std;
/*
1157. 子数组中占绝大多数的元素

实现一个 MajorityChecker 的类，它应该具有下述几个 API：
MajorityChecker(int[] arr) 会用给定的数组 arr 来构造一个 MajorityChecker 的实例。
int query(int left, int right, int threshold) 有这么几个参数：
0 <= left <= right < arr.length 表示数组 arr 的子数组的长度。
2 * threshold > right - left + 1，也就是说阀值 threshold 始终比子序列长度的一半还要大。
每次查询 query(...) 会返回在 arr[left], arr[left+1], ..., arr[right] 中至少出现阀值次数 threshold 的元素，
如果不存在这样的元素，就返回 -1。

示例： MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // 返回 1
majorityChecker.query(0,3,3); // 返回 -1
majorityChecker.query(2,3,2); // 返回 2

提示：     1 <= arr.length <= 20000        1 <= arr[i] <= 20000
对于每次查询，0 <= left <= right < len(arr)        对于每次查询，2 * threshold > right - left + 1
查询次数最多为500
*/

class MajorityChecker {
private:
    vector<int> array;
public:
    MajorityChecker(vector<int>& arr) {
        array = arr;
    }
    
    int query(int left, int right, int threshold) {
        int res = array[left], count = 1;
        for(int i=left+1; i<=right; i++){
            if(array[i] == res) count++;
            else count--;
            if(count == 0){
                res = array[i];
                count = 1;
            }
        }
        count = 0;
        for(int i=left; i<=right; i++)
            if(array[i] == res) count++;
        if(threshold > count) return -1;
        return res;
    }
};


int main(){
    vector<int> arr{1,1,2,2,1,1};
    MajorityChecker* obj = new MajorityChecker(arr);
    int res1 = obj->query(0,5,4);
    int res2 = obj->query(0,3,3);
    int res3 = obj->query(2,3,2);
    cout<<res1<<res2<<res3<<endl;
    return 0;
}