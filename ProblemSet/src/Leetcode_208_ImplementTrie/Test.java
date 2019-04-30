package Leetcode_208_ImplementTrie;

/*


 */
public class Test {

	public static void main(String[] args) {
		Trie trie = new Trie();
		String[] op = { "insert", "insert", "insert", "insert", "insert", "insert", "search", "search", "search",
				"search", "search", "search", "search", "search", "search", "startsWith", "startsWith", "startsWith",
				"startsWith", "startsWith", "startsWith", "startsWith", "startsWith", "startsWith" };
		String[] words = { "app", "apple", "beer", "add", "jam", "rental", "apps", "app", "ad", "applepie", "rest",
				"jan", "rent", "beer", "jam", "apps", "app", "ad", "applepie", "rest", "jan", "rent", "beer", "jam" };

		String[] res = {null, null, null, null, null, null, "false", "true", "false", "false", "false", "false",
				"false", "true", "true", "false", "true", "true", "false", "false", "false", "true", "true", "true" };
		for (int i = 0; i < op.length; i++) {
			if (op[i].equals("insert")) {
				trie.insert(words[i]);
			} else if (op[i].equals("search")) {
				System.out.print("search:" +i+ ",");
				System.out.print(res[i] + ":");
				System.out.println(trie.search(words[i]));
			} else {
				System.out.print("startsWith:"+i + ",");
				System.out.print(res[i] + ":");
				System.out.println(trie.startsWith(words[i]));
			}

		}

	}

}
