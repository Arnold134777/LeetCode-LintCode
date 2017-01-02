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
  var right = 0;
  var current = 0;

  for(var i = 0;i <= nums.length - 1 - right;i++){
  	if(nums[i] === 0){
  		var temp = nums[left];
        nums[left] = nums[i];
        nums[i] = temp;
  	    left++;
  	}else if(nums[i] === 2){
  		var temp = nums[nums.length - 1 - right];
        nums[nums.length - 1 - right] = nums[i];
        nums[i] = temp;
        i--;
        right++;
  	}
  }
  console.log(nums);
};


sortColors([1,0]);

