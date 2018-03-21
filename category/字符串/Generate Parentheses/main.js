/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
	if(n <= 0){
		return [];
	}

	var result = ["()"];
	var map = {};

	for(var i = 2;i <= n;i++){
		var newResult = [];
		for(var j = 0;j < result.length;j++){
			var str = result[j];
			var index = 0;
			var markIndex = 1;// 标记左括号的数目
			var newStr =  "()" + str;
			if(map[newStr] === undefined){
				map[newStr] = true;
				newResult.push(newStr);
			}
			while(true){
				if(str[index] === '('){
					newStr = str.substring(0,index + 1) + "()" + str.substring(index + 1,str.length);
					if(map[newStr] === undefined){
						map[newStr] = true;
						newResult.push(newStr);
					}
					markIndex++;
				}
				index++;
				if(markIndex >= i){
					break;
				}
			}
		}
		result = newResult.slice(0);
		map = {};
	}

	return result;
};
console.log(generateParenthesis(2));
console.log(generateParenthesis(4).length);