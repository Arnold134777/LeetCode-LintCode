class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        if nums.count <= 0 {
            return false;
        }
        
        var map = Dictionary<Int, Bool>();
        for (number) in nums{
            if map[number] == true{
                return true;
            }
            
            map[number] = true;
        }
        
        return false;
    }
}

let solution = Solution();
solution.containsDuplicate([1,2,3,4,5,2]);
