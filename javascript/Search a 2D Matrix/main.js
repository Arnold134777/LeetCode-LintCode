/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
	if(matrix.length <= 0){
		return false;
	}
	
	var left = 0;
	var right = matrix.length - 1;
	var row = matrix.length - 1;
	var col = matrix[0].length - 1;
	
	if(target < matrix[0][0] || target > matrix[row][col]){
		return false;
	}
    var findMid;
	// 二分查找先找出所在的行
	while(left <= right){
		var mid = parseInt((left + right) / 2);
		if(matrix[mid][0] <= target && target <= matrix[mid][col]){
			findMid = mid;
			break;
		}

		if(matrix[mid][0] > target){
			right = mid - 1;
		}

		if(target > matrix[mid][col]){
			left = mid + 1;
		}
	}

	if(findMid === undefined){
		return false;
	}

	// 二分查找target
	left = 0;
	right = col;
	while(left <= right){
		mid = parseInt((left + right) / 2);
		if(matrix[findMid][mid] === target){
			return true;
		}else if(matrix[findMid][mid] < target){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}

	return false;
};
console.log(searchMatrix([
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
],15));
