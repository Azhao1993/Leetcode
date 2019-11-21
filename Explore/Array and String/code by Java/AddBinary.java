package Leetcode_067_AddBinary;
/*
	给定两个二进制字符串，返回他们的和（用二进制表示）。
	
	输入为非空字符串且只包含数字 1 和 0。
	
		示例 1:		
			输入: a = "11", b = "1"
			输出: "100"
			
		示例 2:		
			输入: a = "1010", b = "1011"
			输出: "10101"
 */
public class AddBinary {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AddBinary ab = new AddBinary();
		System.out.println(ab.addBinary("1010", "1011"));
	}
	
	//67. 二进制求和
    public String addBinary(String a, String b) {
    	
    	int maxlength = Math.max(a.length(), b.length());
    	int minlength = Math.min(a.length(), b.length());
    	//补齐零
    	StringBuilder sb = new StringBuilder();
    	for(int i = 0;i<maxlength-minlength;i++) {
    		sb.append('0');
    	}
    	
    	if(a.length()>b.length()) {
    		//a长b短,补齐b
    		sb.append(b);
    		b = sb.toString();
    	}else {
    		//b长a短,补齐a
    		sb.append(a);
    		a = sb.toString();
    	}
    	
        //计算
    	sb = new StringBuilder();    	
    	int flag= 0;//进位符
    	for(int i = maxlength-1;i>=0;i--) {    	
    		int temp = a.charAt(i)+b.charAt(i)-96+flag;    		
    		if(temp>=2) {
    			temp -= 2;
    			flag = 1;
    		}else {
    			flag = 0;
    		}    		
    		sb.insert(0,temp);
    		if((i==0)&&(flag==1)) {
    			sb.insert(0, 1);
    		}
    		
    	}
    	return sb.toString();
    }

}
