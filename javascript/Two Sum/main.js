/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var result=[];
    var map={};
    if(nums.length <= 0){
    	return result;
    }

    for(var i=0;i<nums.length;i++){
    	var num=nums[i];
      var key=''+num;
      var value=map[key];
      var count=1;
      if(value){
        count=value[0];
        count++;
      }
    	map[key]=[count,i];
    }
    //console.log(map);
    for(i=0;i<nums.length;i++){
    	var firstNum=nums[i];
    	var secondNum=target-firstNum;
      if((secondNum==firstNum && map[firstNum][0] >= 2) || (map[secondNum]!==undefined && secondNum!==firstNum )){
        result[0]=i;
    		result[1]=map[secondNum][1];
        break;
      }
    }
    return result;
};

var result=twoSum([3,2,4],6);
console.log(result);
