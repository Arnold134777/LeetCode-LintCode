/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
	if(n <= 0) {
		return "";
	}
	var originStr = "1";
	for(var i = 2;i <= n;i++) {
		var character = originStr[0];
		var count = 1;
		var newStr = "";
		for(var j = 1;j < originStr.length;j++) {
			if(originStr[j] === character){
				count++;
			}else{
				newStr += (count.toString() + character);
				count = 1;
				character = originStr[j];
			}
		}
		newStr += (count.toString() + character);
		originStr = newStr;

	}

	return originStr;
};

console.log(countAndSay(2));
console.log(countAndSay(3));
console.log(countAndSay(4));
console.log(countAndSay(5));
console.log(countAndSay(10));
