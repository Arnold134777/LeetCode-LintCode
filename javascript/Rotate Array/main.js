/**
 * @param {number[]} prices
 * @return {number}
 */
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
  if(nums.length <= 0){
    return;
  }

  var len = nums.length;
  k = k%len;
  var nums1 = nums.slice(len - k);
  nums.splice(len - k, k);
  Array.prototype.unshift.apply(nums, nums1);
};

rotate([1,2,3,4,5,6,7],3);
