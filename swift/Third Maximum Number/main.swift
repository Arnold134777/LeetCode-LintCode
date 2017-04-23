class Solution {
    func thirdMax(_ nums: [Int]) -> Int {
        if nums.count <= 0{
            return -1;
        }
        
        var firstMaxNum = Int.min;
        var secondMaxNum = Int.min;
        var thirdMaxNum = Int.min;
        
        for index in 0..<nums.count{
            if nums[index] > firstMaxNum && firstMaxNum != Int.min{
                thirdMaxNum = secondMaxNum;
                secondMaxNum = firstMaxNum;
                firstMaxNum = nums[index];
            }else{
                if nums[index] == firstMaxNum{
                    continue;
                }
                
                if firstMaxNum == Int.min{
                    firstMaxNum = nums[index];
                    continue;
                }else{
                    if nums[index] > secondMaxNum && nums[index] < firstMaxNum{
                        if secondMaxNum == Int.min{
                            secondMaxNum = nums[index];
                            continue;
                        }else{
                            thirdMaxNum = secondMaxNum;
                            secondMaxNum = nums[index];
                        }
                    }else{
                        if nums[index] == secondMaxNum{
                            continue;
                        }
                        
                        if nums[index] > thirdMaxNum && nums[index] < secondMaxNum{
                            thirdMaxNum = nums[index];
                        }
                    }
                }
            }
        }
        
        if thirdMaxNum != Int.min{
            return thirdMaxNum;
        }else{
            return firstMaxNum;
        }
    }
}
