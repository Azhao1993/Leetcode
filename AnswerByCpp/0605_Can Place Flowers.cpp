#include<bits\stdc++.h>
using namespace std;
/*
605. 种花问题

假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，
两者都会死去。给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:   输入: flowerbed = [1,0,0,0,1], n = 1  输出: True
示例 2:   输入: flowerbed = [1,0,0,0,1], n = 2  输出: False

注意: 数组内已种好的花不会违反种植规则。   输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int ind = 0, len = flowerbed.size();
        while(n > 0 && ++ind < len-1){
            if(flowerbed[ind] == 1) continue;
            if(flowerbed[ind-1] == 0 && flowerbed[ind+1] == 0)
                flowerbed[ind] = 1, n--;
        }
        return n==0;

        for(int i=0; i<len && n > 0; i++)
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                n--;
                flowerbed[i] = 1;
            }
        return n==0;
    }
};

int main(){
    vector<int> nums{1,0,0,0,1};
    bool res = Solution().canPlaceFlowers(nums, 1);
    cout<<res<<endl;
    return 0;
}