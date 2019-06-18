#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1081. 不同字符的最小子序列

返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

示例 1：		输入："cdadabcc"		输出："adbc"
示例 2：		输入："abcd"			输出："abcd"
示例 3：		输入："ecbacba"		输出："eacb"
示例 4：		输入："leetcode"		输出："letcod"

提示：	1 <= text.length <= 1000		text 由小写英文字母组成
*/

class Solution {
public:
    string smallestSubsequence(string text) {
        
    }
};

int main(){
    string a = "leetcode", b = "programs", s = "sourcecode";
    Solution* so = new Solution();
    string res = so->smallestEquivalentString(a,b,s);
    cout<<res<<endl;

    return 0;
}

	1036	逃离大迷宫
	1039	多边形三角剖分的最低得分
	1040	移动石子直到连续 II
	1042	不邻接植花
	1044	最长重复子串    
	1055	形成字符串的最短路径
	1057	校园自行车分配
	1058	最小化舍入误差以满足目标
	1059	从始点到终点的所有路径
	1062	最长重复子串
	1063	有效子数组的数目    
	1072	按列翻转得到最大值等行数
	1073	负二进制数相加
	1074	元素和为目标值的子矩阵数量
	1079	活字印刷
	1080	根到叶路径上的不足节点
	1081	不同字符的最小子序列