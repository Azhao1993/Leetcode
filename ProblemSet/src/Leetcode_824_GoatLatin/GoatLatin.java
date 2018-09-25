package Leetcode_824_GoatLatin;

/*
	给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。
	我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。
	
	山羊拉丁文的规则如下：
		如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
		例如，单词"apple"变为"applema"。
		
		如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
		例如，单词"goat"变为"oatgma"。
		
		根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
		例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
		返回将 S 转换为山羊拉丁文后的句子。
	
	示例 1:
		输入: "I speak Goat Latin"
		输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
	示例 2:
		输入: "The quick brown fox jumped over the lazy dog"
		输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/
public class GoatLatin {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GoatLatin gl = new GoatLatin();
		String s = "I speak Goat Latin";
		System.out.println(s);
		System.out.println("Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
		System.out.println(gl.toGoatLatin(s));

	}

	// 824. 山羊拉丁文
	public String toGoatLatin(String S) {
		// 单个单词判断
		StringBuffer buffer = new StringBuffer(S);
		StringBuffer result = new StringBuffer();
		// 截取单词的个数
		int count = 0;
		while (buffer.length() != 0) {
			// 空格分割单词，index空格的位置
			int index = buffer.indexOf(" ");
			// 单词的个数
			count++;
			// 截取第一个单词
			StringBuffer sb;
			if (index == -1) {
				sb = new StringBuffer(buffer.toString());
				buffer.delete(0, buffer.length());
			} else {
				sb = new StringBuffer(buffer.subSequence(0, index));
				buffer.delete(0, index + 1);
			}
			result.append(wordChange(sb, count));
		}

		return (result.toString().trim());

	}

	// 单词修改
	public StringBuffer wordChange(StringBuffer sb, int count) {
		StringBuffer result = new StringBuffer();
		// 判断是否是以元音开头
		char temp = sb.charAt(0);
		if ((temp != 'a') & (temp != 'A') & (temp != 'E') & (temp != 'e') & (temp != 'I') & (temp != 'i')
				& (temp != 'O') & (temp != 'o') & (temp != 'u') & (temp != 'U')) {
			sb.deleteCharAt(0);
			sb.append(temp);
		}

		result.append(sb).append("ma");
		for (int i = 0; i < count; i++) {
			result.append("a");
			if (i == count - 1) {
				result.append(" ");
			}
		}
		return result;
	}

}
