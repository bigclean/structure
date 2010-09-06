/**
 * Sequence stack, implemented in generic array list
 * @author Bigclean
 * @note In this java implementation, there are some differences:
 *       <ul>
 *       <li> Default stack element is String, maybe generic type 
 *       stack maybe better </li>
 *       <li> Top and base reference only can not used for basic
 *       types, because basic types use heaps, not reference always </li>
 *       <li> Now use getLength() instead 'length' field in c version,
 *       maintain 'length' data field is not so essential as in c,
 *       because java provide its size() function </li>
 *       <li> use peek() not stack_get_top() in c, but they just
 *       execute action of having a look of top element of stack </li>
 *       </ul>
 * @TODO add call-back mechanism for stack when traversing, or use
 *       internal iterator of generic array list
 * 
 */
package info.tinyjaty.structure;

import java.util.*;

public class Stack 
       implements Cloneable{
	public Stack() {
		// When initialized, capacity is StackInitSize, but size is 
		// still 0, so it throws IndexOutOfBoundsException exception
		stackArray = new ArrayList<String>(StackInitSize);
		stackArray.ensureCapacity(StackInitSize);
		// TODO: top and base now only works for reference,
		//       basic types(such as int, double) can't be consistent
	}
	
	/**
	 * get current length of stack
	 * @return stack size(length)
	 */
	public int getLength() {
		return stackArray.size();
	}
	
	/**
	 * add a value to stack
	 * @param anString added element
	 */
	public void push(String anString) {
		// adjust sizes, should isFull() be added?
		if (getLength() >= capacity) {
			capacity += StackIncrement;
			stackArray.ensureCapacity(capacity);
		}
		stackArray.add(anString);
		
		// when push first once
		if (getLength() == 1) {
			base = stackArray.get(0);
			top = base;
		}
		// index is zero based
		top = stackArray.get(getLength() - 1);
	}
	
	/**
	 * retrieve top value from the stack and remove it
	 * @return top value of stack
	 */
	public String pop() {
		String tmpTop = top;
		stackArray.remove(top);
		top = stackArray.get(getLength() - 1);
		return tmpTop;

	}
	
	/**
	 * only receive top value without removing it
	 * @return top element of stack
	 */
	public String peek() {
		return top;
	}
	
	/**
	 * see stack if is empty
	 * @return <ul>
	 *         <li> true  stack is empty </li>
	 *         <li> false stack is not empty </li>
	 *         </ul>
	 */
	public boolean isEmpty() {
		if (getLength() == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	public int hashCode() {
		return super.hashCode();
	}
	
	public String toString() {
		return super.toString();
	}
	
	public Stack clone() throws CloneNotSupportedException {
		Stack clonedStack = (Stack) super.clone();
		return clonedStack;
	}
	
	/**
	 * simple test for generic array constructed stack
	 */
	public static void main(String[] args) {
		System.out.println("Starts to sample");
		Stack aStack = new Stack();
		aStack.push("world");
		aStack.push("hello");
		System.out.printf("%s, %s", aStack.pop(), aStack.peek());
	}
	
	// fields data
	
	// constants variable
	/**
	 * initial size of stack
	 */
	private static final int StackInitSize = 100;
	/**
	 * increment size of stack
	 */
	private static final int StackIncrement = 10;
	
	/**
	 * stack current capacity, relative static
	 */
	private int capacity = StackInitSize;
	/**
	 * stack top address
	 * @note Because implementation limits, top always refer to last
	 *       element of stack, not the upper address of last
	 *       element in c version implementation
	 * 
	 * @TODO: I wonder if top and base fields is necessary in Java version,
	 *        it's consistent with c version only
	 */
	private String top = null;
	/**
	 * stack base address
	 */
	private String base = null;
	
	/**
	 * Generic String stack array holds data
	 */
	private ArrayList<String> stackArray;
	

}