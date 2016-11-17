title: LintCode 最大间距
date: 2015-11-23 12:25:25
tags: [算法,LintCode]
---


------
http://www.lintcode.com/zh-cn/problem/maximum-gap/

最大间距 查看运行结果 

给定一个未经排序的数组，请找出其排序表中连续两个要素的最大间距。

如果数组中的要素少于 2 个，请返回 0.

您在真实的面试中是否遇到过这个题？ Yes
样例
给定数组 [1, 9, 2, 5]，其排序表为 [1, 2, 5, 9]，其最大的间距是在 5 和 9 之间，= 4.

注意
可以假定数组中的所有要素都是非负整数，且最大不超过 32 位整数。

挑战
排序十分简单，但将使用 O(nlogn) 时间复杂度。请避免使用线性时间复杂度和空间。

##代码:
```java
class Solution {
    /**
     * @param nums: an array of integers
     * @return: the maximum difference
     */
   public int maximumGap(int[] nums) {
		if(null == nums || nums.length < 2)
		{
			return 0;
		}
		
		int length = nums.length;
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;   
		
		for(int i = 0;i < length;i++)
		{
			if(nums[i] < min)
			{
				min = nums[i];
			}
			
			if(nums[i] > max)
			{
				max = nums[i];
			}
		}
		// 桶的概念
		int bucketCapacity = (max - min) / length + 1;
		int bucketNumber = (max - min) / bucketCapacity + 1;
		int[] minBuckets = new int[bucketNumber];
		int[] maxBuckets = new int[bucketNumber];
		int maxDistance = 0;
		
		for(int i = 0;i < bucketNumber;i++)
		{
			minBuckets[i] = Integer.MAX_VALUE;
			maxBuckets[i] = Integer.MIN_VALUE;
		}
		
		for(int i = 0;i < length;i++)
		{
			int index = (nums[i] - min) / bucketCapacity;
			if(minBuckets[index] > nums[i])
			{
				minBuckets[index] = nums[i];
			}
			
			if(maxBuckets[index] < nums[i])
			{
				maxBuckets[index] = nums[i];
			}
		}
	
		int pre = 0;
		for(int i = 1;i < bucketNumber;i++)
		{
			if(minBuckets[i] == Integer.MAX_VALUE && maxBuckets[i] == Integer.MIN_VALUE)
				continue;
			if(minBuckets[i] - maxBuckets[pre] > maxDistance)
			{
				maxDistance = minBuckets[i] - maxBuckets[pre]; // 因为最大间距不可能在一个桶内，否则bucketNumber ＊ maxDistance > length;
			}
			pre = i;
		}
		return  maxDistance;
	}
}
```



