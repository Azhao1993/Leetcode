package Leetcode_914_XofaKindinaDeckofCards;

import java.util.HashMap;
import java.util.Set;

/*
	给定一副牌，每张牌上都写着一个整数。
	此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
		每组都有 X 张牌。
		组内所有的牌上都写着相同的整数。
	仅当你可选的 X >= 2 时返回 true。 
	
	示例 1：
		输入：[1,2,3,4,4,3,2,1]
		输出：true
		解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
	
	示例 2：
		输入：[1,1,1,2,2,2,3,3]
		输出：false
		解释：没有满足要求的分组。
	
	示例 3：
		输入：[1]
		输出：false
		解释：没有满足要求的分组。
	
	示例 4：
		输入：[1,1]
		输出：true
		解释：可行的分组是 [1,1]
	
	示例 5：
		输入：[1,1,2,2,2,2]
		输出：true
		解释：可行的分组是 [1,1]，[2,2]，[2,2]
	
	提示：
		1 <= deck.length <= 10000
		0 <= deck[i] < 10000
 */
public class XofaKindinaDeckofCards {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

	// 914. 卡牌分组(36ms)
	public boolean hasGroupsSizeX(int[] deck) {
		HashMap<Integer, Integer> map = new HashMap<>();

		for (int i = 0; i < deck.length; i++) {
			if (map.containsKey(deck[i])) {
				int count = map.get(deck[i]);
				count++;
				map.put(deck[i], count);
			} else {
				map.put(deck[i], 1);
			}
		}

		int mincount = Integer.MAX_VALUE;
		int maxcount = 0;
		Set<Integer> keyset = map.keySet();
		int[] valarr = new int[keyset.size()];
		int index = 0;
		for (Integer temp : keyset) {
			valarr[index] = map.get(temp);
			mincount = Math.min(mincount, valarr[index]);
			maxcount = Math.max(maxcount, valarr[index]);
			index++;			
		}
		if(mincount<=1) {
			return false;
		}
		for(int i = 2;i<=maxcount;i++) {
			for(int j = 0;j<valarr.length;j++) {
				if(valarr[j]%i!=0) {
					break;
				}
				if(j==valarr.length-1) {
					return true;
				}
			}			
		}
		return false;
		
	}
	//大牛代码
	public boolean hasGroupsSizeX2(int[] deck) {
		int res = 0;
	    int[] times = new int[10000];
	    //统计各个元素出现的个数
	    for(int i:deck) {
	    	times[i]++;
	    }	            
	    for(int i:times){
	        if(i!=0){
	        	//计算times数组中所有元素的最小公约数
	        	res = gcd(i,res); 
	        }
	    }
	     return res>1;
	}
	//求两数的最小公约数
	public static int gcd(int a,int b){
	        return b>0 ? gcd(b,a%b) : a;
	    }
}
