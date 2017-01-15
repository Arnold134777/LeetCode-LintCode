
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
};

/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
	return buildTreeNode(preorder,0,preorder.length - 1,inorder,0,inorder.length - 1);
};

var buildTreeNode = function(preorder,preorderStart,preorderEnd,inorder,inorderStart,inorderEnd){
	if(preorderStart > preorderEnd || inorderStart > inorderEnd){
		return null;
	}

	var rootValue = preorder[preorderStart];
	var rootIndex = 0;
	for(var i = inorderStart;i <= inorderEnd;i++){
		if(inorder[i] === rootValue){
			rootIndex = i;
			break;
		}
	}

	var length = rootIndex - inorderStart;
	var root = new TreeNode(rootValue);
	root.left = buildTreeNode(preorder,preorderStart + 1,preorderStart + length,inorder,inorderStart,rootIndex - 1);
	root.right = buildTreeNode(preorder,preorderStart + length + 1,preorderEnd,inorder,rootIndex + 1,inorderEnd);
	return root;
};

var print = function(root){
	console.log(root.val);
	if(root.left){
		print(root.left);
	}

	if(root.right){
		print(root.right);
	}
};

print(buildTree([1,2,4,5,3,6,7],[4,2,5,1,6,3,7]));

