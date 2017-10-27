class Solution {
    func maximumSwap(_ num: Int) -> Int {
        var nums:[Int] = [];
        var maxNums:[Int] = [];
        var maxNumsIndex:[Int] = [];
        
        // 首先计算出从低位数到最高位的每一位的最大值
        var currentNum:Int = num;
        var maxNum:Int = 0;
        var maxNumIndex:Int = 0;
        var count:Int = 0;
        while currentNum > 0 {
            var tempBitNum:Int = currentNum % 10;
            nums.append(tempBitNum);
            if tempBitNum > maxNum{
                maxNum = tempBitNum;
                maxNumIndex = count;
            }
            
            maxNums.append(maxNum);
            maxNumsIndex.append(maxNumIndex);
            count += 1;
            currentNum -= tempBitNum;
            currentNum = currentNum / 10;
        }
        
        // 高位往低位遍历发现第一个当前数 < 下一位的最大值，开始替换
        for var index in 0..<count - 1{
            if nums[count - 1 - index] < maxNums[count - 2 - index]{
                var temp:Int = nums[count - 1 - index];
                nums[count - 1 - index] = maxNums[count - 2 - index];
                nums[maxNumsIndex[count - 2 - index]] = temp;
                break;
            }
        }
        
        // 重新计算最大的值
        var result:Int = 0;
        var multiple:Int = 1;
        for var index in 0..<count{
            result += multiple * nums[index];
            multiple *= 10
        }
        
        return result;
    }
}
