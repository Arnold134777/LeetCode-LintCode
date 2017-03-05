/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  if(nums.length <= 0){
    return 0;
  }  

  var max = nums[0];
  var min = nums[0];
  var maxProduct = nums[0];

  for(var index = 1; index < nums.length;index++){
    var maxTemp = max;
    // 1.局部最优解
    max = Math.max(Math.max(nums[index],max * nums[index]),nums[index] * min);
    min = Math.min(Math.min(nums[index],min * nums[index]),nums[index] * maxTemp);

    // 2.全局最优解
    maxProduct = (max > maxProduct ?  max : maxProduct);
  }
  return maxProduct;
};


var result = maxProduct([2,-5,-2,-4,3]);
console.log(result);
