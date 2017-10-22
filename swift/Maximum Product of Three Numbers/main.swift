class Solution {
    func maximumProduct(_ nums: [Int]) -> Int {
        var firstMinProduct:Int = 1001;
        var secondMinProduct:Int = 1001;
        
        var firstMaxProduct:Int = -1001;
        var secondMaxProduct:Int = -1001;
        var thirdMaxProduct:Int = -1001;
        
        for var index in (0...nums.count - 1){
            let num:Int = nums[index];
            if num >= firstMaxProduct{
                thirdMaxProduct = secondMaxProduct;
                secondMaxProduct = firstMaxProduct;
                firstMaxProduct = num;
            }else if num >= secondMaxProduct{
                thirdMaxProduct = secondMaxProduct;
                secondMaxProduct = num;
            }else if num > thirdMaxProduct{
                thirdMaxProduct = num;
            }
            
            if num < firstMinProduct{
                secondMinProduct = firstMinProduct;
                firstMinProduct = num;
            }else if num < secondMinProduct{
                secondMinProduct = num;
            }
        }
        
        // 两个负数 * 一个整正数，三个正数
        var result = max(firstMinProduct * secondMinProduct * firstMaxProduct, firstMaxProduct * secondMaxProduct * thirdMaxProduct);
        return result;
    }
}
