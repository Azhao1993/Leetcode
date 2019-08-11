#include<bits\stdc++.h>
using namespace std;
/*
1154. 一年中的第几天

给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。 通常情况下，
我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

示例 1：   输入：date = "2019-01-09"      输出：9
示例 2：   输入：date = "2019-02-10"      输出：41
示例 3：   输入：date = "2003-03-01"      输出：60
示例 4：   输入：date = "2004-03-01"      输出：61

提示： date.length == 10       date[4] == date[7] == '-'，其他的 date[i] 都是数字。
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
*/

class Solution {
public:
    int ordinalOfDate(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + date[3] - '0';
        int month = (date[5] - '0') * 10 + date[6] - '0';
        int day = (date[8] - '0') * 10 + date[9] - '0';

        bool isLeap = year%4 != 0 ? false : year%100 != 0 ? true : year%400 != 0 ? false : true;
        
        vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
        int res = day;
        for(int i=0; i<month-1; i++) res += days[i];
        if(month > 2 && isLeap) res++;
        
        return res;
    }
};

int main(){
    int res = Solution().ordinalOfDate("2004-03-01");
    cout<<res<<endl;
    return 0;
}