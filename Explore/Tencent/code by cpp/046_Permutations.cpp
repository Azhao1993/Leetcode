#include<iostream>
#include<vector>
using namespace std;
/*
46. 全排列

给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],  [1,3,2],    [2,1,3],
  [2,3,1],  [3,1,2],    [3,2,1]
]
 */

class Solution {
private:
    vector<vector<int> > arr;
    vector<bool>used;
public:
    vector<vector<int> > permute(vector<int>& nums) {
        arr.clear();
        if(!nums.size())return arr;
        used = vector<bool>(nums.size(),false);
        vector<int> tmp;
        helper(nums,tmp);
        return arr;
    }
    void helper(vector<int> nums,vector<int> tmp){
        if(tmp.size()==nums.size()){
            arr.push_back(tmp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                used[i] = true;
                tmp.push_back(nums[i]);
                helper(nums,tmp);
                // 暴力探索，把所有数加入进去才能弹出
                used[i] = false;
                tmp.pop_back();
            }
        }
        return ;
    }
};

/*
class Solution {
public:
    void helper(vector<vector<int> >& arr,unordered_map<int,int> hash,vector<int> tmp,vector<int> nums){
        if(tmp.size()==nums.size()){
            arr.push_back(tmp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!hash[nums[i]]){
                tmp.push_back(nums[i]);
                hash[nums[i]]++;
                helper(arr,hash,tmp,nums);
                // 暴力探索，把所有数加入进去才能弹出
                hash[nums[i]]--;
                tmp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > arr;
        unordered_map<int,int> hash;
        vector<int> tmp;
        helper(arr,hash,tmp,nums);
        return arr;
    }
};
*/

int main(){
    int x[4] = {1,2,3,4};
    vector<int> nums(x,x+4);

    auto so = new Solution();
    vector<vector<int> > num = so->permute(nums);

    for(int i=0;i<num.size();i++){
        for(int j=0;j<num[i].size();j++)
            cout<<num[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
