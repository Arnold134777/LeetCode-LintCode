/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {

	if(n <= 2){
		return n;
	}

	var lastOneStepResult = 1;
	var lastTwoStepResult = 2;

	while(n > 2){
		n--;
		var temp = lastTwoStepResult;
		lastTwoStepResult = lastOneStepResult + lastTwoStepResult;
		lastOneStepResult = temp;
	}  

	return lastTwoStepResult;
};

console.log(climbStairs(3));
console.log(climbStairs(4));
console.log(climbStairs(5));
console.log(climbStairs(6));