#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1185. 一周中的第几天

给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
输入为三个整数：day、month 和 year，分别表示日、月、年。
您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

示例 1：   输入：day = 31, month = 8, year = 2019         输出："Saturday"
示例 2：   输入：day = 18, month = 7, year = 1999         输出："Sunday"
示例 3：   输入：day = 15, month = 8, year = 1993         输出："Sunday"

提示：  给出的日期一定是在 1971 到 2100 年之间的有效日期。
*/

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        // 如果是前两个月，变换成上一年的 13 14 月计算  
        if(month <= 2) month += 12, year--;
        int y = year%100, c = year/100, w;
        // 菜勒公式
        w = y + y/4 + c/4 - 2*c + 26*(month+1)/10 + day - 1;
        return week[(w + 700)%7];
    }
};


int main(){
    string str = Solution().dayOfTheWeek(31, 8, 2019);
    cout << str << endl; 
    return 0;
}