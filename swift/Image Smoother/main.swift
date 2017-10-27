class Solution {
    func imageSmoother(_ M: [[Int]]) -> [[Int]] {
        var result:[[Int]] = [];
        
        var directions:[[Int]] = [
            [-1,-1],
            [-1,0],
            [-1,1],
            [0,-1],
            [0,0],
            [0,1],
            [1,-1],
            [1,0],
            [1,1]
        ];
        
        for var x in 0...M.count - 1{
            var column:[Int] = [];
            for var y in 0...M[0].count - 1{
                var count:Int = 0;
                var sum:Int = 0;
                for var index in 0...directions.count - 1{
                    var direction:[Int] = directions[index];
                    var destX = x + direction[0];
                    var destY = y + direction[1];
                    
                    if destX < 0 || destX >= M.count || destY < 0 || destY >= M[0].count{
                        continue;
                    }
                    
                    sum += M[destX][destY];
                    count += 1;
                }
                column.append(Int(sum / count));
            }
            result.append(column);
        }
        
        return result;
    }
}
