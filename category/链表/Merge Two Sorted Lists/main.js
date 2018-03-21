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

var mergeTwoLists = function(l1, l2) {
	if(l1 === undefined || l1 === null ){
		return l2;
	}

	if(l2 === undefined || l2 === null){
		return l1;
	}

	var result;
	var current;
    var temp;
	while(l1 && l2){
		if(l1.val <= l2.val){
			temp = l1;
			l1 = l1.next;
		}else{
			temp = l2;
			l2 = l2.next
		}

		if(result === undefined){
			result = temp;
			current = temp;
		}else{
			current.next = temp;
			current = current.next;
		}
	}

	if(l1){
		current.next = l1;
	}else{
		current.next = l2;
	}

	return result;
};

var node1 = new ListNode(1);
var node2 = new ListNode(3);
var node3 = new ListNode(5);
node1.next = node2;
// node2.next = node3;


var node4 = new ListNode(2);
var node5 = new ListNode(4);
var node6 = new ListNode(6);
var node7 = new ListNode(8);

var node9;
var node8;
// node4.next = node5;
// node5.next = node6;
// node6.next = node7;

var resultNode = mergeTwoLists(node9,node8);
while(resultNode){
	console.log(resultNode.val);
	resultNode = resultNode.next;
}

