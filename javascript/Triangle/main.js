/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  if(triangle.length <= 0){
    return 0;
  }  
  var minimumTotal = triangle[0][0];
  for(var row = 1;row < triangle.length;row++){
    var numbers = triangle[row];

    for(var col = 0; col < numbers.length;col++){
      if(col === 0){
        numbers[col] += triangle[row - 1][col];
        if(row === triangle.length - 1){
          minimumTotal = numbers[col];
        }
        continue;
      }

      if(col === numbers.length - 1){
        numbers[col] += triangle[row - 1][col - 1];
      }else{
         numbers[col] += Math.min(triangle[row - 1][col],triangle[row - 1][col - 1]);
      }
     
      if(row === triangle.length - 1){
        if(numbers[col] < minimumTotal){
          minimumTotal = numbers[col];
        }
      }
    }
    triangle[row] = numbers;
  }
  
  return minimumTotal;
};

var result=minimumTotal([[-1],[-2,-3]]);
console.log(result);
