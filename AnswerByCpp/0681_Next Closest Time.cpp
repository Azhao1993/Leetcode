#include <iostream>
#include <array>
#include <set>
#include <algorithm>
using namespace std;
/*
681. 最近时刻

给定一个形如 “HH:MM” 表示的时刻，利用当前出现过的数字构造下一个距离当前时间最近的时刻。每个出现数字都可以被无限次使用。
你可以认为给定的字符串一定是合法的。例如，“01:34” 和 “12:09” 是合法的，“1:34” 和 “12:9” 是不合法的。

样例 1:   输入: "19:34"     输出: "19:39"
解释: 利用数字 1, 9, 3, 4 构造出来的最近时刻是 19:39，是 5 分钟之后。结果不是 19:33 因为这个时刻是 23 小时 59 分钟之后。
样例 2:   输入: "23:59"     输出: "22:22"
解释: 利用数字 2, 3, 5, 9 构造出来的最近时刻是 22:22。 答案一定是第二天的某一时刻，所以选择可构造的最小时刻。
*/

class Solution {
public:
    string nextClosestTime(string time) {
        time = time.substr(0,2) + time.substr(3,2);
        array<int, 4> arr;
        for (int i=0; i<4; i++) arr[i] = time[i] - '0';
        int now = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
        set<int> st;
        for (int i=0; i<4; i++) for (int j=0; j<4; j++) for (int k=0; k<4; k++) for (int l=0; l<4; l++) {
            int cur = arr[i]*1000+arr[j]*100+arr[k]*10+arr[l];
            if (cur/100 < 24 && cur%100 < 60) st.insert(cur);
        }
        auto te = st.find(now);
        int res = ++te == st.end() ? *st.begin() : *te;
        return to_string(res/1000)+to_string(res/100%10)+":"+to_string(res/10%10)+to_string(res%10);
    }
};

int main(){
    cout << Solution().nextClosestTime("19:34") << endl;
    cout << Solution().nextClosestTime("22:59") << endl;
    return 0;
}