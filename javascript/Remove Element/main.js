/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    if(nums.length <= 0){
		return 0;
	}
	var index=0;
	for(var i=0;i<nums.length;i++){
		if(nums[i]!=val){
			nums[index++]=nums[i];
		}
	}

	return index;
};

var result=removeElement([1,1,2,3,3],3);
console.log(result);




