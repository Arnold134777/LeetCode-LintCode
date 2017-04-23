/**
 * Initialize your data structure here.
 */
var RandomizedSet = function() {
    this.map = {};
};

/**
 * Inserts a value to the set. Returns true if the set did not already contain the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
  if(this.map[val]){
    return false;
  }
  this.map[val] = val;
  console.log(this.map);
  return true;
};

/**
 * Removes a value from the set. Returns true if the set contained the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
  console.log(this.map);
  if(this.map[val] !== undefined){
    delete(this.map[val]);
    return true;
  }
  return false;
};

/**
 * Get a random element from the set.
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    var keys = Object.keys(this.map);
    var count = keys.length;
    var randomVal = parseInt(Math.random()*count, 10);
    return this.map[keys[randomVal]];
};

var obj = new RandomizedSet();
console.log('remove 0:' + obj.remove(0));
console.log('remove 0:' + obj.remove(0));
console.log('insert 0:' + obj.insert(0));
console.log('getRandom:' + obj.getRandom());
console.log('remove 0:' + obj.remove(0));
console.log('insert 0:' + obj.insert(0));






 