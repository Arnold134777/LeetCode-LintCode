/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
	if(s === undefined || s.length <= 0){
		return 0;
	} 

	var length = 0;
	var index;
	for(index = s.length - 1;index >= 0;index--){
		if(s[index] !== ' '){
			break;
		}
	}

	for(;index >= 0;index--){
		if(s[index] !== ' '){
			length++;
		}else{
			break;
		}
	}

	return length; 
};


console.log(lengthOfLastWord("8  "));