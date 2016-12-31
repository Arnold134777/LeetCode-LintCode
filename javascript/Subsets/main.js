/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
  if(nums.length <= 0){
    return [];
  }
  var result = [];
  result.push([]);
  var index = 1;
  for(var i = 0;i < nums.length;i++){
    var tempSubSets = result.slice(0, result.length)
    for(var j = 0; j < tempSubSets.length;j++){
      var currentSubSet = tempSubSets[j].slice(0, tempSubSets[j].length);
      currentSubSet.push(nums[i]);
      result[index++] = currentSubSet.slice(0, currentSubSet.length);
    }
  }
  return result;
};
var result=subsets([1,2,3]);
console.log(result);
