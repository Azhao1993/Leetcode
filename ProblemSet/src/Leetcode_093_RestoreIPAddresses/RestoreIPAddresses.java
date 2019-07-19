package Leetcode_093_RestoreIPAddresses;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
	
	示例:	
		输入: "25525511135"
		输出: ["255.255.11.135", "255.255.111.35"]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/restore-ip-addresses
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class RestoreIPAddresses {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if(s==null||s.length()<4) {
        	return res;
        }
        restoreIpAddresses(s,1,1,1,1,res);
        
        return res;
    }

	private void restoreIpAddresses(String s, int i, int j, int k, int l, List<String> res) {
				
	}
}
