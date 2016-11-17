/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
	if(nums.length <= 0){
		return 0;
	}
	var index=1;
	for(var i=1;i<nums.length;i++){
		if(nums[i]!=nums[i-1]){
			nums[index]=nums[i];
			index++;
		}
	}

	return index;
};

var result=removeDuplicates([1,1,2,3,3]);
console.log(result);




