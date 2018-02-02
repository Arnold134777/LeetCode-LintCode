class Solution {
    
    class Bucket{
        public int max = Integer.MIN_VALUE;
        public int min = Integer.MAX_VALUE;
    }
    
    // 利用桶排序的思想
    public int maximumGap(int[] nums) {
        
        if(nums.length <= 1) {
            return 0;
        }
        int maxNum = Integer.MIN_VALUE;
        int minNum = Integer.MAX_VALUE;
        
        // 1.首先找到最大值与最小值，确定桶的大小与桶的个数
        for(int i = 0;i < nums.length;i++) {
            if(nums[i] > maxNum) {
                maxNum = nums[i];
            }
            
            if(nums[i] < minNum) {
                minNum = nums[i];
            }
        }
        
        int bucketCapacity = (maxNum - minNum) / (nums.length - 1);
        if(bucketCapacity <= 0) {
            return maxNum - minNum;
        }
        int bucketNum = (maxNum - minNum) / bucketCapacity + 1;
        ArrayList<Solution.Bucket> arrayList = new ArrayList<Solution.Bucket>();
        for (int i = 0; i < bucketNum; i++) {
            arrayList.add(new Solution.Bucket());
        }
        
        // 2.开始往桶内插入数据
        for(int i = 0; i < nums.length;i++) {
            int num = nums[i];
            int bucketIndex = (num - minNum) / bucketCapacity;
            Solution.Bucket bucket = arrayList.get(bucketIndex);
            if(num > bucket.max) {
                bucket.max = num;
            }
            
            if(num < bucket.min) {
                bucket.min = num;
            }
        }
        
        // 3.遍历桶计算出最大间距
        int premax = Integer.MIN_VALUE;
        int curmin = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < arrayList.size();i++) {
            Solution.Bucket bucket = arrayList.get(i);
            if(bucket.min != Integer.MAX_VALUE) {
                curmin = bucket.min;
                if(premax != Integer.MIN_VALUE) {
                    max = Math.max(max,  curmin - premax);
                }
            }
            
            if(bucket.max != Integer.MIN_VALUE) {
                premax = bucket.max;
            }
        }
        
        return max;
    }
}
