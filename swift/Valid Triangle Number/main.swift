/*
 解题思路：先排序，然后倒序遍历，每次固定三角形的最长边，指定左右两个的指针
 根据条件依次往中间移动，当sortedNums[left] + sortedNums[right] > thirdLengt时，
 left 与 right之间的任何值与sortedNums[right]都大于thirdLengt，因此需要增加right - left
 个三角形个位。
 */
class Solution {
    func triangleNumber(_ nums: [Int]) -> Int {
        var result:Int = 0;
        if nums.count <= 2 {
            return result;
        }
        
        var sortedNums = nums.sorted();
        for index in (2...sortedNums.count - 1).reversed(){
            var thirdLength = sortedNums[index];
            
            var left = 0;
            var right = index - 1;
            while left < right{
                if sortedNums[left] + sortedNums[right] > thirdLength{
                    result += right - left;
                    right -= 1;
                }else{
                    left += 1;
                }
            }
        }
        
        return result;
    }
}
