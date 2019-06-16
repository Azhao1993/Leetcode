package Leetcode_1088_ConfusingNumberII;
/*
	本题我们会将数字旋转 180° 来生成一个新的数字。
	比如 0、1、6、8、9 旋转 180° 以后，我们得到的新数字分别为 0、1、9、8、6。
	2、3、4、5、7 旋转 180° 后，是 无法 得到任何数字的。
	易混淆数（Confusing Number）指的是一个数字在整体旋转 180° 以后，能够得到一个和原来 不同 的数，且新数字的每一位都应该是有效的。（请注意，旋转后得到的新数字可能大于原数字）
	给出正整数 N，请你返回 1 到 N 之间易混淆数字的数量。 
	
	示例 1：
		输入：20
		输出：6
		解释：
			易混淆数为 [6,9,10,16,18,19]。
			6 转换为 9
			9 转换为 6
			10 转换为 01 也就是 1
			16 转换为 91
			18 转换为 81
			19 转换为 61
	
	示例 2：
		输入：100
		输出：19
		解释：
		易混淆数为 [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100]。
 */

//1088.易混淆数 II
public class ConfusingNumberII {
	public static void main(String[] args) {
		System.out.println(new ConfusingNumberII().confusingNumberII(100));
	}	
	
    public int confusingNumberII(int N) {
        int num = 1;
        int count = 0;
        while(num<=N) {
        	if(isConfusing(num)) {        		
        		count++;        		
        	}
        	num = nextNum(num);
        }
        return count;
    }
    /**
     * 下一个由0,1,6,8,9组成的数
     * @param num
     * @return
     */
	private int nextNum(int num) {		
		if(num%10==0) {
			num+=1;
		}else if(num%10==1) {
			num+=5;
		}else if(num%10==6) {
			num+=2;
		}else if(num%10==8) {
			num+=1;
		}else {			
            num++;
            int temp = num;
            int multiple = 1;
            while (temp > 0) {
            	//判断各个位是不是由0,1,6,8,9组成
                while (!isValid(temp % 10)) {
                	//当前位不是由0,1,6,8,9
                    temp++;
                    num += multiple;
                }
                temp /= 10;
                multiple *= 10;
            }
			
		}
		return num;
	}

	private boolean isConfusing(int num) {
		String str1 = String.valueOf(num);
		char[] s1 = str1.toCharArray();
		char[] s2 = new char[s1.length];
		for(int i = 0;i<s1.length;i++) {			
			if(s1[i]=='6') {
				s2[s1.length-1-i] = '9';
			}else if(s1[i]=='9') {
				s2[s1.length-1-i] = '6';
			}else {
				s2[s1.length-1-i] = s1[i];
			}			
		}
		return !str1.equals(String.valueOf(s2));
		
	}
	private boolean isValid(int c) {
		return c==0||c==1||c==6||c==8||c==9;
	}
}
