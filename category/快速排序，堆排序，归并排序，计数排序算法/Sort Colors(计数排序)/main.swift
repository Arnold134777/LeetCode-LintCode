class Solution {
    func sortColors(_ nums: inout [Int]) {
        if nums.count <= 1{
            return;
        }
        
        var counts:[Int] = [Int](repeating: 0, count: 3);
        for var num in nums{
            var count = counts[num];
            count += 1;
            counts[num] = count;
        }
        
        counts[1] += counts[0];
        counts[2] += counts[1];
        var result = [Int](repeating: 0, count: nums.count);
        for var num in nums.reversed(){
            let currentIndex = counts[num];
            result[currentIndex - 1] = num;
            counts[num] -= 1;
        }
        
        nums = result;
    }
}

