/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

var exist = function(board, word) {
	if(word.length <= 0 || board.length <= 0){
		return false;
	}

	var mark = [];
	for(var i = 0;i < board.length;i++){
		var eachRow = [];
		for(var j = 0;j < board[0].length;j++){
			eachRow[j] = 0;
		}
		mark[i] = eachRow;
	}

	for(i = 0;i < board.length;i++){
		for(j = 0;j < board[0].length;j++){
			mark[i][j] = 1;
			if(board[i][j] === word.charAt(0) && findWord(i,j,board,word,mark,1)){
				return true;
			}else{
				mark[i][j] = 0;
			}
		}
	}

	return false;
};

var findWord = function(startX,startY,board,word,mark,index){

	if(index >= word.length){
		return true;
	}
  console.log(mark);
	// 左
	if(startY > 0 && mark[startX][startY - 1] === 0 && board[startX][startY - 1] === word.charAt(index)){
		mark[startX][startY - 1] = 1;
		if(!findWord(startX,startY - 1,board,word,mark,index + 1)){
			mark[startX][startY - 1] = 0;
		}else{
			return true;
		}
	}

	// 右
	if(startY < board[0].length - 1  && mark[startX][startY + 1] === 0 && board[startX][startY + 1] === word.charAt(index)){
		mark[startX][startY + 1] = 1;
		if(!findWord(startX,startY + 1,board,word,mark,index + 1)){
			mark[startX][startY + 1] = 0;
		}else{
			return true;
		}
	}

	// 左
	if(startX > 0 && mark[startX - 1][startY] === 0 && board[startX - 1][startY] === word.charAt(index)){
		mark[startX - 1][startY] = 1;
		if(!findWord(startX - 1,startY,board,word,mark,index + 1)){
			mark[startX - 1][startY] = 0;
		}else{
			return true;
		}
	}

	// 右
	if(startX < board.length - 1 && mark[startX + 1][startY] === 0 && board[startX + 1][startY] === word.charAt(index)){
		mark[startX + 1][startY] = 1;
		if(!findWord(startX + 1,startY,board,word,mark,index + 1)){
			mark[startX + 1][startY] = 0;
		}else{
			return true;
		}
	}

  return false;
};

console.log(exist([
  ['A','A']
],"AAA"));
