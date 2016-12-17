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