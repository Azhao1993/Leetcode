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
//1096. 花括号展开 II
public class BraceExpansionII2 {

	public static void main(String[] args) {
		String expression = "{{a,z},a{b,c},{ab,z}}";
		new BraceExpansionII2().braceExpansionII(expression);
	}

	public List<String> braceExpansionII(String expression) {
		Stack<Integer> stack = new Stack<>();
		int length = expression.length();
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
		HashSet<String> set = new HashSet<>(res);
		res = new ArrayList<String>();
		for (String str : set) {
			res.add(str);
		}
		Collections.sort(res);
		return res;

	}

	private List<String> helper(int[] index, String expression, int begin, int end) {
		List<String> list = new ArrayList<>();
		List<String> temp = new ArrayList<>();
		temp.add("");
		char[] exp = expression.toCharArray();
		for (int i = begin; i <= end;) {
			if (exp[i] == '{') {
				List<String> inner = helper(index, expression, i + 1, index[i] - 1);
				temp = multiply(temp, inner);
				i = index[i] + 1;
			} else if (exp[i] >= 'a' && exp[i] <= 'z') {
				temp = multiply(temp, exp[i]);
				i++;
			} else if (exp[i] == ',') {
				list.addAll(temp);
				temp.clear();
				temp.add("");
				i++;
			}
		}
		if (temp != null) {
			list.addAll(temp);
		}
		return list;
	}

	private List<String> multiply(List<String> temp, char c) {
		List<String> res = new ArrayList<>();
		for (String str : temp) {
			res.add(str + c);
		}
		return res;
	}

	private List<String> multiply(List<String> temp, List<String> inner) {
		List<String> res = new ArrayList<>();
		for (String str : temp) {
			for (String str2 : inner) {
				res.add(str + str2);
			}
		}
		return res;
	}

}
