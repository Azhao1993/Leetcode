#include<iostream>
#include<vector>
#include<map>
#include<float.h>
using namespace std;
/*
149. 直线上最多的点数

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    int gcd(int x,int y){
        return (y==0) ? x:gcd(y,x%y);
    }
    int maxPoints(vector<Point>& points) {
        int maxValue = 0;
        if(points.size()<3)return points.size();

        for(int i=0;i<points.size();i++){
            map<pair<int,int>,int> cnt;

            int samePoint = 1;
            for(int j=i+1;j<points.size();j++){
                if(points[i].x==points[j].x && points[i].y == points[j].y){
                    samePoint++;
                    continue;
                }
                // 为防止精度出错，通过最大公约数来表示斜率。（8,4）→（2,1）
                int dx = points[i].x-points[j].x;
                int dy = points[i].y-points[j].y;
                int dvs = gcd(dx,dy);

                cnt[make_pair(dx/dvs,dy/dvs)]++;
                //cnt[{dx/dvs,dy/dvs}]++;
            }
            for(auto j:cnt)
                if(j.second+samePoint >= maxValue)maxValue = j.second+samePoint;
            if(samePoint>maxValue)maxValue = samePoint;
        }
        return maxValue;
    }
};

int main(){
    //[[0,0],[94911151,94911150],[94911152,94911151]]
    double num1 =1.0*(0-94911151)/(0-94911150);
    double num2 =1.0*(94911152)/(94911151);
    cout<<num1<<endl<<num2<<endl;
    cout<<FLT_MAX<<endl;
    return 0;
}
