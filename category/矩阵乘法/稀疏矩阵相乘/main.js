var multiply = function(matrixA, matrixB) {
	var resultMatrix = [];
	if(matrixA === undefined || matrixB === undefined ||
		matrixA.length <= 0 || matrixB.length <= 0){
		return resultMatrix;
	}

	for(var i in matrixA){
		var eachResultMatrix = [];
		for(var j in matrixB[0]){
			eachResultMatrix.push(0);	
		}
		resultMatrix.push(eachResultMatrix);
	}

	/*
	 第一种解法：暴力解法
	 */
	// for(var i in matrixA){
	// 	for(var k in matrixA[0]){
	// 		for(var j in matrixB[0]){
	// 			resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
	// 		}
	// 	}
	// }

	/*
	 第二种解法：排除0的解法
	 */
	 for(var i in matrixA){
		for(var k in matrixA[0]){
			if(matrixA[i][k] !== 0){
				for(var j in matrixB[0]){
					if(matrixB[k][j] === 0){
						continue;
					}
					resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
	}

	return resultMatrix;
};

var matrixA = [
	[1,0,1],
	[0,0,1],
	[1,1,0],
	[1,0,1]
];

var matrixB = [
	[1,2],
	[3,4],
	[5,6]
];

var resultMatrix = multiply(matrixA, matrixB);
console.log(resultMatrix);
