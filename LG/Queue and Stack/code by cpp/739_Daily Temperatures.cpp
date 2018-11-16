#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
739. 每日温度

根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
*/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> arr(temperatures.size(),0);
    stack<pair<int,int> >sta;
    for(int i = 0;i<temperatures.size();i++){
        int todayT = temperatures[i];
        while(!sta.empty() && sta.top().first < todayT){
            arr[sta.top().second] = i-sta.top().second;
            sta.pop();
        }
        sta.push({todayT,i});
    }
    return arr;

    /*
    vector<int> arr;
    stack<pair<int,int> >sta;
    for(int i = temperatures.size()-1;i>=0;i--){
        int todayT = temperatures[i];
        if(sta.empty())arr.insert(arr.begin(),0);
        else {
            while(!sta.empty()){
                pair<int,int> tem = sta.top();
                // 找到比当天气温大的那天
                if(tem.first > todayT){
                    arr.insert(arr.begin(),tem.second-i);
                    break;
                }
                else sta.pop();
                if(sta.empty())arr.insert(arr.begin(),0);
            }
        }
        sta.push({todayT,i});
    }
    return arr;
    */
}


int main(){
    int a[8]={73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> arr(a,a+8);
    vector<int> brr = dailyTemperatures(arr);
    for (int i = 0; i < brr.size(); ++i)
        cout<<brr[i]<<' ';
    cout<<endl;
    return 0;
}
