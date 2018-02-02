import java.util.LinkedList;

public class Main {
	public static void main(String[] args) {

		MyStack solution = new MyStack();
		solution.push(1);
		solution.push(2);
		System.out.println(solution.pop());
		solution.push(3);
		System.out.println(solution.pop());
		solution.push(4);
		System.out.println(solution.pop());
		System.out.println(solution.pop());
	}
}

class MyStack {

	LinkedList<Integer> firstQueue;
	LinkedList<Integer> secondQueue;

	/** Initialize your data structure here. */
	public MyStack() {
		firstQueue = new LinkedList<Integer>();
		secondQueue = new LinkedList<Integer>();
	}

	/** Push element x onto stack. */
	public void push(int x) {
		if (firstQueue.size() <= 0 && secondQueue.size() <= 0) {
			firstQueue.add(x);
		} else if (firstQueue.size() <= 0) {
			secondQueue.add(x);
		} else {
			firstQueue.add(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	public int pop() {
		if (this.empty()) {
			return -1;
		}
		if (firstQueue.size() > 0) {
			while (firstQueue.size() >= 2) {
				secondQueue.add(firstQueue.pop());
			}
			return firstQueue.pop();
		} else {
			while (secondQueue.size() >= 2) {
				firstQueue.add(secondQueue.pop());
			}
			return secondQueue.pop();
		}
	}

	/** Get the top element. */
	public int top() {
		if (this.empty()) {
			return -1;
		}
		int top;
		if (firstQueue.size() > 0) {
			while (firstQueue.size() >= 2) {
				secondQueue.add(firstQueue.pop());
			}
			top = firstQueue.pop();
			secondQueue.add(top);
			return top;
		} else {
			while (secondQueue.size() >= 2) {
				firstQueue.add(secondQueue.pop());
			}
			top = secondQueue.pop();
			firstQueue.add(top);
			return top;
		}
	}

	/** Returns whether the stack is empty. */
	public boolean empty() {
		return firstQueue.size() <= 0 && secondQueue.size() <= 0;
	}
}
