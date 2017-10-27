class Solution {
    func constructArray(_ n: Int, _ k: Int) -> [Int] {
        var result:[Int] = [];
        
        var left:Int = 1;
        var right:Int = left + k;
        
        while left < right{
            result.append(left);
            result.append(right);
            left += 1;
            right -= 1;
        }
        
        if left == right{
            result.append(left);
        }
        
        if k + 2 <= n{
            for var index in ((k + 2)...n){
                result.append(index);
            }
        }
        
        return result;
    }
}
