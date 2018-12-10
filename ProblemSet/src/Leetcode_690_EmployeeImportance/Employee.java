package Leetcode_690_EmployeeImportance;

import java.util.List;

public class Employee {
		// Employee info	
		// It's the unique id of each node;
		// unique id of this employee
		public int id;
		// the importance value of this employee
		public int importance;
		// the id of direct subordinates
		public List<Integer> subordinates;
		public int getId() {
			return id;
		}
		public void setId(int id) {
			this.id = id;
		}
		public int getImportance() {
			return importance;
		}
		public void setImportance(int importance) {
			this.importance = importance;
		}
		public List<Integer> getSubordinates() {
			return subordinates;
		}
		public void setSubordinates(List<Integer> subordinates) {
			this.subordinates = subordinates;
		}
		
		
	
}
