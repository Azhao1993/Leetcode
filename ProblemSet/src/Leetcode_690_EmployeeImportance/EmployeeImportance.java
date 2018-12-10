package Leetcode_690_EmployeeImportance;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/*
	给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。	
	比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。
	那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。
	注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。
	
	现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
	
	示例 1:	
		输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
		输出: 11
	解释:
		员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
	
	注意:	
		一个员工最多有一个直系领导，但是可以有多个直系下属
		员工数量不超过2000。
 */
public class EmployeeImportance {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		EmployeeImportance ei = new EmployeeImportance();
		List<Employee> employees = new ArrayList<Employee>();
		// id 为1 的员工
		Employee em = new Employee();
		em.setId(1);
		em.setImportance(5);
		List<Integer> subordinates1 = Arrays.asList(2, 3);
		em.setSubordinates(subordinates1);
		employees.add(em);
		// id 为2 的员工
		Employee em2 = new Employee();
		em2.setId(2);
		em2.setImportance(3);
		List<Integer> subordinates2 = new ArrayList<Integer>();
		em2.setSubordinates(subordinates2);
		employees.add(em2);
		// id 为 3 的员工
		Employee em3 = new Employee();
		em3.setId(3);
		em3.setImportance(3);
		List<Integer> subordinates3 = new ArrayList<Integer>();
		em3.setSubordinates(subordinates3);
		employees.add(em3);

		ei.getImportance(employees, 1);

	}	

	// 690. 员工的重要性
	public int getImportance(List<Employee> employees, int id) {
		int result = 0;
		// 遍历员工找到id员工
		for (Employee em : employees) {
			if (em.id == id) {
				result += em.importance;
				if (em.subordinates.size() != 0) {
					for (Integer subid : em.subordinates) {
						result += getImportance(employees, subid);
					}
				}
			}

		}
		return result;
	}
	
	//7ms
	int importance =0;
    public int getImportance0(List<Employee> employees, int id) {
    	HashMap<Integer, Employee> map = new HashMap<Integer, Employee>();
    	for(Employee e: employees) {
    		map.put(e.id, e);
    	}
    	dfs(map.get(id), map);
    	return importance;
    }
    public void dfs(Employee e, HashMap<Integer, Employee> map) {
    	importance += e.importance;
    	for(Integer i: e.subordinates) {
    		dfs(map.get(i), map);
    	}
    }

}
