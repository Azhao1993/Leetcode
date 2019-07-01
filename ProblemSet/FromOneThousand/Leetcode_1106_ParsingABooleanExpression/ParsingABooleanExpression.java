package Leetcode_1106_ParsingABooleanExpression;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/*
	给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。
	
	有效的表达式需遵循以下约定：	
		"t"，运算结果为 True
		"f"，运算结果为 False
		"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
		"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
		"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）	 
	
	示例 1：	
		输入：expression = "!(f)"
		输出：true
	示例 2：	
		输入：expression = "|(f,t)"
		输出：true
	示例 3：	
		输入：expression = "&(t,f)"
		输出：false
	示例 4：
		输入：expression = "|(&(t,f,t),!(t))"
		输出：false	 
	
	提示：	
		1 <= expression.length <= 20000
		expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
		expression 是以上述形式给出的有效表达式，表示一个布尔值。
 */

//1106. 解析布尔表达式
public class ParsingABooleanExpression {
	public boolean parseBoolExpr(String expression) {
		Stack<Character> stack = new Stack<>();
		List<List<Boolean>> list = new ArrayList<>();

		char[] exp = expression.toCharArray();
		for (int i = 0; i < exp.length; i++) {
			if (exp[i] == '!' || exp[i] == '|' || exp[i] == '&') {
				stack.push(exp[i]);
			} else if (exp[i] == '(') {
				list.add(new ArrayList<Boolean>());
			} else if (exp[i] == 't') {
				list.get(list.size() - 1).add(true);
			} else if (exp[i] == 'f') {
				list.get(list.size() - 1).add(false);
			} else if (exp[i] == ')') {
				List<Boolean> temp = list.remove(list.size() - 1);
				if (list.size() == 0) {
					list.add(new ArrayList<Boolean>());
				}
				char flag = stack.pop();
				boolean res = temp.get(0);
				if (flag == '!') {
					res = !res;
				} else if (flag == '&') {
					for (int j = 1; j < temp.size(); j++) {
						res &= temp.get(j);
					}
				} else if (flag == '|') {
					for (int j = 1; j < temp.size(); j++) {
						res |= temp.get(j);
					}
				}

				list.get(list.size() - 1).add(res);

			}
		}
		return list.get(0).get(0);
	}
}
