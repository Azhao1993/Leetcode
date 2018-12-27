#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
/*
17. 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> arr;
        if(!digits.size()) return arr;
        arr.push_back("");
        for(int i=0;i<digits.length();i++){
            int size = arr.size();
            for(int j=0;j<size;j++){
                string temp = arr[0];
                arr.erase(arr.begin());
                switch(digits[i]-'0'){
                    case 2: arr.push_back(temp+"a");
                            arr.push_back(temp+"b");
                            arr.push_back(temp+"c");
                            break;
                    case 3: arr.push_back(temp+"d");
                            arr.push_back(temp+"e");
                            arr.push_back(temp+"f");
                            break;
                    case 4: arr.push_back(temp+"g");
                            arr.push_back(temp+"h");
                            arr.push_back(temp+"i");
                            break;
                    case 5: arr.push_back(temp+"j");
                            arr.push_back(temp+"k");
                            arr.push_back(temp+"l");
                            break;
                    case 6: arr.push_back(temp+"m");
                            arr.push_back(temp+"n");
                            arr.push_back(temp+"o");
                            break;
                    case 7: arr.push_back(temp+"p");
                            arr.push_back(temp+"q");
                            arr.push_back(temp+"r");
                            arr.push_back(temp+"s");
                            break;
                    case 8: arr.push_back(temp+"t");
                            arr.push_back(temp+"u");
                            arr.push_back(temp+"v");
                            break;
                    case 9: arr.push_back(temp+"w");
                            arr.push_back(temp+"x");
                            arr.push_back(temp+"y");
                            arr.push_back(temp+"z");
                            break;
                }
            }
        }
        return arr;
    }
};

int main(){
	Solution* so = new Solution();
    vector<string> arr = so->letterCombinations("23");
    for(auto it:arr)
        cout<<it<<endl;
    return 0;
}
