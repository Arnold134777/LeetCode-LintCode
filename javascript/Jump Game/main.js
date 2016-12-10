/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
  if(nums.length <= 0){
    return false;
  }

  var targetLength = nums.length - 1;
  var maxJumpLength = nums[0];
  var currentStep = 1;
  while(currentStep <= maxJumpLength){
    if(nums[currentStep] + currentStep > maxJumpLength){
      maxJumpLength = nums[currentStep] + currentStep;
      if(maxJumpLength >= targetLength){
        break;
      }
    }

    currentStep++;
    if(currentStep > maxJumpLength){
      break;
    }
  }

  return maxJumpLength >= targetLength;
};


var result = canJump([0,1]);
console.log(result);
