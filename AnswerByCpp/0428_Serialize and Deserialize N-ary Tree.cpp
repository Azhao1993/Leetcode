#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
428. 序列化和反序列化 N 叉树

序列化是指将一个数据结构转化为位序列的过程，因此可以将其存储在文件中或内存缓冲区中，
以便稍后在相同或不同的计算机环境中恢复结构。
设计一个序列化和反序列化 N 叉树的算法。一个 N 叉树是指每个节点都有不超过 N 个孩子节点的有根树。
序列化 / 反序列化算法的算法实现没有限制。
你只需要保证 N 叉树可以被序列化为一个字符串并且该字符串可以被反序列化成原树结构即可。
例如，你需要序列化下面的 3-叉 树。
为 [1 [3[5 6] 2 4]]。你不需要以这种形式完成，你可以自己创造和实现不同的方法。

注意： N 的范围在 [1, 1000]
不要使用类成员 / 全局变量 / 静态变量来存储状态。你的序列化和反序列化算法应是无状态的。
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        string res = to_string(root->val) + "[";
        for (auto &it : root->children) res += serialize(it);
        res += "]";
        return  res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        // 1[3[5[],6[]],2[],4[]]
        string val;
        Node* head = nullptr;
        stack<Node*> sta;
        for (int i=0; i<data.size(); i++) {
            char ch = data[i];
            if (ch == '[') {
                Node* node = new Node(stoi(val));
                if (head == nullptr) head = node;
                sta.push(node);
                val = "";
            } else if (ch == ']') {
                Node* node = sta.top();
                sta.pop();
                if (!sta.empty()) sta.top()->children.push_back(node);
            } else val += ch;
        }
        
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
