
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
	if(numRows <= 0){
		return [];
	}

	var number = [];
	for(var i = 1;i <= numRows;i++){
		var eachRowNumber = [];
		for(var j = 0;j < i;j++){
			if(j === 0 || j === i - 1){
				eachRowNumber[j] = 1;
			}else{
				eachRowNumber[j] = number[i - 2][j - 1] + number[i - 2][j];
			}
		}
		number[i - 1] = eachRowNumber;
	}

	return number;
};

console.log(generate(5));

