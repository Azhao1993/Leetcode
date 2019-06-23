package Leetcode_1096_BraceExpansionII;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Stack;

/*
	如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。
	
	花括号展开的表达式可以看作一个由 花括号、逗号 和 小写英文字母 组成的字符串，定义下面几条语法规则：	
		如果只给出单一的元素 x，那么表达式表示的字符串就只有 "x"。 
			例如，表达式 {a} 表示字符串 "a"。
		而表达式 {ab} 就表示字符串 "ab"。
		当两个或多个表达式并列，以逗号分隔时，我们取这些表达式中元素的并集。
			例如，表达式 {a,b,c} 表示字符串 "a","b","c"。
		而表达式 {a,b},{b,c} 也可以表示字符串 "a","b","c"。
		要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。
			例如，表达式 {a,b}{c,d} 表示字符串 "ac","ad","bc","bd"。
		表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
			例如，表达式 a{b,c,d} 表示字符串 "ab","ac","ad"​​​​​​。
			例如，表达式 {a{b,c}}{{d,e}f{g,h}} 可以代换为 {ab,ac}{dfg,dfh,efg,efh}，
				表示字符串 "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"。
		给出表示基于给定语法规则的表达式 expression，返回它所表示的所有字符串组成的有序列表。
	
	假如你希望以「集合」的概念了解此题，也可以通过点击 “显示英文描述” 获取详情。	 
	
	示例 1：	
		输入："{a,b}{c{d,e}}"
		输出：["acd","ace","bcd","bce"]
	示例 2：	
		输入："{{a,z}, a{b,c}, {ab,z}}"
		输出：["a","ab","ac","z"]
	解释：输出中 不应 出现重复的组合结果。 
	
	提示：	
		1 <= expression.length <= 50
		expression[i] 由 '{'，'}'，',' 或小写英文字母组成
		给出的表达式 expression 用以表示一组基于题目描述中语法构造的字符串
 */
public class BraceExpansionII {
	public static void main(String[] args) {
		String expression = "{{a,z}, a{b,c}, {ab,z}}";
		new BraceExpansionII().braceExpansionII(expression);
	}

	public List<String> braceExpansionII(String expression) {
		Stack<Integer> stack = new Stack<>();
		int length = expression.length();
		// (i,index[i])-> 分别对应 一对{ }的索引
		int[] index = new int[length];
		char[] exp = expression.toCharArray();
		for (int i = 0; i < length; i++) {
			if (exp[i] == '{') {
				stack.push(i);
			} else if (exp[i] == '}') {
				index[stack.pop()] = i;
			}
		}

		List<String> res = helper(index, expression, 0, length - 1);
		// set去重
		HashSet<String> set = new HashSet<>(res);
		res = new ArrayList<String>();
		for (String str : set) {
			res.add(str);
		}
		// 排序
		Collections.sort(res);
		return res;
	}

	/**
	 * 
	 * @param index      记录一对括号的索引
	 * @param expression
	 * @param begin      起始位置
	 * @param end        终止位置
	 * @return
	 */

	private List<String> helper(int[] index, String expression, int begin, int end) {
		List<String> list = new ArrayList<String>();// 记录结果
		List<String> temp = null;// 缓存
		char[] exp = expression.toCharArray();
		for (int i = begin; i <= end;) {
			if (exp[i] == '{') {
				// （i+1,index[i]-1）-> inner
				List<String> inner = helper(index, expression, i + 1, index[i] - 1);
				// 将inner加入缓存
				if (temp != null) {
					List<String> temp1 = new ArrayList<String>();
					for (String str1 : temp) {
						for (String str2 : inner) {
							temp1.add(str1 + str2);
						}
					}
					temp = temp1;
				} else {
					temp = inner;
				}
				// 从}后面开始
				i = index[i] + 1;
			} else if (exp[i] >= 'a' && exp[i] <= 'z') {
				// 将字母加入到缓存中的每一个字符串
				List<String> temp2 = new ArrayList<String>();
				if (temp != null) {
					for (String str : temp) {
						temp2.add(str + exp[i]);
					}
				} else {
					temp2.add("" + exp[i]);
				}
				temp = temp2;
				i++;
			} else if (exp[i] == ',') {
				// 将缓存加入到list结果集，并清空缓存
				list.addAll(temp);
				temp = null;
				i++;
			}
		}
		if (temp != null) {
			list.addAll(temp);
		}
		return list;
	}

}
