#include<iostream>
#include<vector>
using namespace std;
/*
179. 最大数

给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto it:nums)arr.push_back(to_string(it));
        // sort的高级用法
        sort(arr.begin(),arr.end(),[](string a,string b){return a+b>b+a;});
        string res = "";
        for(auto it:arr)res += it;
        // 防止有多个0
        if(res[0]=='0')return "0";
        return res;
    }
};

int main(){
    vector<int> a({0,9,34,214});

    Solution* so = new Solution();
    string n = so->largestNumber(a);
    cout<<n<<endl;
    return 0;
}
