#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
/*
418. 屏幕可显示句子的数量

给你一个 rows x cols 的屏幕和一个用 非空 的单词列表组成的句子，请你计算出给定句子可以在屏幕上完整显示的次数。
注意： 一个单词不能拆分成两行。  单词在句子中的顺序必须保持不变。
在一行中 的两个连续单词必须用一个空格符分隔。 句子中的单词总量不会超过 100。
每个单词的长度大于 0 且不会超过 10。  1 ≤ rows, cols ≤ 20,000.

示例 1： 输入：   rows = 2, cols = 8, 句子 sentence = ["hello", "world"]    输出：1
解释：
hello---
world---
字符 '-' 表示屏幕上的一个空白位置。
示例 2： 输入：   rows = 3, cols = 6, 句子 sentence = ["a", "bcd", "e"]     输出：2
解释：
a-bcd- 
e-a---
bcd-e-
字符 '-' 表示屏幕上的一个空白位置。
示例 3： 输入：    rows = 4, cols = 5, 句子 sentence = ["I", "had", "apple", "pie"]     输出： 1

解释：
I-had
apple
pie-I
had--
字符 '-' 表示屏幕上的一个空白位置。
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str;
        for (auto &s : sentence) str += s + " ";
        int n = str.size(), start = 0;
        for (int i=0; i<rows; i++) {
            start += cols;
            if (str[start % n == ' ']) {
                ++start;
                continue;
            }
            while (start > 0 && str[(start-1) % n] != ' ') start--;
        }
        return start / n;
        int len = sentence.size(), res = 0, cur = 0, idx = 0, l = 0;
        for (auto &s : sentence) l += s.size() + 1;
        for (int i=0; i<rows; i++) {
            cur = cols;
            while (cur > 0 && cur >= sentence[idx].size()) {
                cur = cur - sentence[idx].size();
                if (cur > 0) cur--;
                if (++idx == len) idx = 0, res += cur/l + 1, cur = cur%l;
            }
        }
        return res;
    }
};

int main(){
    vector<string> arr{"I", "had", "apple", "pie"};
    int res = Solution().wordsTyping(arr, 4, 5);
    cout << res << endl;
    return 0;
}