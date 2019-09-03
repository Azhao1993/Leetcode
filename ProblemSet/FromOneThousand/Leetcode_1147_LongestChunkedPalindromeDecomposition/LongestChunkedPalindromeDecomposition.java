package Leetcode_1147_LongestChunkedPalindromeDecomposition;

import java.util.Arrays;

/*
    段式回文 其实与 一般回文 类似，只不过是最小的单位是 一段字符 而不是 单个字母。
    举个例子，对于一般回文 "abcba" 是回文，而 "volvo" 不是，
    但如果我们把 "volvo" 分为 "vo"、"l"、"vo" 三段，
    则可以认为 “(vo)(l)(vo)” 是段式回文（分为 3 段）。

    给你一个字符串 text，在确保它满足段式回文的前提下，请你返回 段 的 最大数量 k。

    如果段的最大数量为 k，那么存在满足以下条件的 a_1, a_2, ..., a_k：

    每个 a_i 都是一个非空字符串；
    将这些字符串首位相连的结果 a_1 + a_2 + ... + a_k 和原始字符串 text 相同；
    对于所有1 <= i <= k，都有 a_i = a_{k+1 - i}。


    示例 1：
        输入：text = "ghiabcdefhelloadamhelloabcdefghi"
        输出：7
        解释：我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。
    示例 2：
        输入：text = "merchant"
        输出：1
        解释：我们可以把字符串拆分成 "(merchant)"。
    示例 3：
        输入：text = "antaprezatepzapreanta"
        输出：11
        解释：我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。
    示例 4：
        输入：text = "aaa"
        输出：3
        解释：我们可以把字符串拆分成 "(a)(a)(a)"。
 */

//1147.段式回文
public class LongestChunkedPalindromeDecomposition {
    //递归
    public int longestDecomposition(String text) {
        if (text.length() < 2) {
            return text.length();
        }
        return helper(text, 0, text.length() - 1);
    }

    private int helper(String text, int left, int right) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return 1;
        }
        int length = 1;
        while (left + length <= right - length + 1) {
            String lStr = text.substring(left, left + length);
            String rStr = text.substring(right + 1 - length, right + 1);
            if (lStr.equals(rStr)) {
                return helper(text, left + length, right - length) + 2;
            }
            length++;
        }
        return 1;
    }

    //记忆化搜索
    public int longestDecomposition2(String text) {
        int len = text.length();
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; i++) {
            Arrays.fill(dp[i], -1);
        }
        return helper(0, len - 1, dp, text);
    }

    private int helper(int l, int r, int[][] dp, String s) {
        if(l>r){
            return 0;
        }
        if (l == r) {
            return 1;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        int len = (r-l+1)/2;
        int res = 1;
        for(int length = 1;length<=len;length++)
        {
            if(s.substring(l,l+length).equals(s.substring(r-length+1,r+1))){
                res = Math.max(res,helper(l+length,r-length,dp,s)+2);
            }
        }
        dp[l][r] = res;
        return res;
    }
}
