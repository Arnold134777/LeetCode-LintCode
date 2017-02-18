/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  // 先找到分割点
  var left = 0;
  var right = nums.length - 1;
  var i = 1;
  for(;i < nums.length;i++){
    if(nums[i] < nums[i - 1]){
      break;
    }
  }
  var resultIndex = searchInRange(nums,left,i - 1,target);
  if(resultIndex != -1){
    return resultIndex;
  }

  return searchInRange(nums,i,right,target); 
};

var searchInRange = function(nums,left,right,target){
  while(left <= right){
    var mid = parseInt((left + right) / 2);
    if(target > nums[mid]){
      left = mid + 1;
    }else if(target < nums[mid]){
      right = mid - 1;
    }else{
      return mid;
    }
  }

  return -1;
}

console.log(search([4,5,6,7,0,1,2],0));
console.log(search([4,5,6,7,0,1,2],1));
console.log(search([4,5,6,7,0,1,2],2));
console.log(search([4,5,6,7,0,1,2],3));
console.log(search([4,5,6,7,0,1,2],4));
console.log(search([4,5,6,7,0,1,2],5));
console.log(search([4,5,6,7,0,1,2],6));
console.log(search([4,5,6,7,0,1,2],7));
