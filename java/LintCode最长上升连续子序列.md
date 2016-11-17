title: LintCode最长上升连续子序列
date: 2015-12-05 20:36:33
tags: [算法,动态规划,LintCode]
---
给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。（最长上升连续子序列可以定义为从右到左或从左到右的序列。）

代码如下：
```java
public class Solution {
    /**
     * @param A an array of Integer
     * @return  an integer
     */
   public int longestIncreasingContinuousSubsequence(int[] nums) {
		if(null == nums || nums.length <= 0)
			return 0;
		int ascendCount = 1;
		int maxAscendCount = -1;
		for(int i = 1;i < nums.length;i++)
		{
			if(nums[i] > nums[i - 1])
			{
				ascendCount++;
				if(ascendCount > maxAscendCount)
				{
					maxAscendCount = ascendCount;
				}
			}
			else
			{
				ascendCount = 1;
			}
		}
		
		if(ascendCount > maxAscendCount)
		{
			maxAscendCount = ascendCount;
		}
		ascendCount = 1;
		for(int i = nums.length - 1;i >= 1;i--)
		{
			if(nums[i] < nums[i - 1])
			{
				ascendCount++;
				if(ascendCount > maxAscendCount)
				{
					maxAscendCount = ascendCount;
				}
			}
			else
			{
				ascendCount = 1;
			}
		}
		return maxAscendCount;
	}
}
```

