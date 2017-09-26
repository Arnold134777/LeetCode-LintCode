/*
 解决思路:如题所示，从某个节点出发一定会通过：S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }的方式
 访问会该节点，且经过的所有节点必然与其他的节点无任何交集，因此依次遍历，同时用map记录访问访问过的节点即可。
 */
class Solution {
    func arrayNesting(_ nums: [Int]) -> Int {
        var maxResult = 0;
        if nums.count <= 0{
            return maxResult;
        }
        
        var map:[Int:Bool] = [:];
        for (index,num) in nums.enumerated(){
            let tempNum = map[num];
            if tempNum != nil{
                continue;
            }
            var firstNum = num;
            map[firstNum] = true;
            var currentNum = nums[firstNum];
            var count = 1;
            while firstNum != currentNum{
                map[currentNum] = true;
                currentNum = nums[currentNum];
                count += 1;
            }
            if(count > maxResult){
                maxResult = count;
            }
        }
        return maxResult;
    }
}
