package Leetcode_495_TeemoAttacking;

/*
	在《英雄联盟》的世界中，有一个叫“提莫”的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。
	现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。
	
	你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。
	
	示例1:
		输入: [1,4], 2
		输出: 4
		原因: 在第1秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持2秒钟，直到第2秒钟结束。
		在第4秒开始时，提莫再次攻击艾希，使得艾希获得另外2秒的中毒时间。
		所以最终输出4秒。
	
	示例2:
		输入: [1,2], 2
		输出: 3
		原因: 在第1秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持2秒钟，直到第2秒钟结束。
		但是在第2秒开始时，提莫再次攻击了已经处于中毒状态的艾希。
		由于中毒状态不可叠加，提莫在第2秒开始时的这次攻击会在第3秒钟结束。
		所以最终输出3。
	
	注意：
		你可以假定时间序列数组的总长度不超过10000。
		你可以假定提莫攻击时间序列中的数字和提莫攻击的中毒持续时间都是非负整数，并且不超过10,000,000。
*/
public class TeemoAttacking {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

	// 495. 提莫攻击
	public int findPoisonedDuration(int[] timeSeries, int duration) {
		//空数组
		if(timeSeries.length==0) {
			return 0;
		}
		// [i] - [i-1] 和duration 的最小值
		int sum = 0;
		for (int i = 1; i < timeSeries.length; i++) {
			sum += Math.min(timeSeries[i] - timeSeries[i - 1], duration);
		}
		sum += duration;
		return sum;
	}

}
