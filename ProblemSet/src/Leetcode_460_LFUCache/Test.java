package Leetcode_460_LFUCache;

public class Test {
	public static void main(String[] args) {
		LFUCache lfu = new LFUCache(0);
		lfu.put(0, 0);
		lfu.get(0);
	}
}
