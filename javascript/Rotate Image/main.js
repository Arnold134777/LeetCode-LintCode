/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  if(matrix.length <= 0){
    return matrix;
  }
  // 递归的方式处理旋转
  var rotateCount = parseInt(matrix.length / 2);
  var length = matrix.length;
  for(var i = 0;i < rotateCount;i++){
    for(var j = 0;j < length - 1;j++){
      var firstNum = matrix[i][j + i];
      var secondNum = matrix[j + i][length - 1 + i];
      var thirdNum = matrix[length - 1 + i][length - 1 + i - j];
      var fourthNum = matrix[length - 1 + i - j][i];

      matrix[i][j + i] = fourthNum;
      matrix[j + i][length - 1 + i] = firstNum;
      matrix[length - 1 + i][length - 1 + i - j] = secondNum;
      matrix[length - 1 + i - j][i] = thirdNum;
    }
    length = length - 2;
  }
};

rotate([[0,1,2,3,4],[5,6,7,8,9],[10,11,12,13,14],[15,16,17,18,19],[20,21,22,23,24]]);
