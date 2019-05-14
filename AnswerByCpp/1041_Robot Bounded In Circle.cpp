#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1041. 困于环中的机器人

在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一：
"G"：直走 1 个单位
"L"：左转 90 度
"R"：右转 90 度
机器人按顺序执行指令 instructions，并一直重复它们。
只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。

示例 1：   输入："GGLLGG"     输出：true
解释： 机器人从 (0,0) 移动到 (0,2)，转 180 度，然后回到 (0,0)。
重复这些指令，机器人将保持在以原点为中心，2 为半径的环中进行移动。
示例 2：   输入："GG"         输出：false
解释： 机器人无限向北移动。
示例 3：   输入："GL"         输出：true
解释： 机器人按 (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... 进行移动。

提示：
1 <= instructions.length <= 100
instructions[i] 在 {'G', 'L', 'R'} 中
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y=0, i=0;
        vector<vector<int>> arr({{0,1},{1,0},{0,-1},{-1,0}});
        for(int j=0; j<instructions.size(); ++j){
            if(instructions[j] == 'R')
                i = (i+1)%4;
            else if(instructions[j] == 'L')
                i = (i+3)%4;
            else x += arr[i][0], y += arr[i][1];
        }
        return x==0 && y==0 || i > 0;
    }
};

int main(){
    Solution* so = new Solution();
    bool bl = so->isRobotBounded("GGGL");
    cout<<bl<<endl;
    return 0;
}
