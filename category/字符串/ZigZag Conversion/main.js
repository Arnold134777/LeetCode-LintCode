/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {

	if(s === undefined || s.length <= 0 || numRows <= 1){
		return s;
	}

	var length = s.length;
	var result = "";
    // 记录每行两个元素之间的间隔
    var space = 2 * (numRows - 1);
	for(var row = 0 ;row < numRows;row++){
		var currentIndex = row;
		while(currentIndex < length){

			result += s[currentIndex];
			if(row !== 0 && row !== numRows - 1){
				if(currentIndex + (space - 2 * row) < length){
					result += s[currentIndex + (space - 2 * row)];
				}
			}
			currentIndex += space;
		}
	}

	return result;
    
};

console.log(convert("PAYPALISHIRING", 2));