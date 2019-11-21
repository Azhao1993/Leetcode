package Leetcode_075_SortColors;
/*
	给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
	
	此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
	
	注意:
		不能使用代码库中的排序函数来解决这道题。
	
	示例:	
		输入: [2,0,2,1,1,0]
		输出: [0,0,1,1,2,2]
	进阶：	
		一个直观的解决方案是使用计数排序的两趟扫描算法。
		首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
		你能想出一个仅使用常数空间的一趟扫描算法吗？
 */
public class SortColors {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		SortColors sc = new SortColors();
		int[] nums = {2,0,2,1,1,0};
		sc.sortColors(nums);
	}
	
	//75. 颜色分类
	
	//常数空间
	public void sortColors(int[] nums) {
		int index = 0;//当前位置
		int color = 0;//当前颜色
		while(index<nums.length) {
			if(nums[index]==color) {
				index++;
			}else {
				for(int i = index+1;i<nums.length;i++) {
					if(nums[i]==color) {
						int temp = nums[index];
						nums[index++] = color;
						nums[i] = temp;
					}
				}
				color++;
			}
		}
		
	}
	
	
	
	//提示方法
    public void sortColors2(int[] nums) {
    	int[] color = new int[3];
    	for(int i = 0;i<nums.length;i++) {
    		if(nums[i]==0) {
    			color[0]++;
    		}else if(nums[i]==1){
    			color[1]++;
    		}else {
    			color[2]++;
    		}
    	}
    	
    	int j=0;
    	for(int i = 0;i<color.length;i++) {
    		int count = 0;    		
    		while(count<color[i]) {
    			nums[j++] = i; 
    			count++;
    		}
    	}
    		
    }
        
    

}
