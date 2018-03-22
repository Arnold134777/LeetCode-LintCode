/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {

	const INT_MAX  = 2147483647;
    const INT_MIN = (-INT_MAX - 1);

	// 标记符号
	var sign = ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) ? true : false;
	if(dividend === 0 || divisor === 0){
		return 0;
	}
    if(dividend === INT_MIN && divisor === -1){
		return INT_MAX;
	}
	var absDividend = Math.abs(dividend);
	var absDivisor = Math.abs(divisor);
	if(absDivisor === 1){
		return (sign ? absDividend : 0 - absDividend);
	}

    // 利用位运算，以2倍的方式递增被除数，计算临界值
	var result = 0;
	while(absDividend >= absDivisor){
		var multiple = 0;
		var num = absDivisor;

		// 注意位运算容易数据超范围变为负数
		while(absDividend >> 1 >= num && num > 0){
			multiple++;
			num = absDivisor << multiple;
		}

		absDividend -= num;
		result += (1 << multiple);
	}

	return sign ? result : 0 - result;
};


console.log(divide(9,1));

