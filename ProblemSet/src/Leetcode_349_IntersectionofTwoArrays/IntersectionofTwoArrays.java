package Leetcode_349_IntersectionofTwoArrays;



import java.util.HashMap;
//import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Vector;





/*
	给定两个数组，编写一个函数来计算它们的交集。
	
	示例 1:	
		输入: nums1 = [1,2,2,1], nums2 = [2,2]
		输出: [2]
	示例 2:	
		输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
		输出: [9,4]
	说明:	
		输出结果中的每个元素一定是唯一的。
		我们可以不考虑输出结果的顺序。
*/
public class IntersectionofTwoArrays {

	public static void main(String[] args) {
		
	}
	//349. 两个数组的交集
	//集合的处理方式有两种set和map
	//set
    public int[] intersection(int[] nums1, int[] nums2) {
        //定义set
    	Set<Integer> nums = new HashSet<Integer>();
    	Set<Integer> result = new HashSet<>();
    	//将数组nums2放入集合nums
    	for(int i =0;i<nums2.length;i++) {
    		nums.add(nums2[i]);
    	}
    	//遍历nums1,找到交集,放入集合result
    	for(int i = 0;i<nums1.length;i++) {
    		if(nums.contains(nums1[i])) {
    			result.add(nums1[i]);
    		}
    	}
    	//将集合转换为数组，使用迭代器
    	int[] res= new int[result.size()];
    	//迭代器
    	Iterator iter = result.iterator();
    	int i = 0;
    	while(iter.hasNext()) {
    		res[i++]=(int)iter.next();
    	}
    	return res;
    }
    //Map
    public int[] intersection2(int[] nums1, int[] nums2) {    	
    	//定义Map:键和值一一映射
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        //定义一个动态数组
        Vector<Integer> ret = new Vector<>();
        //将第一个数组作为键值输入
        for(int i = 0;i<nums1.length;i++) {
        	map.put(nums1[i], 1);
        }
        //遍历nums2,判断是否存在键值
        //如果存在取出键值，存入结果数组
        for(int i = 0;i<nums2.length;i++) {
        	//如果存在
        	if(map.containsKey(nums2[i])) {
        		if(map.get(nums2[i])==1) {
        			ret.add(nums2[i]);
        			map.put(nums2[i],0);
        		}
        		
        	}
        }
        //定义结果数组
        int[] result = new int[ret.size()];
        //定义迭代器
        Iterator<Integer> iter = ret.iterator();
        int i = 0;
        while(iter.hasNext()) {
        	result[i++] = iter.next();
        }
        return result;
       
    }
}
