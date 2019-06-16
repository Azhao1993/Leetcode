#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
1090. 受标签影响的最大值

我们有一个项的集合，其中第 i 项的值为 values[i]，标签为 labels[i]。
我们从这些项中选出一个子集 S，这样一来：
|S| <= num_wanted   对于任意的标签 L，子集 S 中标签为 L 的项的数目总满足 <= use_limit。
返回子集 S 的最大可能的 和。

示例 1：   输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1    
          输出：9      解释：选出的子集是第一项，第三项和第五项。
示例 2：   输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
          输出：12       解释：选出的子集是第一项，第二项和第三项。
示例 3：   输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
           输出：16    解释：选出的子集是第一项和第四项。
示例 4：   输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
           输出：24   解释：选出的子集是第一项，第二项和第四项。

提示：     1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000      1 <= num_wanted, use_limit <= values.length
*/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int len = values.size();
        // 把价值和标签存放到一个 vector 中，然后按照价值，降序排列
        vector<vector<int>> arr(len, vector<int>(2,0));
        for(int i = 0; i<len; i++)
            arr[i][0] = values[i], arr[i][1] = labels[i];
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){return a[0] > b[0];});

        // 通过 hashmap 来记录和判断标签出现的次数
        unordered_map<int,int> hash;
        int res = 0;
        for(int i = 0; i<len && num_wanted != 0; i++)
            if(hash[arr[i][1]]++ < use_limit)
                num_wanted--, res += arr[i][0];
        
        return res;
    }
};

int main(){
    vector<int> arr{5,4,3,2,1};
    vector<int> brr{1,1,2,2,3};
    int it = Solution().largestValsFromLabels(arr,brr,3,1);
    cout<<it<<endl;
    return 0;
}