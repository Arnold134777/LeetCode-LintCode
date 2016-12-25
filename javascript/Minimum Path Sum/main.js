/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
  if(!grid || grid.length <= 0){
    return 0;
  }
  var row = grid.length;
  var col = grid[0].length;
  var minPathSum = [];
  for(var i = 0;i < grid.length;i++){
    var echoRow = [];
    for(var j = 0; j < grid[0].length;j++){

      if(j === 0){
        if(i === 0){
          echoRow[0] =  grid[i][j];
        }else{
          echoRow[0] = minPathSum[i - 1][j] + grid[i][j];
        }
        continue;
      }
      
      if(i === 0){
        echoRow[j] = echoRow[j - 1] + grid[i][j];
        continue;
      }
      
      echoRow[j] = Math.min(minPathSum[i - 1][j],echoRow[j - 1]) + grid[i][j];
    }

    minPathSum[i] = echoRow;
  }

  return minPathSum[row - 1][col - 1];
};


console.log(minPathSum([[1,2,3],[1,2,3],[1,2,3]]));
