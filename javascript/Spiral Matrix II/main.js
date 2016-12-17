/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
  if(n <= 0){
    return [];
  }
  var matrix = [];
  var rotateCount = parseInt((n + 1) / 2);
  var number = 1;

  for(var i = 0;i < n;i++){
    matrix[i] = [];
  }

  for(i = 0;i < rotateCount;i++){
    var startX = i;
    var startY = i;
    var endX = n - 1 - i;
    var endY = n - 1 - i;
    var j;

   if(startX === endX && startY === endY){
     matrix[startX][startY] = number++;
   }

    for(j = startY;j <= endY - 1;j++){
      matrix[startX][j] = number++;
    }

    for(j = startX;j <= endX - 1;j++){
      matrix[j][endY] = number++;
    }

    for(j = endY;j > startY;j--){
      matrix[endX][j] = number++;
    }

    for(j = endX;j > startX;j--){
      matrix[j][startY] = number++;
    }
  }

  return matrix;
};

console.log(generateMatrix(4));
