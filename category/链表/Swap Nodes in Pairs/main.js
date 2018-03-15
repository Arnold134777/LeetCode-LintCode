/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}

var swapPairs = function(head) {

	if(head === null || head.next === null){
		return head;
	}

	var currentNode = head;
	var resultNode = head.next;
	// 用于记录上一个相邻结点的头结点
	var preNode = null; 
	// 用于记录下一个相邻结点的第一个结点
	var nextSwapPairHead = null;
	while(currentNode !== null){
		if(preNode !== null){
			if(currentNode.next === null){
				preNode.next = currentNode;
				break;
			}else{
				preNode.next = currentNode.next;
			}
			
		}
		
		nextSwapPairHead = currentNode.next.next;
		currentNode.next.next = currentNode;
		preNode = currentNode;
		currentNode = nextSwapPairHead
		preNode.next = null;
	}

	return resultNode;
};

var node1 = new ListNode(1);
var node2 = new ListNode(2);
var node3 = new ListNode(3);
var node4 = new ListNode(4);
// var node5 = new ListNode(5);

node1.next = node2;
node2.next = node3;
node3.next = node4;
// node4.next = node5;

var resultNode = swapPairs(node1);
while(resultNode !== null){
	console.log(resultNode.val);
	resultNode = resultNode.next;
}