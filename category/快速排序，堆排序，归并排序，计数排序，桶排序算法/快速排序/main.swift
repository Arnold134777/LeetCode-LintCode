class Solution {
    func quickSort(_ nums:inout [Int]) {
        if nums.count <= 0{
            return;
        }
        quickSort(&nums, 0, nums.count - 1);
    }
    
    func quickSort(_ nums:inout [Int],_ left:Int,_ right:Int) {
        if left >= right{
            return;
        }
        var partition:Int = findPartition(&nums, left, right);
        quickSort(&nums, left, partition - 1);
        quickSort(&nums, partition + 1, right);
    }
    
    func exchange(_ nums:inout [Int],_ left:Int,_ right:Int) {
        var temp:Int = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    
    func findPartition(_ nums:inout [Int],_ left:Int,_ right:Int) -> Int {
        var start:Int = left;
        var end:Int = right;
        
        if start >= end{
            return start;
        }
        var firstIndex = start;
        var lastIndex = end;
        var firstNum:Int = nums[firstIndex];
        start += 1;
        while start <= end{
            
            // 从左边找到第一个比firstNum大的数字
            while start <= end && nums[start] <= firstNum{
                start += 1;
            }
            
            // 从右边找到第一个比firstNum小的数字
            while start <= end && nums[end] >= firstNum{
                end -= 1;
            }
            
            if start < end{
                exchange(&nums, start, end);
            }
        }
        
        // 最后交换第一个与right的下标
        if firstIndex != end{
            exchange(&nums, firstIndex, end);
        }
        
        return end;
    }
}

var solution:Solution = Solution();
var nums:[Int] = [4,1,3,2,16,9,10,14,8,7];
solution.quickSort(&nums);
print(nums);

