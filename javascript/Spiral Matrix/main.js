/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  if(matrix.length <= 0){
    return [];
  }

  var number = [];
  var row = matrix.length;
  var col = matrix[0].length;
  var rotateCount = parseInt((Math.min(row, col) + 1) / 2);

  for(var i = 0;i < rotateCount;i++){
    var startX = i;
    var startY = i;
    var endX = row - 1 - i;
    var endY = col - 1 - i;
    var j;
    if(startX === endX){
      for(j = startY; j <= endY; j++){
        number.push(matrix[startX][j]);
      }
      break;
    }else if(startY === endY){
      for(j = startX; j <= endX; j++){
        number.push(matrix[j][startY]);
      }
      break;
    }

    for(j = startY;j <= endY - 1;j++){
      number.push(matrix[startX][j]);
    }

    for(j = startX;j <= endX - 1;j++){
      number.push(matrix[j][endY]);
    }

    for(j = endY;j > startY;j--){
      number.push(matrix[endX][j]);
    }

    for(j = endX;j > startX;j--){
      number.push(matrix[j][startY]);
    }
  }

  return number;
};

var result = spiralOrder([
 [ 1]
]);
console.log(result);
