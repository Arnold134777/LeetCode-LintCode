
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {

	var romanNumMap = {
		'I' : 1,
		'V' : 5,
		'X' : 10,
		'L' : 50,
		'C' : 100,
		'D' : 500,
		'M' : 1000
	};

	var total = romanNumMap[s[0]];

	var pre = romanNumMap[s[0]];
	for(var index = 1;index < s.length;index++){
		var curr = romanNumMap[s[index]];
		if(curr <= pre){
			total += curr;
		}else{
			total += (curr - 2 * pre);
		}
		pre = curr;
	}

	return total;
};

console.log(romanToInt("IV"));
console.log(romanToInt("CD"));
console.log(romanToInt("MMMCMXCIV"));

