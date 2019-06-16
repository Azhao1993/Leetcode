package Leetcode_1092_ShortestCommonSupersequence;
/*
	给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。
	如果答案不止一个，则可以返回满足条件的任意一个答案。
	
	（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），
	可以得到字符串 S，那么 S 就是 T 的子序列）	 
	
	示例：	
		输入：str1 = "abac", str2 = "cab"
		输出："cabac"
		解释：
		str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
		str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
		最终我们给出的答案是满足上述属性的最短字符串。 
	
	提示：	
		1 <= str1.length, str2.length <= 1000
		str1 和 str2 都由小写英文字母组成。
 */
//1092. 最短公共超序列
public class ShortestCommonSupersequence {
	public static void main(String[] args) {
		new ShortestCommonSupersequence().shortestCommonSupersequence2("abac", "cab");
	}
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        int[][] dp = new int[m+1][n+1];
        
        for(int i = 0;i<m;i++) {
        	for(int j = 0;j<n;j++) {
        		dp[i+1][j+1] = 
        				str1.charAt(i)==str2.charAt(j)
        				?dp[i][j]+1
        				:Math.max(dp[i][j+1], dp[i+1][j]);
        	}
        }
        
        String res = "";
        int i = m;
        int j = n;
        int len = dp[m][n];
        
        while(len>0) {
        	while(dp[i][j]==len) {
        		res += str1.charAt(--i);
        	}
        	i++;
        	res  = res.substring(0, res.length()-1);
        	while(dp[i][j]==len) {
        		res += str2.charAt(--j);
        	}
        	i--;
        	len--;        	
        }
        while(i>0)res+=str1.charAt(--i);
        while(j>0)res+=str2.charAt(--j);
        res = new StringBuilder(res).reverse().toString();
        return res;
    }
    public String shortestCommonSupersequence2(String str1, String str2) {
        int len1=str1.length();
        int len2=str2.length();
        int[][] dp=new int[len1+1][len2+1];
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        StringBuilder sb=new StringBuilder();
        for(int i=len1,j=len2;i>0||j>0;){
            if(i<=0){
            	//只剩下str2
                sb.append(str2.charAt(--j));
            }else if(j<=0){
            	//只剩下str1
                sb.append(str1.charAt(--i));
            }else if(dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1]){
            	//str1.i和str2.j相同
                sb.append(str1.charAt(--i));
                --j;
            }else if(dp[i][j]>dp[i-1][j]){
            	//dp[i][j]=dp[i][j-1]  -> str1.i和str2.j-1相同
                sb.append(str2.charAt(--j));
            }else{
            	//dp[i][j]=dp[i-1][j]  -> str1.i-1和str2.j相同
                sb.append(str1.charAt(--i));
            }
        }
        return sb.reverse().toString();
    }
    
}
