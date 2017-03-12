/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    if(nums.length <= 0){
        return -1;
    }
    
    var currentNum;
    var currentNumCount = 0;
    for(var index = 0; index < nums.length;index++){
        if(currentNumCount === 0){
            currentNum = nums[index];
            currentNumCount++;
            continue;
        }
        
        if(nums[index] !== currentNum){
            currentNumCount--;
        }else{
            currentNumCount++;
        }
    }
    
    return currentNum;
};

