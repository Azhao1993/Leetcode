#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/*
1054. 距离相等的条形码

在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

示例 1：   输入：[1,1,1,2,2,2]        输出：[2,1,2,1,2,1]
示例 2：   输入：[1,1,1,1,2,2,3,3]    输出：[1,3,1,3,2,1,2,1]

提示： 1 <= barcodes.length <= 10000   1 <= barcodes[i] <= 10000
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> res(barcodes);
        if(barcodes.size() < 3) return res;
        // 通过 hashmap 获取出现元素的频率
        unordered_map<int,int> hash;
        for(auto it:barcodes) hash[it]++;

        // 以频率为主元素，存放到大根堆中
        priority_queue<pair<int,int>> que;
        for(auto& it : hash)
            que.push({it.second, it.first});

        for(int i=0; i<res.size(); i++){
            // 先把频率大的元素排到数组中
            if(i == 0 || res[i-1] != que.top().second){
                pair<int, int> tem = que.top();
                res[i] = tem.second;
                tem.first--;
                que.pop();
                que.push(tem);
            }else {
                // 若当前频率最大的元素等于数组元素中最后一个，则需要把第二大的元素放入数组中
                pair<int, int> tem1 = que.top();
                que.pop();
                pair<int, int> tem = que.top();

                res[i] = tem.second;
                tem.first--;
                que.pop();
                que.push(tem);
                que.push(tem1);
            }   
        }
        return res;
    }
};

int main(){
    vector<int> arr = {1,1,1,2,2,2};
    vector<int> num = Solution().rearrangeBarcodes(arr);
    for(auto it:num) cout<<it<<' ';
    cout<<endl;
    return 0;
}