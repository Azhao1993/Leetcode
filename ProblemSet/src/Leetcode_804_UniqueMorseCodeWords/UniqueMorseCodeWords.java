package Leetcode_804_UniqueMorseCodeWords;

/*
	国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应 "-...", "c" 对应 "-.-.", 等等。
	
	为了方便，所有26个英文字母对应摩尔斯密码表如下：	
	[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
	给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." + "-..." + ".-"字符串的结合)。我们将这样一个连接过程称作单词翻译。
	返回我们可以获得所有词不同单词翻译的数量。
	
	例如:
		输入: words = ["gin", "zen", "gig", "msg"]
		输出: 2
	解释: 
		各单词翻译如下:
		"gin" -> "--...-."
		"zen" -> "--...-."
		"gig" -> "--...--."
		"msg" -> "--...--."
	
		共有 2 种不同翻译, "--...-." 和 "--...--.".
	 
	
	注意:	
		单词列表words 的长度不会超过 100。
		每个单词 words[i]的长度范围为 [1, 12]。
		每个单词 words[i]只包含小写字母。
 */
public class UniqueMorseCodeWords {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		UniqueMorseCodeWords umcw = new UniqueMorseCodeWords();
		String[] words = { "zocd", "gjkl", "hzqk", "hzgq", "gjkl" };
		umcw.uniqueMorseRepresentations(words);
	}

	// 804. 唯一摩尔斯密码词
	public int uniqueMorseRepresentations(String[] words) {
		String[] alphabet = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
				"--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		String[] result = new String[words.length];
		for (int i = 0; i < words.length; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < words[i].length(); j++) {
				char temp = words[i].charAt(j);
				sb.append(alphabet[temp - 'a']);
			}
			result[i] = sb.toString();
		}
		int count = 0;
		// 判断不同
		String temp = result[0];
		for (int i = 0; i < result.length; i++) {
			if (result[i] != null) {
				temp = result[i];
				count++;
			} else {
				continue;
			}
			int j = i + 1;
			while (j < result.length) {
				if (result[j] == null) {
					j++;
					continue;
				}
				if (result[j].equals(temp)) {
					result[j] = null;
				}
				j++;
			}

		}
		return count;

	}
}
