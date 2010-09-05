/**
 * Link node
 * @author Bigclean
 */
package info.tinyjaty.structure;

/**
 * In Java, now use interface and class to implement callback
 * function mechanism.
 * @XXX: It should be stressed that implement interface not
 *      be placed in main function
 * @author Bigclean
 *
 */
interface LinkNodeCallback {
	/**
	 * visit node of link list when traversing
	 * @param node iterated node
	 */
	void linkNodeVisit(LinkNode node);
}

/**
 * Simple and clean link node class
 *
 */
public class LinkNode
implements LinkNodeCallback, Cloneable {
	public LinkNode() {
		// initial data.
		// XXX: construction should be improved
	}
	public LinkNode(String anString) {
		data = anString;
		// sets previous and next node reference as null
		prev = null;
		next = null;
	}
	
	/**
	 * Get next node of current node
	 * It equals <code> node->next </code> in c language version.
	 * @return next node reference of current node
	 */
	public LinkNode getNext() {
		return next;
	}
	
	/**
	 * Set next node of current node
	 * It equals <code> node->next = nextNode </code> in c language version
	 * @param nextNode next node reference of current node
	 */
	public void setNext(LinkNode nextNode) {
		this.next = nextNode;
	}
	
	/**
	 * Get previous node of current node
	 * It equals <code> node->prev </code> in c language version
	 * @return previous node reference of current node
	 */
	public LinkNode getPrev() {
		return prev;
	}
	
	/**
	 * Set previous node of current node
	 * It equals <code> node->prev = prevNode </code> in c language version
	 * @param prevNode previous node reference of current node
	 */
	public void setPrev(LinkNode prevNode) {
		this.prev = prevNode;
	}
	
	/**
	 * Get data field of current node
	 * It equals <code> node->data </code> in c language version.
	 * @return current node data field
	 */
	public String getNodeData() {
		return data;
	}
	
	/**
	 * Set data field of current node
	 * It equals <code> node->data = nodeData </code> in c language version
	 * @param nodeData data
	 */
	public void setNodeData(String anString) {
		data = anString;
	}
	
	public int hashCode() {
		return super.hashCode();
	}
	
	public String toString() {
		return super.toString();
	}
	
	public LinkNode clone() throws CloneNotSupportedException {
		LinkNode clonedNode = (LinkNode)super.clone();
		
		// deep copy
		clonedNode.next = (LinkNode) next.clone();
		clonedNode.prev = (LinkNode) prev.clone();
		
		return clonedNode;
	}
	
	/**
	 * Simply display information of node
	 */
	public void linkNodeVisit(LinkNode node) {
		System.out.printf("element domain is %d.\n", node.getNodeData());
	}
	
	public static void mian(String[] args) {
		System.out.println("Sample starts");
	}
	
	/**
	 * data field
	 */
	private String data = "Intial link node";
	/**
	 * next node reference, initial value is <tt> null </tt>
	 */
	private LinkNode next = null;
	/**
	 * previous node reference, initial value is <tt> null </tt>
	 */
	private LinkNode prev = null;
}