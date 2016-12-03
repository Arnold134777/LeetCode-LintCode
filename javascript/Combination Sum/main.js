/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
  if(candidates.length <= 0){
    return [];
  }
  var result = [];
  // 1.先排序
  candidates.sort(function(a,b){
    return a - b;
  });
  // 2.递归查找
  var eachResult = [];
  searchCombinationSum(0,candidates,target,eachResult,result);

  return result;
};

var searchCombinationSum = function(index,candidates,leftSum,eachResult,result){

  for(var i = index;i < candidates.length;i++){
    if(i >= index + 1 && (candidates[i] === candidates[i - 1])){
      continue;
    }
    var tempEachResult = eachResult.slice(0);
    if(leftSum < candidates[i]){
      return;
    }else if(leftSum === candidates[i]){
      tempEachResult.push(leftSum);
      result.push(tempEachResult);
      return;
    }

    tempEachResult.push(candidates[i]);
    searchCombinationSum(i + 1,candidates,leftSum - candidates[i],tempEachResult,result);
  }
};

console.log(combinationSum2([10, 1,2, 2, 7, 6, 1, 5],8));
