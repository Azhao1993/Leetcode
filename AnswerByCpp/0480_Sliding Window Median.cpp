#include<bits\stdc++.h>
using namespace std;
/*
480. 滑动窗口中位数

中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如： [2,3,4]，中位数是 3      [2,3]，中位数是 (2 + 3) / 2 = 2.5
给出一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口移动 1 位。
你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

例如： 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

提示： 假设k是合法的，即：k 始终小于输入的非空数组的元素个数.
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        if(k == 0 || nums.size() == 0) return res;
        multiset<int> win(nums.begin(), nums.begin()+k);
        auto mid = next(win.begin(), k/2);
        for(int i=k; ; i++){
            // 偶数往前移一格，奇数不变
            res.push_back(*mid/2.0 + *prev(mid, 1-k%2)/2.0);
            if(i == nums.size()) return res;
            win.insert(nums[i]);
            if(nums[i] < *mid) mid--;
            if(nums[i-k] <= *mid) mid++;
            // 通过 lower_bound 来获取位置
            win.erase(win.lower_bound(nums[i-k]));
        }
        return res;
    }
        /*
        Node* dummyNode = new Node(-1e9);
        Node* mid = nullptr;
        dummyNode->next = dummyNode->pre = dummyNode;
        // 防止有重复的值
        unordered_map<int, vector<Node*>> hashMap;

        vector<int> tem(nums.begin(), nums.begin()+k);
        sort(tem.begin(), tem.end());
        for(int i=0; i<k; i++){
            Node* cur = new Node(tem[i]);
            if(i == k/2) mid = cur;
            addNode(cur, dummyNode);
            hashMap[tem[i]].push_back(cur);
        }
        for(int i=k; i<nums.size(); i++){
            if(k%2 == 1) res.push_back(mid->val);
            else res.push_back(mid->val/2.0 + mid->pre->val/2.0);
            // 判断增删元素的位置
            int num = 0;
            Node* dele = hashMap[nums[i-k]].back();
            hashMap[nums[i-k]].pop_back();
            if( dele->val > mid->val ) num++;
            else {
                num--;
                if(dele->val == mid->val) mid = mid->pre;
            }
            dele->pre->next = dele->next;
            dele->next->pre = dele->pre;
            delete dele;

            Node* add = new Node(nums[i]);
            Node* cur = mid;
            if( add->val >= mid->val || mid == dummyNode){
                num--;
                while(add->val >= cur->val && cur != dummyNode)
                    cur = cur->next;
            } else {
                num++;
                while(cur->val > add->val && cur != dummyNode)
                    cur = cur->pre;
                cur = cur->next;
            }
            addNode(add, cur);
            hashMap[nums[i]].push_back(add);

            // 右边删除一个  左边加了一个
            if(num == 2) mid = mid->pre;
            // 右边加了一个  左边减了一个
            if(num == -2) mid = mid->next;
        }

        if(k%2 == 1) res.push_back(mid->val);
        else res.push_back(mid->val/2.0 + mid->pre->val/2.0);

        return res;  
    }
    struct Node{
        int val;
        Node *pre;
        Node *next;
        Node(int i) : val(i), pre(nullptr), next(nullptr) {};
    };
    void addNode(Node* fir, Node* sec){
        fir->next = sec;
        fir->pre = sec->pre;
        sec->pre->next = fir;
        sec->pre = fir;
    }
    */
};

int main(){
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<double> res = Solution().medianSlidingWindow(nums, 3);
    for(auto& it:res) cout<<it<<' '; cout<<endl;
    return 0;
}