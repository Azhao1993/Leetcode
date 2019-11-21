package Leetcode_367_ValidPerfectSquare;

/*
	给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
	
	说明：不要使用任何内置的库函数，如  sqrt。
	
	示例 1：	
		输入：16
		输出：True
	示例 2：	
		输入：14
		输出：False
*/
public class ValidPerfectSquare {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValidPerfectSquare vps = new ValidPerfectSquare();
		int num = 5;		
		//System.out.println(1073697800*1073697800);
		System.out.println(vps.isPerfectSquare(num));
	}

	// 367.有效的完全平方数
	public boolean isPerfectSquare(int num) {
		if (num == 1) {
			return true;
		}
		if (num <= 0) {
			return false;
		}
		// 二分查找
		int left = 1;
		int right = num;
		while (left+1 < right) {			
			int mid = left + (right - left) / 2;
			System.out.println("left:"+left+",right:"+right+",mid:"+mid);
			if(num/mid>mid) {
				left = mid;
			}else {
				right = mid;
			}
			//System.out.println("left2:"+left+",right2:"+right+",mid2:"+mid);
		}
		if((left*left==num)||(right*right==num)) {
			return true;
		}		
		return false;
	}

}
