class Solution {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var result:Double = 0.0;
        if nums.count <= 0 {
            return result;
        }
        
        var maxSum:Int = Int.min;
        var sum:Int = 0;
        
        for index in (0...nums.count - 1){
            if index < k {
                sum += nums[index];
                if index < k - 1 {
                    continue;
                }
            }else{
                sum += nums[index] - nums[index - k];
            }
            
            if sum > maxSum{
                maxSum = sum;
            }
        }
        
        return Double(maxSum) / Double(k);
    }
}

