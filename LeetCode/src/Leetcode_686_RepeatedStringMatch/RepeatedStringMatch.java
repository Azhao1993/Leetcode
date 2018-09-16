package Leetcode_686_RepeatedStringMatch;
/*
	给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
	
	举个例子，A = "abcd"，B = "cdabcdab"。	
	答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。
	
	注意:	
	 	A 与 B 字符串的长度在1和10000区间范围内。
*/
public class RepeatedStringMatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RepeatedStringMatch rsm = new RepeatedStringMatch();
		System.out.println(rsm.repeatedStringMatch("aaaaaaaaaaaaaaaaaaaaaab","ba"));
	}
	//686. 重复叠加字符串匹配//超时
    public int repeatedStringMatch(String A, String B) {
    	//计数器
    	int count=1;
        StringBuilder abuilder = new StringBuilder(A);
        StringBuilder bbuilder = new StringBuilder(B);
        
        while((abuilder.length()<=bbuilder.length())&&(count<=bbuilder.length())){        	  	
        	if(abuilder.indexOf(B)!=-1) {
        		return count;
        	}
        	count++;      
        	abuilder.append(A);
        }
        return -1;
    }
}
