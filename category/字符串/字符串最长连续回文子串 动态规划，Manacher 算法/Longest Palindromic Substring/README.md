# 最长连续回文串Swift实现

## 题目：[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

**Example:**

```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
```

**Example:**

```
Input: "cbbd"

Output: "bb"
```

## 算法分析

### 解法一：
> 暴力解法，时间复杂度：O(n^n)。

遍历每一个字符，然后左右依次向两边比较是否相等，继而判断是否满足回文串的条件，找出最长即可。注意需要判断回文长度为奇，偶长度的情况。

### 解法二：
> * 动态规划，时间复杂度:O(n^2)。
dp[i][j] 表示从i~j的子串是否是回文串。

动态转移方程：

```
dp[i][j] = {
	dp[i-1][j + 1] : s[i] == s[j],
	false          : s[i] != s[j]
}
```

Swift实现

```
class Solution {
    func longestPalindrome(_ s: String) -> String {
        var dp:[[Bool]] = [];
        if s.count <= 1{
            return s;
        }
        
        var longest:Int = 1;
        var left:Int = 0;
        var right:Int = 0;
        
        for var i in 0...s.count - 1{
            var eachRow:[Bool] = [];
            for var j in 0...s.count - 1{
                if i == j{
                    eachRow.append(true);
                }else{
                    eachRow.append(false);
                }
            }
            dp.append(eachRow);
        }
        
        var i:Int = 0;
        var j:Int = 0;
        for var character_j in s {
            if j == 0 {
                j += 1;
                continue;
            }
            i = 0;
            for var character_i in s {
                if character_i == character_j {
                    dp[i][j] = dp[i + 1][j - 1] || j - i <= 1;
                    if dp[i][j] && j - i + 1 > longest{
                        longest = j - i + 1;
                        left = i;
                        right = j;
                    }
                }else{
                    dp[i][j] = false;
                }
                i += 1;
                if i >= j{
                    break;
                }
            }
            j += 1;
        }
        let leftIndex = s.index(s.startIndex, offsetBy: left);
        let rightIndex = s.index(s.startIndex, offsetBy: right);
        return String(s[leftIndex...rightIndex]);
    }
}
```

AC结果：可能是swift处理字符串的效率问题会超时。

```
Time Limit Exceeded
```

### 第三种解法

> * Manacher算法,时间复杂度：O(n)。

[Manacher's ALGORITHM: O(n)时间求字符串的最长回文子串](https://www.felix021.com/blog/read.php?2040)思路分析这里介绍的很清晰，
此处只是简单介绍与Swift实现。

#### 首先解决回文长度为奇偶的问题
> * 插桩处理，整个字符串的前后间隔处插入'#'字符，最终得到的字符串就一定是奇数长度，回文的长度也一定是奇数长度。

我们来举一个例子："cbbd"。先进行插桩处理 -> "#c#b#b#d#"。我们定义一个数组`P[i]`用来记录以i处的字符作为轴心的最大的回文半径。我们自己计算得到如下的对应关系：

```
# c # b # b # d #
1 2 1 2 3 2 1 2 1
```

#### 解决计算`P[i]`问题

我们增加两个辅助量`id`,`max`分别代表当前计算的到最右边回文覆盖的轴心与最右下标。借用[Manacher's ALGORITHM: O(n)时间求字符串的最长回文子串](https://www.felix021.com/blog/read.php?2040)中的两张图解：

当 mx - i > P[j] 的时候，以S[j]为中心的回文子串包含在以S[id]为中心的回文子串中，由于 i 和 j 对称，以S[i]为中心的回文子串必然包含在以S[id]为中心的回文子串中，所以必有 P[i] = P[j]，见下图。

![](https://github.com/Arnold134777/LeetCode-LintCode/raw/master/category/%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%8CManacher%20%E7%AE%97%E6%B3%95/Longest%20Palindromic%20Substring/1.png)

当 P[j] >= mx - i 的时候，以S[j]为中心的回文子串不一定完全包含于以S[id]为中心的回文子串中，但是基于对称性可知，下图中两个绿框所包围的部分是相同的，也就是说以S[i]为中心的回文子串，其向右至少会扩张到mx的位置，也就是说 P[i] >= mx - i。至于mx之后的部分是否对称，就只能老老实实去匹配了。
![](https://github.com/Arnold134777/LeetCode-LintCode/raw/master/category/%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%8CManacher%20%E7%AE%97%E6%B3%95/Longest%20Palindromic%20Substring/2.png)

得到的计算的方程式：

```
//记j = 2 * id - i，也就是说 j 是 i 关于 id 的对称点(j = id - (i - id))
P[i] = {
	P[j] ,mx - i > P[j]
	mx - i, mx - i <= P[j]
}
```

#### Swift 实现

```swift
class Solution {
    func longestPalindrome(_ s: String) -> String {
        if s.count <= 1 {
            return s;
        }
    
        // 1.间隔之间先插入#
        var newString:String = "#";
        for var character in s {
            newString.append(character);
            newString = newString + "#";
        }
        let characters = Array(newString);
        
        // 2.遍历找出以每个节点作为轴最长半径
        var maxId:Int = 0;
        var max:Int = 0;
        var ids:[Int] = [];
        ids.append(1);
        var maxLength:Int = 1;
        var maxLengthIndex = 0;
        
        for var i in 1...characters.count - 1 {
            var j:Int = maxId - (i - maxId);
            if max > i && j >= 0 {
                ids.append(min(ids[j], max - i));
            }else{
                ids.append(1);
            }
            while i + ids[i] <= characters.count - 1 && i - ids[i] >= 0 && characters[i + ids[i]] == characters[i - ids[i]]{
                ids[i] += 1;
            }
            
            if i + ids[i] - 1 > max {
                maxId = i;
                max = i + ids[i] - 1;
            }
            
            if ids[i] > maxLength{
                maxLength = ids[i];
                maxLengthIndex = i;
            }
        }
        let leftIndex = s.index(s.startIndex, offsetBy: (maxLengthIndex - (maxLength - 1))/2);
        let rightIndex = s.index(leftIndex, offsetBy:maxLength - 1 - 1);
        return String(s[leftIndex...rightIndex]);
    }
}
```

AC结果：
```
Accepted
```


### 参考
https://www.felix021.com/blog/read.php?2040



    
