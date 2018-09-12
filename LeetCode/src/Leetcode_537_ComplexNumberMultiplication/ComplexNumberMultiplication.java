package Leetcode_537_ComplexNumberMultiplication;
/*
	给定两个表示复数的字符串。
	返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。
	
	示例 1:
		输入: "1+1i", "1+1i"
		输出: "0+2i"
	解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
	示例 2:
		输入: "1+-1i", "1+-1i"
		输出: "0+-2i"
	解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
*/
public class ComplexNumberMultiplication {

	//537.复数乘法
    public  String complexNumberMultiply(String a, String b) {
        //将a、b转成数组
    	String[] arr = a.split("\\+");
    	arr[1] = arr[1].substring(0, arr[1].length()-1);
    	String[] brr = b.split("\\+");//特殊字符需要转义
    	brr[1] = brr[1].substring(0, brr[1].length()-1);
    	//将字符串数组转成整形数组
    	int[] ant = {Integer.parseInt(arr[0]),Integer.parseInt(arr[1])};
    	int[] bnt = {Integer.parseInt(brr[0]),Integer.parseInt(brr[1])};
    	//乘法计算
    	int m = ant[0]*bnt[0]-ant[1]*bnt[1];
    	int n = ant[0]*bnt[1]+bnt[0]*ant[1];   
    	String result = m+"+"+n+"i";
    	return result;
    }

}
