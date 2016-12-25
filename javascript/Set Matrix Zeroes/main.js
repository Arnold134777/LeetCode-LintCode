/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
	var matrixDic = {};
	for(var i = 0;i < matrix.length;i++){
		for(var j = 0;j < matrix[0].length;j++){
			if(matrix[i][j] === 0){
				matrixDic["row_" + i] = 1;
				matrixDic["col_" + j] = 1;
			}
		}
	}

	for(var i = 0;i < matrix.length;i++){
		for(var j = 0;j < matrix[0].length;j++){
			if(matrixDic["row_" + i] === 1 || matrixDic["col_" + j] === 1){
				matrix[i][j] = 0;
			}
		}
	}
};

var result = setZeroes([[1,1,1],
						[1,1,2],
						[1,2,0]]);

