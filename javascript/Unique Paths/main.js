/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var nums = [];    
    for(var i = 0;i < m;i++){
        var num = [];
        for(var j = 0;j < n;j++){
          if(i === 0 || j === 0){
            num[j] = 1;
            continue;
          }
          num[j] = nums[i - 1][j] + num[j - 1];
        }
        nums[i] = num;
    }
    
    return nums[m - 1][n - 1];
};

/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
  if(obstacleGrid.length <= 0){
    return 0;
  } 

  var nums = [];   
  for(var i = 0;i < obstacleGrid.length;i++){
      var num = [];
      for(var j = 0;j < obstacleGrid[0].length;j++){
        if(obstacleGrid[i][j] === 1){
          num[j] = 0;
          continue;
        }

        if(i === 0 && j === 0){
          num[j] = (obstacleGrid[i][j] === 1) ? 0 : 1;
          continue;
        }

        if(i === 0){
          num[j] = num[j - 1];
          continue;
        }

        if(j === 0){
          num[j] = nums[i - 1][j];
          continue;
        }

        num[j] = num[j - 1] + nums[i - 1][j];
      }
      nums[i] = num;
  }
    
    return nums[obstacleGrid.length - 1][obstacleGrid[0].length - 1]; 
};


var result = uniquePathsWithObstacles([
  [0,1]
]);
console.log(result);
