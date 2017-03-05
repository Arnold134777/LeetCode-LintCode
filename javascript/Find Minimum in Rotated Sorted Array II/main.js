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
    }else if(nums[mid] < nums[right]){
      if(nums[mid] < nums[left]){
        right = mid;
      }else{
        right = mid - 1;
      }
    }else{
      if(nums[mid] < nums[left]){
        right = mid;
      }else if(nums[mid] > nums[left]){
        right = mid - 1;
      }else{
        var existMiniNum = false; 
        for(var index = mid;index > left;index--){
          if(nums[index] > nums[index - 1]){
            existMiniNum = true;
            break;
          }
        }

        if(existMiniNum){
          right = mid - 1;
        }else{
          left = mid + 1;
        }
      }
    }
  }

  return nums[left];
};
console.log(findMin([3,1,3,3,3]));
