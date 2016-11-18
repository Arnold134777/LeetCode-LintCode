/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  var result = [];
  if(nums.length < 3){
    return result;
  }

  // 1.先排序
  nums.sort(function(a,b){
    return a-b;
  });

  // 2.查找
  var length = nums.length;
  for(var i = 0;i <= length - 3;i++){
    if(nums[i] > 0){
      break;
    }

    if(i >= 1 && nums[i] === nums[i - 1]){
      continue;
    }

    var left = i + 1;
    var right = length - 1;
    findThreeSum(nums,nums[i],left,right,result);
  }
  return result;
};

var findThreeSum = function(nums,firstNum,left,right,result){
  var targetNum = -firstNum;
  if(left >= right){
    return;
  }

  while(left < right){
    var secondNum = nums[left];
    var thirdNum = nums[right];
    if(secondNum + thirdNum > targetNum){
      right--;
    }else if(secondNum + thirdNum < targetNum){
      left++;
    }else{
      result.push([firstNum,secondNum,thirdNum]);
      while(left < right && nums[left] === secondNum){
        left++;
      }

      while(left < right && nums[right] === thirdNum){
        right--;
      }
    }
  }
};

var result = threeSum([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]);
console.log(result);
