package Leetcode_441_ArrangingCoins;
/*
	你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。	
	给定一个数字 n，找出可形成完整阶梯行的总行数。	
	n 是一个非负整数，并且在32位有符号整型的范围内。
	
	示例 1:	
		n = 5
	
		硬币可排列成以下几行:
		¤
		¤ ¤
		¤ ¤
		
		因为第三行不完整，所以返回2.
		
	示例 2:	
		n = 8
		
		硬币可排列成以下几行:
		¤
		¤ ¤
		¤ ¤ ¤
		¤ ¤
	
		因为第四行不完整，所以返回3.
 */
public class ArrangingCoins {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrangingCoins ac = new ArrangingCoins();
		System.out.println(ac.arrangeCoins(2));
	}
	//441. 排列硬币
	//二分查找
	public int arrangeCoins(int n) {
		//0或1返回n
		if(n<=1) {
			return n;			
		}
		//n>=2时
		long left = 0;
		long right = n;
		while(left<=right) {
			long mid = left+(right-left)/2;
			long sum = (1+mid)*mid/2;			
			if(sum<=n) {
				left = mid+1;
			}else {
				right = mid-1;
			}
		}		
		return (int)right;
	}
	//直接计算
    public int arrangeCoins2(int n) {    	
    	int i = 1;
        while(n>0) {
        	n -= i;
        	if(n<0) {
        		return i-1;
        	}else if(n==0) {
        		return i;
        	}
        	i++;        	
        }
        return i-1;
    }

}
