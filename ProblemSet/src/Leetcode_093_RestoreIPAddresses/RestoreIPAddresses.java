package Leetcode_093_RestoreIPAddresses;

import java.util.ArrayList;
import java.util.LinkedList;
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
//93. 复原IP地址
public class RestoreIPAddresses {
	List<String> res = new ArrayList<>();
	String s;

	public List<String> restoreIpAddresses(String s) {
		if (s == null || s.length() == 0) {
			return res;
		}
		this.s = s;
		dfs(0, "", 0);
		return res;
	}

	private void dfs(int curLength, String cur, int count) {
		if (count > 4) {
			return;
		}
		if (count == 4 && curLength == s.length()) {
			res.add(cur);
		}
		for (int i = 1; i < 4; i++) {
			if (curLength + i > s.length()) {
				break;
			}
			String str = s.substring(curLength, curLength + i);
			if ((str.startsWith("0") && str.length() > 1) || (i == 3 && Integer.valueOf(str) >= 256)) {
				continue;
			}
			dfs(curLength + i, cur + str + (count == 3 ? "" : "."), count + 1);
		}
	}
}
