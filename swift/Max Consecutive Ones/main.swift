class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        var count = 0;
        var max = 0;
        if nums.count <= 0{
            return max;
        }
        
        for(index,num) in nums.enumerated(){
            if num == 0{
                count = 0;
            }else if num == 1{
                if index > 0 && nums[index - 1] == 1{
                    count += 1;
                }else{
                    count = 1;
                }
                if(count > max){
                    max = count;
                }
            }
        }
        return max;
    }
}

