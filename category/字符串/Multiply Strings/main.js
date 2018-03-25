/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
	if(num1 === undefined || num2 === undefined || num1.length <= 0 || num2.length <= 0){
		return "";
	}

	if(num1.length < num2.length){
		var temp = num1;
		num1 = num2;
		num2 = temp;
	}

	var result = "0";
	var suffix = "";
	for(var i = num2.length - 1;i >= 0;i--){

		if(i !== num2.length - 1){
			suffix += "0";
		}

		if(num2[i] === '0'){
			continue;
		}

		var eachMultiplyResult = ""; 
		var temp = 0;
		var multiplier = num2[i] - '0';
		for(var j = num1.length - 1;j >= 0;j--) {
			var bitResult = (num1[j] - '0') * multiplier + temp;
			temp = parseInt(bitResult / 10);
			bitResult = bitResult % 10;
			eachMultiplyResult = bitResult + eachMultiplyResult;
		}

		if(temp > 0){
			eachMultiplyResult = temp + eachMultiplyResult;
		}
		eachMultiplyResult = eachMultiplyResult + suffix;
		result = add(eachMultiplyResult,result);
	}

	return result;
};

var add = function(num1,num2) {

	var length1 = num1.length;
	var length2 = num2.length;
	var maxLength = Math.max(length1,length2);

	for(var i = length1 + 1;i <= maxLength;i++){
		num1 = "0" + num1;
	}

	for(var i = length2 + 1;i <= maxLength;i++){
		num2 = "0" + num2;
	}

	var result = "";
	var temp = 0;

	for(var i = maxLength - 1;i >= 0;i--){
		var bitResult = (num1[i] - '0') + (num2[i] - '0') + temp;
		temp = parseInt(bitResult / 10);
		bitResult = bitResult % 10;
		result = bitResult + result;
	}

	if(temp >= 1){
		result = "1" + result;
	}

	return result;
};



console.log(multiply("0", "1234567"));