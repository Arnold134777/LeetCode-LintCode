
function Interval(start, end) {
    this.start = start;
    this.end = end;
}
 
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
  if(intervals.length <= 0){
    return [];
  }  

  intervals.sort(function(intervalA,intervalB){
    if(intervalA.start === intervalB.start){
      return intervalA.end - intervalB.end;
    }
    return intervalA.start - intervalB.start;
  });

  var intervalStart = intervals[0].start;
  var intervalEnd = intervals[0].end;
  var mergeIntervals = [];
  mergeIntervals.push(intervals[0]);
  var lastInterval = intervals[0];

  for(var index = 1;index < intervals.length;index++){
    var interval = intervals[index];

    if(lastInterval.end > interval.end){
      continue;
    }

    if(lastInterval.end >= interval.start && lastInterval.end < interval.end){
      lastInterval.end = interval.end
      continue;
    }

    if(lastInterval.end < interval.start){
      lastInterval = interval;
      mergeIntervals.push(interval);
    }
  }

  return mergeIntervals;
};

var intervals = [];
intervals.push(new Interval(1,19));
intervals.push(new Interval(2,3));
intervals.push(new Interval(2,6));
intervals.push(new Interval(15,18));

console.log(merge(intervals));
