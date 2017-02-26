/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if(prices.length <= 0){
    return 0;
  }
  var maxProfit = 0;
  var minPrice = prices[0];
  for(var index = 1;index <= prices.length - 1;index++){

    if(prices[index] - minPrice > maxProfit){
      maxProfit = prices[index] - minPrice;
    }

    if(prices[index] < minPrice){
      minPrice = prices[index];
    }
  }

  return maxProfit;
};

console.log(maxProfit([7, 1, 5, 3, 6, 4]));
console.log(maxProfit([7, 6, 4, 3, 1]));
