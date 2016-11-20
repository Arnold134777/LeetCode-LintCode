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

  // 1.构建两个数字和的hashMap
  var twoSumMap = buildHashMap(nums);

  // 2.查找两个数字和的hashMap
  findFourSum(twoSumMap,target,result);

  // 3.针对4个数字相同的情况特殊处理
  handleFourSameNum(nums,target,result);
  
  return result;
};

var buildHashMap = function(nums){
  // 1.先排序
  nums.sort(function(a,b){
    return a-b;
  });

  // 2每两个数字和构建hash表
  var twoSumMap = {};
  var length = nums.length;
  for(var i = 0;i <= length - 2;i++){
    for(var j = i + 1;j <= length - 1;j++){
      var twoSum = nums[i] + nums[j];
      var twoSumKey = '' + twoSum;
      var twoSumValue = twoSumMap[twoSumKey];
      if(twoSumValue === undefined){
        twoSumValue = [];
      }
      twoSumValue.push([nums[i],nums[j]]);
      twoSumMap[twoSumKey] = twoSumValue;
    }
  }
  return twoSumMap;
};

var findFourSum = function(twoSumMap,target,result){
  var allKeys = Object.keys(twoSumMap);
  allKeys.sort(function(a,b){
    return a-b;
  });

  var left = 0;
  var right = allKeys.length - 1;
  while(left < right){
    var thirdNum = parseInt(allKeys[left]) ;
    var fourthNum = parseInt(allKeys[right]);
    var sum = thirdNum + fourthNum;

    if(sum > target){
      right--;
    }else if(sum < target){
      left++;
    }else{
      mergeResult(twoSumMap[allKeys[left]],twoSumMap[allKeys[right]],result);

      // 当集合内部2个value相加==target
      if(thirdNum * 2 === target){
        mergeResult(twoSumMap[allKeys[left]],twoSumMap[allKeys[right]],result);
      }
      left++;
    }
  }
};

var mergeResult = function(firstList,secondList,result){
  var eachResult;
  for(var i = 0;i < firstList.length;i++){
    if(i >= 1 &&firstList[i][0] === firstList[i - 1][0] && firstList[i][1] === firstList[i - 1][1]){
      continue;
    }
    for(var j = 0;j < secondList.length;j++){
      // 已经统计过的忽略掉
      if(j >= 1 && eachResult && firstList[i][0] === eachResult[0] && firstList[i][1] === eachResult[1] && secondList[j][0] === eachResult[2] && secondList[j][1] === eachResult[3]){
        continue;
      }

      if(firstList[i][1] > secondList[j][0]){
        continue;
      }else if(firstList[i][1] === secondList[j][0]){
        if(firstList[i][3] >= secondList[j][2]){
          continue;
        }
      }
      eachResult = [firstList[i][0],firstList[i][1],secondList[j][0],secondList[j][1]];
      result.push(eachResult);
    }
  }
};

handleFourSameNum = function(nums,target,result){
  if(target % 4 !== 0){
    return;
  }
  var i = 0;
  for(;i < nums.length;i++){
    if(nums[i] === target/4){
      break;
    }
  }
  var count = 0;
  while(i < nums.length){
    if(nums[i] === target/4){
      count++;
      i++;
      if(count >= 4){
        break;
      }
    }else{
      break;
    }
  }
  if(count >= 4){
    result.push([target/4,target/4,target/4,target/4]);
  }
};


var result = fourSum([-4,-10,-1,-5,-7,0,0,4,-1,7,-8],-8);
console.log(result);
