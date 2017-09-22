class Solution {
    func findPoisonedDuration(_ timeSeries: [Int], _ duration: Int) -> Int {
        var totalDuration = 0;
        if timeSeries.count <= 0{
            return totalDuration;
        }
        
        var lastTimeSerie:Int = 0;
        var currentTimeSerie:Int = 0;
        for (index,timeSerie) in timeSeries.enumerated(){
            if index == 0{
                lastTimeSerie = timeSeries[0];
                continue;
            }
            
            if timeSerie - lastTimeSerie >= duration{
                totalDuration += duration;
            }else{
                totalDuration += (timeSerie - lastTimeSerie)
            }
            lastTimeSerie = timeSerie;
        }
        totalDuration += duration;
        return totalDuration;
    }
}
