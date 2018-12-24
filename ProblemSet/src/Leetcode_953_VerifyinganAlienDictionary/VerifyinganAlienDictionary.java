package Leetcode_953_VerifyinganAlienDictionary;

/*
	某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。	
	给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
	
	 
	
	示例 1：	
		输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
		输出：true
		解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
	
	示例 2：	
		输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
		输出：false
		解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
	
	示例 3：	
		输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
		输出：false
		解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
	 
	
	提示：	
		1 <= words.length <= 100
		1 <= words[i].length <= 20
		order.length == 26
		在 words[i] 和 order 中的所有字符都是英文小写字母。
 */
public class VerifyinganAlienDictionary {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] words = { "word", "world", "row" };
		String order = "worldabcefghijkmnpqstuvxyz";
		VerifyinganAlienDictionary vad = new VerifyinganAlienDictionary();
		vad.isAlienSorted(words, order);
	}

	// 953. 验证外星语词典
	public boolean isAlienSorted(String[] words, String order) {
		int[] map = orderToMap(order);
		// 遍历单词数组
		for (int i = 1; i < words.length; i++) {
			if (!compareTo(words[i - 1], words[i], map)) {
				return false;
			}
		}
		return true;

	}

	// 比较两个单词
	private boolean compareTo(String string, String string2, int[] map) {
		int length1 = string.length();
		int length2 = string2.length();
		int minlength = Math.min(length1, length2);
		for (int i = 0; i < minlength; i++) {
			int temp1 = map[string.charAt(i) - 'a'];
			int temp2 = map[string2.charAt(i) - 'a'];
			if (temp1 > temp2) {
				return false;
			} else if (temp1 < temp2) {
				return true;
			}
		}
		if (length1 > length2) {
			return false;
		}
		return true;
	}

	// 将order转换成map
	private int[] orderToMap(String order) {
		int[] map = new int[26];
		// 将order存入字典
		for (int i = 0; i < order.length(); i++) {
			int temp = order.charAt(i) - 'a';
			map[temp] = i;
		}
		return map;
	}

}
