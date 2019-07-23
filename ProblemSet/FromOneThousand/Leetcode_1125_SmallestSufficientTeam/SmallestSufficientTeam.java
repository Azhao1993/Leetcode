package Leetcode_1125_SmallestSufficientTeam;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/*
	作为项目经理，你规划了一份需求的技能清单 req_skills，
	并打算从备选人员名单 people 中选出些人组成一个「必要团队」
	（ 编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。
	
	所谓「必要团队」，就是在这个团队中，
	对于所需求的技能列表 req_skills 中列出的每项技能，
	团队中至少有一名成员已经掌握。
	
	我们可以用每个人的编号来表示团队中的成员：
	例如，团队 team = [0, 1, 3] 表示掌握技能分别为 
	people[0]，people[1]，和 people[3] 的备选人员。
	
	请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。
	你可以按任意顺序返回答案，本题保证答案存在。
	
	 
	
	示例 1：	
		输入：
			req_skills = ["java","nodejs","reactjs"], 
			people = [["java"],["nodejs"],["nodejs","reactjs"]]
		输出：[0,2]
	
	示例 2：	
		输入：
			req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
			people = [	["algorithms","math","java"],
						["algorithms","math","reactjs"],
						["java","csharp","aws"],
						["reactjs","csharp"],
						["csharp","math"],
						["aws","java"]]
		输出：[1,2] 
	
	提示：
		1 <= req_skills.length <= 16
		1 <= people.length <= 60
		1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
		req_skills 和 people[i] 中的元素分别各不相同
		req_skills[i][j], people[i][j][k] 都由小写英文字母组成
		本题保证「必要团队」一定存在
 */

//1125.最小的必要团队
public class SmallestSufficientTeam {
	public static void main(String[] args) {
		String[] req_skills = { "algorithms", "math", "java", "reactjs", "csharp", "aws" };
		String[][] peo = { { "algorithms", "math", "java" }, { "algorithms", "math", "reactjs" },
				{ "java", "csharp", "aws" }, { "reactjs", "csharp" }, { "csharp", "math" }, { "aws", "java" } };
		List<List<String>> people = new ArrayList<List<String>>();
		for (int i = 0; i < peo.length; i++) {
			people.add(Arrays.asList(peo[i]));
		}
		new SmallestSufficientTeam().smallestSufficientTeam(req_skills, people);

	}

	public int[] smallestSufficientTeam(String[] skills, List<List<String>> people) {
		int ns = skills.length;
		int np = people.size();
		HashMap<String, Integer> map = new HashMap<>();
		for (int i = 0; i < ns; i++) {
			map.put(skills[i], i);
		}
		List<Integer>[] dp = new List[1 << ns];
		dp[0] = new ArrayList<Integer>();
		for (int i = 0; i < np; i++) {
			int skill = 0;
			for (String str : people.get(i)) {
				skill |= (1 << map.get(str));
			}
			for (int prev = 0; prev < dp.length; prev++) {
				if (dp[prev] == null) {
					continue;
				}
				int comb = prev | skill;
				if (dp[comb] == null || dp[prev].size() + 1 < dp[comb].size()) {
					dp[comb] = new ArrayList<Integer>(dp[prev]);
					dp[comb].add(i);
				}
			}
		}
		int i = 0;
		List<Integer> list = dp[dp.length - 1];
		int[] res = new int[list.size()];
		for (Integer x : list) {
			res[i++] = x;
		}
		return res;
	}

}
