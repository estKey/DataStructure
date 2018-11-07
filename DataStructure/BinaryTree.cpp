#include "BinaryTree.hpp"

namespace bt {

	int btUI()
	{
		int value = 6;
		int data[16] = { 00,5,4,6,2,0,0,8,1,3,0,0,0,0,7,9 };
		BinaryTree *tree = NULL;
		//tree = initTree(10, &value);
		insert(10, &value, tree);
		insert(3, &value, tree);
		insert(1, &value, tree);
		insert(7, &value, tree);
		insert(20, &value, tree);
		insert(15, &value, tree);
		insert(18, &value, tree);
		insert(17, &value, tree);
		insert(16, &value, tree);

		return 0;
	}

	BinaryTree *initTree(Key key, type value)
	{
		BinaryTree *newTree = (BinaryTree *)malloc(sizeof(BinaryTree));
		newTree->root = NULL;
		newTree->height = 0;
		return newTree;
	}

	Node *createtree(int *data, int pos)
	{
		Node *newnode;
		if (data[pos] == 0 || pos > strlen((char *)data))
			return NULL;
		else
		{
			newnode = (Node *)malloc(sizeof(Node));
			newnode->key = data[pos];
			newnode->leftChild = createtree(data, 2 * pos);
			newnode->rightChild = createtree(data, 2 * pos + 1);
			return newnode;
		}
	}

	Node *createNode(Key key, type value, Node *parent, Node *left, Node *right)
	{
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->value = value;
		newNode->leftChild = left;
		newNode->rightChild = right;
		return newNode;
	}

	Node *initNode(Key key, type value)
	{
		Node *newNode = createNode(key, value, NULL, NULL, NULL);
		return newNode;
	}

	void insertChild(Key key, type value, Node *root, BinaryTree *tree)
	{
		if (root->key == key) {
			printf("Key already exist");
			return;
		}
		else if (key < root->key) {
			if (root->leftChild != NULL)
				insertChild(key, value, root->leftChild, tree);
			else
				root->leftChild = initNode(key, value);
			if (!root->rightChild)
				tree->height++;
		}
		else if (key > root->key)
		{
			if (root->rightChild != NULL)
				insert(key, value, tree);
			else
				root->rightChild = initNode(key, value);
			if (!root->leftChild)
				tree->height++;
		}
	}

	void insert(Key key, type value, BinaryTree *tree)
	{
		if (!tree->root)
		{
			tree->root = initNode(key, value);
			tree->height = -1;
		}
		else
			insertChild(key, value, tree->root, tree);
	}

	void preorder(Node *root)
	{
		if (root)
		{
			printf("(Key:%d,Value:%d)\t", root->key, root->value);
			preorder(root->leftChild);
			preorder(root->rightChild);
		}
		else printf("NULL\n");
	}

	void inorder(Node *root)
	{
		if (root)
		{
			inorder(root->leftChild);
			printf("(Key:%d,Value:%d)\t", root->key, root->value);
			inorder(root->rightChild);
		}
	}

	void postorder(Node *root)
	{
		if (root)
		{
			postorder(root->leftChild);
			postorder(root->rightChild);
			printf("(Key:%d,Value:%d)\t", root->key, root->value);
		}
	}

	void dfs(Node* root)
	{
		printf("%d ", root->value);
		if (root->leftChild)
			dfs(root->leftChild);
		else if (root->rightChild)
			dfs(root->rightChild);
	}

	void bfs(Node* root)
	{

	}

	void invert(BinaryTree tree)
	{

	}

	void AVLtree()
	{

	}

	void printTree(BinaryTree *tree)
	{
		printf("Current Tree:\n");
		Node *root = tree->root;
		if (root)
		{
			printf("(Key:%d,Value:%d)\n", root->key, root->value);
			preorder(root->leftChild);
			preorder(root->rightChild);
		}
		else printf("NULL\n");
	}

	int getNumber(char ch)
	{
		if (isNumber(ch)) {
			int v = ch - '0';
			return v;
		}
	}
	
	int isNumber(char ch)
	{
		if ((ch >= 48) && (ch <= 57))
			return 1;
		else
			return 0;
	}

	int isEmpty(Node* node)
	{
		return (node == NULL);
	}
}