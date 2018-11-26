#include "AVLBinarySearchTree.hpp"

namespace avlbst {

	void avlbstUI()
	{

	}

	Node *initNode(Key k, Value v)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode)
		{
			newNode->key = k;
			newNode->value = v;
			newNode->height = 0;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;
		}
		return newNode;
	}

	Tree *initTree()
	{
		Tree *newTree = (Tree *)malloc(sizeof(Tree));
		if(newTree) newTree->root = NULL;
		return newTree;
	}

	Node* insertNode(Key k, void *v, Node *root)
		// Build new node and insert into (non-empty) tree. Check if insertion has
		// created imbalance and rebalance if necessary.
	{
		if (root == NULL) {
			Node *n = initNode(k, v);
			n->height = 0;
			return n;
		}
		if (k == root->key)
			printf("Key already exists");
		else if (k < root->key) {
			root->leftChild = insertNode(k, v, root->leftChild);
			root->height = calcHeight(root);
		}

		else if (k > root->key) {
			root->rightChild = insertNode(k, v, root->rightChild);
			root->height = calcHeight(root);
		}
		return rebalance(root);
	}//insertNode()



	void insert(Key k, void *v, Tree *t)
		// Add new data item to tree.  Use two data components - key and actual data -
		// to create new node and insert node in appropriate place.
	{
		printf("Inserting %d\n", k);
		if (t->root == NULL) {
			Node *n = initNode(k, v);
			n->height = 0;
			t->root = n;
		}
		else {
			t->root = insertNode(k, v, t->root);
		}
		return;
	}//insert()

	void createTree(Key *key, Value value, Tree *tree)
	{
		for (int i = 0; key && value; i++) {
			insert(key[i], &value, tree);
		}

	}

		Node* rotateRight(Node* root)
			// Rotate to right.  Returns new root pointer.
		{
			printf("Rotate Right\n");
			//---Your code goes here
			//---<SNIP>---
			if (root->leftChild) {
				Node *subL = root->leftChild;
				root->leftChild = subL->rightChild;
				subL->rightChild = root;
				root->height = calcHeight(root);
				subL->height = calcHeight(subL);
				return subL;
			}
			//---<SNIP>---
			else
				return root;
		}//rotateRight()


		Node* rotateLeft(Node* root)
			// Rotate to left.  Returns new root pointer.
		{
			printf("Rotate Left\n");
			if (root->rightChild) {
				Node *subR = root->rightChild;
				root->rightChild = subR->leftChild;
				subR->leftChild = root;
				root->height = calcHeight(root);
				subR->height = calcHeight(subR);
				return subR;
			}
			else
				return root;
		}//rotateLeft()


		int getBalanceFactor(Node* root)
			// Get balance factor - difference between left height and right height
		{
			int	hr = -1, hl = -1;		// Default values
										//---Your code goes here
										//---<SNIP>---
			if (!root)
				return 0;
			hr = (!root->rightChild) ? 0 : root->rightChild->height + 1;
			hl = (!root->leftChild) ? 0 : root->leftChild->height + 1;
			return hl - hr;
		}//getBalanceFactor()


		int calcHeight(Node* root)
			// Calculate height of this node by adding 1 to maximum of left, right
			// child height.
		{
			int hrl = -1, hll = -1;		// Default values
			if (!root)
				return -1;
			hrl = (!(root->rightChild)) ? -1 : root->rightChild->height;
			hll = (!(root->leftChild)) ? -1 : root->leftChild->height;
			return MAXINT(hrl, hll) + 1;
		}//calcHeight();

		void deleteNode (Node* p, Node *n)
			// Delete node pointed to by n.
			// Parameters:
			//	n	- points to node to be deleted
			//	p	- points to parent of node to be deleted.
		{
			if (!n->leftChild || !n->rightChild) {
				if (!n->leftChild && !n->rightChild) {
					if (p->leftChild == n)
						p->leftChild = NULL;
					else if (n->rightChild == n)
						p->rightChild = NULL;
				}
				else if (n->leftChild) {
					if (p->leftChild == n)
						p->leftChild = n->leftChild;
					else if (p->rightChild == n)
						p->rightChild = n->leftChild;
				}
				else if (n->rightChild) {
					if (p->leftChild == n)
						p->leftChild = n->rightChild;
					else if (p->rightChild == n)
						p->rightChild = n->rightChild;
				}
				free(n);
			}
			else if (n->leftChild && n->rightChild) {
				Node *backparent = n, *subsitituter = n->leftChild;
				if (n->leftChild->height <= n->rightChild->height) {
					while (subsitituter->rightChild)
					{
						backparent = subsitituter;
						subsitituter = subsitituter->rightChild;
					}
				}
				n->key = subsitituter->key;
				n->value = subsitituter->value;
				if (backparent->leftChild == subsitituter)
					backparent->leftChild = subsitituter->leftChild;
				else
					backparent->rightChild = subsitituter->leftChild;
				free(subsitituter);
			}
		}//delete()

		Node* rebalance(Node* root)
			// Check balance factor to see if balancing required (bf > 1 or bf < -1).
			// If balancing required, perform necessary rotations.
		{
			int bf = getBalanceFactor(root);
			if (bf > 1) {
				printf("Node %d is unbalanced. ", root->key);
				if (getBalanceFactor(root->leftChild) >= getBalanceFactor(root->rightChild)) {
					printf("Left of Left: ");
					root = rotateRight(root);
				}
				else if (getBalanceFactor(root->leftChild) < getBalanceFactor(root->rightChild)) {
					printf("Right of Left: ");
					root->leftChild = rotateLeft(root->leftChild);
					root = rotateRight(root);
				}
			}
			else if (bf < -1) {
				printf("Node %d is unbalanced. ", root->key);
				if (getBalanceFactor(root->leftChild) >= getBalanceFactor(root->rightChild)) {
					printf("Right of Right: ");
					root = rotateLeft(root);
				}
				else if (getBalanceFactor(root->leftChild) < getBalanceFactor(root->rightChild)) {
					printf("Left of Right: ");
					root->rightChild = rotateRight(root->rightChild);
					root = rotateLeft(root);
				}
			}
			//else
			//printf("Node %d is balanced. ", root->key);
			//---<SNIP>---
			return root;
		}//rebalance()


}