/*
 解题思路：记录有多少个连续的存在0个数 >= 2的区间
 */
class Solution {
    func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
        var result = 0;
        if flowerbed.count <= 0 {
            return false;
        }
        
        var continuousZeroNums = 0;
        for (index,num) in flowerbed.enumerated(){
            if num == 0{
                continuousZeroNums += 1;
                // 注意如果首个跟最后一个也是0，
                if index == 0 {
                    continuousZeroNums += 1;
                }
                
                if index == flowerbed.count - 1{
                    continuousZeroNums += 1;
                    if(continuousZeroNums >= 3){
                        result += (continuousZeroNums - 1) / 2;
                    }
                }
            }else{
                if(continuousZeroNums >= 3){
                    result += (continuousZeroNums - 1) / 2;
                }
                continuousZeroNums = 0;
            }
        }
        
        return n <= result;
    }
}
