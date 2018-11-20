package UsualMethod;

/**
 * 这是一个跟数组有关的操作工具类
 * 
 * @author Andrew
 *
 */
public class array {
	private array() {

	}

	/**
	 * 交换数组中的两个数
	 * 
	 * @param nums 被操作的数组
	 * @param i    要交换的索引1
	 * @param j    要交换的索引2
	 */
	public static void exchange(int[] nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	//一位数组输出；Array.toString(arr);
	
	/**
	 *  二维数组输出
	 * @param grid 要输出的二维数组
	 */
	public static void ArrayOutput(int[][] grid) {
		// 获取grid的行和列
		int row = grid.length;
		int col = grid[0].length;
		// 输出数组
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (j != col - 1) {
					System.out.print(grid[i][j] + ",");
				} else {
					System.out.println(grid[i][j]);
				}

			}
		}
	}
}
