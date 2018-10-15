package Leetcode_278_FirstBadVersion;

/*
	���ǲ�Ʒ������Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ��
	���ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
	����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ��ġ�
	
	�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾�����ĵ�һ������İ汾��
	
	�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г�����ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����
	
	ʾ��:	
		���� n = 5������ version = 4 �ǵ�һ������İ汾��
		
		���� isBadVersion(3) -> false
		���� isBadVersion(5) -> true
		���� isBadVersion(4) -> true
	
		���ԣ�4 �ǵ�һ������İ汾�� 
*/
public class FirstBadVersion {
	/*
	 * The isBadVersion API is defined in the parent class VersionControl. boolean
	 * isBadVersion(int version);
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FirstBadVersion fbv = new FirstBadVersion();
		System.out.println(fbv.firstBadVersion(5));
	}

	// 278. ��һ������İ汾
	public int firstBadVersion(int n) {

		int min = 1;
		int max = n;
		while (min < max) {
			int mid = min + (max - min) / 2;
			// mid�汾����
			if (isBadVersion(mid)) {
				// ��
				max = mid;
			} else {
				// mid�汾��ȷ������
				min = mid + 1;
			}
		}
		return min;

	}

	//
	public boolean isBadVersion(int version) {
		// �����һ������汾
		int firstBadVersion = 4;
		return (version >= firstBadVersion);
	}

}