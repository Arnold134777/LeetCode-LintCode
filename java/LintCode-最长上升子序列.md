title: LintCode 最长上升子序列
date: 2016-03-20 22:28:36
tags: [算法,LintCode,动态规划]
---

给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。

#### 说明
最长上升子序列的定义：

最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

#### 样例

给出[5,4,1,2,3]，这个LIS是[1,2,3]，返回 3

给出[4,2,4,5,3,7]，这个LIS是[4,4,5,7]，返回 4

#### 分析

第一种做法(常规做法):<br>
时间复杂度:O(n^2)

```java
public class Solution {
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    public int longestIncreasingSubsequence(int[] nums) {
		if(null == nums || nums.length <= 0)
			return 0;
		int[] logestSequences = new int[nums.length + 1];
		logestSequences[0] = 1;
		for(int i = 1;i < nums.length;i++)
		{
			logestSequences[i] = 1;
			for(int j = 0;j < i;j++)
			{
				if(nums[i] >= nums[j] && (logestSequences[j] + 1 > logestSequences[i])) // 核心代码
				{
					logestSequences[i] = logestSequences[j] + 1;
				}
			}
		}
		
		int longestIncreasingSubsequence = -1;
		for(int i = 0;i < nums.length;i++)
		{
			if(logestSequences[i] > longestIncreasingSubsequence)
			{
				longestIncreasingSubsequence = logestSequences[i];
			}
		}
		return longestIncreasingSubsequence;
    }
}

```

第二种做法(贪心策略)：<br>
时间复杂度:O(n*lg(n))

分析：开一个栈，每次取栈顶元素top和读到的元素temp做比较，如果temp > top 则将temp入栈；如果temp < top则二分查找栈中的比temp大的第1个数，并用temp替换它。 最长序列长度即为栈的大小top。
这也是很好理解的，对于x和y，如果x < y且Stack[y] < Stack[x],用Stack[x]替换Stack[y]，此时的最长序列长度没有改变但序列Q的''潜力''增大了。<br>

举例：原序列为1，5，8，3，6，7
栈为1，5，8，此时读到3，用3替换5，得到1，3，8； 再读6，用6替换8，得到1，3，6；再读7，得到最终栈为1，3，6，7。最长递增子序列为长度4。

```java
public class Solution {
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    public int longestIncreasingSubsequence(int[] nums) {
		if(null == nums || nums.length <= 0)
			return 0;
		if(nums.length == 1)
			return 1;
		int[] subsequenceStack = new int[nums.length + 1];
		int top = 0;
		subsequenceStack[0] = -1;
		
		for(int i = 0;i < nums.length;i++)
		{
			if(nums[i] >= subsequenceStack[top])
			{
				top++;
				subsequenceStack[top] = nums[i];
			}
			else
			{
				int low = 0;
				int high = top;
				while(low <= high)
				{
					int middle = (low + high) / 2;
					if(nums[i] < subsequenceStack[middle])
					{
						high = middle - 1;
					}
					else
					{
						low = middle + 1;
					}
				}
				subsequenceStack[low] = nums[i];
			}
		}
		return top;
    }
}

```
