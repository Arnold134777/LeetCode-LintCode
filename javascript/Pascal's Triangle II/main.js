
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var getRow = function(rowIndex) {
	if(rowIndex < 0){
		return [];
	}

	var preNumber = [];
	var currentNumber = [];
	for(var i = 1;i <= rowIndex + 1;i++){
		if(i >= 2){
			preNumber = currentNumber.slice(0)
			currentNumber = [];
		}
		for(var j = 0;j < i;j++){
			if(j === 0 || j === i - 1){
				currentNumber[j] = 1;
			}else{
				currentNumber[j] = preNumber[j - 1] + preNumber[j];
			}
		}
	}

	return currentNumber;
};

console.log(getRow(0));