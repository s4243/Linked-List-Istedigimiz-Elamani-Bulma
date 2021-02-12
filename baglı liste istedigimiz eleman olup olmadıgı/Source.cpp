#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 
//recursive fonksiyon
struct Node
{
	int key;
	struct Node* next;
};
void push(struct Node** head_ref, int new_key)//push basa eleman ekle
{
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	new_node->key = new_key;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
bool search(struct Node* head, int x)//istedigimiz ifadenin olup olmadıgını kontrol ediyoruz
{
	if (head == NULL)
		return false;

	if (head->key == x)
		return true;

	return search(head->next, x);
}
int main()
{
	struct Node* head = NULL;
	int x = 21;//bulmak istedigimiz ifade

	/* Use push() to construct below list
	 14->21->11->30->10  */
	push(&head, 10);
	push(&head, 30);
	push(&head, 11);
	push(&head, 21);
	push(&head, 14);

	search(head, 21) ? printf("Yes") : printf("No");
	return 0;
}