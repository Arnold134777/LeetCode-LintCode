title: LintCode背包问题
date: 2015-12-13 19:40:06
tags: [算法,动态规划,LintCode]
---

***一：***
在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]

**样例**
如果有4个物品[2, 3, 5, 7]

如果背包的大小为11，可以选择[2, 3, 5]装入背包，最多可以装满10的空间。

如果背包的大小为12，可以选择[2, 3, 7]装入背包，最多可以装满12的空间。

函数需要返回最多能装满的空间大小。

**注意**
你不可以将物品进行切割。

**代码：**
```java
public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
 public int backPack(int m, int[] capacitys) {
		if(capacitys == null || capacitys.length <= 0)
			return 0;
		int[] maxCapacity = new int[m + 1];
		for(int i = 0;i < capacitys.length;i++)
		{
			for(int j = m;j >= 1;j--)
			{
				if(j >= capacitys[i])
				{
					maxCapacity[j] = Math.max(maxCapacity[j - capacitys[i]] + capacitys[i], maxCapacity[j]);
				}
			}
		}
		return maxCapacity[m];
	}
}
```

***二：***
给出n个物品的体积A[i]和其价值V[i]，将他们装入一个大小为m的背包，最多能装入的总价值有多大？

***样例***
对于物品体积[2, 3, 5, 7]和对应的价值[1, 5, 2, 4], 假设背包大小为10的话，最大能够装入的价值为9。

***注意***
A[i], V[i], n, m均为整数。你不能将物品进行切分。你所挑选的物品总体积需要小于等于给定的m。

***代码：***
```java
public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
   public int backPackII(int m, int[] capacitys, int values[]) {
		if(null == capacitys || capacitys.length <= 0 || null == values || values.length <= 0)
			return 0;
		int[] maxValues = new int[m + 1];
		for(int i = 0;i < capacitys.length;i++)
		{
			for(int j = m;j >= 1;j--)
			{
				if(j >= capacitys[i])
				{
					maxValues[j] = Math.max(maxValues[j - capacitys[i]] + values[i], maxValues[j]);
				}
			}
		}
		return maxValues[m];
	}
}
```