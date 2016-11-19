## Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

#### 分析：
>* 1.area的计算原则为是min(height[j],height[i])*(j - i)
>* 2.首尾两个标记依次往中间移动，移动的原则是height小的往中间移动，去尝试寻找更大的height，比较找到最终的maxArea