package Leetcode_211_AddandSearchWord;

public class Test {

	public static void main(String[] args) {
//		"addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
//		["at"],   ["and"],    ["an"],   ["add"], ["a"],   [".at"], ["bat"],  [".at"], ["an."],["a.d."], ["b."],  ["a.d"],  ["."]]
		WordDictionary wd = new WordDictionary();
		wd.addWord("bad");
		wd.addWord("dad");
		wd.addWord("mad");		
		System.out.println(wd.search("b.."));// -> true

	}

}
