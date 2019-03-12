#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
12. 整数转罗马数字

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
字符  数值
I   1   V  5   X  10   L  50   C   100   D   500    M  1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:   输入: 3       输出: "III"
示例 2:   输入: 4       输出: "IV"
示例 3:   输入: 9       输出: "IX"
示例 4:   输入: 58      输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:   输入: 1994    输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    string intToRoman(int num) {
        /*
        string res = "";
        int tem = num%1000;
        res.append(num/1000, 'M');
        string arr[3][10] = {{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},{"","I","II","III","IV","V","VI","VII","VII","IX"}};
        res += arr[0][tem/100];    tem %= 100;
        res += arr[1][tem/10];     tem %= 10;
        res += arr[2][tem];
        cout<<res<<endl;
        */

        string str = "";

        // 处理千位上的数字
        str.append(num / 1000, 'M'); num %= 1000;

        // 处理百位上的数字
        int b = num/100;  num %= 100;
        if(b==9)str += "CM";
        else if(b==4) str += "CD";
        else if(b >= 5)b -= 5,str+= "D";
        if(b<4) str.append(b, 'C');

        // 处理十位上的数字
        int c = num/10;   num %= 10;
        if(c==9)str += "XC";
        else if(c==4) str += "XL";
        else if(c >= 5)c -= 5,str+= "L";
        if(c<4) str.append(c, 'X');

        int d = num;
        if(d==9)str += "IX";
        else if(d==4) str += "IV";
        else if(d >= 5)d -= 5,str+= "V";
        if(d<4) str.append(d, 'I');

        return str;
    }
};


int main(){
    int n;
    while(cin>>n){
        Solution* so = new Solution();
        string num = so->intToRoman(n);
        cout<<num<<endl;
    }
    return 0;
}
