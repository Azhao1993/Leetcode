#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
30. 串联所有单词的子串

给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

示例 1：输入：   s = "barfoothefoobarman",
                words = ["foo","bar"]
        输出：[0,9]
解释： 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：输入：     s = "wordgoodgoodgoodbestword",
                  words = ["word","good","best","word"]
        输出：[]
*/

// substr(index,length)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()<1 || s.size()<1 || s.size()<words[0].size())return res;
        int wordNum = words.size(), wordLen = words[0].size();
        unordered_map<string,int> allWord;
        for(auto it:words){
            if(it.size()!=wordLen)return res;
            allWord[it]++;
        }
        for(int i=0;i<wordLen;++i){
            // 记录第二个hash表里的个数
            int num = 0;
            unordered_map<string,int> hash;
            for(int j=i;j<s.size()-wordNum*wordLen+1;j+=wordLen){
                // 防止情况一和情况三都进行删除
                bool hasRemoved = false;
                while(num<wordNum){
                    string word = s.substr(j+num*wordLen, wordLen);
                    if(allWord[word]){
                        hash[word]++;
                        // 情况三，单词符合，次数超了
                        if(hash[word]>allWord[word]){
                            hasRemoved = true;
                            int removeNum = 0;
                            while(hash[word]>allWord[word]){
                                string temp = s.substr(j+removeNum*wordLen, wordLen);
                                removeNum++;
                                hash[temp]--;
                            }
                            // 加1是因为我们把当前单词加入到了hash
                            num = num-removeNum+1;
                            // 第二层for循环还会加一个
                            j = j + (removeNum-1)*wordLen;
                            break;
                        }
                    }else{
                        // 情况二，出现了不符合的单词
                        hash.clear();
                        j += num*wordLen;
                        num = 0;
                        break;
                    }
                    num++;
                }
                if(num == wordNum)
                    res.push_back(j);
                if(num > 0 && !hasRemoved){
                    string temp = s.substr(j,wordLen);
                    hash[temp]--;
                    num--;
                }
            }
        }
        return res;
    }
};

int main(){
    string str = "barfoothefoobarman";
    vector<string> words({"foo","bar"});

    Solution* so = new Solution();
    vector<int> arr = so->findSubstring(str,words);
    for(auto it: arr) cout<<it<<' ';
    cout<<endl;
    return 0;
}
