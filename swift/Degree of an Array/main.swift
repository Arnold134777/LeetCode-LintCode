class Solution {
    func findShortestSubArray(_ nums: [Int]) -> Int {
        if nums.count <= 1{
            return nums.count;
        }
        
        var numCountMap:[Int:Int] = [:];
        var leftIndexOfNumMap:[Int:Int] = [:];
        var maxCount:Int = 0;
        var miniLength:Int = 1;
        
        for var index in 0...nums.count - 1{
            let num:Int = nums[index];
            if numCountMap[num] == nil{
                numCountMap[num] = 1;
                leftIndexOfNumMap[num] = index;
            }else{
                var count:Int = numCountMap[num]!;
                count += 1;
                numCountMap[num] = count;
                if count > maxCount{
                    maxCount = count;
                    miniLength = index - leftIndexOfNumMap[num]! + 1;
                }else if count == maxCount{
                    if index - leftIndexOfNumMap[num]! + 1 < miniLength{
                        miniLength = index - leftIndexOfNumMap[num]! + 1;
                    }
                }
            }
        }
        
        return miniLength;
    }
}
