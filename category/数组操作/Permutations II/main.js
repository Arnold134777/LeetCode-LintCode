/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var permuteUnique = function(nums) {
  if(nums === undefined || nums.length <= 0){
    return 
  }

  nums = nums.sort();
  var result = [nums.slice(0)];
  while(true){
    if(nextPermutation(nums,result) === false){
      break;
    }
  } 
  return result;
};

var nextPermutation = function(nums,result) {
  
  var length = nums.length;
  // 1.先倒序找到使nums[i - 1] < nums[i]
  var i = length - 1;
  for(;i > 0;i--){
    if(nums[i - 1] < nums[i]){
      break;
    }
  }

  if(i <= 0){
    return false;
  }
  i--;
  // 2.找分界点再倒序找到第一个比分界点大的数字二者交换位置
  var j = length - 1;
  for(;j > i;j--){
    if(nums[j] > nums[i]){
      break;
    }
  }

  var temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;

  // 3.从分界面开始再逆序排序
  var left = i + 1;
  var right = length - 1;
  while(left < right){

    temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
    left++;
    right--;
  }

  result.push(nums.slice(0));
  return true;
};


 console.log(permuteUnique([1,1,1])); 

// console.log(nextPermutation([0,1,-1]));

