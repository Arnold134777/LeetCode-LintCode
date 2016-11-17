title: LintCode数字三角形
date: 2015-12-05 21:06:39
tags: [算法,动态规划,LintCode]
---
给定一个数字三角形，找到从顶部到底部的最小路径和。每一步可以移动到下面一行的相邻数字上。

样例
比如，给出下列数字三角形：

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

从顶到底部的最小路径和为11 ( 2 + 3 + 5 + 1 = 11)。

注意
如果你只用额外空间复杂度O(n)的条件下完成可以获得加分，其中n是数字三角形的总行数。
```java
public class Solution {
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
   public int minimumTotal(int[][] triangle) {
		if(null == triangle)
			return 0;
		int row = triangle.length;
		if(row <= 0)
			return 0;
		int[][] steps = new int[row][row];
		int min = Integer.MAX_VALUE;
		steps[0][0] = triangle[0][0];
		if(row == 1)
			return steps[0][0];
		for(int i = 1;i < row;i++)
		{
			for(int j = 0;j <= i;j++)
			{
				if(j == 0)
				{
					steps[i][j] = steps[i - 1][j] + triangle[i][j];
				}
				else if(j == i)
				{
					steps[i][j] = steps[i - 1][j - 1] + triangle[i][j];
				}
				else
				{
					steps[i][j] = Math.min(steps[i - 1][j], steps[i - 1][j - 1]) + triangle[i][j];
				}
				
				if(i == row - 1)
				{
					if(steps[i][j] < min)
					{
						min = steps[i][j];
					}
				}
			}
		}
		return min;
	}
}


```
