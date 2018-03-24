/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
	if(a === undefined && b === undefined) {
		return "";
	}

	var result = "";

	var aIndex = a.length - 1;
	var bIndex = b.length - 1;
	var bitSum = 0;

	while(aIndex >= 0 || bIndex >= 0){
		var bitResult = (aIndex >= 0 ? (a[aIndex] - '0') : 0) + (bIndex >= 0 ? (b[bIndex] - '0') : 0) + bitSum;
		if(bitResult >= 2){
			bitResult = bitResult % 2;
			bitSum = 1;
		}else{
			bitSum = 0;
		}
		aIndex--;
		bIndex--;
		result = bitResult + result;
	}

	if(bitSum === 1){
		result = "1" + result;
	}

	return result;
};

console.log(addBinary("1111","1111"));