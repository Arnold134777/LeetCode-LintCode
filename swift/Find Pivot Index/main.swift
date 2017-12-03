class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        if nums.count <= 0{
            return -1;
        }
        var sum:Int = 0;
        for var index in 0..<nums.count {
            sum += nums[index];
        }
        
        var leftSum:Int = 0;
        for var index in 0..<nums.count{
            if leftSum == sum - nums[index] - leftSum{
                return index
            }
            leftSum += nums[index];
        }
        
        return -1;
    }
}
