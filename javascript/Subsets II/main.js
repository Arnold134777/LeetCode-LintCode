/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
  if(nums.length <= 0){
    return [];
  }
  nums.sort();
  var result = [];
  result.push([]);
  var index = 1;
  var lastAddCount;
  for(var i = 0;i < nums.length;i++){
    var tempSubSets;
    if(i >= 1 && nums[i] === nums[i - 1]){
      tempSubSets = result.slice(result.length - lastAddCount, result.length)
    }else{
      tempSubSets = result.slice(0, result.length);
    }
    
    for(var j = 0; j < tempSubSets.length;j++){
      var currentSubSet = tempSubSets[j].slice(0, tempSubSets[j].length);
      currentSubSet.push(nums[i]);
      result[index++] = currentSubSet.slice(0, currentSubSet.length);
    }
    lastAddCount = tempSubSets.length;
  }
  return result;
};
var result=subsetsWithDup([4,4,4,1,4]);
console.log(result);
