/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
  // 1.先找到分割点
  var left = 0;
  var right = nums.length - 1;
  var i = 1;
  for(;i < nums.length;i++){
    if(nums[i] < nums[i - 1]){
      break;
    }
  }
  return searchInRange(nums,left,i - 1,target) || searchInRange(nums,i,right,target); 
};

var searchInRange = function(nums,left,right,target){
  while(left <= right){
    var mid = parseInt((left + right) / 2);
    if(target > nums[mid]){
      left = mid + 1;
    }else if(target < nums[mid]){
      right = mid - 1;
    }else{
      return true;
    }
  }

  return false;
}

console.log(search([4,5,6,7,0,1,2],0));
console.log(search([4,5,6,7,0,1,2],1));
console.log(search([4,5,6,7,0,1,2],2));
console.log(search([4,5,6,7,0,1,2],3));
console.log(search([4,5,6,7,0,1,2],4));
console.log(search([4,5,6,7,0,1,2],5));
console.log(search([4,5,6,7,0,1,2],6));
console.log(search([4,5,6,7,0,1,2],7));
