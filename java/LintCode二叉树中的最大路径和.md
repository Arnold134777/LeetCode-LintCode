title: LintCode二叉树中的最大路径和
date: 2015-12-13 19:40:48
tags: [算法,动态规划,LintCode]
---

给出一棵二叉树，寻找一条路径使其路径和最大，路径可以在任一节点中开始和结束（路径和为两个节点之间所在路径上的节点权值之和）

样例
给出一棵二叉树：

       1
      / \
     2   3
返回 6

***代码:***
```java
/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: An integer.
     */
   int max = Integer.MIN_VALUE;
	public int maxPathSum(TreeNode root) {
		if(null == root)
		{
			return 0;
		}
		subMaxPathSum(root);
		return max;
        }
	
	public int subMaxPathSum(TreeNode node)
	{
		if(null == node)
		{
			return 0;
		}
		int leftMax = subMaxPathSum(node.left);
		int rightMax = subMaxPathSum(node.right);
		int subMax = Math.max(Math.max(Math.max(leftMax + node.val, rightMax + node.val), node.val),leftMax + rightMax + node.val);
		if(max < subMax)
		{
			max = subMax;
		}
		return Math.max(Math.max(leftMax + node.val, rightMax + node.val), node.val);
	}
}
```
