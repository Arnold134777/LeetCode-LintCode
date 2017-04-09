//: Playground - noun: a place where people can play

class Solution {
    func summaryRanges(_ nums: [Int]) -> [String] {
        if nums.count <= 0 {
            return [];
        }
        
        if nums.count <= 1{
            return ["\(nums[0])"];
        }
        
        var result:[String] = [];
        var leftValue = nums[0];
        var rigthValue = nums[0];
        for index in 1 ..< nums.count{
            if nums[index] > nums[index - 1] + 1{
                rigthValue = nums[index - 1];
                if leftValue == rigthValue{
                    result.append("\(leftValue)");
                }else{
                    result.append("\(leftValue)->\(rigthValue)");
                }
                leftValue = nums[index];
                rigthValue = nums[index];
            }
            
            if(index == nums.count - 1){
                rigthValue = nums[index];
                if leftValue == rigthValue{
                    result.append("\(leftValue)");
                }else{
                    result.append("\(leftValue)->\(rigthValue)");
                }
            }
        }
        
        return result;
    }
}

let solution = Solution();
solution.summaryRanges([0]);
