
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
	if(x <= 0) {
		return 0;
	}

	if(x <= 3) {
		return 1;
	}

	var left = 2;
	var right = parseInt(x / 2);
	var result;

	while(true){
		console.log(left + " " + right)
		if(right - left <= 1){
			result = (right * right === x ? right : left);
			break;
		}

		var middle = parseInt((left + right) / 2);
		var product = middle * middle;
		if(product > x) {
			right = middle;
		}else if(product < x){
			left = middle;
		}else{
			result = middle;
			break;
		}
	}

	return result ? result : left;
};

console.log(mySqrt(5));

