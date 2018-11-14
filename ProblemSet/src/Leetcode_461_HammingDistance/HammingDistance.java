package Leetcode_461_HammingDistance;
/*
	两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。	
	给出两个整数 x 和 y，计算它们之间的汉明距离。
	
	注意：
		0 ≤ x, y < 2^31.
	
	示例:	
		输入: x = 1, y = 4		
		输出: 2
		
		解释:
			1   (0 0 0 1)
			4   (0 1 0 0)
			       ↑   ↑		
		上面的箭头指出了对应二进制位不同的位置。
 */
public class HammingDistance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HammingDistance hd= new HammingDistance();
		hd.hammingDistance(1, 4);
	}
	//461. 汉明距离
    public int hammingDistance(int x, int y) {
    	//x^y:相同的为0,不同为1
    	int temp = x^y;
    	//计算temp中有多少个1
    	int count = 0;
    	while(temp>0) {
    		count += temp&1;
    		//右移1位
    		temp >>>= 1;    		
    	}
        return count;
    }

}
