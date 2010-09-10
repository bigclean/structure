// BinaryTree.java --- 
// 
// Filename: BinaryTree.java
// Description: Simple binary tree
// Author: bigclean
// Created: Fri Sep 10 2010, 15:20
// Last-Updated: Fri Sep 10, 2010 15:27

// Code:


/**
 * Simple binary tree
 * @author Bigclean
 */
package info.tinyjaty.structure;

// see enumerated class specification
enum BinaryInsertMode { LEFT, RIGHT };
enum BinaryTraverseMode { PreOrder, InOrder, PostOrder };

public class BinaryTree implements Cloneable {
	public BinaryTree() {
		root = new BinaryTreeNode();
		root.setLeftChild(null);
		root.setRightChild(null);
		root.setNodeData("Reserved root");
	}
	
	public BinaryTreeNode getRoot() {
		return root;
	}
	public void setRoot(BinaryTreeNode rootNode) {
		root = rootNode;
		root.setNodeData("Reserved root");
	}
	
	/**
	 * insert child node to parent node
	 * @param parentNode
	 * @param childNode
	 * @param flag <ul>
	 *             <li> LEFT insert left </li>
	 *             <li> RIGHT insert right </li>
	 *             </ul>
	 */
	public void insertNode(BinaryTreeNode parentNode, 
			BinaryInsertMode flag, BinaryTreeNode childNode) {
		BinaryTreeNode moveNode = null;
		
		if (flag == BinaryInsertMode.LEFT) {
			// insert at left side
			moveNode = parentNode.getLeftChild();
			parentNode.setLeftChild(childNode);
			childNode.setRightChild(moveNode);
		} else {
			// insert at right side
			moveNode = parentNode.getRightChild();
			childNode.setRightChild(parentNode.getRightChild());
			parentNode.setRightChild(childNode);
		}
	}
	
	/**
	 * Insert child tree to parent node
	 * @param parentNode
	 * @param childTree
	 */
	public void insertTree(BinaryTreeNode parentNode, 
			BinaryInsertMode flag, BinaryTree childTree) {
		insertNode(parentNode, flag, childTree.getRoot());
	}
	
	public void traverse(BinaryTreeNode node, BinaryTraverseMode flag) {
		if (node != null) {
			// TODO: best practice is function jump table, to be continued
		}		
	}
	
	/**
	 * traverse tree in pre-order
	 * @param node root of traversed subtree
	 */
	public void traversePreOrder(BinaryTreeNode node) {
		if (node != null) {
			// visit
			System.out.println(node.getNodeData());
			traversePreOrder(node.getLeftChild());
			traversePreOrder(node.getRightChild());
		}
	}
	
	/**
	 * traverse tree in post-order
	 * @param node root of traversed subtree
	 */
	public void traversePostOrder(BinaryTreeNode node) {
		if (node != null) {
			traversePostOrder(node.getLeftChild());
			traversePostOrder(node.getRightChild());
			// visit
		}
	}
	
	/**
	 * traverse tree in in-order
	 * @param node root of traversed subtree
	 */
	public void traverseInOrder(BinaryTreeNode node) {
		traverseInOrder(node.getLeftChild());
		// visit
		traverseInOrder(node.getRightChild());
	}
	
	/**
	 * 
	 * @param general node node of this tree, maybe special root or normal child node
	 * @return depth of referred node
	 * @note If you want depth of current tree, you should use such code:
	 *       <code> depth(root) </code>
	 * @TODO should be considered also implemented in c version
	 */
	public int nodeDepth(BinaryTreeNode node) {
		int leftDepth, rightDepth;
		int maxDepth;
		if (node == null) {
			return 0;
		}
		
		if (node.getLeftChild() != null) {
			leftDepth = nodeDepth(node.getLeftChild());
		} else {
			leftDepth = 0;
		}
		
		if(node.getRightChild() != null) {
			rightDepth = nodeDepth(node.getRightChild());
		} else {
			rightDepth = 0;
		}
		
		// maybe three-meta expression is a little implicit
		maxDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return maxDepth;
	}
	
	/**
	 * depth of tree
	 * @return root node depth
	 */
	public int depth() {
		return nodeDepth(root);
	}
	
	public int hashCode() {
		return super.hashCode();
	}
	
	public String toString() {
		return super.toString();
	}
	
	public BinaryTree clone() throws CloneNotSupportedException {
		BinaryTree clonedTree = (BinaryTree) super.clone();
		
		// deep copy
		clonedTree.root = (BinaryTreeNode) root.clone();
		return clonedTree;
	}
	
	public static void main(String[] args) {
		System.out.println("starts to test binary tree");
		BinaryTree tree = new BinaryTree();
		BinaryTreeNode nodeOne = new BinaryTreeNode("hello");
		BinaryTreeNode nodeTwo = new BinaryTreeNode("world");
		tree.insertNode(tree.getRoot(), BinaryInsertMode.LEFT, nodeOne);
		tree.insertNode(tree.getRoot(), BinaryInsertMode.LEFT, nodeTwo);
		System.out.printf("Depth of tree is %d\n", tree.depth());
		tree.traversePreOrder(tree.getRoot());
	}
	
	// fields data
	private BinaryTreeNode root;
}
// 
// BinaryTree.java ends here
