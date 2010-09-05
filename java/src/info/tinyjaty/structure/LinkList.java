/**
 * Double link list version
 * @author Bigclean
 * @todo add exception handling
 */

package info.tinyjaty.structure;

public class LinkList
       implements Cloneable {
	/**
	 * Double link list constructor
	 * @note In this implemented version, head and tail node is
	 *       auxiliary, is not considered as valid node
	 * @note After list is constructed, head and tail node would
	 *       not be changed unless deleteNode() modify it
	 * @note For distinguishing head(tail) with normal valid node,
	 *       head and tail node data field is "Reserved" to indicate it
	 */
	public LinkList() {
		head = new LinkNode();
		tail = new LinkNode();		
		
		// set head and tail node special data field
		head.setNodeData("Reserved");
		tail.setNodeData("Reserved");
		
		// concatenate head and tail node to construct list
		head.setNext(tail);
		tail.setPrev(head);
	}
	
	/**
	 * Get head node of current list
	 * It equals <code> list->head </code> in c language version 
	 * @return head node
	 */
	public LinkNode getHead() {
		System.out.println("get head node of list");
		System.out.println(head);
		return head;
	}
	
	/**
	 * Set head node of current list
	 * It equals <code> list->head = headNode </code> in c language version
	 * @param headNode new head node of current list
	 */
	public void setHead(LinkNode headNode) {
		this.head = headNode;
	}
	
	/**
	 * Get tail node of current list
	 * It equals <code> list->tail </code> in c language version.
	 * @return tail node 
	 */
	public LinkNode getTail() {
		return tail;
	}
	
	/**
	 * Set tail node of current list
	 * It equals <code> list->tail = tailNode </code> in c language version
	 * @param tailNode new tail node of current list
	 */
	public void setTail(LinkNode tailNode) {
		this.tail = tailNode;
	}
	
	/**
	 * Get length of list, number of node in list
	 * It equals <code> list->length </code> in c language version
	 * @return list length
	 */
	public int getListLength() {
		return length;
	}
	
	/**
	 * insert before referred node
	 * @param nextNode node after newly generated node
	 * @param elem data field of node inserted
	 */
	public void insertBefore(LinkNode nextNode, String anString) {
		if (nextNode.getPrev() == null) {
			// TODO: should throw exception.
			System.out.println("inserts before head node, error occurs");
		}
		
		LinkNode newNode = new LinkNode(anString);
		LinkNode prevNode = nextNode.getPrev();
		
		newNode.setPrev(prevNode);
		newNode.setNext(nextNode);
		
		prevNode.setNext(newNode);
		nextNode.setPrev(newNode);
		
		length++;
	}
	
	/**
	 * insert after referred node
	 * @param prevNode node after newly generated node
	 * @param elem data field of node inserted
	 */
	public void insertAfter(LinkNode prevNode, String anString) {
		if(prevNode.getNext() == null) {
			System.out.println("inserts after tail node, error occurs");
		}
		
		LinkNode newNode = new LinkNode(anString);
		LinkNode nextNode = prevNode.getNext();
		
		newNode.setPrev(prevNode);
		newNode.setNext(nextNode);
		
		prevNode.setNext(newNode);
		nextNode.setPrev(newNode);
		
		length++;
	}
	
	/**
	 * Insert before first valid node
	 * @param elem data field of inserted node
	 */
	public void insertFirst(String anString) {
		LinkNode newNode = new LinkNode(anString);
		LinkNode nextNode = head.getNext();
		
		newNode.setNext(nextNode);
		newNode.setPrev(head);
		
		head.setNext(newNode);
		nextNode.setPrev(newNode);
		
		length++;
	}
	
	/**
	 * insert node after tail of list
	 * @param elem data domain of node appended to list
	 */
	public void append(String anString) {
		LinkNode newNode = new LinkNode(anString);
		LinkNode prevNode = tail.getPrev();
		
		newNode.setPrev(prevNode);
		newNode.setNext(tail);
		
		tail.setPrev(newNode);
		prevNode.setNext(newNode);
		
		length++;
	}
	
	/**
	 * Remove referred node from list
	 * @note Remove node have <em> side effect </em>, especially that when you
	 *       remove head and tail node from list, it will set new head
	 *       or tail node
	 * @param node removed node
	 * 
	 */
	public void deleteNode(LinkNode node) {
		LinkNode prevNode = node.getPrev();
		LinkNode nextNode = node.getNext();
		
		if (prevNode != null) {
			prevNode.setNext(nextNode);
		} else { 
			// deleted node is head node, and 'nextNode' node would be
			// first node of  list, so it would place 'nextNode' node
			// as new head node of  list.
			head = nextNode;
			head.setNodeData("Reserved");
		}
		if (nextNode != null) {
			nextNode.setPrev(prevNode);
		} else {
			// deleted node is tail node, and 'prevNode' node would be
			// last node of  list, so it would place 'prevNode' node
			// as new tail node of  list.
			tail = prevNode;
			tail.setNodeData("Reserved");
		}
		
		length--;
	}
	
	public void isEmpty() {
	}
	
	/**
	 * Iterate nodes of list
	 * @param callback callback interface when iterating list
	 * @note Because there is no function pointer mechanism in Java,
	 *       so interface is used instead
	 */
	public void foreach(LinkNodeCallback callback) {
		LinkNode current = head.getNext();
		while (current.getNext() != null) {
			callback.linkNodeVisit(current);
			current = current.getNext();
		}
	}
	
	public int hashCode() {
		return super.hashCode();
	}
	
	public String toString() {
		return super.toString();
	}
	
	public LinkList clone() throws CloneNotSupportedException {
		LinkList clonedList = (LinkList) super.clone();
		
		// deep copy
		clonedList.head = (LinkNode) head.clone();
		clonedList.tail = (LinkNode) tail.clone();
		
		return clonedList;
	}
	
	/**
	 * Simple list usage sample, it's equal with list_class_test_main().
	 * Of course, it's a c language version function
	 */
	public static void main(String[] args) {
		LinkList list = new LinkList();
		list.insertFirst("Hello");
		list.insertFirst("World");
		list.insertFirst("Peace");
		list.insertFirst("Love");
		list.deleteNode(list.getTail().getPrev().getPrev());
		list.insertAfter(list.getTail().getPrev().getPrev(), "Code");
		list.insertBefore(list.getTail().getPrev().getPrev(), "Would");
		
		// traverse string list
		// TODO: maybe it's should to be named as Observer, not callback
		//       mechanism in c.
		list.foreach(new LinkNodeCallback() {
			// define linkNodeAction
			public void linkNodeVisit(LinkNode node) {
				System.out.println(node.getNodeData());
			}
		});
	}
	
	// fields data
	/**
	 * head node of list, not considered as valid node
	 */
	private LinkNode head;
	/**
	 * tail node of list, not considered as valid node
	 */
	private LinkNode tail;
	/**
	 * length of list, apparently initial value should be <tt> 0 <tt>
	 */
	private int length = 0;
}