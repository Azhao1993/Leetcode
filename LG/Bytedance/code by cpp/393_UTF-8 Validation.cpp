#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
393. UTF-8 编码验证

UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
对于 1 字节的字符，字节的第一位设为0，后面7位为这个符号的unicode码。
对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。
这是 UTF-8 编码的工作方式：

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
给定一个表示数据的整数数组，返回它是否为有效的 utf-8 编码。

注意:
输入是整数数组。只有每个整数的最低 8 个有效位用来存储数据。这意味着每个整数只表示 1 字节的数据。
示例 1:
data = [197, 130, 1], 表示 8 位的序列: 11000101 10000010 00000001.
返回 true 。
这是有效的 utf-8 编码，为一个2字节字符，跟着一个1字节字符。
示例 2:
data = [235, 140, 4], 表示 8 位的序列: 11101011 10001100 00000100.
返回 false 。
前 3 位都是 1 ，第 4 位为 0 表示它是一个3字节字符。
下一个字节是开头为 10 的延续字节，这是正确的。
但第二个延续字节不以 10 开头，所以是不符合规则的。
 */

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt=0;
        for(int d:data)
        {
            if(cnt==0)
            {
                // 只判断前几位 0b为2进制
                if((d>>5)==0b110)cnt=1;
                else if((d>>4)==0b1110)cnt=2;
                else if((d>>3)==0b11110)cnt=3;
                else if(d>>7)return false;
            }else{
                if((d>>6)!=0b10) return false;
                --cnt;
            }
        }
        return cnt==0;
        /*
        // 只有4种情况是对的
        // 0-127、192-223 128-191、224-239 （128-191）*2、240-247 （128-191）*3
        if(!data.size())return true;
        while(data.size()){
            if(data[0]>=0 && data[0]<=127)data.erase(data.begin());
            else if(data[0]>=192 && data[0]<=223){
                if(data[1]>=128 && data[1]<=191)data.erase(data.begin(),data.begin()+2);
                else return false;
            }else if(data[0]>=224 && data[0]<=239){
                if(data[1]>=128 && data[1]<=191 && data[2]>=128 && data[2]<=191)
                    data.erase(data.begin(),data.begin()+3);
                else return false;
            }else if(data[0]>=240 && data[0]<=247){
                if(data[1]>=128 && data[1]<=191&& data[2]>=128 && data[2]<=191 && data[3]>=128 && data[3]<=191)
                    data.erase(data.begin(),data.begin()+4);
                else return false;
            }else return false;
        }
        return true;
        */
    }
};

int main(){
    int cha[4]={235, 140, 149,190};
    vector<int> a(cha,cha+4);

    Solution* so = new Solution();
    bool bl = so->validUtf8(a);
    cout<<bl<<endl;
    return 0;
}
