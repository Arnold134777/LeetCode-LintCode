/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
	if(head === null || head.next === null){
		return head;
	}

	var preNode = head;
	var curNode = head.next;

	while(curNode !== null){
		if(preNode.val !== curNode.val){
			preNode.next = curNode;
			preNode = curNode;
		}

		curNode = curNode.next;
	}
	preNode.next = null;

	return head;
};

var node1 = new ListNode(4);
var node2 = new ListNode(4);
var node3 = new ListNode(4);
// var node4 = new ListNode(5);
// var node5 = new ListNode(5);
// var node6 = new ListNode(6);
// var node7 = new ListNode(6);

node1.next = node2;
node2.next = node3;
// node3.next = node4;
// node4.next = node5;
// node5.next = node6;
// node6.next = node7;

var resultNode = deleteDuplicates(node1);
while(resultNode){
	console.log(resultNode.val);
	resultNode = resultNode.next;
}

