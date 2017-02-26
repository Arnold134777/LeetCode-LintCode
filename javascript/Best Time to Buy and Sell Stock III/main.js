/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if(prices.length <= 0){
    return 0;
  }
  return getMaxProfit(prices,2);
};

var getMaxProfit = function(prices,mostTransactionCount){
  var localProfit = [];
  var globalProfit = [];

  for(var day = 1;day <= prices.length - 1;day++){
    var eachLocalProfit = [0];
    var eachGlobalProfit = [0];
    var diff = prices[day] - prices[day - 1];
    for(var transactionCount = 1;transactionCount <= mostTransactionCount;transactionCount++){
      eachLocalProfit[transactionCount] = Math.max(globalProfit[day - 1][transactionCount - 1] + Math.max(diff,0),localProfit[day - 1][transactionCount] + diff);
      eachGlobalProfit[transactionCount] = Math.max(eachLocalProfit[transactionCount],globalProfit[day - 1][transactionCount]);
    }

    localProfit[day] = eachLocalProfit;
    globalProfit[day] = eachGlobalProfit;
  }

  return globalProfit[prices.length - 1][mostTransactionCount];
}

console.log(maxProfit([7, 1, 5, 3, 6, 4]))