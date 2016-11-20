/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  var result = [];
  if(nums.length < 4){
    return result;
  }

  // 1.先排序
  nums.sort(function(a,b){
    return a-b;
  });

  // 2.查找
  var length = nums.length;
  for(var i = 0;i <= length - 4;i++){
    if(i >= 1 && nums[i] === nums[i - 1]){
      continue;
    }
    for(var j = i + 1;j <= length - 3;j++){
      if(j >= i + 2 && nums[j] === nums[j - 1]){
        continue;
      }

      var left = j + 1;
      var right = length - 1;
      findFourSum(nums,i,j,left,right,target,result);
    }
  }
  return result;
};

var findFourSum = function(nums,firstIndex,secondIndex,left,right,target,result){
  while(left < right){
    var sum = nums[firstIndex] + nums[secondIndex] + nums[left] + nums[right];
    if(sum > target){
      right--;
    }else if(sum < target){
      left++;
    }else{
      result.push([nums[firstIndex],nums[secondIndex],nums[left],nums[right]]);
      var thirdNum = nums[left];
      var forthNum = nums[right];
      while(left < right && nums[left] === thirdNum){
        left++;
      }

      while(left < right && nums[right] === forthNum){
        right--;
      }
    }
  }
};


var result = fourSum([1, 0, -1, 0, -2, 2],0);
console.log(result);
