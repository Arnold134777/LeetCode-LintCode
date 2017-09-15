/**
 解决思路：注意数组的取值范围是[1...n] 因此可以遍历取每个的值作为下标改变原始
 数组的值为-1，一次遍历完成基本就确定不存在的数就是未被访问到的，即对应数字不为-1的
 */
class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var result:[Int] = [];
        if nums.count <= 0{
            return result;
        }
        var var_nums = nums;
        for(index,num) in var_nums.enumerated(){
            var visitIndex = num - 1;
            var_nums[visitIndex] = -1;
        }
        
        for(index,num) in var_nums.enumerated(){
            if var_nums[index] != -1{
                result.append(index + 1)
            }
        }
        
        return result;
    }
}
