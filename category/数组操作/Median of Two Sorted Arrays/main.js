
var reverse = function(x) {

	// 0.取正
	var isNegative = false;
	if(x < 0){
		x = -1 * x;
		isNegative = true;
	}

	// 1.首先去除最后的0
	while(x % 10 === 0 && x !== 0){
		x = x / 10;
	}

	// 2.计算位数
	var tempNum = parseInt(x / 10);
	var digitNum = 1;
	while(tempNum > 0){
		digitNum *= 10;
		tempNum = parseInt(tempNum / 10);
	}

	// 3.按照位计算结果
	var result = 0;
	while(x > 0){
		result += digitNum  * (x % 10);
		x = parseInt(x / 10);
		digitNum /= 10;
	}

	if(result > Math.pow(2,31)){
         return 0;
    }

	return isNegative ? result * -1 : result;
};

console.log(reverse(12));