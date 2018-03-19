/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
	if(strs === undefined || strs.length <= 0){
		return "";
	}  

	var result = strs[0];

	for(var index = 1;index < strs.length;index++){
		var currentStr = strs[index];
		result = commonPrefix(result,currentStr);
	}

	return result;
};

var commonPrefix = function(firstStr,secondStr){
	var commonPrefix = "";
	for(var index = 0;index < firstStr.length;index++){
		if(secondStr.length - 1 < index || secondStr[index] !== firstStr[index]){
			break;
		}

		commonPrefix += firstStr[index];
	}
	return commonPrefix;
};

console.log(longestCommonPrefix(["","abd","abd"]));