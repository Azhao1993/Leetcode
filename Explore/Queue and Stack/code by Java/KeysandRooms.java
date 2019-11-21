package Leetcode_841_KeysandRooms;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

/*
	有 N 个房间，开始时你位于 0 号房间。
	每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。
	
	在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 
	钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
	
	最初，除 0 号房间外的其余所有房间都被锁住。	
	你可以自由地在房间之间来回走动。	
	如果能进入每个房间返回 true，否则返回 false。
	
	示例 1：	
		输入: [[1],[2],[3],[]]
		输出: true
	解释:  
		我们从 0 号房间开始，拿到钥匙 1。
		之后我们去 1 号房间，拿到钥匙 2。
		然后我们去 2 号房间，拿到钥匙 3。
		最后我们去了 3 号房间。
		由于我们能够进入每个房间，我们返回 true。
		
	示例 2：	
		输入：[[1,3],[3,0,1],[2],[0]]
		输出：false
	解释：我们不能进入 2 号房间。
	
	提示：	
		1.1 <= rooms.length <= 1000
		2.0 <= rooms[i].length <= 1000
		3.所有房间中的钥匙数量总计不超过 3000。
 */
public class KeysandRooms {
	// 841. 钥匙和房间
	public boolean canVisitAllRooms(List<List<Integer>> rooms) {
		if (rooms.size() == 1) {
			return true;
		}
		boolean[] roomIsOpen = new boolean[rooms.size()];
		Set<Integer> keySet = new HashSet<Integer>();
		// 队列+BFS
		Queue<Integer> keyQueue = new LinkedList<Integer>();
		for (int key : rooms.get(0)) {
			keyQueue.add(key);
			keySet.add(key);
			roomIsOpen[0] = true;
		}
		while (!keyQueue.isEmpty()) {
			int curKey = keyQueue.poll();
			// 拿钥匙开门
			if (!roomIsOpen[curKey]) {
				List<Integer> curRoom = rooms.get(curKey);
				roomIsOpen[curKey] = true;
				// 开门取钥匙
				for (int keyTemp : curRoom) {
					if (keySet.contains(keyTemp)) {
						continue;
					} else {
						keySet.add(keyTemp);
						keyQueue.offer(keyTemp);
					}
				}
			} else {
				continue;
			}
		}

		for (boolean roomisopen : roomIsOpen) {
			if (!roomisopen) {
				return false;
			}
		}
		return true;
	}

	// 4ms
	public boolean canVisitAllRooms0(List<List<Integer>> rooms) {
		/* DFS */
		int size = rooms.size();
		boolean[] visited = new boolean[size];
		dfsVisit(rooms, 0, visited);
		for (int i = 0; i < size; ++i) {
			if (!visited[i])
				return false;
		}
		return true;
	}

	private void dfsVisit(List<List<Integer>> rooms, int in, boolean[] visited) {
		// 如果第in房间进去了，则返回。否则，进入
		if (visited[in]) {
			return;
		}
		// 房间已打开
		visited[in] = true;
		// 取房间中的钥匙
		for (int temp : rooms.get(in)) {
			// 取钥匙开门
			if (!visited[temp]) {
				dfsVisit(rooms, temp, visited);
			}
		}
	}
}
