/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {

	const INT_MAX = 2147483647;
	const INT_MIN = -2147483648;
	if(str === undefined || str.length <= 0){
		return 0;
	}

	// 1.预先处理掉头部的空格与0
	var leftIndex = 0;
	for(var index = 0;index < str.length;index++){
		if(str[index] !== ' ' && str[index] !== '0'){
			break;
		}
	}
	leftIndex = index;
	str = str.substring(leftIndex,str.length);

	// 2.处理掉头部的+-符号
    var isNegative = false;
    var startIndex = 0;
    var isNaN = false;
    var hasPrefixSymbol = false;
	if(str[0] === '-' || str[0] === '+'){
		isNegative = (str[0] === '-');
		hasPrefixSymbol = true;
		startIndex = 1;
	}

	//console.log(leftIndex + " " + rightIndex + " " + str);

	var result = 0;
	for(;startIndex <= str.length - 1;startIndex++){
		if(str[startIndex] < '0' || str[startIndex] > '9'){
			isNaN = true;
			break;
		}
		result = result * 10 + (str[startIndex] - '0');
	}

    if(result === 0){
		return 0;
	}

	isNegative && (result *= -1);
	if(result > INT_MAX){
		result = INT_MAX;
	}else if(result < INT_MIN){
		result = INT_MIN;
	}

	return result;
};

console.log(myAtoi("-0012a42"));
console.log(myAtoi("+"));
console.log(myAtoi("    010"));
console.log(myAtoi("1"));

