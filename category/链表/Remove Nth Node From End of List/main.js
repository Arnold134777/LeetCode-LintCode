/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */

function ListNode(val) {
      this.val = val;
      this.next = null;
}

var removeNthFromEnd = function(head, n) {
	if(head === undefined || n <= 0) {
		return head;
	}    
 
    var index = 0;
	var frontNode = head;
	var behindNode = head;
	var preNode = undefined;

	while(frontNode){
		if(index >= n){
			preNode = behindNode;
			behindNode = behindNode.next;
		}
		index++;
		frontNode = frontNode.next;
	}

    // 注意超过删除范围
	if(index < n){
		return head;
	}

    // 处理删除头结点的情况
	if(preNode == undefined){
		return head.next;
	}

	preNode.next = behindNode.next;
	return head;
};

var node1 = new ListNode(1);
var node2 = new ListNode(2);
var node3 = new ListNode(3);
var node4 = new ListNode(4);
var node5 = new ListNode(5);

// node1.next = node2;
// node2.next = node3;
// node3.next = node4;
// node4.next = node5;

var resultNode = removeNthFromEnd(node1,1);
while(resultNode){
	console.log(resultNode.val);
	resultNode = resultNode.next;
}

