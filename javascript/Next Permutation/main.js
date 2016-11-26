/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  if(nums.length <= 0){
    return nums;
  }
  var length = nums.length;
  // 1.先倒序找到使nums[i - 1] < nums[i]
  var i = length - 1;
  for(;i > 0;i--){
    if(nums[i - 1] < nums[i]){
      break;
    }
  }
  // 没有找到分界点直接nums逆序即可
  if(i <= 0){
    nums = nums.reverse();
    return;
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
  console.log(nums);
};

nextPermutation([1,2,5,4,3,1]);
nextPermutation([1,2,5]);
nextPermutation([3,2,1]);
