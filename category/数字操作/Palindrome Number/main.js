
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {

	if(x < 0){
		return false;
	}

	var tempNum = x;
	var digit = 0;
	while(tempNum > 0){
		digit++;
		tempNum = parseInt(tempNum / 10);
	}
	
	var reverseNum = 0;
	tempNum = x;
	while(tempNum > 0){
		reverseNum += Math.pow(10,digit - 1) * (tempNum % 10);
		digit--;
		tempNum = parseInt(tempNum / 10);
	}

	return reverseNum === x;
};

console.log(isPalindrome(100));

