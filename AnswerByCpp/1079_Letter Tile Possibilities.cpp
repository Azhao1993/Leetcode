#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
1079. 活字印刷

你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

示例 1：   输入："AAB"        输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：   输入："AAABBC"     输出：188

提示：     1 <= tiles.length <= 7      tiles 由大写英文字母组成
*/

class Solution {
public:
	// AAB :  A; AA;AAB; AB;ABA;  B;BA;BAA;  8 次  
	int getNum(vector<int>& cnt, int num){
		if(num <= 1) return num;
		int res = 0;
		// 每一个字母只会进入一次
		for(auto &val : cnt)
			if(val > 0) // 当前组成的字母  所以 +1
				val--, res += getNum(cnt, num-1) + 1, val++;
			
		return res;
	}
    int numTilePossibilities(string tiles) {
    	vector<int> cnt(26, 0);
    	for(auto it:tiles) cnt[it-'A']++;
    	return getNum(cnt, tiles.size());
    	/*
        unordered_set<string> hash;
        // 先排序，再通过 next_permutation 来查看每种排列的情况
        // 通过 hash 去重
        sort(tiles.begin(), tiles.end());
        while(1){
            for(int i=0; i<tiles.size(); i++)
                hash.insert(tiles.substr(0, i+1));
            if(!next_permutation(tiles.begin(), tiles.end()))
                break;
        }
        return hash.size();
        */
    }
};

int main(){
    int res = Solution().numTilePossibilities("AAC");
    cout<<res<<endl;
    return 0;
}