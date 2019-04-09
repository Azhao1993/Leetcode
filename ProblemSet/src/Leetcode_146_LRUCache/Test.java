package Leetcode_146_LRUCache;

/*
	示例:	
		LRUCache cache = new LRUCache( 2 /* 缓存容量  );
		
		cache.put(1, 1);
		cache.put(2, 2);
		cache.get(1);       // 返回  1
		cache.put(3, 3);    // 该操作会使得密钥 2 作废
		cache.get(2);       // 返回 -1 (未找到)
		cache.put(4, 4);    // 该操作会使得密钥 1 作废
		cache.get(1);       // 返回 -1 (未找到)
		cache.get(3);       // 返回  3
		cache.get(4);       // 返回  4
		["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
 */
public class Test {
	public static void main(String[] args) {
		LRUCache lru = new LRUCache(0);
		String[] test = { "LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get" };
		int[][] value = { { 2, 0 }, { 1, 1 }, { 2, 2 }, { 1, 0 }, { 3, 3 }, { 2, 0 }, { 4, 4 }, { 1, 0 }, { 3, 0 },
				{ 4, 0 } };
		for (int i = 0; i < test.length; i++) {
			if (test[i].equals("LRUCache")) {
				lru = new LRUCache(value[i][0]);
				System.out.println("LRUCache cache = new LRUCache(" + value[i][0] + ")");
			}
			if (test[i].equals("put")) {
				lru.put(value[i][0], value[i][1]);
				System.out.println("put(" + value[i][0] + "," + value[i][1] + ")");
			}
			if (test[i].equals("get")) {
				lru.get(value[i][0]);
				System.out.println("get(" + value[i][0] + ")");
			}
		}
	}
}
