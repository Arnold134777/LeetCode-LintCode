class Solution {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        if nums.count <= 0 {
            return false;
        }
        
        var map = Dictionary<Int, Int>();
        for (index,number) in nums.enumerated(){
            if map[number] != nil && index - map[number]! <= k{
                return true;
            }
            
            map[number] = index;
        }
        return false;
    }
}

let solution = Solution();
solution.containsNearbyDuplicate([1,2,3,4,5,2],4);
