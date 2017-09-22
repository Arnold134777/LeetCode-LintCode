class Solution {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        var result = 0;
        if nums.count <= 0 || k < 0{
            return result;
        }
        
        var map:[Int:Int] = [:];
        var count:Int = 0;
        for (_,num) in nums.enumerated(){
            let temCount = map[num];
            if temCount == nil{
                count = 0;
            }
            count += 1;
            map[num] = count;
        }
        
        for (key,value) in map{
            if k == 0 {
                if value >= 2 {
                    result += 2;
                }
                continue;
            }
            
            let firstNum = key + k;
            let secondNum = key - k;
            
            if map[firstNum] != nil {
                result += 1;
            }
            
            if map[secondNum] != nil {
                result += 1;
            }
            
        }
        
        return result / 2;
    }
}
