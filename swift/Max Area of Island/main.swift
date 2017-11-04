class Solution {
    
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        var maxArea:Int = 0;
        var  gridMap:[[Int]] = grid;
        
        for var x in 0...gridMap.count - 1{
            for var y in 0...gridMap[0].count - 1{
                if gridMap[x][y] == 0{
                    continue;
                }
                
                var count:Int = finMaxAreaOfIsland(&gridMap,x,y);
                if count > maxArea{
                    maxArea = count;
                }
            }
        }
        
        return maxArea;
    }
    
    func finMaxAreaOfIsland(_ grid:inout [[Int]], _ x:Int, _ y:Int) -> Int{
        // 1.如果查找的范围超出许可范围直接返回
        if x < 0 || x >= grid.count || y < 0 || y >= grid[0].count{
            return 0;
        }
        
        // 2.如果该位置已经被标记为0也直接返回
        if grid[x][y] == 0{
            return 0;
        }
        
        // 3.先标记计算过该区域
        grid[x][y] = 0;
        
        // 4.遍历周围的四个方向
        var count:Int = 1;
        var directions = [[-1,0],[0,-1],[1,0],[0,1]];
        for var index in 0...directions.count - 1{
            var direction:[Int] = directions[index];
            count += finMaxAreaOfIsland(&grid, x + direction[0], y + direction[1]);
        }
        
        return count;
    }
}

