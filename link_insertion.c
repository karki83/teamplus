#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void link_traversal(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("\n%d", ptr->data);
		ptr = ptr->next;
	}
}

struct node *insert_first(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
};
struct node *insert_index(struct node *head, int data, int index)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *p = head;
	int i = 0;
	while (i != index - 1)
	{
		p = p->next;
		i++;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;
	return head;
};
struct node *insert_end(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *p = head;

	ptr->data = data;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = ptr;
	ptr->next = NULL;

	return head;
};

struct node *insert_after_node(struct node *head, struct node *prevNode, int data)
{

	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = prevNode->next;
	prevNode->next = ptr;

	return head;
};

int main()
{
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;

	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	fourth = (struct node *)malloc(sizeof(struct node));

	scanf("%d", &head->data);
	scanf("%d", &second->data);
	scanf("%d", &third->data);
	scanf("%d", &fourth->data);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	link_traversal(head);
	// head = insert_first(head, 23);

	printf(" adding at first node");
	link_traversal(head);

	// head = insert_index(head, 34, 2);
	printf(" adding at index node");
	link_traversal(head);

	// head = insert_end(head, 34);
	//    link_traversal(head);

	head = insert_after_node(head, second, 34);
	link_traversal(head);
	return 0;
}
