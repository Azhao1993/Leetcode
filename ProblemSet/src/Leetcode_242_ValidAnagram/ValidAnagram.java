package Leetcode_242_ValidAnagram;

/*
	给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
	
	示例 1:	
		输入: s = "anagram", t = "nagaram"
		输出: true
	
	示例 2:	
		输入: s = "rat", t = "car"
		输出: false
	
	说明:
		你可以假设字符串只包含小写字母。
	
	进阶:
		如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 */
public class ValidAnagram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 242. 有效的字母异位词
	public boolean isAnagram(String s, String t) {
		// 长度不等，不相为谋
		if (s.length() != t.length()) {
			return false;
		}
		// 类似哈希表
		int alphabet[] = new int[26];
		char[] sArr = s.toCharArray();
		char[] tArr = t.toCharArray();
		// 将第一个字符串存入字母表
		for (int i = 0; i < sArr.length; i++) {
			alphabet[sArr[i] - 'a']++;
		}
		// 将第二个字符串存入字母表
		for (int i = 0; i < tArr.length; i++) {
			alphabet[tArr[i] - 'a']--;
		}
		// 遍历找到结果
		for (int i = 0; i < alphabet.length; i++) {
			if (alphabet[i] != 0) {
				return false;
			}
		}
		return true;

	}

}
