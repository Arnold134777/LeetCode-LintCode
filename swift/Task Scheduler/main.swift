/**
 解题思路:1.先统计每个字符出现的个数，记录出现次数最多的字符以及出现的个数maxCount
 2.我们将整个的任务看成填充maxCount - 1个相同的容器(最后一个不用考虑)，每个容器的大小的n + 1
 3.计算插入完出现最多的字符还需要的任务数为neededCount = (n - (maxLength - 1)) * (maxCount - 1)
 4.计算还剩余的需要插入的字符的个数leftCount = tasks.count - maxCount * maxLength
 5.result = max(0, neededCount - leftCount) + tasks.count 即为最终的计算的结果
 */
class Solution {
    func leastInterval(_ tasks: [Character], _ n: Int) -> Int {
        var result:Int = 0;
        if tasks.count <= 0{
            return result;
        }
        var maxCount:Int = 0;
        var maxLength:Int = 0;
        var map:[Character:Int] = [:];
        for var index in (0...tasks.count - 1){
            var character:Character = tasks[index];
            var count:Int = 0;
            if map[character] == nil {
                map[character] = 1;
            }else{
                count = map[character]!;
                count += 1;
                map[character] = count;
            }
            
            if count > maxCount {
                maxCount = count;
                maxLength = 1;
            }else if(count == maxCount){
                maxLength += 1;
            }
        }
        
        var neededCount = (n - (maxLength - 1)) * (maxCount - 1);
        var leftCount = tasks.count - maxCount * maxLength;
        result = max(0, neededCount - leftCount) + tasks.count;
        return result;
    }
}
