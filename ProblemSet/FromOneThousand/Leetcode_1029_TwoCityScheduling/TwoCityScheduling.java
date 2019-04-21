package Leetcode_1029_TwoCityScheduling;

import java.util.Comparator;
import java.util.PriorityQueue;

/*
	公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。	
	返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
		
	示例：	
		输入：[[10,20],[30,200],[400,50],[30,20]]
		输出：110
		解释：
		第一个人去 A 市，费用为 10。
		第二个人去 A 市，费用为 30。
		第三个人去 B 市，费用为 50。
		第四个人去 B 市，费用为 20。	
		最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。	 
	
	提示：	
		1 <= costs.length <= 100
		costs.length 为偶数
		1 <= costs[i][0], costs[i][1] <= 1000
 */

//1029. 两地调度
public class TwoCityScheduling {
	public int twoCitySchedCost(int[][] costs) {
		PriorityQueue<Integer> queueA = new PriorityQueue<>(new MyComparator());
		PriorityQueue<Integer> queueB = new PriorityQueue<>(new MyComparator());
		
		int sum = 0;		
		for (int i = 0; i < costs.length; i++) {
			if (costs[i][0] - costs[i][1] > 0) {
				//去B
				queueB.add(Math.abs(costs[i][0]-costs[i][1]));
			} else {
				//去A
				queueA.add(Math.abs(costs[i][0]-costs[i][1]));
			}
			sum+=Math.min(costs[i][0],costs[i][1]);
		}
		while(queueA.size()>costs.length/2) {
			sum+=queueA.poll();
		}
		while(queueB.size()>costs.length/2) {
			sum+=queueB.poll();
		}
		return sum;
	}
}

class MyComparator implements Comparator {

	@Override
	public int compare(Object o1, Object o2) {
		Integer arr1 = (Integer) o1;
		Integer arr2 = (Integer) o2;
		return arr1 - arr2;
	}

}