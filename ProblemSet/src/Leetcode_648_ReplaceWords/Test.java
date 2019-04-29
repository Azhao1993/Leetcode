package Leetcode_648_ReplaceWords;

import java.util.Arrays;
import java.util.List;

public class Test {

	public static void main(String[] args) {
		String[] str ={ "cat", "bat", "rat" };
		List<String> dict =  Arrays.asList(str);
		String sent = "the cattle was rattled by the battery";
		ReplaceWords rw = new ReplaceWords();
		rw.replaceWords(dict, sent);

	}

}
