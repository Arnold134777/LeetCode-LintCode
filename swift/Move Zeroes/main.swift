class Solution {
    // 统计0出现的个数即可实现
    func moveZeroes(_ nums: inout [Int]) {
        var zeroCount = 0;
        for (index,_) in nums.enumerated(){
            if(nums[index] == 0){
                zeroCount += 1;
            }
        }
        
        var targetIndex = 0;
        
        for (index,_) in nums.enumerated(){
            if(nums[index] != 0){
                nums[targetIndex] = nums[index];
                targetIndex += 1;
            }
        }
        
        for index in 0..<zeroCount{
            nums[targetIndex + index] = 0;
        }
    }
}
