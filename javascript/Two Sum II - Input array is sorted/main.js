/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    if(numbers.length <= 0){
        return [];
    }
    
    var left = 0;
    var right = numbers.length - 1;
    while(left < right){
        if(numbers[left] + numbers[right] > target){
            right--;
        }else if(numbers[left] + numbers[right] < target){
            left++;
        }else{
            return [left + 1,right + 1];
        }
    }
};