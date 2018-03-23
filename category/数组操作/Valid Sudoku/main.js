/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
	if(board === undefined || board.length < 9 || board[0].length < 9){
		return false;
	}

	var rowMaps= [];
	var colMaps = [];
	var gridMaps = [];

    // 按照行，列，小方块先标记所有的存在的数字
    var isValidSudoku = true;
	for(var i = 0;i < 9 && isValidSudoku;i++){
		rowMaps.push({});
		var rowMap = rowMaps[i];
		for(var j = 0;j < 9;j++) {
			var colMap;
			var gridMap;
			if(colMaps.length <= j){
				colMap = {};
				colMaps.push(colMap);
			} 
			colMap = colMaps[j];
			
			var gridIndex = parseInt(i / 3) * 3 + parseInt(j / 3);
			if(gridMaps.length <= gridIndex){
				gridMap = {};
				gridMaps.push(gridMap);
			} 
			gridMap = gridMaps[gridIndex];
			
			var character = board[i][j];
			if(character !== "."){
				if(rowMap[character] || colMap[character] || gridMap[character]){
					isValidSudoku = false;
					break;
				}

				rowMap[character] = true;
				colMap[character] = true;
				gridMap[character] = true;
			}
		}
	}

	return isValidSudoku;
};

// 题意理解错了还认为需要尝试填写数字
var tryValidSuduko = function(row,col,count,board,rowMaps,colMaps,gridMaps){

	var characters = ["1","2","3","4","5","6","7","8","9"];
	if(count === 81){
		console.log(board);
		return true;
	}

    // 跳转条件
	if(row >= 9){
		return false;
	}

	var newRow;
	var newCol;
	if(col >= 8){
		newRow = row + 1;
		newCol = 0;
	}else{
		newRow = row;
		newCol = col + 1;
	}

	var isValidSudoku = false;
	if(board[row][col] === "."){
		var rowMap = rowMaps[row];
		var colMap = colMaps[col];
		var gridIndex = parseInt(row / 3) * 3 + parseInt(col / 3);
		var gridMap = gridMaps[gridIndex];

		for(var index = 0;index < characters.length;index++){
			var character = characters[index];
			if(rowMap[character] === true || colMap[character] === true || gridMap[character] === true){
				continue;
			}
			console.log(board);
			board[row][col] = character;
			rowMap[character] = true;
			colMap[character] = true;
			gridMap[character] = true;

			if(tryValidSuduko(newRow,newCol,count + 1,board,rowMaps,colMaps,gridMaps)){
				isValidSudoku = true;
				break;
			}else{
				board[row][col] = ".";
				board[row][col] = character;
				rowMap[character] = undefined;
				colMap[character] = undefined;
				gridMap[character] = undefined;
			}
		}
	}else{
		isValidSudoku = tryValidSuduko(newRow,newCol,count + 1,board,rowMaps,colMaps,gridMaps);
	}

	return isValidSudoku;
};


var board = [
[".","8","7","6","5","4","3","2","1"],
["2",".","8",".",".",".",".",".","."],
["3",".",".",".",".",".",".",".","."],
["4",".",".",".",".",".",".",".","."],
["5",".",".",".",".",".",".",".","."],
["6",".",".",".",".",".",".",".","."],
["7",".",".",".",".",".",".",".","."],
["8",".",".",".",".",".",".",".","."],
["9",".",".",".",".",".",".",".","."]];
console.log(isValidSudoku(board)); 

