
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
};

/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
  return buildTreeNode(postorder,0,postorder.length - 1,inorder,0,inorder.length - 1);
};

var buildTreeNode = function(postorder,postorderStart,postorderEnd,inorder,inorderStart,inorderEnd){
	if(postorderStart > postorderEnd || inorderStart > inorderEnd){
		return null;
	}

	var rootValue = postorder[postorderEnd];
	var rootIndex = 0;
	for(var i = inorderStart;i <= inorderEnd;i++){
		if(inorder[i] === rootValue){
			rootIndex = i;
			break;
		}
	}

	var length = rootIndex - inorderStart;
	var root = new TreeNode(rootValue);
	root.left = buildTreeNode(postorder,postorderStart,postorderStart + length - 1,inorder,inorderStart,rootIndex - 1);
	root.right = buildTreeNode(postorder,postorderStart + length,postorderEnd - 1,inorder,rootIndex + 1,inorderEnd);
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

print(buildTree([4,2,5,1,6,3,7],[4,5,2,6,7,3,1]));

