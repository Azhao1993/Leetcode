package Leetcode_336_PalindromePairs;

import java.util.List;

public class Test {

	public static void main(String[] args) {
		PalindromePairs pp = new PalindromePairs();
		String[] words = { "a",  "" };
		for(List<Integer> list:pp.palindromePairs(words)) {
			System.out.println(list);
		}

	}

}
