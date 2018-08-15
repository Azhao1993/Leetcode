package Leetcode_171_ExcelSheetColumnNumber;
/*
	给定一个Excel表格中的列名称，返回其相应的列序号。
	
	例如，	
	    A -> 1
	    B -> 2
	    C -> 3
	    ...
	    Z -> 26
	    AA -> 27
	    AB -> 28 
	    ...
	    
	示例 1:		
		输入: "A"
		输出: 1
		
	示例 2:	
		输入: "AB"
		输出: 28
		
	示例 3:	
		输入: "ZY"
		输出: 701
*/
public class ExcelSheetColumnNumber {
	public int titleToNumber(String s) {
        //获取字符串的长度
		int length = s.length();
		int sum = 0;
		//遍历字符串
		for(int i = 0;i<length;i++) {
			int temp = s.charAt(i)-64;
			sum += Math.pow(26, length-1-i)*temp;
		}
		return sum;
		
    }
}
