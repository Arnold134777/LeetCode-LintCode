/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
  if(nums.length <= 0){
    return;
  }  

  // sort 0
  var left = 0;
  var right = nums.length - 1;
  while(left < right){
    while(nums[left] === 0 && left < right){
      left++;
    }

    while(nums[right] != 0 && left < right){
      right--;
    }

    if(left >= right){
      break;
    }

    var temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
    left++;
    right--;
  }

  // sort 2
  left = 0;
  right = nums.length - 1;
  while(left < right){
    while(nums[left] != 2 && left < right){
      left++;
    }

    while(nums[right] === 2 && left < right){
      right--;
    }

    if(left >= right){
      break;
    }

    temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
    left++;
    right--;
  }
};


sortColors([2,1,2,0,2,1,0,2]);

