
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {

	if(num <= 0){
		return "";
	}

	var nums = [1000,500,100,50,10,5,1];
	var romans = ['M','D','C','L','X','V','I'];

	var pre;
	var result = "";
	var count = 1;
	while(num > 0){
		var length = result.length;
		var index = currentCharaterIndex(num,nums);
		var roman = romans[index];
		num -= nums[index];
		if(result.length > 0 && roman === result[length - 1]){
			count++;
			if(count >= 4){
				if(length >= 4 && result[length - 4] === romans[index - 1]){
					result = result.substring(0,length - 4) + roman + romans[index - 2];
				}else{
					result = result.substring(0,length - 3) + roman + romans[index - 1];
				}
				count = 1;
				continue;
			}
		}else{
			count = 1;
		}
		result += roman;
	}

	return result;
};

var currentCharaterIndex = function(num,nums){
	var index = 0;
	for(;index < nums.length;index++){
		if(num >= nums[index]){
			break;
		}
	}

	return index;
};

console.log(intToRoman("3999"));
console.log(intToRoman("999"));
console.log(intToRoman("494"));
console.log(intToRoman("9"));
console.log(intToRoman("94"));

