title: LintCode Paint Fence
date: 2016-03-20 22:28:16
tags: [算法,LintCode,动态规划]
---

There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

##### 样例:<br>
Given n=3, k=2 return 6

```
     post 1,   post 2, post 3
way1    0         0       1 
way2    0         1       0
way3    0         1       1
way4    1         0       0
way5    1         0       1
way6    1         1       0

```

##### 分析：
影响第n种的颜色的是第n-1与第n-2种颜色的，因此可能性都为k-1种
因此得到如下递推式:`maxWays[n] = (k - 1) * (maxWays[n - 1] + maxWays[n - 2]);`

```objc	
public class Solution {
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
   public int numWays(int n, int k) {
		if(n == 0 || k == 0)
			return 0;
		if(n == 1)
		    return k;
		
		int[] maxWays = new int[n + 1];
		maxWays[0] = 0;
		maxWays[1] = k;
		maxWays[2] = k * k;
		for(int i = 3;i <= n;i ++)
		{
			maxWays[i] = (k - 1) * (maxWays[i - 1] + maxWays[i - 2]);
		}
		
		return maxWays[n];
	}
}

```
