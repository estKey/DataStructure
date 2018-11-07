//SingleLinkedList
#include "SingleLinkedList.hpp"
// 
//

namespace sll {

	int sllUI()
	{
		LinkedList *list = initList();
		printf("Singlely Linked List Implementation\n");
		printf("Please choose the commands below\n");
		printf("Insertion:\t[1]: Insert Node(s) in Front\t[2]: Insert Node(s) in End\n");
		printf("Deletion:\t[3]: Delete Node(s) in Front\t[4]: Delete Node(s) in End\n");
		printf("Search:\t\t[5]: Search Node(s)\t\t[6]: Extract Node(s)\n");
		addFront(5, list);
		addFront(3, list);
		addFront(2, list);
		addFront(0, list);
		addFront(7, list);
		addFront(5, list);
		addFront(11, list);
		addFront(0, list);
		addFront(23, list);
		addFront(9, list);
		addFront(4, list);
		printf("Original List: ");
		printList(list);

		int pos = search(7, list);
		printf("value: 7 index :%d\n", pos);
		//printf("Sort List\n");
		//sortList(list);
		printf("Updated List: ");
		printList(list);

		Node * link = extract(3, list);
		printExtract(link);
		printf("Updated List: ");
		printList(list);
		printf("\n");

		link = extract(1, list);
		printExtract(link);
		printf("Updated List: ");
		printList(list);
		printf("\n");
		printf("Remove link from front\n");
		removeFront(list);
		printf("Updated List: ");
		printList(list);
		printf("Remove link from end\n");
		removeEnd(list);
		printf("Updated List: ");
		printList(list);
		printf("Remove an element from end\n");
		removeEnd(list);
		printf("Updated List: ");
		printList(list);
		printf("ReverseList by Recursion\n");
		list->head = reverseRecursion(list->head);
		printf("Updated List: ");
		printList(list);
		printf("ReverseList by Iteration\n");
		list->head = reverseIteration(list->head);
		printf("Updated List: ");
		printList(list);
		printf("Destroy List\n");
		destroy(list);
		printf("Updated List (should be empty): ");
		printList(list);
		printf("\n");
		return EXIT_SUCCESS;
	}

	LinkedList *initList()
		// Initialize LinkedList structure
	{
		LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
		list->size = 0;
		list->head = NULL;
		return list;
	}

	Node *createNode(int v, Node *nxt)
		// Create new Node and initialize its value and next pointer
	{
		Node *pNode = (Node *)malloc(sizeof(Node));
		if (pNode != NULL) {
			pNode->value = v;
			pNode->next = nxt;
		}
		return pNode;
	}

	int isEmpty(LinkedList *l)
		// Check if LinkedList is empty. It is empty if head pointer is NULL
	{
		return (l->head == NULL);
	}

	void addFront(int v, LinkedList *l)
		// Add new Node to front of linked list. Create and initialize new Node
		// structure with value and current head-of-list pointer.  Make head-of-list
		// point to new node
	{
		Node* newNode = createNode(v, l->head);
		printf("Adding %d to front of list\n", v);
		l->head = newNode;
		l->size++;
	}

	void addEnd(int v, LinkedList *l)
		// Add new Node to end of linked list
	{
		Node* newNode = createNode(v, NULL);
		printf("Adding %d to end of list\n", v);
		// start by increasing size of linked list
		l->size++;
		// Now comes the fun part - have to find current last Node, so it
		// can be made to point to the new node
		if (isEmpty(l)) {
			// LinkedList currently empty - new node becomes first in list
			l->head = newNode;
		}
		else {
			// Not empty - have to find last Node in current list and make
			// it point to new node.
			Node* ptr = l->head;
			// Traverse list until node found that doesn't point to a next one
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			// ptr points to a Node with no next Node; make this Node point to
			// new one
			ptr->next = newNode;
		}
		// Our work is done.
	}

	void addEndt(LinkedList* l, Node *tail, int x)
	{
		Node* newNode = createNode(x, NULL);
		printf("Adding %d to end of list\n", x);
		if (isEmpty(l)) {
			l->head = newNode;
			tail = newNode;
			l->size++;
		}
		else {
			if (tail != NULL) {
				if (tail->next != NULL)
				{
					while (tail->next->next != NULL)
						tail = tail->next;
					if (tail->next->next == NULL) {
						tail->next->next = newNode;
						tail = tail->next;
					}
					l->size++;
				}
				else {
					tail = l->head;
					while (tail->next->next != NULL)
						tail = tail->next;
					tail->next = newNode;
					tail = tail->next;
					l->size++;
				}
			}
		}
	}

	void removeFront(LinkedList* l)
		// Remove first Node from list
	{
		printf("Remove item at front of list\n");
		if (!isEmpty(l)) {
			// List is not empty, so there is a first Node to delete.
			Node *ptr = l->head;		// point to first node
										// Note that list will be one shorter
			l->size--;
			// head of list is now element after first
			l->head = l->head->next;
			// discard node we no longer need
			free(ptr);
		}
	}

	void removeEnd(LinkedList* l)
		// Remove last Node from list
	{
		printf("Remove item at end of list\n");
		// First determine if any work to do
		if (!isEmpty(l)) {
			// Special case - if there is only one Node
			if (l->size == 1) {
				removeFront(l);
			}
			else {
				// More than 1. Note how this code requires that a Node
				// be found that points to a last Node (one with a NULL
				// next pointer, and that doesn't work for the list with
				// only 1 Node.  Fun exercise for the student - think about 
				// how to redesign data and code so that all cases can
				// be handled with one piece of code.
				Node* ptr = l->head;

				// As long as the Node we're pointing to isn't the end of
				// the list, move to next Node
				while (ptr->next->next) {
					ptr = ptr->next;
				}
				Node* delPtr = ptr->next;
				ptr->next = NULL;
				free(delPtr);
				l->size--;
			}
		}
	}

	void removeEndt(LinkedList* l, Node *tail)
	{
		printf("Remove item at end of list\n");
		if (!isEmpty(l)) {
			if (l->size == 1) {
				removeFront(l);
				tail = NULL;
				l->size--;
			}
		}
		else {
			if (tail != NULL) {

				if (tail->next != NULL) {
					while (tail->next->next != NULL)
						tail = tail->next;
					if (tail->next->next == NULL) {
						Node *delNode = tail->next;
						tail->next = NULL;
						free(delNode);
						l->size--;
					}
				}
			}
		}
	}

	/**
	* Extract Element from list with value v and return it
	* return NULL if no link exists with value v
	*/
	Node *extract(int v, LinkedList *list)
	{
		Node *node1 = NULL,
			*node2 = NULL, *resNode = NULL;

		/* check if list is NULL */
		if (list != NULL)
		{
			if (list->head != NULL) /* something in list */
			{
				printf("Extract first node with value %d from list\n", v);
				/* head contains value v */
				if (list->head->value == v)
				{
					resNode = list->head;
					list->head = list->head->next;
					list->size--;
				}
				/* head doesn't contain value v. Must traverse list to find it */
				else
				{
					node1 = list->head;
					node2 = node1->next;
					/* Move link1 and link2 until you find link with value v or reach end of list */
					while ((node2->next != NULL) && (node2->value != v))
					{
						node1 = node2;
						node2 = node2->next;
					}
					/* update resLink accordingly */
					if (node2->value == v) {
						resNode = node2;
						node1->next = node1->next->next;
						list->size--;
					}
					else return NULL;
				}
			}
		}
		return resNode;
	}

	void printExtract(Node *node)
	{
		if(node != NULL)
			printf("Value of extracted node: %d\n", node->value);
		else if (node == NULL)
			printf("No node with value 1 in the list\n");
		else
			printf("Something is wrong.  Check your code\n");
		free(node);
	}

	void insertFront(LinkedList *l)
	{
		int v;
		printf("Inserting value in the front, enter -1 to exit");
		while (1)
		{
			scanf("%d", &v);
			if (v == -1) break;
			addFront(v, l);
		}
	}

	void insertEnd(LinkedList *l)
	{
		int v;
		printf("Inserting value in the front, enter -1 to exit");
		while (1)
		{
			scanf("%d", &v);
			if (v == -1) break;
			addEnd(v, l);
		}
	}

	void insert(LinkedList *l, Node *node, int pos)
	{
		printf("Insert Node into postion %d of List\n", pos);
		if (pos <= (l->size))
		{
			Node *ptr = l->head;
			for (int i = 0; (ptr->next->next != NULL) && (i < pos); i++)
				ptr = ptr->next;
			node->next = ptr->next;
			ptr->next = node;
		}
	}

	int search(int v, LinkedList *list)
	{
		Node *ptr = list->head;
		int index = 0;
		while ((ptr->value != v) && (ptr != NULL)) {
			ptr = ptr->next;
			index++;
		}
		return index;
	}

	void destroy(LinkedList* l)
		// Delete entire linked list - basically by repeatedly deleting first Node
	{
		while (!isEmpty(l)) {
			removeFront(l);
		}
	}

	void removeValue(LinkedList* l, int x)
	{
		printf("Find first %d in the list and remove it\n", x);
		if (l != NULL) {
			if (l->head != NULL) {
				if (l->head->value == x) {
					Node* ptr = l->head, *delPtr = ptr;
					l->head = ptr->next;
					free(delPtr);
					l->size--;
				}
				else {
					if (l->head->next != NULL)
					{
						Node *node1 = l->head, *node2 = node1->next;
						while ((node2->next != NULL) && (node2->value != x)) {
							node1 = node2;
							node2 = node2->next;
						}
						if (node2->value == x) {
							Node *delPtr = node2;
							node1->next = node1->next->next;
							free(delPtr);
							l->size--;
						}
					}
				}
			}
		}
	}

	void decay(LinkedList* l)
		// Find smallest value in linked list and subtract that value from each value
	{
		printf("Decay: Subtract smallest value from all values in list\n");
		if (l != NULL) {
			if (l->head != NULL) {
				int x = l->head->value;
				if (l->head->next == NULL) {
					l->head->value -= x;
				}
				else {
					Node *node = l->head;
					while (node != NULL) {
						x = ((node->value) < x) ? (node->value) : x;
						node = node->next;
					}
					node = l->head;
					while (node != NULL) {
						node->value -= x;
						node = node->next;
					}
				}
			}
		}
	}

	Node *reverseRecursion(Node *head)
		// Recursion way to reverse List
	{
		if (head == NULL || head->next == NULL)
			return head;
		Node *newHead = reverseRecursion(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}

	Node *reverseIteration(Node *head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		Node *ptr = head, *newHead = NULL;
		while (ptr != NULL)
		{
			Node *tmp = ptr->next; 
			ptr->next = newHead;
			ptr = tmp;
		}
		return newHead;
	}

	void printList(LinkedList *l)
	{
		Node* ptr = l->head;
		printf("(");
		if (!ptr) {
			printf("<EMPTY>");
		}
		else {
			while (ptr->next) {
				printf("%d --> ", ptr->value);
				ptr = ptr->next;
			}
			printf("%d", ptr->value);
		}
		printf(") [%d]\n", l->size);
	}

}
