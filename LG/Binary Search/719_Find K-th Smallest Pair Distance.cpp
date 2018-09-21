#include<iostream>
#include<vector>
using namespace std;
/*
719. 找出第 k 小的距离对

给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

/*
[LeetCode] Find K-th Smallest Pair Distance 找第K小的数对儿距离 - Grandyang - 博客园
http://www.cnblogs.com/grandyang/p/8627783.html
我们来看一种基于二分搜索的解法。这道题使用的二分搜索法是博主归纳总结帖LeetCode Binary Search Summary 二分搜索法小结中的第四种，即二分法的判定条件不是简单的大小关系，而是可以抽离出子函数的情况，下面我们来看具体怎么弄。我们的目标是快速定位出第k小的距离，那么很适合用二分法来快速的缩小查找范围，然而最大的难点就是如何找到判定依据来折半查找，即如果确定搜索目标是在左半边还是右半边。做过Kth Smallest Element in a Sorted Matrix和Kth Smallest Number in Multiplication Table这两道题的同学应该对这种搜索方式并不陌生。核心思想是二分确定一个中间数，然后找到所有小于等于这个中间数的距离个数，用其跟k比较来确定折半的方向。具体的操作是，我们首先要给数组排序，二分搜索的起始left为0，结束位置right为最大距离，即排序后的数字最后一个元素减去首元素。然后进入while循环，算出中间值mid，此外我们还需要两个变量cnt和start，其中cnt是记录小于等于mid的距离个数，start是较小数字的位置，均初始化为0，然后我们遍历整个数组，先进行while循环，如果start未越界，并且当前数字减去start指向的数组之差大于mid，说明此时距离太大了，我们增加减数大小，通过将start右移一个，那么while循环退出后，就有i - start个距离小于等于mid，将其加入cnt中，举个栗子来说：

   1    2    3    3    5

start              i

mid = 2

如果start在位置0，i在位置3，那么以nums[i]为较大数可以产生三个（i - start）小于等于mid的距离，[1 3], [2 3], [3 3]，这样当i遍历完所有的数字后，所有小于等于mid的距离的个数就求出来了，即cnt。然后我们跟k比较，如果其小于k，那么left赋值为mid+1，反之，则right赋值为mid。最终返回right或left均可，参见代码如下：
*/
#include<algorithm>

int countPairs(vector<int> &nums, int mid){
    int low = 0, high = 0 ,res = 0;
    while(high<nums.size()){
        while(nums[high]-nums[low]>mid)low++;
        res += high -low;
        high++;
    }
    return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int low = 0,high = nums[nums.size()-1]-nums[0],mid;

    while(low<high){
        mid = low+(high-low)/2;
        if(countPairs(nums,mid)<k)low = mid+1;
        else high = mid;
    }
    return low;
}

int main(){
    int x[3] = {1,3,1};
    vector<int>nums(x,x+3);
    int n = smallestDistancePair(nums,1);
    cout<<n<<endl;
	return 0;
}
