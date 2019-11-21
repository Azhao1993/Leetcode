#include<iostream>
#include<vector>
using namespace std;
/*
621. 任务调度器

给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
你需要计算完成所有任务所需要的最短时间。

示例 1：
输入: tasks = ["A","A","A","B","B","B"], n = 2
输出: 8
执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
注：
任务的总个数为 [1, 10000]。
n 的取值范围为 [0, 100]。
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26]={0};
        int count = 0;
        // 找出最多的任务
        for(auto it:tasks){
            arr[it-'A']++;
            count = max(count,arr[it-'A']);
        }
        int num = (count-1) * (n+1);
        for(auto it:arr)
            if(it==count)num++;
        return max((int)tasks.size(),num);
    }
};

int main(){
    char cha[6]={'A','A','B','A','B','B'};
    vector<char> a(cha,cha+6);

    Solution* so = new Solution();
    int bl = so->leastInterval(a, 2);
    cout<<bl<<endl;
    return 0;
}
