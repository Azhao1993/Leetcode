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
    	Stack<Character> sta = new Stack<>();
    	List<List<Boolean>> flags = new ArrayList<>();           
       
        for(char it:expression.toCharArray()) {
        	if(it=='!'||it=='&'||it=='|') {
        		sta.push(it);
        	}else if(it=='(') {
        		flags.add(new ArrayList<Boolean>());
        	}else if(it=='t') {
        		flags.get(flags.size()-1).add(true);
        	}else if(it=='f') {
        		flags.get(flags.size()-1).add(false);
        	}else if(it==')') {
        		List<Boolean> tem = flags.remove(flags.size()-1);
        		if(flags.size()==0) {
        			flags.add(new ArrayList<Boolean>());
        		}
        		char exp = sta.pop();
        		boolean curFlag = tem.get(0);
        		if(exp=='&') {
        			for(int i = 1;i<tem.size();i++) {
        				curFlag &= tem.get(i);
        			}
        		}else if(exp=='|') {
        			for(int i = 1;i<tem.size();i++) {
        				curFlag |= tem.get(i);
        			}
        		}else {
        			curFlag =!curFlag;
        		}
        		
        		flags.get(flags.size()-1).add(curFlag);
        	}
        }
        return flags.get(0).get(0);
    }

	
}
