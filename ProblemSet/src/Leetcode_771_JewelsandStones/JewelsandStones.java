package Leetcode_771_JewelsandStones;

/*
	给定字符串 J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 
	S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。	
	J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
	
	示例 1:	
		输入: J = "aA", S = "aAAbbbb"
		输出: 3
	
	示例 2:	
		输入: J = "z", S = "ZZ"
		输出: 0
	
	注意:	
		S 和 J 最多含有50个字母。
		J 中的字符不重复。
 */
public class JewelsandStones {
	public static void main(String[] args) {
		JewelsandStones js = new JewelsandStones();

	}

	// 771. 宝石与石头
	public int numJewelsInStones(String J, String S) {
		if ((J.length() == 0) || (J == null)) {
			return 0;
		}
		char[] jewels = J.toCharArray();
		int count = 0;
		for (int i = 0; i < jewels.length; i++) {
			for (int j = 0; j < S.length(); j++) {
				if (jewels[i] == S.charAt(j)) {
					count++;
				}
			}
		}
		return count;
	}

	// 9ms
	public int numJewelsInStones2(String J, String S) {
		// all ASCII letters from A to z represented as a boolean array
		boolean[] JArray = new boolean[58];
		//将珠宝放进字母表
		for (int i = 0; i < J.length(); i++) {
			JArray[J.charAt(i) - 'A'] = true;
		}
		int counter = 0;
		//遍历石头
		for (int i = 0; i < S.length(); i++) {
			//如果是珠宝,计数器++，如果不是，不变
			counter = (JArray[S.charAt(i) - 'A']) ? ++counter : counter;
		}
		return counter;
	}
}
