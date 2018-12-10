package Leetcode_811_SubdomainVisitCount;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，最低的一级为"discuss.leetcode.com"。当我们访问域名"discuss.leetcode.com"时，也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。
	
	给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。其格式为访问次数+空格+地址，例如："9001 discuss.leetcode.com"。
	
	接下来会给出一组访问次数和域名组合的列表cpdomains 。要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。
	
	示例 1:
		输入: 
		["9001 discuss.leetcode.com"]
		输出: 
		["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
	说明: 
		例子中仅包含一个网站域名："discuss.leetcode.com"。按照前文假设，子域名"leetcode.com"和"com"都会被访问，所以它们都被访问了9001次。
	
	示例 2
		输入: 
		["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
		输出: 
		["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
	说明: 
		按照假设，会访问"google.mail.com" 900次，"yahoo.com" 50次，"intel.mail.com" 1次，"wiki.org" 5次。
		而对于父域名，会访问"mail.com" 900+1 = 901次，"com" 900 + 50 + 1 = 951次，和 "org" 5 次。
	
	注意事项：	
		 cpdomains 的长度小于 100。
		每个域名的长度小于100。
		每个域名地址包含一个或两个"."符号。
		输入中任意一个域名的访问次数都小于10000。
 */
public class SubdomainVisitCount {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		SubdomainVisitCount svc = new SubdomainVisitCount();
		String[] cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
		System.out.println(svc.subdomainVisits(cpdomains));
		String[] str = { "901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org",
				"1 intel.mail.com", "951 com" };
		System.out.println(Arrays.toString(str));
	}

	// 811. 子域名访问计数
	public List<String> subdomainVisits(String[] cpdomains) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < cpdomains.length; i++) {
			String[] temp = cpdomains[i].split(" ");
			int count = Integer.valueOf(temp[0]);
			map.put(temp[1], map.getOrDefault(temp[1], 0) + count);
			StringBuilder sbtemp = new StringBuilder(temp[1]);
			while (sbtemp.indexOf(".") != -1) {
				String str = sbtemp.substring(sbtemp.indexOf(".") + 1, sbtemp.length());
				map.put(str, map.getOrDefault(str, 0) + count);
				sbtemp.delete(0, sbtemp.indexOf(".") + 1);
			}
		}
		List<String> list = new ArrayList<String>();
		for (String s : map.keySet()) {
			StringBuilder sb = new StringBuilder();
			list.add(sb.append(map.get(s)).append(" ").append(s).toString());
		}
		return list;
	}
	
	//13ms
	public List<String> subdomainVisits0(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String domain : cpdomains) {
            if (domain.length() == 0) continue; // 跳过空域名
            int index = domain.indexOf(' ');    // 第一个空格出现的位置
            int time = Integer.valueOf(domain.substring(0, index)); // 空格前的字符为出现次数
            domain = domain.substring(index+1); // 空格后的字符为域名
            map.put(domain, map.getOrDefault(domain, 0)+time);   // 每次根据字符串匹配出现次数，第一次出现初始值为0，否则需要累加
            
            // 子域名的边界为'.'
            while (domain.indexOf('.') != -1) {
                domain = domain.substring(domain.indexOf('.')+1);
                map.put(domain, map.getOrDefault(domain, 0)+time);
            }
        }
        List<String> res = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String s = entry.getValue() + " " + entry.getKey();  // 出现次数和子域名拼接
            res.add(s);
        }
        return res;
    }

}
