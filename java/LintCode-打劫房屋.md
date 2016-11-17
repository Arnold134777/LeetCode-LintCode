title: LintCode 打劫房屋
date: 2016-01-10 18:34:09
tags: [LintCode,算法,动态规划]
---

假设你是一个专业的窃贼，准备沿着一条街打劫房屋。每个房子都存放着特定金额的钱。你面临的唯一约束条件是：相邻的房子装着相互联系的防盗系统，且 当相邻的两个房子同一天被打劫时，该系统会自动报警。

给定一个非负整数列表，表示每个房子中存放的钱， 算一算，如果今晚去打劫，你最多可以得到多少钱 在不触动报警装置的情况下。

样例
给定 [3, 8, 4], 返回 8.

挑战
O(n) 时间复杂度 且 O(1) 存储。

#### 分析:
定义dp[i]表示打劫第i个房间为止所获得的最大收益，而dp[i]的值只与dp[i-2] 和dp[i-3]有关 并且 dp[i] = A[i] + max(dp[i-2],dp[i-3])

当求解所有的A[i]后，需要对最后两个dp[len-1] dp[len-2] 取最大值作为最后的答案,因为存储的且 O(1) ,又dp关系仅限于4个数字之间，因此只用4个数字即可。

#### 代码:

```java
public class Solution {
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] houseMoneys) {
		if(null == houseMoneys || houseMoneys.length <= 0)
			return 0;
		if(houseMoneys.length == 1)
			return houseMoneys[0];
		if(houseMoneys.length == 2)
		{
			return Math.max(houseMoneys[0], houseMoneys[1]);
		}
		
		if(houseMoneys.length == 3)
		{
			return Math.max(houseMoneys[1], houseMoneys[0] + houseMoneys[2]);
		}
		
		long[] max = new long[4];
		max[0] = houseMoneys[0];
		max[1] = houseMoneys[1];
		max[2] = Math.max(houseMoneys[1], houseMoneys[0] + houseMoneys[2]);
		
		for(int i = 3;i < houseMoneys.length;i++)
		{
			max[3] = houseMoneys[i] + Math.max(max[0], max[1]);
			if(i == houseMoneys.length - 1)
				continue;
			max[0] = max[1];
			max[1] = max[2];
			max[2] = max[3];
		}
		
		return Math.max(max[3], max[2]);
	}
}

```
