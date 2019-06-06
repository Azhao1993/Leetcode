#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
401. 二进制手表

二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
每个 LED 代表一个 0 或 1，最低位在右侧。
例如，上面的二进制手表读取 “3:25”。
给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:	输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 
注意事项:	输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
*/

class Solution {
private: 
	int count1(int num){
		int res = 0;
		while(num != 0)
			res++, num = num & (num-1);
		return res;
	}
public:
    vector<string> readBinaryWatch(int num) {
    	if(num < 0 || num > 8 ) return vector<string>();
    	if(num == 0) return vector<string>{"0:00"};
    	vector<string> res;
        for(int h = 0; h < 12; h++)
        	for(int m = 0; m < 60; m++)
        		if(count1(h) + count1(m) == num)
        			res.push_back( to_string(h) + (m < 10 ? ":0" : ":") + to_string(m) );
        return res;
    }
/*
private: 
	vector<vector<int>> hour{{0},{1,2,4,8},{3,5,6,9,10},{7,11}};
	// 1 + 6 + 15 + 20 + 14 + 4
	vector<vector<int>> minute{{0},{1,2,4,8,16,32},{3,5,6,9,10,12,17,18,20,24,33,34,36,40,48},{7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56},{15,23,27,29,30,39,43,45,46,51,53,54,57,58},{31,47,55,59}};
public:
    vector<string> readBinaryWatch(int num) {
    	if(num < 0 || num > 8 ) return vector<string>();
    	if(num == 0) return vector<string>{"0:00"};
    	vector<string> res;
        for(int h = min(3, num); h >= 0; h--){
        	int m = num-h;
        	if(m > 5) continue;
        	for(int i = 0; i < hour[h].size(); i++)
        		for(int j = 0; j < minute[m].size(); j++)
        			res.push_back(to_string(hour[h][i]) + (minute[m][j] < 10 ? ":0" : ":") + to_string(minute[m][j]));
        }
        return res;
    }
*/
};

int main(){
    vector<string> arr = Solution().readBinaryWatch(6);
    for(auto it:arr) cout<<it<<' ';
    cout<<endl;
    return 0;
}