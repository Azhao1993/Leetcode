#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
546. 移除盒子

给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k 个积分。
当你将所有盒子都去掉之后，求你能获得的最大积分和。

示例 1：
输入: [1, 3, 2, 2, 2, 3, 4, 3, 1]
输出: 23
解释:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 分)
----> [1, 3, 3, 3, 1] (1*1=1 分)
----> [1, 1] (3*3=9 分)
----> [] (2*2=4 分)
提示：盒子的总数 n 不会超过 100。
*/

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        len = vector<int>(boxes.size());
        for(int i=1;i<boxes.size();++i)
            // 数据预处理，把连续相同的数字进行统计一下
            if(boxes[i]==boxes[i-1])len[i]=len[i-1]+1;
        return dfs(boxes,0,boxes.size()-1,0);
    }
private:
    unordered_map<int,int>m;
    vector<int> len;
    int dfs(vector<int> boxes,int l,int r,int k){// k代表在[l,r]后跟着的k个与boxes[r]相同的元素
        if(l>r) return 0;
        k += len[r];// 跳过原数组中连续相同的
        r -= len[r];
        int key = (l*100+r)*100+k;// 将位置转换为一维作为hash值
        if(m.find(key)!=m.end()) return m[key];
        int & ans = m[key];// 引用，同步改变
        ans = dfs(boxes,l,r-1,0)+(k+1)*(k+1);// 递归，r以及后面的全部remove
        for(int i=l;i<r;++i)
            // 如果在前面仍有和后面相同的数，把中间的进行remove
            if(boxes[i]==boxes[r])
                ans = max(ans,dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));
        return ans;
    }
};

int main(){
    vector<int> nums = vector<int>({1, 3, 2, 2, 2, 3, 4, 3, 1});

    Solution* so = new Solution();
    int it = so -> removeBoxes(nums);
    cout<<it<<endl;
  return 0;
}
