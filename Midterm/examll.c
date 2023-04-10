#include<stdio.h>
#include<stdlib.h>
struct my_node{
  int data;
  struct my_node * next;
};
typedef struct my_node Node;
Node * first; // point to the first element in my linked list
void deleteAt(int index)
{
  Node * temp;
  int count = 0;
  if(!first) return;
  else if(!index)
  {
    temp = first;
    first = temp->next;
    free(temp);
} else {
    for(temp = first; count < index-1 && temp->next != NULL ; temp = temp->next)
    count++;
    Node * temp2 = temp->next;
    if(!temp->next) return;
    temp->next = temp->next->next;
    free(temp2); // fixed cus not using temp2 we need to free(temp2) but not free(temp)
  }
}
void print()
{
  Node * current;
  for(current = first; current!=NULL; current = current->next)
  {
    printf("%d, ", current->data);
  }
}
void insertAt(int index,int data)
{
  Node * temp;
  int count = 1; 
  if(!(first) || index == 0) //if(first==NULL || index == 0)
  {
    temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = first;
    first = temp;
return; }
  for(temp = first; count < index && temp->next != NULL; temp = temp->next)
    count++;
  Node * temp2;
  temp2 = malloc(sizeof(Node));
  temp2->data = data;
  temp2->next = temp->next; 
  temp->next = temp2;
}
int getSize(Node * list)
{
  int count = 0;
  Node * current;
  for(current = first; current!=NULL; current = current->next)
  {
count++; }
  return count;
}

//just add
int* toArray(){
  int size = getSize(first);
  Node * current;
  current = first;
  int* ar = malloc(sizeof(int)*size);
  for(int i = 0 ; i < size ; i++ ){
    *(ar+i) = current->data;
    current = current->next;
  }
  return ar;
}
void insert(int data){
  int index = 0;
  Node * current;
  for(current=first ; current!=NULL ; current = current->next){
    if(current->data > data){break;}
    else{index++;}
  }
  insertAt(index,data);
}

//sorted from small->large
//recreate the current link list from the new input 
void arrayToSortedList(int * input, int newsize){ 
  int size = getSize(first);
  for(int i = 0 ; i<size ; i++){
    deleteAt(0);
  }
  for(int j = 0 ; j<newsize ; j++){
    insert(*(input+j));
  }
}

int main(int argc, char* argv[])
{
	insertAt(0, 1);   	// {1}
	insertAt(1, 4);  	// {1,4}
	insertAt(2, 5);	// {1,4,5}
	insertAt(3, 3);	// {1,4,5,3}
  insertAt(4, 10);	// {1,4,5,3,10}
  insertAt(5, 6);	// {1,4,5,3,10,6}

int * b = malloc(sizeof(int)*3);
*(b) =1;
*(b+1) =2;
*(b+2) =7;

	print();
  printf("\nArray : ");
  int *a;
  for(int i = 0; i< getSize(first) ; i++){
    a = toArray();
    printf("%d ",*(a+i));
  }
  printf("\n");

  insert(7);
  print(); printf("Size of linkedlist is %d\n",getSize(first));
  printf("\n");
  arrayToSortedList(b,3);
  print(); printf("Size of sorted linkedlist is %d\n",getSize(first));
	// deleteAt(1);		// {5, 10}
	// print();
	// printf("Size of linkedlist is %d\n",getSize(first));
	// deleteAt(0);		// {10}
	// print();
	// printf("Size of linkedlist is %d\n",getSize(first));
	// deleteAt(1000);		// Do nothing
	// print();
	// printf("Size of linkedlist is %d\n",getSize(first));
	// deleteAt(0);		// Empty
	// print();
	// printf("Size of linkedlist is %d\n",getSize(first));
  free(a);
  free(b);
	return 0;
}

