package Leetcode_374_GuessNumberHigherorLower;

import java.util.Scanner;

/*
	我们正在玩一个猜数字游戏。 游戏规则如下：
	我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
	每次你猜错了，我会告诉你这个数字是大了还是小了。
	你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
		-1 : 结果比较小，猜大了
		 1 : 结果比较大。猜小了
		 0 : 恭喜！猜对了！
	示例 :
		输入: n = 10, pick = 6
		输出: 6
*/
/* 
	The guess API is defined in the parent class GuessGame.
	@param num, your guess
	@return -1 if my number is lower, 1 if my number is higher, otherwise return 0
   	int guess(int num); 
*/
public class GuessNumberHigherorLower {	
	
    public int guessNumber(int n) {
        int left = 1;
        int right = n;
        int mid = 0;;
        while(left <=right) {
        	//int 类型溢出
        	//mid = (left +right)/2;
        	mid = left + (right-left)/2;
        	if(guess(mid)==0) {
        		//我猜的刚好
        		return mid;
        	}else if(guess(mid)>0) {
        		//我猜mid小了
        		left = mid+1;
        	}else {
        		//我猜mid大了
        		right = mid-1;
        	}
        }
        return mid;
    }
    //预先定义好的接口 guess(int num)
    public int guess(int num) {
    	//要猜的数
    	int result = 99;
    	//猜大了，返回-1
    	if(num>result) {
    		return -1;
    	}
    	if(num<result) {
    		return 1;
    	}
    	return 0;
    }
    
}
