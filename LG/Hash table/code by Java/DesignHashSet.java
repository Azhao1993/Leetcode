package Leetcode_705_DesignHashSet;

import java.util.LinkedList;
import java.util.List;

/*
	不使用任何内建的哈希表库设计一个哈希集合	
	具体地说，你的设计应该包含以下的功能	
		add(value)：向哈希集合中插入一个值。
		contains(value) ：返回哈希集合中是否存在这个值。
		remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
	
	示例:	
		MyHashSet hashSet = new MyHashSet();
		hashSet.add(1);         
		hashSet.add(2);         
		hashSet.contains(1);    // 返回 true
		hashSet.contains(3);    // 返回 false (未找到)
		hashSet.add(2);          
		hashSet.contains(2);    // 返回 true
		hashSet.remove(2);          
		hashSet.contains(2);    // 返回  false (已经被删除)
	
	注意：	
		所有的值都在 [1, 1000000]的范围内。
		操作的总数目在[1, 10000]范围内。
		不要使用内建的哈希集合库。
 */
//705. 设计哈希集合
//public class MyHashSet {
public class DesignHashSet {
	// 成员变量
	private boolean[] flag;
	
	/** Initialize your data structure here. */
	// 构造函数
	// public MyHashSet() {
	public DesignHashSet() {
		flag = new boolean[100000];
	}

	// 成员方法
	public void add(int key) {
		flag[key] = true;
	}

	public void remove(int key) {
		flag[key] = false;
	}

	/** Returns true if this set contains the specified element */
	public boolean contains(int key) {
		return flag[key];
	}
}

/**
 * Your MyHashSet object will be instantiated and called as such: MyHashSet obj
 * = new MyHashSet(); obj.add(key); obj.remove(key); boolean param_3 =
 * obj.contains(key);
 */
//79ms
class MyHashSet {

	// 二维数组
	// in worst case it will take size of 1000000
	int bucket = 1000, item = 1001;
	boolean[][] table;

	/** Initialize your data structure here. */
	public MyHashSet() {
		table = new boolean[bucket][];
	}

	// hash值
	public int hash(int i) {
		return i % bucket;
	}

	// i在桶的位置
	public int pos(int i) {
		return i / bucket;
	}

	public void add(int key) {
		int hash = hash(key);
		if (table[hash] == null)
			table[hash] = new boolean[item];
		table[hash][pos(key)] = true;
	}

	public void remove(int key) {
		int hash = hash(key);
		if (table[hash] != null)
			table[hash][pos(key)] = false;
	}

	/** Returns true if this set contains the specified element */
	public boolean contains(int key) {
		int hash = hash(key);
		return table[hash] != null && table[hash][pos(key)];
	}
}
