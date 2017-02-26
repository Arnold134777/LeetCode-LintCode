## 4Sum

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).**
    
### 分析

#### 第一种解法：(O(n3) 耗时：182ms)
> * 与3Sum题的解法类似，加一层for循环即可。
> 

#### 第一种解法：(O(n2) - O(n4) 耗时：400-500ms)
> * 维护一个2个数字和的hashMap，然后利用2sum去处理这个hashMap,即hashMap[sum1],hashMap[sum2],满足sum1 + sum2 == target;
> 

### 疑点：本尝试第二种解法的效率更高，但是实际耗时更长，与cases可能有关系。