#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
1096. 花括号展开 II

如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。
花括号展开的表达式可以看作一个由 花括号、逗号 和 小写英文字母 组成的字符串，定义下面几条语法规则：
如果只给出单一的元素 x，那么表达式表示的字符串就只有 "x"。 
例如，表达式 {a} 表示字符串 "a"。   而表达式 {ab} 就表示字符串 "ab"。
当两个或多个表达式并列，以逗号分隔时，我们取这些表达式中元素的并集。
例如，表达式 {a,b,c} 表示字符串 "a","b","c"。
而表达式 {a,b},{b,c} 也可以表示字符串 "a","b","c"。
要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。
例如，表达式 {a,b}{c,d} 表示字符串 "ac","ad","bc","bd"。
表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
例如，表达式 a{b,c,d} 表示字符串 "ab","ac","ad"​​​​​​。
例如，表达式 {a{b,c}}{{d,e}f{g,h}} 可以代换为 {ab,ac}{dfg,dfh,efg,efh}，
表示字符串 "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"。
给出表示基于给定语法规则的表达式 expression，返回它所表示的所有字符串组成的有序列表。
假如你希望以「集合」的概念了解此题，也可以通过点击 “显示英文描述” 获取详情。

示例 1： 输入："{a,b}{c{d,e}}"            输出：["acd","ace","bcd","bce"]
示例 2： 输入："{{a,z}, a{b,c}, {ab,z}}"  输出：["a","ab","ac","z"]
解释：输出中 不应 出现重复的组合结果。

提示：  1 <= expression.length <= 50    expression[i] 由 '{'，'}'，',' 或小写英文字母组成
给出的表达式 expression 用以表示一组基于题目描述中语法构造的字符串
*/

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        if(expression[0] != '{') expression = '{' + expression + '}';
        auto tem = calc(expression, 0, expression.size()-1);
        return vector<string>(tem.begin(), tem.end());
    }
    set<string> calc(string& s, int l, int r){
        set<string> res, cur;
        if(l > r) return res;
        int t1 = pro(s, l, r);
        // 没有并列括号时
        if(t1 == r){
            int m = 0, t = l+1;
            for(int i = l; i <= r; i++){
                if(s[i] == '{') m++;
                if(s[i] == '}') m--;
                // 第一层里的括号
                if(s[i] == ',' && m == 1){
                    cur = calc(s, t, i-1);
                    res.insert(cur.begin(), cur.end());
                    t = i+1;
                }
            }
            cur = calc(s, t, r-1);
            res.insert(cur.begin(), cur.end());
            return res;
        }
        res.insert("");
        for(int i = l; i<=r; i++){
            if(s[i] == ',') continue;
            if(s[i] == '{') {
                int t = pro(s, i, r);
                cur = calc(s, i, t);
                set<string> tem;
                for(auto re:res)
                    for(auto it:cur)
                        tem.insert(re+it);
                swap(res, tem);
                i = t;
            }else{
                set<string> tem;
                for(auto it: res)
                    tem.insert(it+s[i]);
                swap(tem, res);
            }
        }
        return res;
    }
    // m 为 { 时， 找所对应的 }
    int pro(string& s, int m, int n){
        if(s[m] != '{') return -1;
        int d = 1, t = m+1;
        while(t <= n && d != 0){
            if(s[t] == '{') d++;
            if(s[t] == '}') d--;
            t++;
        }
        return t-1;
    }
    /*
    // 大佬写的 dfs 版本
    vector<string> braceExpansionII(string expression) {
        int L = -1;
        auto tem = dfs(expression, L);
        return vector<string>(tem.begin(), tem.end());
    }
    set<string> dfs(string& s, int &L){
        set<string> res;
        set<string> cur{""};
        // 每一步都会挪到下一步
        while(++L < s.size()) {
            // 原字符串中会有空格
            if(s[L] == ' ') continue;
            // 当前为 左括号时，需要将当前的字符串数组乘以后面得到的字符串数组
            if(s[L] == '{') cur = mul(cur, dfs(s, L));
            else if(s[L] == ',') res = add(res, cur), cur = {""};
            else if(s[L] == '}') { res = add(res, cur); return res; }
            else cur = append(cur, s[L]);
        }
        res = add(res, cur);
        return res;
    }
    set<string> mul(set<string> a, set<string> b){
        set<string> res;
        for(auto i:a) for(auto j:b) res.insert(i+j);
        return res;
    }
    set<string> add(set<string> a, set<string> b){
        for(auto i:b) a.insert(i);
        return a;
    }
    set<string> append(set<string> a, char c){
        set<string> res;
        for(auto it:a) it.push_back(c), res.insert(it);
        return res;
    }
    */
};

int main(){
    vector<string> arr = Solution().braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    // vector<string> arr = Solution().braceExpansionII("{a,b}{c{d,e}}");
    for(auto it:arr) cout<<it<<' '; cout<<endl;
    return 0;
}
