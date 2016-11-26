/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  if(nums.length <= 0){
    return 0;
  }

  if(target <= nums[0]){
    return 0;
  }

  if(target > nums[nums.length - 1]){
    return nums.length;
  }

  var left = 0;
  var right = nums.length - 1;
  while(left <= right){
    if(target < nums[left]){
      return left;
    }

    if(left === right){
      if(nums[left] < target){
        return left + 1;
      }

      if(nums[left] >= target){
        return left;
      }
    }
    var mid = parseInt((left + right) / 2);
    if(nums[mid] < target){
      left = mid + 1;
    }else if(nums[mid] > target){
      right = mid - 1;
    }else{
      right = mid;
    }
  }
  return right;
};

console.log(searchInsert([3,5,7,9,10],8));
console.log(searchInsert([1,3,5,5,6],2));
console.log(searchInsert([1,3,5,5,6],7));
console.log(searchInsert([1,3,5,5,6],0));
console.log(searchInsert([1,3,5,5,6],4));
