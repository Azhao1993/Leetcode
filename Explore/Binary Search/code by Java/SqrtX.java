package BinarySearch_069_SqrtX;
/*
	实现 int sqrt(int x) 函数。	
	计算并返回 x 的平方根，其中 x 是非负整数。	
	由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
	
	示例 1:	
		输入: 4
		输出: 2
	示例 2:	
		输入: 8
		输出: 2
		说明: 8 的平方根是 2.82842..., 
		     由于返回类型是整数，小数部分将被舍去。
*/
public class SqrtX {
	//69.x的平方根
	public int mySqrt(int x) {
		// 小于1
		if (x <= 1) {
			return 1;
		}
		// 0-x二分查找
		int left = 0;
		int right = x;	
		while (left < right) {
			int mid = (left + right) / 2;
			if(x/mid>=mid) {
				//mid太小了
				left = mid +1;
			}else{
				//mid太大了
				right = mid;
			}
		}
		return right-1;
	}
}
