title: LintCode 不同的子序列
date: 2015-12-20 15:32:57
tags: [LintCode,算法,动态规划]
---
给出字符串S和字符串T，计算S的不同的子序列中T出现的个数。

子序列字符串是原始字符串通过删除一些(或零个)产生的一个新的字符串，并且对剩下的字符的相对位置没有影响。(比如，“ACE”是“ABCDE”的子序列字符串,而“AEC”不是)。 
样例
给出S = "rabbbit", T = "rabbit"

返回 3

分析：这里我们可以用f(i,j)表示S中前i个字符串中，T的前j个字符出现的次数，不管S[i]和T[j]相不相等，首先f(i,j)=f(i-1,j)，其次要是S[i]==T[j]的话，f(i,j) = f(i-1,j)+f(i-1,j-1),可以看到，i的状态只与i-1有关，于是可以用滚动数组来进行优化。代码类似01背包。

```java
public class Solution {
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
   public int numDistinct(String S, String T) {
		if(null == S || null == T)
			return 0;
		// commons 表示S中的前i个字符包含T的前j个字符的个数
		int[][] commons = new int[S.length() + 1][T.length() + 1];
		for(int i = 0;i <= S.length();i++)
		{
			commons[i][0] = 1;
		}
		for(int i = 1;i <= S.length();i++)
		{
			for(int j = 1;j <= T.length();j++)
			{
				
				if(S.charAt(i - 1) != T.charAt(j - 1))
				{
					// 不包含S中的第i个
					commons[i][j] = commons[i - 1][j];
				}
				else
				{
					// dp思想，匹配结果分为包含S中的第i个与不包含第i个两种
					commons[i][j] = commons[i - 1][j - 1] +  commons[i - 1][j];
				}
			}
		}		
		return commons[S.length()][T.length()];
	}
}
```

