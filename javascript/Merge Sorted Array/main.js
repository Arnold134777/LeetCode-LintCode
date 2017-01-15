/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  var index = m + n - 1;
  if(m <= 0){
    for(var i = n;i > 0;i--){
      nums1[index--] = nums2[i - 1];
    }
  }

  while(index > 0){
    if(nums1[m - 1] < nums2[n - 1]){
      nums1[index--] = nums2[n - 1];
      n--;
      if(n <= 0){
        break;
      }
    }else{
      nums1[index--] = nums1[m - 1];
      m--;
      if(m <= 0){
        for(var i = n;i > 0;i--){
          nums1[index--] = nums2[i - 1];
        }
      }
    }
  } 

  console.log(nums1);
};

merge([0],0,[2],1)

