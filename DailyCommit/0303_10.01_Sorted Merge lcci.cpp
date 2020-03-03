//
// Created by Azhao1993 on 2020/3/3.
//
/*
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorted-merge-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:

    // 提示：尝试从数组的末端向前端移动。
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            A = B;
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int curIndex = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[curIndex] = A[i];
                i--;
            } else {
                A[curIndex] = B[j];
                j--;
            }
            curIndex--;
        }
        if (i < 0) {
            while (j >= 0) {
                A[curIndex] = B[j];
                j--;
                curIndex--;
            }
        }
        return;
    }
};


