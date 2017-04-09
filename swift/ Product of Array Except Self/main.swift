class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        
        if nums.count <= 1 {
            return nums;
        }
        
        // 题解：不能使用除法，因此需要统计从左到右，从右到左的乘积，然后处理：result[index] = left[index - 1] * right[index + 1];
        var left:[Int] = [Int](repeating: 0, count: nums.count);
        var right:[Int] = [Int](repeating: 0, count: nums.count);
        var result:[Int] = [Int](repeating: 0, count: nums.count);
        for index in 0..<nums.count{
            if index == 0{
                left[0] = nums[0];
                right[nums.count - 1] = nums[nums.count - 1];
                continue;
            }
            
            left[index] = left[index - 1] * nums[index];
            right[nums.count - index - 1] = right[nums.count - index] * nums[nums.count - 1 - index];
        }
        
        for (index,_) in nums.enumerated(){
            if index == 0{
                result[index] = right[1];
            }else if(index == nums.count - 1){
                result[index] = left[nums.count - 2];
            }else{
                result[index] = left[index - 1] * right[index + 1];
            }
        }
        
        return result;
    }
}
