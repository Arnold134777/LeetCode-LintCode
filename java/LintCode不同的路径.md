title: LintCode不同的路径
date: 2015-12-05 20:42:19
tags: [算法,动态规划,LintCode]
---
**一：**
有一个机器人的位于一个M×N个网格左上角（下图中标记为'Start'）。
机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角（下图中标记为'Finish'）。
问有多少条不同的路径？

|1,1| 1,2|1,3 |1,4|1,5|1,6|1,7|
|---|---|---|---|---|---|---|
|2,1| | |||||
|3,1| | ||||3,7|

```java
public class Solution {
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
   public int uniquePaths(int m, int n) {
		if(m == 0 || n == 0)
			return 0;
		int[][] paths = new int[m][n];
		for (int i = 0; i < m; i++) {
			paths[i][0] = 1;
		}

		for (int i = 0; i < n; i++) {
			paths[0][i] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}
		}
		return paths[m - 1][n - 1];
	}
}
```

**二：**
"不同的路径" 的跟进问题：

现在考虑网格中有障碍物，那样将会有多少条不同的路径？

网格中的障碍和空位置分别用 1 和 0 来表示。
样例
如下所示在3x3的网格中有一个障碍物：

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
一共有2条不同的路径从左上角到右下角。

注意
m 和 n 均不超过100

```java
public class Solution {
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
  public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		if (null == obstacleGrid)
			return 0;
		int[] columns = obstacleGrid[0];
		int[][] paths = new int[obstacleGrid.length][columns.length];
		boolean havePath = true;
		for (int i = 0; i < obstacleGrid.length; i++) {
			if (!havePath) {
				paths[i][0] = 0;
				continue;
			}
			if (obstacleGrid[i][0] == 1) {
				paths[i][0] = 0;
				havePath = false;
			} else {
				paths[i][0] = 1;
			}
		}

		havePath = true;
		for (int i = 0; i < columns.length; i++) {
			if (!havePath) {
				paths[0][i] = 0;
				continue;
			}
			if (obstacleGrid[0][i] == 1) {
				paths[0][i] = 0;
				havePath = false;
			} else {
				paths[0][i] = 1;
			}
		}

		for (int i = 1; i < obstacleGrid.length; i++) {
			for(int j = 1;j < columns.length;j++)
			{
				if(obstacleGrid[i][j] == 1)
				{
					paths[i][j] = 0;
					continue;
				}
				else	
				{
					paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
				}
			}
		}
		return paths[obstacleGrid.length - 1][columns.length - 1];
	}
}
```



