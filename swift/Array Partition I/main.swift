class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        var maxSum = 0;
        if nums.count % 2 != 0 {
            return maxSum;
        }
        
        let sorted_nums = nums.sorted();
        for (index, item) in sorted_nums.enumerated(){
            if(index % 2 != 0){
                continue;
            }
            maxSum += item;
        }
        
        return maxSum;
    }
}
