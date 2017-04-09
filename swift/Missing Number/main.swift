class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        if nums.count <= 0 {
            return 0;
        }
        var product = 0;
        for (_,value) in nums.enumerated(){
            product += value;
        }
        
        return (nums.count + 1) * nums.count / 2 - product;
    }
}
