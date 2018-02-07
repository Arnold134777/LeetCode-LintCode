import java.util.Stack;

public class Main {
	public static void main(String[] args) {

		MyQueue solution = new MyQueue();
		solution.push(1);
		solution.push(2);
		solution.push(3);
		System.out.println(solution.pop());
		System.out.println("peek" + solution.peek());
		System.out.println(solution.pop());
		solution.push(4);
		System.out.println(solution.pop());
		System.out.println(solution.pop());
	}
}

class MyQueue {

	/** Initialize your data structure here. */
	Stack<Integer> firstStack = null;
	Stack<Integer> secondStack = null;

	public MyQueue() {
		firstStack = new Stack<Integer>();
		secondStack = new Stack<Integer>();
	}

	/** Push element x to the back of queue. */
	public void push(int x) {
		firstStack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	public int pop() {
		if (empty()) {
			return -1;
		}
		if (secondStack.size() <= 0) {
			while (firstStack.size() > 0) {
				secondStack.push(firstStack.pop());
			}
		}
		return secondStack.pop();
	}

	/** Get the front element. */
	public int peek() {
		if (empty()) {
			return -1;
		}
		if (secondStack.size() <= 0) {
			while (firstStack.size() > 0) {
				secondStack.push(firstStack.pop());
			}
		}
		return secondStack.lastElement();
	}

	/** Returns whether the queue is empty. */
	public boolean empty() {
		return firstStack.isEmpty() && secondStack.isEmpty();
	}
}
