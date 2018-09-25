package Leetcode_605_CanPlaceFlowers;

/*
	假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
	给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
	
	示例 1:	
		输入: flowerbed = [1,0,0,0,1], n = 1
		输出: True
		
	示例 2:	
		输入: flowerbed = [1,0,0,0,1], n = 2
		输出: False
	
	注意:	
		数组内已种好的花不会违反种植规则。
		输入的数组长度范围为 [1, 20000]。
		n 是非负整数，且不会超过输入数组的大小。
*/
public class CanPlaceFlowers {
	public boolean canPlaceFlowers(int[] flowerbed, int n) {
        // 获取花坛的大小
		int length = flowerbed.length;
		// 定义空花盆的个数
		int count = 0;

		int sum = 0;

		// 遍历判断
        
		for (int i = 0; i < length; i++) {
			
			// 统计0的个数
			if (flowerbed[i] == 1) {
			    //count--;
				sum +=count / 2 ;
				i++;
				count=0;
			} else {
				count++;
			}
		}
		sum += (count+1)/2;
		if(sum>=n) {
			return true;
		}
		return false;
	}
}
