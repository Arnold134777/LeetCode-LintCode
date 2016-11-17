title: LintCode Maximal Square
date: 2015-12-06 19:37:03
tags: [算法,LintCode]
---

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

样例
For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

***解题思路***
  初始思路是判断对角方向以及相邻的两个数,运行结果错误，然后查看错误发现需要判断整个邻边，因此想到遍历邻边判断（i，j）位置的最大面积。但是会发现（i，j）之前的点的结果已经得出，为什么会重复用到之前的点，整个过程应该可以优化。思考后想到了同时三个方向判断，因此得出转移方程：maxArea[i][j] = Math.min(maxArea[i][j - 1],Math.min(maxArea[i - 1][j - 1], maxArea[i - 1][j])) + 1；

***错误代码***
```java
	if(matrix[i - 1][j] == 1 && matrix[i][j - 1] == 1 && matrix[i - 1][j - 1] == 1)
	{
           maxArea[i][j] = maxArea[i - 1][j - 1] + 1;
	   if(maxArea[i][j] > maxResultArea)
	   {
              maxResultArea = maxArea[i][j];
	   }
	}			
```
  
***正确代码***
```java
public class Solution {
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
  public int maxSquare(int[][] matrix) {
		if(null == matrix)
		{
			return 0;
		}
		int row = matrix.length;
		if(row <= 0)
		{
			return 0;
		}
		int col = matrix[0].length;
		int[][] maxArea = new int[row][col];
		int maxResultArea = Integer.MIN_VALUE;
		
		for(int i = 0;i < row;i++)
		{
			maxArea[i][0] = matrix[i][0];
			if(maxArea[i][0] > maxResultArea)
			{
				maxResultArea = maxArea[i][0];
			}
		}
		
		for(int i = 0;i < col;i++)
		{
			maxArea[0][i] = matrix[0][i];
			if(maxArea[0][i] > maxResultArea)
			{
				maxResultArea = maxArea[0][i];
			}
		}
		
		for(int i = 1;i < row;i++)
		{
			for(int j = 1;j < col;j++)
			{
				if(matrix[i][j] == 1)
				{
					maxArea[i][j] = Math.min(maxArea[i][j - 1],Math.min(maxArea[i - 1][j - 1], maxArea[i - 1][j])) + 1;
				}
				if(maxArea[i][j] > maxResultArea)
				{
					maxResultArea = maxArea[i][j];
				}
			}
		}
		return maxResultArea > 0 ?  maxResultArea * maxResultArea : 0;
	}
}

```
