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

var addTwoNumbers = function(l1, l2) {
	if(l1 === undefined){
		return l2;
	}

	if(l2 === undefined){
		return l1;
	}

	var resultNode;
	var currentNode;
	var currentAddSum = 0;

	while(l1 !== null || l2 !== null){
		currentAddSum += ((l1 !== null ? l1.val : 0) + (l2 != null ? l2.val : 0));
		// console.log("1 ==> " + l1.val);
		// console.log("2 ==> " + l2.val);
		// console.log(currentAddSum);
		var newNode = new ListNode(currentAddSum % 10);
		if(resultNode === undefined){
			resultNode = newNode;
			currentNode = resultNode;
		}else{
			currentNode.next = newNode;
			currentNode = currentNode.next;
		}
		//console.log("result ==> " + resultNode.val);
		currentAddSum = parseInt(currentAddSum / 10);
		l1 && (l1 = l1.next);
		l2 && (l2 = l2.next);
	}

	if(currentAddSum >= 1){
		var newNode = new ListNode(currentAddSum);
		currentNode.next = newNode;
	}

	return resultNode;
};

var node1 = new ListNode(2);
var node2 = new ListNode(4);
var node3 = new ListNode(5);
node1.next = node2;
node2.next = node3;


var node4 = new ListNode(5);
var node5 = new ListNode(6);
var node6 = new ListNode(4);
var node7 = new ListNode(1);
node4.next = node5;
node5.next = node6;
node6.next = node7;

var resultNode = addTwoNumbers(node1,node4);
while(resultNode){
	console.log(resultNode.val);
	resultNode = resultNode.next;
}

