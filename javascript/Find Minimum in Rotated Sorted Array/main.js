/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
  if(nums.length <= 0){
    return -1;
  }

  var left = 0;
  var right = nums.length - 1;
  while(left < right){
    var mid = parseInt((left + right) / 2);
    if(nums[mid] > nums[right]){
      left = mid + 1;
    }else{
      if(nums[mid] < nums[left]){
        right = mid;
      }else{
        right = mid - 1;
      }
    }
  }

  return nums[left];
};
console.log(findMin([4,5,6,7,0,1,2,3]));
