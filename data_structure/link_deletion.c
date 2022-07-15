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
struct node *delete_first(struct node *head) {
    struct node *ptr = head;
    head = head->next;
    free(ptr);
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

printf("deletion of first node");
    head = delete_first(head);
    link_traversal(head);

    return 0;
}