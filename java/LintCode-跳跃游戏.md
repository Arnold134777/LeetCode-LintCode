title: LintCode 跳跃游戏
date: 2016-01-10 18:34:24
tags: [LintCode,算法,动态规划]
---

给出一个非负整数数组，你最初定位在数组的第一个位置。　　　

数组中的每个元素代表你在那个位置可以跳跃的最大长度。　　　　

判断你是否能到达数组的最后一个位置。

样例
A = [2,3,1,1,4]，返回 true.

A = [3,2,1,0,4]，返回 false.

注意
这个问题有两个方法，一个是贪心和 动态规划。

贪心方法时间复杂度为O（N）。

动态规划方法的时间复杂度为为O（n^2）。

我们手动设置小型数据集，使大家阔以通过测试的两种方式。这仅仅是为了让大家学会如何使用动态规划的方式解决此问题。如果您用动态规划的方式完成它，你可以尝试贪心法，以使其再次通过一次。

#### 分析：
##### 一：动态规划

```java
canJumps[i] = (canJumps[j] && (j + maxSteps[j] >= i));(0 <= j < i)
```

#### 代码：

```java
public class Solution {
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
   public boolean canJump(int[] maxSteps) {
        if(null == maxSteps || maxSteps.length <= 0)
        	return false;
        
        boolean canJumps[] = new boolean[maxSteps.length];
        canJumps[0] = true; 
        for(int i = 1;i < maxSteps.length;i++)
        { 
        	for(int j = 0;j < i;j++)
        	{
        		if(canJumps[i])
        			break;
        		canJumps[i] = (canJumps[j] && (j + maxSteps[j] >= i));
        	}
        }
        return canJumps[maxSteps.length - 1];
    }
}

```

##### 二：贪心做法
自上而下，依此寻找可以一步跳跃到该点的上一个点，且上个点离该点最远,由于是自上而下，所以当当满足最后meet_index == 0时，表示可以满足条件。

#### 代码：

 ```java
 public class Solution {
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
  public boolean canJump(int[] maxSteps) {
        if(null == maxSteps || maxSteps.length <= 0)
        	return false;
        int meetIndex = maxSteps.length - 1;
        for(int i = maxSteps.length - 1;i >= 0;i--)
        {
        	if(i + maxSteps[i] >= meetIndex)
        	{
        		meetIndex = i;
        	}
        }
        return meetIndex == 0;
    }
}
 ```

