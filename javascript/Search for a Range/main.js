/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
  if(nums.length <= 0){
    return [-1,-1];
  }

  var left = 0;
  var right = nums.length - 1;
  var findLeft;
  while(left <= right){
    var mid = parseInt((left + right) / 2);
    if(nums[mid] > target){
      right = mid - 1;
    }else if(nums[mid] < target){
      left = mid + 1;
    }else{
      findLeft = mid;
      right = mid - 1;
    }
  }

  left = 0;
  right = nums.length - 1;
  var findRight;
  while(left <= right){
    mid = parseInt((left + right) / 2);
    if(nums[mid] > target){
      right = mid - 1;
    }else if(nums[mid] < target){
      left = mid + 1;
    }else{
      findRight = mid;
      left = mid + 1;
    }
  }

  if(findLeft === undefined || findRight === undefined){
    return [-1,-1];
  }
  return [findLeft,findRight];
};

searchRange([5, 7, 7, 8, 8, 10],11);
