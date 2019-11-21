#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;
/*
777. 在LR字符串中交换相邻字符

在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。

示例 :
输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
输出: True
解释:
我们可以通过以下几步将start转换成end:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
注意:
1 <= len(start) = len(end) <= 10000。
start和end中的字符串仅限于'L', 'R'和'X'。
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        // 记录两个字符串中，字符L和字符R的个数
        if(start.size()!=end.size())return false;
        // 为了方便判断最后一个
        start+="Y",end+="Y";
        int i=0,j=0;
        while(i<start.size() && j<end.size()){
            while(start[i]=='X')i++;
            while(end[j]=='X')j++;
            // L R的相对位置是不变的
            if(start[i]!=end[j])return false;
            // L只能向左走
            if(start[i]=='L' && i<j)return false;
            // R只能向右走
            if(start[i]=='R' && j<i)return false;
            i++;j++;
        }
        return true;
    }
};

int main(){
    Solution* so = new Solution();
    bool it = so -> canTransform("RXXLRXRXL","XRLXXRRLX");
    cout<<it<<endl;
  return 0;
}
