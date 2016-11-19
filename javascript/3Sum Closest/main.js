/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var threeSumClosest = function(nums, target) {
  var result = [];
  if(nums.length < 3){
    return result;
  }

  // 1.先排序
  nums.sort(function(a,b){
    return a-b;
  });

  result = nums[0] + nums[1] + nums[2];
  if(result === target){
    return result;
  }
  // 2.查找
  var length = nums.length;
  for(var i = 0;i <= length - 3;i++){
    if(i >= 1 && nums[i] === nums[i - 1]){
      continue;
    }

    var left = i + 1;
    var right = length - 1;
    result = findThreeSumClosest(nums,i,left,right,target,result);
    if(result === target){
      break;
    }
  }
  return result;
};

var findThreeSumClosest = function(nums,firstIndex,left,right,target,result){
  while(left < right){
    var sum = nums[firstIndex] + nums[left] + nums[right];
    if(sum > target){
      right--;
    }else if(sum < target){
      left++;
    }else{
      return sum;
    }

    if(Math.abs(target - sum) < Math.abs(target - result)){
      result = sum;
      if(result === target){
        return result;
      }
    }
  }

  return result;
};

var result = threeSumClosest([-1,2,1,-4,-8],-11);
console.log(result);
