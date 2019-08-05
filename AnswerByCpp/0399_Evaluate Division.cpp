#include <bits\stdc++.h>
using namespace std;
/*
399. 除法求值

给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。
根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :    给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: vector<pair<string, string>> equations, vector<double>& values, 
vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 
其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（
程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：
equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Floyd 算法，对于一个点作为中间一个点 i ,   n^2  更新每个点对 i 的取值
        int len = values.size(), ind = 0;
        vector<double> res;
        if(len == 0 || queries.size() == 0) return res;
        // 字符和下标的映射
        unordered_map<string, int> hashMap;
        vector<vector<double>> graph(2*len, vector<double>(2*len, 1e9));
        
        for(int i=0; i<len; i++){
            string str1 = equations[i][0], str2 = equations[i][1];
            if(hashMap.find(str1) == hashMap.end()) 
                hashMap[str1] = ind++;
            if(hashMap.find(str2) == hashMap.end()) 
                hashMap[str2] = ind++;
            graph[hashMap[str1]][hashMap[str2]] = values[i];
            graph[hashMap[str2]][hashMap[str1]] = 1/values[i];
            graph[hashMap[str1]][hashMap[str1]] = 1;
            graph[hashMap[str2]][hashMap[str2]] = 1;
        }
        // 更新两个等式传递的值， Floyd 算法
        for(int i=0; i<ind; i++)
            for(int j=0; j<ind; j++)
                for(int k=0; k<ind; k++)
                    if(graph[i][k] != 1e9 && graph[k][j] != 1e9 && graph[i][j] == 1e9)
                        graph[i][j] = graph[i][k]*graph[k][j];

        for(int i=0; i<queries.size(); i++){
            string str1 = queries[i][0], str2 = queries[i][1];
            if(hashMap.find(str1) == hashMap.end() || hashMap.find(str2) == hashMap.end())
                res.push_back(-1.0);
            else{
                double tem = graph[hashMap[str1]][hashMap[str2]];
                res.push_back( tem == 1e9 ? -1.0 : tem );
            }
        }
        return res;
    }
};

class Solution {
private:
    // 并查集的操作
    unordered_map<string, string> faMap;
    string getFa(string a){
        string fa = faMap[a];
        if(fa != a)
            fa = getFa(fa);
        faMap[a] = fa;
        return fa;
    }
    void merge(string a, string b){
        string fa = getFa(a), fb = getFa(b);
        if(fa == fb) return ;
        faMap[fb] = fa;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = values.size();
        vector<double> res;
        unordered_map<string, double> hashMap;

        // 先遍历有互相有关系的点
        // 初始化并查集， 并把有关系的点放到一个 hashMap 中，方便后序的遍历
        unordered_map<string, vector<int>> rel;
        for(int i=0; i<len; i++){
            if(faMap.find(equations[i][0]) == faMap.end()) 
                faMap[equations[i][0]] = equations[i][0];
            if(faMap.find(equations[i][1]) == faMap.end()) 
                faMap[equations[i][1]] = equations[i][1];
            merge(equations[i][0], equations[i][1]);
            rel[equations[i][0]].push_back(i);
            rel[equations[i][1]].push_back(i);
        }

        // BFS 遍历 ， 把同属于一个并查集的都先遍历一下
        vector<bool> used(len, false);
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            if(used[cur]) continue;
            used[cur] = true;
            string str1 = equations[cur][0], str2 = equations[cur][1];
            if(hashMap.find(str1) != hashMap.end())
                hashMap[str2] = hashMap[str1] / values[cur];
            else {
                if(hashMap.find(str2) == hashMap.end())
                    hashMap[str2] = 1.0;
                hashMap[str1] = hashMap[str2] * values[cur];
            }
            // 把和当前点有直接关系的都入队
            for(int i=0; i<rel[str1].size(); i++)
                if(!used[rel[str1][i]]) que.push(rel[str1][i]);
            for(int i=0; i<rel[str2].size(); i++)
                if(!used[rel[str2][i]]) que.push(rel[str2][i]);
            // 看看是否还有没有遍历到的节点
            if(que.empty()){
                int ind=0;
                while(ind < len && used[ind]) ind++;
                if(ind != len) que.push(ind); 
            }
        }

        for(int i=0; i<queries.size(); i++){
            string str1 = queries[i][0], str2 = queries[i][1];
            if(hashMap.find(str1) == hashMap.end() || 
                hashMap.find(str2) == hashMap.end() || getFa(str1) != getFa(str2))
                res.push_back(-1.0);
            else res.push_back(hashMap[str1] / hashMap[str2]);
        }
        return res;
    }
};

int main(){
    vector<vector<string>> equ{{"a", "b"}, {"b", "c"}};
    vector<double> val{2.0, 3.0};
    vector<vector<string>> que{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> arr = Solution().calcEquation(equ, val, que);
    for(auto& it:arr) cout<<it<<' '; cout<<endl;
    return 0;
}
