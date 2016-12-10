/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  if(nums.length <= 0){
    return 0;
  }

  var maxSubArray = nums[0];
  var sum = nums[0];
  if(sum < 0){
    sum = 0;
  }
  for(var index = 0;index < nums.length;index++){
    sum += nums[index];
    if(sum > maxSubArray){
      maxSubArray = sum;
    }

    if(sum < 0){
      sum = 0;
    }
  }
  return maxSubArray;
};


var result = maxSubArray([-2,-1,3,4,-2,4]);
console.log(result);
