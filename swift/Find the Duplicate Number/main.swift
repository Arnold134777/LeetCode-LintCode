class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        if nums.count <= 0{
            return 0;
        }
        
        // 二分的思想，统计大于n/2的个数
        var left = 0;
        var right = nums.count - 1;
        while left <= right{
            
            let mid = (right - left) / 2 + left;
            var count = 0;
            for index in 0...nums.count - 1{
                if nums[index] <= mid{
                    count += 1;
                }
            }
            // print("\(left) : \(right) :\(count)" )
            // 如果小于等于中间数的数量大于中间数，说明前半部分必有重复
            if count > mid{
                right = mid - 1;
                // 否则后半部分必有重复
            }else{
                left = mid + 1;
            }
        }
        
        return left;
    }
}
