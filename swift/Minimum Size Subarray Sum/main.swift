//: Playground - noun: a place where people can play

class Solution {
    func minSubArrayLen(_ s: Int, _ nums: [Int]) -> Int {
        
        if nums.count <= 0{
            return 0;
        }
        var left = 0,right = 0;
        var minLength = Int.max;
        var sum  = nums[left];
        while true{
            
            if sum < s{
                right += 1;
                if(right >= nums.count){
                    break;
                }
                sum += nums[right];
                continue;
            }
            
            while left <= right {
                if sum < s{
                    break;
                }
                
                // sum >= s
                if right - left + 1 < minLength{
                    minLength = right - left + 1;
                }
                
                sum -= nums[left];
                left += 1;
            }
        }
        
        if minLength == Int.max{
            minLength = 0;
        }
        
        return minLength;
    }
}

let solution = Solution();
solution.minSubArrayLen(20,[2,3,1,2,4,3]);
