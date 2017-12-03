class Solution {
    
    /**
     与最长公共子序列的算法类似但是存在不同，以下是两个算法对应的转移方程
     最长公共子序列：A[i] == B[j] ? max[i][j] = max[i - 1][j - 1] + 1 : MAX(max[i][j - 1],max[i - 1][j]);
     此题因为必须是连续的子串：A[i] == B[j] ? max[i][j] = max[i - 1][j - 1] + 1 : 0;
     */
    func findLength(_ A: [Int], _ B: [Int]) -> Int {
        
        var maximumLengthArray:[[Int]] = [];
        if A.count <= 0 || B.count <= 0{
            return 0;
        }
        
        for var index in 0...A.count{
            var eachRowMaximumLengthArray:[Int] = [];
            eachRowMaximumLengthArray.append(0);
            maximumLengthArray.append(eachRowMaximumLengthArray);
        }
        
        for var index in 1...B.count{
            maximumLengthArray[0].append(0);
        }
        
        var result:Int = 0;
        for var i in 1...A.count{
            for var j in 1...B.count{
                if A[i - 1] == B[j - 1]{
                    maximumLengthArray[i].append(maximumLengthArray[i - 1][j - 1] + 1);
                    if maximumLengthArray[i][j] > result{
                        result = maximumLengthArray[i][j];
                    }
                }else{
                    maximumLengthArray[i].append(0);
                }
            }
        }
        
        return result;
    }
}
