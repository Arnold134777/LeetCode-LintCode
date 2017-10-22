class Solution {
    func checkPossibility(_ nums: [Int]) -> Bool {
        if nums.count <= 2{
            return true;
        }
        
        var decreaseCount:Int = 0;
        for var index in 0..<nums.count - 1{
            if nums[index + 1] < nums[index]{
                decreaseCount += 1;
                if decreaseCount >= 2{
                    break;
                }
            }
            
            // [3,5,2,3]、[3,5,2,4]类似的波动
            if index < nums.count - 3{
                if (nums[index] > nums[index + 2] && nums[index + 1] > nums[index + 2] &&
                    nums[index + 1] > nums[index + 3]) {
                    return false;
                }
            }
        }
        
        return decreaseCount <= 1;
    }
}
