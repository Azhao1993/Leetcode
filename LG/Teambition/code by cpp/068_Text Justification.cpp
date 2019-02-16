#include<iostream>
#include<vector>
using namespace std;
/*
68. 文本左右对齐

给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:
输入: words = ["This", "is", "an", "example", "of", "text", "justification."] maxWidth = 16
输出: ["This    is    an","example  of text","justification.  "]
示例 2:
输入: words = ["What","must","be","acknowledgment","shall","be"]  maxWidth = 16
输出: ["What   must   be","acknowledgment  ","shall be        "]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:
输入: words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"] maxWidth = 20
输出: ["Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  "]
}*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i=0;i<words.size();){
            int num = 1,sum = words[i].size();
            string temp = "";
            while(sum<=maxWidth && i+num<words.size()){
                // 加上至少要有的空格
                sum += words[i+num].size() + 1;
                num++;
            }
            // 走到了最后
            if(sum<=maxWidth){
                while(i < words.size()-1)temp += words[i++]+' ';
                temp+=words[i++];
                temp += string(maxWidth-sum,' ');
                res.push_back(temp);
                return res;
            }else{
                // num为不包括第一个的个数，单词之间
                num -= 2;
                sum = sum-1-words[i+num+1].size();
                // 还需添加的空格的个数
                int rem = maxWidth-sum;
                for(;num>0;num--){
                    // 当前需要添加的个数
                    int cur = (rem+num-1)/num;
                    rem -= cur;
                    temp += words[i++]+string(cur+1,' ');
                }
                // 最后一个单词不需要括号
                temp+=words[i++];
                // 防止一行只有一个字符
                temp+=string(rem,' ');
                res.push_back(temp);
            }
        }
        return res;
    }
};

int main(){
    vector<string> nums({"What","must","be","acknowledgment","shall","be"});

    Solution* so = new Solution();
    vector<string> arr = so -> fullJustify(nums,16);
    for(auto it:arr)
        cout<<it<<endl;
	return 0;
}
