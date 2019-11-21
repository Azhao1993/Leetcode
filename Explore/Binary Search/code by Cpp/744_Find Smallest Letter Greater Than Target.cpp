#include<iostream>
#include<vector>
using namespace std;
/*
744. 寻找比目标字母大的最小字母

给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"
*/
char nextGreatestLetter(vector<char>& letters, char target) {
    int low = 0, high = letters.size()-1,mid;
    if(target<letters[0] || target>=letters[high])return letters[0];
    while(low<=high){
        mid = low + (high-low)/2;
        if(letters[mid] == target){
            while(letters[++mid]==target);
            return letters[mid];
        }
        if(letters[mid] > target)high = mid-1;
        else low = mid+1;
    }
    if(low>high)return letters[low];
    else return letters[high];
}

int main(){
    char x[3] = {'c','f','j'};
    vector<char>nums(x,x+3);
    char n = nextGreatestLetter(nums,'d');
    cout<<n<<endl;
	return 0;
}
