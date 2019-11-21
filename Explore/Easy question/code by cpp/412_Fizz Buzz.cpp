#include<iostream>
#include<vector>
using namespace std;
/*
412. Fizz Buzz

写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
vector<string> fizzBuzz(int n) {
    vector<string> str;
    for(int i = 1;i<=n;i++){
        if(i%15 == 0)str.push_back("FizzBuzz");
        else if(i%3 == 0)str.push_back("Fizz");
        else if(i%5 == 0)str.push_back("Buzz");
        else str.push_back(to_string(i));
    }
    return str;
}

int main(){
    vector<string>nums = fizzBuzz(15);
    for(int i = 0;i<nums.size();i++)
        cout<<nums[i]<<endl;
	return 0;
}
