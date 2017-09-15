/**
 解决思路：注意数组的取值范围是[1...n] 因此可以遍历取每个的值作为下标改变原始
 数组的值为取反数，如果再次遍历到该下标即存在2次
 */

class Solution {
    func findDuplicates(_ nums: [Int]) -> [Int] {
        var result:[Int] = [];
        // 必须转换为var否则编译错误，不能操作let的变量
        var var_nums = nums;
        if var_nums.count < 2{
            return result;
        }
        
        for (index,num) in var_nums.enumerated(){
            var visitIndex = abs(var_nums[index]) - 1;
            if var_nums[visitIndex] < 0{
                result.append(visitIndex + 1)
            }else{
                var_nums[visitIndex] = var_nums[visitIndex] * -1;
            }
        }
        return result;
    }
}

let solution = Solution();
solution.containsDuplicate([1,2,3,4,5,2]);
