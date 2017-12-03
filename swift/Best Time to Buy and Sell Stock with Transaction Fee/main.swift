class Solution {
    
    /**
     sold[i]表示第i天卖掉股票此时的最大利润，hold[i]表示第i天保留手里的股票此时的最大利润
     sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);s
     hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
     */
    func maxProfit(_ prices: [Int], _ fee: Int) -> Int {
        if prices.count <= 0 {
            return 0;
        }
        
        var hold:[Int] = [];
        var sold:[Int] = [];
        
        hold.append(-1 * prices[0]);
        sold.append(0);
        
        for var index in 1..<prices.count {
            // 第index天卖出股票
            sold.append(max(sold[index - 1],hold[index - 1] + prices[index] - fee));
            // 第index天买入股票
            hold.append(max(hold[index - 1],sold[index - 1] - prices[index]));
        }
        
        return sold[prices.count - 1];
    }
}
