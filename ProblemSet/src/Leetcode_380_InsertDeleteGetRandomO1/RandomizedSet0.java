package Leetcode_380_InsertDeleteGetRandomO1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

//75ms
class RandomizedSet0 {
	Map<Integer, Integer> map;
	List<Integer> list;
	int size = 0;

	/** Initialize your data structure here. */
	public RandomizedSet0() {
		map = new HashMap<Integer, Integer>();
		list = new ArrayList<Integer>();
		this.size = 0;

	}

	/**
	 * Inserts a value to the set. Returns true if the set did not already contain
	 * the specified element.
	 */
	public boolean insert(int val) {
		if (map.containsKey(val)) {
			return false;
		} else {
			list.add(size, val);
			map.put(val, size++);
			return true;
		}
	}

	/**
	 * Removes a value from the set. Returns true if the set contained the specified
	 * element.
	 */
	public boolean remove(int val) {
		if (!map.containsKey(val)) {
			return false;
		} else if (size == 0) {
			map.remove(val);

		} else {
			int tailKey = list.get(size - 1);
			map.put(tailKey, map.get(val));
			list.set(map.get(val), tailKey);
			size--;
			map.remove(val);

		}
		return true;
	}

	/** Get a random element from the set. */
	public int getRandom() {
		Random rd = new Random();
		return list.get(rd.nextInt(size));
	}
}