#include <vector>
//
// Created by Azhao1993 on 2020/3/5.
//

using namespace std;
class Solution {
public:
    //有问题后面改
    vector<int> distributeCandies(int candies, int num_people) {
        int count = (1 + num_people) * num_people / 2;
        int x = 0;
        while ((1+x)*x/2*num_people*num_people+(x+1)*count <= candies){
            x++;
        }

        vector<int> res(num_people,0);
        for(int i = 0;i<num_people;i++){
            int curCandies=  (i+1)*(x+1)+(1+x)*x*num_people/2;
            candies -= curCandies;
            res[i] += curCandies;
        }
        x++;
        for(int i = 0;i<num_people;i++){
            int curCandies=  (i+1)+x*num_people;
            if(candies>=curCandies){
                res[i] += curCandies;
            }else{
                res[i] += candies;
                break;
            }
            candies-= curCandies;
        }
        return res;
    }

    //官方题解
    vector<int> distributeCandies2(int candies, int num_people) {
        int n = num_people;
        // how many people received complete gifts
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            // complete rows
            d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            // cols in the last row
            if (i < cols) d[i] += i + 1 + rows * n;
        }
        // remaining candies
        d[cols] += remaining;
        return d;
    }

};
int main(){
    Solution s;
    int candies = 7;
    int num_people = 4;
    s.distributeCandies(candies,num_people);
}
