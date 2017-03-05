/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
  if(nums.length <= 0){
    return -1;
  }

  var left = 0;
  var right = nums.length - 1;
  while(left < right){
    var mid = parseInt((left + right) / 2);
    if(nums[mid] < nums[mid + 1]){
      left = mid + 1;
    }else{
      right = mid;
    }
  }

  return right;
};

console.log(findPeakElement([1,2,3]));
