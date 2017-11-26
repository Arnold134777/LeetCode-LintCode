class Solution {
    func isOneBitCharacter(_ bits: [Int]) -> Bool {
        return isOneBitCharacter(bits, at: 0);
    }
    
    func isOneBitCharacter(_ bits:[Int],at index:Int) ->Bool {
        
        if index == bits.count - 1 && bits[index] == 0{
            return true;
        }else if index == bits.count - 2 && bits[index] == 1{
            return false
        }
        
        if bits[index] == 0{
            return isOneBitCharacter(bits,at:index + 1);
        }else{
            return isOneBitCharacter(bits,at:index + 2);
        }
    }
}
