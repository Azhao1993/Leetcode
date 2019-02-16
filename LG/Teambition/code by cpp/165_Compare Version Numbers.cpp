#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
165. 比较版本号

比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。
 . 字符不代表小数点，而是用于分隔数字序列。
例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。

示例 1:
输入: version1 = "0.1", version2 = "1.1"          输出: -1
示例 2:
输入: version1 = "1.0.1", version2 = "1"          输出: 1
示例 3:
输入: version1 = "7.5.2.4", version2 = "7.5.3"    输出: -1
示例 4：
输入：version1 = "1.01", version2 = "1.001"        输出：0
解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
示例 5：
输入：version1 = "1.0", version2 = "1.0.0"         输出：0
解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。

提示：
版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
版本字符串不以点开始或结束，并且其中不会有两个连续的点。
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,num1=0,num2=0;
        while(i<version1.size() || j<version2.size()){
            // 查找某一级的版本号
            while(i<version1.size()&&version1[i]!='.'){
                num1 = num1*10 + version1[i]-'0';
                i++;
            }
            // 查找某一级的版本号
            while(j<version2.size()&&version2[j]!='.'){
                num2 = num2*10 + version2[j]-'0';
                j++;
            }
            if(num1>num2)return 1;
            if(num1<num2)return -1;
            // 数据更新
            num1=0,num2=0,i++,j++;
        }
        /*
        // 字符串预处理，方便最后一个数的转换
        version1 += ".",version2 += ".";
        // 当前位置
        int cur1 = 0, cur2 = 0;
        // 全都结束才算比较完成
        while(cur1<version1.length() || cur2<version2.length()){
            int num1,num2;
            if(cur1<version1.length()){
                // 查找某一级的版本号
                int tem1 = version1.find_first_of('.',cur1);
                num1 = stoi(version1.substr(cur1,tem1-cur1));
                cur1 = tem1+1;
            // 默认版本号为0
            }else num1 = 0;

            if(cur2<version2.length()){
                // 查找某一级的版本号
                int tem2 = version2.find_first_of('.',cur2);
                num2 = stoi(version2.substr(cur2,tem2-cur2));
                cur2 = tem2+1;
            // 默认版本号为0
            }else num2 = 0;
            if(num1>num2)return 1;
            if(num1<num2)return -1;
        }
        return 0;
        */
    }
};

int main(){
    Solution* so = new Solution();
    int n = so->compareVersion("0","001");
    cout<<n<<endl;
    return 0;
}
