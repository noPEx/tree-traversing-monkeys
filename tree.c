#include <stdio.h>
#include <stdlib.h>

#define GREY 0
#define BLACK 1 //Discovered
typedef struct {

	struct tree_node* left_child ;
	struct tree_node* right_child ;
	int value ;
	int color ;

} tree_node ;

typedef struct {
	struct node* next ;
	tree_node* fruit;

} node ;
/* given the tail of the queue append a number */
/*
	parameters
		@tail_add_Ptr:
			it is the address of the head, head is itself a address :P
*/
void enqueue( node** tail_add_Ptr, tree_node* fruit ) {
	node* new = ( node* )malloc( sizeof( node ) ) ;
	new->fruit = fruit ;
	new->next = NULL ;
	(*tail_add_Ptr)->next = new ;
	*tail_add_Ptr = (*tail_add_Ptr)->next ;

}

/* dequeue the first element in the queue FIFO : first appended remove first */
void dequeue( node** head_add_Ptr ) {
	tree_node* head = (*head_add_Ptr)->fruit ;
	*head_add_Ptr = (*head_add_Ptr)->next ;
	return head ;
}

/* gets the color of  first element in the queue FIFO : first appended remove first */
void get_next_color( node** head_add_Ptr ) {
	if( head_add_Ptr ) {
		return head_add_Ptr->fruit->color ;
	}
	else{
		return NULL ;
	}
}

/* inserts a new tree_node */
tree_node* insert( tree_node* root, int value ) {
	if( !root ) {
		root = ( tree_node* )malloc( sizeof( tree_node ) ) ;
		root->value = value ;
		root->color = GREY ;
		root->left_child = ( tree_node* )NULL ;
		root->right_child = ( tree_node* )NULL ;
		return root ;
	}
	else {
		if( value < root->value ) {
			root->left_child = insert( root->left_child,value ) ;
			return root ;
		}
		else {
			root->right_child = insert( root->right_child,value ) ;
			return root ;
		}

	}

}

void insert_TREE_NODE( node** head, tree_node* tn ) {
	node* current = *head ;
	while( current ) {
		current = current->next ;
	}

	current = ( node* )malloc( sizeof( node ) ) ;
	current->fruit = tn ;
	current->next = NULL ;

}

/* prints the tree level by level */
/*             a
			b     c
*         d   e  f  g
*
*
*  the output is :
*              a
*            b   c
*          d e  f  g 
*
*/

tree_node* initialize_tree( int arr[], int size ) {
	tree_node* root = NULL ;
	int i ;
	for( i = 0 ; i < size ; i++ ) {
		root = insert( root,arr[i] ) ;
	}
	return root ;
}

/* prints an element from the linked list and adds children to queue */
void print_and_add( node** q_head,node* p_head ) {
	while( p_head ) {
		printf("%d->",p_head->value ) ;
		enqueue( 

	}
	printf("\n") ;
}
/* bfs traversal */
void bfs_recursive( node* q_head ) {

	node* p_head = NULL ; //head to start printing
	while( q_head ) {
		//pop element from the head until queue becomes empty and store them in a node
		tree_node* current = dequeue( &q_head ) ;	
		insert_TREE_NODE( &p_head,current ) ;

	}
	print_and_add( &q_head,p_head ) ;
}
void print_level_tree( tree_node* root ) {
	/* use queues : 
		pop node from queue
		put node's children's in a list
		print nodes'
	*/

	node* q_head = ( node* )malloc( sizeof( node ) );
	q_tail = q_head ;
	node* q_tail = NULL ;


	//enqueue the first element 
	bfs_recursive( q_head ) ;

}

int main( int argc,char** argv ) {

	int arr[] = { 1,4,2,4,5 } ;
	tree_node* root = initialize_tree( arr,5 ) ;

	print_level_tree( root ) ;



	return 0 ;
}
