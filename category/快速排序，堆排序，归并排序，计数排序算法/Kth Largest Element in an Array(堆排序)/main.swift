class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        if nums.count <= 0 || k > nums.count{
            return -1;
        }
        
        if(nums.count <= 1){
            return nums[0];
        }
        
        var mutableNum:[Int] = nums;
        return heapSort(&mutableNum, k,nums.count);
    }
    
    func buildMaxHeap(_ nums:inout [Int]){
        for var index in (0...nums.count/2).reversed(){
            maxHeapify(&nums,index,nums.count);
        }
    }
    
    func exchange(_ nums:inout [Int],_ left:Int,_ right:Int){
        var temp:Int = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    
    func maxHeapify(_ nums:inout [Int], _ index:Int, _ size:Int){
        var left:Int = 2 * index + 1;
        var right:Int = 2 * index + 2;
        var large:Int = index;
        if left < size && nums[left] > nums[large]{
            large = left;
        }
        
        if right < size && nums[right] > nums[large]{
            large = right;
        }
        
        if large != index{
            exchange(&nums, index, large)
            // 递归的方式向下建堆
            maxHeapify(&nums, large, size);
        }
    }
    
    /**
     堆排序
     */
    func heapSort(_ nums:inout [Int],_ k:Int, _ size:Int) -> Int{
        
        // 1.首先构建大顶堆
        buildMaxHeap(&nums);
        var size:Int = nums.count;
        for var index in ((nums.count - k)...(nums.count - 1)).reversed(){
            
            // 2.每次交换完第一个与最后一个，交换k次
            exchange(&nums, 0, index)
            
            // 3.排除交换的元素，重新调整大顶堆
            size -= 1;
            maxHeapify(&nums, 0,size);
        }
        print(nums);
        // 4.取最后的倒数第k个
        return nums[nums.count - k];
    }
}
