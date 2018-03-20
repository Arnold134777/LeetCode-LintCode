/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
	if(s === undefined || s.length <= 0 || s.length % 2 === 1){
		return false;
	}    

	var stack = [];
	var characters = [
		'(',')',
		'{','}',
		'[',']'
	];
	var result = true;
	for(var index = 0; index < s.length;index++){
		var character = s[index];
		var characterIndex = characters.indexOf(character);
		if(characterIndex === -1){
			result = false;
			break;
		}
		if(character === '(' || character === '{' || character === '['){
			stack.push(character);
		}else{

			if(stack.length <= 0 || stack[stack.length - 1] !== characters[characterIndex - 1]){
				result = false;
				break;
			}else{
				stack.pop();
			}
		}
	}

	return result && stack.length <= 0;
};

console.log(isValid("({"));
console.log(isValid("{[()]}(){}"));
