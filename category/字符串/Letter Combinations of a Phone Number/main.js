/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {

    if(digits === undefined || digits.length <= 0){
    	return [];
    }

    var result = [""];
    var existException = false;
	var phoneNumMap = {
		'2':"abc",
		'3':"def",
		'4':"ghi",
		'5':"jkl",
		'6':"mno",
		'7':"pqrs",
		'8':"tuv",
		'9':"wxyz"
	};

	for(var i = 0; i < digits.length;i++){
		var nums = phoneNumMap[digits[i]];
		if(nums === undefined){
			existException = true;
			break;
		}
		var newResult = [];
		for(var j = 0;j < result.length;j++){
			for(var k = 0;k < nums.length;k++){
				var newNum = result[j] + nums[k];
				newResult.push(newNum);
			}
		}
		result = newResult.slice(0);
	}

	return !existException ? result : [];
};

console.log(letterCombinations("239f"));
