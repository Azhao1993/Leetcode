package Leetcode_443_StringCompression;

/*
	给定一组字符，使用原地算法将其压缩。
	压缩后的长度必须始终小于或等于原数组长度。
	数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
	
	在完成原地修改输入数组后，返回数组的新长度。
	
	进阶：
		你能否仅使用O(1) 空间解决问题？
	
	示例 1：
		输入：
			["a","a","b","b","c","c","c"]
		输出：
			返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
	说明：
		"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
	
	示例 2：
		输入：
			["a"]
		输出：
			返回1，输入数组的前1个字符应该是：["a"]
	说明：
		没有任何字符串被替代。、
	
	示例 3：	
		输入：
			["a","b","b","b","b","b","b","b","b","b","b","b","b"]	
		输出：
			返回4，输入数组的前4个字符应该是：["a","b","1","2"]。	
	说明：
		由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
		注意每个数字在数组中都有它自己的位置。
	注意：	
		所有字符都有一个ASCII值在[35, 126]区间内。
		1 <= len(chars) <= 1000。
*/
public class StringCompression {

	public static void main(String[] args) {
		StringCompression sc = new StringCompression();
		char[] chars = String.valueOf("aabbccc").toCharArray();
		int length = sc.compress(chars);		
		System.out.println(String.copyValueOf(chars));
		System.out.println(length);
	}

	// 443.压缩字符串
	public int compress(char[] chars) {
		//双指针，index在前，i在后
		//index为新数组的指针,i是原数组的指针
		int index = 0;
		//长度小于2，返回长度
		if(chars.length<2) {
			return chars.length;
		}
		//遍历原数组
		for(int i = 0;i<chars.length;) {
			//单字符计次
			int count = 1;
			//新数组覆盖原数组
			chars[index++] = chars[i++];
			//判断是否重复
			while((i<chars.length)&&(chars[i]==chars[i-1])) {
				//如果i-1和i相等，计次
				count++;
				//原数组指针后移
				i++;
			}
			//出现超过1次添加次数
			if(count>1) {
				//将次数存入字符串数组
				char[] chs = String.valueOf(count).toCharArray();
				for(int j = 0;j<chs.length;j++) {
					//存入数组并后移
					chars[index++] = chs[j];
				}
			}			
		}
		//返回新数组长度
		return index;
	}

}
