class Solution {
    func numSubarrayProductLessThanK(_ nums: [Int], _ k: Int) -> Int {
        if nums.count <= 0{
            return 0;
        }
        
        var result:Int = 0;
        var product:Int = 1;
        var left:Int = 0;
        var right:Int = 0;
        
        for var index in 0..<nums.count{
            right = index;
            product *= nums[index];
            while product >= k && left <= right{
                product /= nums[left];
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }
}
