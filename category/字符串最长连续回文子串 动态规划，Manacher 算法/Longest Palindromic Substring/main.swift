class Solution {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        if nums.count <= 1{
            return nums.count;
        }
        var maxLength:Int = 1;
        var count:Int = 1;
        for var index in 1...nums.count - 1{
            if nums[index] > nums[index - 1]{
                count += 1;
            }else{
                count = 1;
            }
            
            if count > maxLength{
                maxLength = count;
            }
        }
        
        return maxLength;
    }
}
