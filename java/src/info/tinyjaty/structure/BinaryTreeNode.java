// BinaryTreeNode.java --- 
// 
// Filename: BinaryTreeNode.java
// Description: 
// Author: bigclean
// Created: Fri Sep 10 2010, 15:20
// Last-Updated: Fri Sep 10 2010, 15:27

// Code:


/**
 * simple sample binary tree node
 * @author bigclean
 */
package info.tinyjaty.structure;

interface BinaryTreeNodeCallback {
	/**
	 * visit node of binary tree when traversing
	 * @param node iterated node
	 */
	void binaryTreeNodeVisit();
}

public class BinaryTreeNode
implements BinaryTreeNodeCallback, Cloneable{
	public BinaryTreeNode() {
		// XXX: construction should be improved
	}
	
	public BinaryTreeNode(String anString) {
		data = anString;
	}
	
	/**
	 * get left child of referred node
	 * @return left child of node
	 */
	public BinaryTreeNode getLeftChild() {
		return left;
	}
	
	/**
	 * set referred node left child field
	 * @param leftNode new left child of node
	 */
	public void setLeftChild(BinaryTreeNode leftNode) {
		left = leftNode;
	}
	
	/**
	 * get right child of referred node
	 * @return right child of node
	 */
	public BinaryTreeNode getRightChild() {
		return right;
	}
	
	/**
	 * set referred node right child field
	 * @param rightNode new right child of node
	 */
	public void setRightChild(BinaryTreeNode rightNode) {
		right = rightNode;
	}
	
	/**
	 * get data field of referred node
	 * @return data field of node
	 */
	public String getNodeData() {
		return data;
	}
	
	/**
	 * set referred node data field
	 * @param anString new data string of node
	 */
	public void setNodeData(String anString) {
		data = anString;
	}
	
	public void binaryTreeNodeVisit() {
		System.out.printf("String of this node data is %d\n", getNodeData());
	}
	
	public int hashCode() {
		return super.hashCode();
	}
	public String toString() {
		return super.toString();
	}
	
	public BinaryTreeNode clone() throws CloneNotSupportedException{
		BinaryTreeNode clonedNode = (BinaryTreeNode) super.clone();
		
		// deep copy
		clonedNode.left = (BinaryTreeNode) left.clone();
		clonedNode.right = (BinaryTreeNode) right.clone();
		
		return clonedNode;
	}
	
	public static void main(String[] args) {
		System.out.println("Sample of binary tree node");
	}
	
	// data fields
	/**
	 * data field, maybe initial value is not necessary
	 */
	private String data = "Initial binary tree node";
	/**
	 * left child reference, initial value is <tt> null </tt>
	 */
	private BinaryTreeNode left = null;
	/**
	 * right child reference, initial value is <tt> null </tt>
	 */
	private BinaryTreeNode right = null;
}
// 
// BinaryTreeNode.java ends here
