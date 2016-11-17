title: LintCode 编辑距离
date: 2015-12-20 19:26:44
tags: [LintCode,算法,动态规划]
---

给出两个单词word1和word2，计算出将word1 转换为word2的最少操作次数。

你总共三种操作方法：

插入一个字符
删除一个字符
替换一个字符

样例
给出 work1="mart" 和 work2="karma"

返回 3

分析:minSteps[i][j]表示word1的前i个字符改为word2的前j个字符的最少操作数，因此有转移方程
minSteps[i][j] = 
{
   minSteps[i - 1][j - 1];(word1[i] == wrod2[j])
min(minSteps[i - 1][j - 1],minSteps[i][j - 1],minSteps[i - 1][j]);(word1[i] != wrod2[j])
} 

```java
public class Solution {
	public int minDistance(String word1, String word2) {
		if(null == word1 || null == word2)
			return 0;
		
		int[][] minSteps = new int[word1.length() + 1][word2.length() + 1];
		for(int i = 0;i <= word1.length();i++)
		{
			minSteps[i][0] = i;
		}
		
		for(int i = 0;i <= word2.length();i++)
		{
			minSteps[0][i] = i;
		}
		
		for(int i = 1;i <= word1.length();i++)
		{
			for(int j = 1;j <= word2.length();j++)
			{
				if(word1.charAt(i - 1) == word2.charAt(j - 1))
				{
					minSteps[i][j] = minSteps[i - 1][j - 1];
				}
				else
				{
					minSteps[i][j] = Math.min(minSteps[i - 1][j - 1], Math.min(minSteps[i - 1][j], minSteps[i][j - 1])) + 1;
				}
			}
		}
		return minSteps[word1.length()][word2.length()];
	}
};
```
