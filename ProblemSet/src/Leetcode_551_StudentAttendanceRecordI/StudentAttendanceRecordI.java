package Leetcode_551_StudentAttendanceRecordI;
/*
	给定一个字符串来代表一个学生的出勤纪录，这个纪录仅包含以下三个字符：	
		'A' : Absent，缺勤
		'L' : Late，迟到
		'P' : Present，到场
	如果一个学生的出勤纪录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
	
	你需要根据这个学生的出勤纪录判断他是否会被奖赏。
	
	示例 1:
		输入: "PPALLP"
		输出: True
	示例 2:	
		输入: "PPALLL"
		输出: False
*/
public class StudentAttendanceRecordI {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StudentAttendanceRecordI sar1 = new StudentAttendanceRecordI();
		System.out.println(sar1.checkRecord("PPALLP"));
		System.out.println(sar1.checkRecord("PPALLL"));
	}
	public boolean checkRecord(String s) {
		//记录A的个数
		int countA = 0;
		//记录L的个数
		int countL = 0;
		if(s.charAt(0)=='A') {
			countA++;
		}
		if(s.charAt(0)=='L') {
			countL++;
		}
		for(int i = 1;i<s.length();i++) {
			//缺勤两次
			if(s.charAt(i)=='A') {
        		countA++;
        		if(countA>1) {
        			return false;
        		}
        	}
			//连续迟到3次
			if(s.charAt(i)=='L') {
				if(s.charAt(i-1)=='L') {
					countL++;
					if(countL==3) {
						return false;
					}
				}else {
					countL=1;
				}
			}			
		}
		return true;
		
		
    }

}
