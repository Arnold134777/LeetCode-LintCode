title: LintCode最小路径和
date: 2015-12-05 21:04:22
tags: [算法,动态规划,LintCode]
---
给定一个只含非负整数的m*n网格，找到一条从左上角到右下角的可以使数字和最小的路径。
样例
注意
你在同一时间只能向下或者向右移动一步

```java
public class Solution {
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
   public int minPathSum(int[][] grid) {
		if(null == grid)
			return 0;
		int row = grid.length;
		int col = grid[0].length;
		if(row <= 0 || col <= 0)
			return 0;
		int[][] steps = new int[row][col];
		steps[0][0] = grid[0][0];
		for(int i = 1;i < row;i++)
		{
			steps[i][0] += steps[i - 1][0] + grid[i][0];
		}
		
		for(int i = 1;i < col;i++)
		{
			steps[0][i] += steps[0][i - 1] + grid[0][i];
		}
	
		for(int i = 1;i < row;i++)
		{
			for(int j = 1;j < col;j++)
			{
				steps[i][j] = Math.min(steps[i - 1][j], steps[i][j - 1]) + grid[i][j];
			}
		}
	
		return steps[row - 1][col - 1];
	}
}
```
