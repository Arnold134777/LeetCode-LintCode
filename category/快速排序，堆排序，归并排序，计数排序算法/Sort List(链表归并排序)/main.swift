
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}
class Solution {
    func sortList(_ head: ListNode?) -> ListNode? {
        
        if head == nil || head?.next == nil{
            return head;
        }
        
        // 1.首先通过快慢指针找到中间分结点
        var fastNode:ListNode? = head;
        var slowNode:ListNode? = head;
        while fastNode?.next != nil && fastNode?.next?.next != nil{
            fastNode = fastNode?.next?.next;
            slowNode = slowNode?.next;
        }
        print("\(slowNode?.val)")
        // 2.归并排序
        var rightHeadNode:ListNode? = slowNode?.next;
        slowNode?.next = nil;
        var leftListNode:ListNode? = sortList(head);
        var rightListNode:ListNode? = sortList(rightHeadNode);
        return mergeTwoListNode(&leftListNode, &rightListNode);
    }
    
    func mergeTwoListNode(_ left:inout ListNode?, _ right:inout ListNode?) -> ListNode? {
        // 建一个虚拟的头结点
        var currentNode:ListNode? = ListNode(-1);
        var newHead:ListNode? = currentNode;
        
        while left != nil && right != nil{
            if left!.val < right!.val{
                currentNode?.next = left;
                left = left?.next;
            }else{
                currentNode?.next = right;
                right = right?.next;
            }
            
            currentNode = currentNode?.next;
        }
        
        if left == nil{
            currentNode?.next = right;
        }else{
            currentNode?.next = left;
        }
        
        return newHead?.next;
    }
}


var solution:Solution = Solution();
var node1:ListNode? = ListNode(4);
var node2:ListNode? = ListNode(3);
var node3:ListNode? = ListNode(2);
var node4:ListNode? = ListNode(1);
//var node5:ListNode? = ListNode(1);
//var node6:ListNode? = ListNode(3);
//var node7:ListNode? = ListNode(5);
//var node8:ListNode? = ListNode(7);
node1?.next = node2;
node2?.next = node3;
node3?.next = node4;
//node4?.next = node5;
//node5?.next = node6;
//node6?.next = node7;
//node7?.next = node8;
var resultNode:ListNode? = solution.sortList(node1);
while resultNode != nil {
    print(resultNode?.val);
    resultNode = resultNode?.next;
}


