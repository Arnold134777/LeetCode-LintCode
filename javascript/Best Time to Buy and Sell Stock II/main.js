/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if(prices.length <= 0){
    return 0;
  }

  var maxProfit = 0;
  for(var index = 1;index <= prices.length - 1;index++){
    if(prices[index] > prices[index - 1]){
      maxProfit += prices[index] - prices[index - 1];
    }
  }
  return maxProfit;
};

console.log(maxProfit([7, 1, 5, 3, 6, 4]))