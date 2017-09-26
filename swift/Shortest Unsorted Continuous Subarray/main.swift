/*
 解题思路：分别记录从右到左的最小值集合与从左到右的最大值的数组集合，然后依次遍历比较
 计算出区间[left,right],然后针对特殊情况做处理
 */
class Solution {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        if nums.count <= 1 {
            return 0;
        }
        
        // 1.首先寻找区间的左下标
        var mins:[Int] = [Int](repeating:0,count:nums.count);
        var min = nums[nums.count - 1];
        for (index,num) in nums.enumerated().reversed() {
            if num < min {
                min = num;
            }
            mins[index] = min;
        }
        var left = 0;
        for (index,num) in nums.enumerated(){
            if index == nums.count - 1{
                continue;
            }
            if num <= mins[index + 1]{
                left += 1;
            }else{
                break;
            }
        }
        
        // 2.再寻找区间的右下标
        var maxs:[Int] = [Int](repeating:0,count:nums.count);
        var max = nums[0];
        for (index,num) in nums.enumerated(){
            if num > max {
                max = num;
            }
            maxs[index] = max;
        }
        
        var right = nums.count - 1;
        for (index,num) in nums.enumerated().reversed(){
            if index == 0{
                continue;
            }
            if num >= maxs[index - 1]{
                right -= 1;
            }else{
                break;
            }
        }
        
        if(right - left + 1 < 0){
            return 0;
        }
        return right - left + 1;
    }
}
