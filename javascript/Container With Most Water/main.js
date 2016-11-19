/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  
  if(height.length <= 1){
    return 0;
  }

  var left = 0;
  var right = height.length - 1;
  var maxArea = 0;

  while(left < right){
    var minHeight = Math.min(height[left],height[right]);
    var area = minHeight * (right - left);
    if(area > maxArea){
      maxArea = area;
    }

    if(height[left] < height[right]){
      left++;
    }else{
      right--;
    }
  }

  return maxArea;
};

var result = maxArea([1,1]);
console.log(result);
