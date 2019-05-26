package Leetcode_1054_DistantBarcodes;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;
/*
	在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。	
	请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。	 
	
	示例 1：	
		输入：[1,1,1,2,2,2]
		输出：[2,1,2,1,2,1]
	示例 2：	
		输入：[1,1,1,1,2,2,3,3]
		输出：[1,3,1,3,2,1,2,1]
	 
	
	提示：	
		1 <= barcodes.length <= 10000
		1 <= barcodes[i] <= 10000
 */
//1054. 距离相等的条形码
public class DistantBarcodes {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}
	
    public int[] rearrangeBarcodes(int[] barcodes) {
        int[] res = Arrays.copyOf(barcodes, barcodes.length);
        if(barcodes.length<3) {
        	return res;
        }
        HashMap<Integer,Integer> hash = new HashMap<>();
        for(Integer it : barcodes) {
        	if(hash.containsKey(it)) {
        		hash.put(it, hash.get(it)+1);
        	}else {
        		hash.put(it, 1);
        	}
        }
        PriorityQueue<int[]> que = new PriorityQueue<>(new Comparator<int[]>() {
        	@Override
        	public int compare(int[] o1, int[] o2) {
        		// 频率从高到低
        		return o2[0]-o1[0];
        	}
        });
        for(Integer it :hash.keySet()) {
        	que.add(new int[] {hash.get(it),it});
        }
        for(int i = 0;i<res.length;i++) {
        	if(i==0||res[i-1]!=que.peek()[1]) {
        		int[] tem  = que.peek();
        		res[i]=tem[1];
        		tem[0]--;
        		que.poll();
        		que.add(tem);
        	}else {
        		int[] tem1 = que.poll();
        		int[] tem = que.peek();
        		res[i] = tem[1];
        		tem[0]--;
        		que.poll();
        		que.add(tem);
        		que.add(tem1);
        		
        	}
        }
        return res;
    }

}
