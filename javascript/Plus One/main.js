/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {

  if(!digits || digits.length <= 0){
    return digits;
  }

  var needCarry = false;
  var addNum = digits[digits.length - 1] + addNum >= 10 ? 2 : 1;
  for(var i = digits.length - 1;i >= 0;i--){
    needCarry = false;
    if(digits[i] + addNum >= 10){
      needCarry = true;
    }
    digits[i] = (digits[i] + addNum) % 10;
    addNum = 0;
    if(needCarry){
      addNum = 1;
    }
  }

  if(needCarry){
    digits.splice(0,0,1); 
  }

  return digits;
};

console.log(plusOne([9,9,9,9]));
