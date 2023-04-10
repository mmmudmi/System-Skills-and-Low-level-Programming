/* Name: Pearploy Chaicharoensin
 * ID: 6381278
 * Collaborator : Kanladaporn Sirithatthamrong 6480952
 */


#include <stdio.h>
#include <stdlib.h>
#include "box.h"

/*
typedef struct {
    int *data;
    int size;
    int cap;
} Box;
*/

/*
Creates a new box with capacity of init_cap.
If the box b has already been allocated, this function does nothing.
*/
void createBox(Box **b, int init_cap) {
    if( *b == NULL){
        (*b) = malloc(sizeof(Box));
        (*b)->data = (int*) malloc(sizeof(int)*init_cap);
        (*b)->cap = init_cap;
        (*b)->size = 0 ;
    }
}

/*
Inserts an element into a given box. If the box is full ,you must fist increase
 its capacity by doubling the capacity with realloc and then add the element.
*/
void insert(Box *b, int elem) {
    // if (b == NULL) {
    //     createBox(&b, 1);
    //     b->size = 1;
    //     *(b->data) = elem;
    // }
    // if(b==NULL){
    //     createBox(&b,1);
    // }
    if(b->size == b->cap){
        b->cap *= 2;
        b->data = realloc(b->data,sizeof(int)*(b->cap));
    }
    int index = b->size;
    *(b->data+index) = elem;
    b->size ++;
}

/*
Removes all occurances of an element from a box. After removal, 
the elements in the box must be condensed i.e. no gap between any two elements. 
Also, this function must not change the capacity of the box.
*/

void removeAll(Box *b, int elem) {
    int* temp = malloc(sizeof(int)*b->cap);
    int count = 0;
    for(int i = 0; i<b->size ;i++){
        int cur = *(b->data+i);
        if(cur!=elem){
            *(temp+count) = *(b->data+i);
            count++;
        }
    }
    free(b->data); 
    b->data = temp;
    b->size = count;
}

/*
Prints out elements of a box, one element per line.
*/
void printBox(Box *b) {
    for(int i = 0; i < (b->size) ; i++){
        printf("%d\n",*(b->data+i));
    }
}

/*
Returns the mean of data in a box.
*/
double getMean(Box *b) {
    int sum = 0;
    for(int i = 0 ; i< b->size ; i++){
        sum += (int)(*(b->data+i));
    }
    return sum/b->size;
}

/*
Deallocates the box along with its data.
*/
void dealloc(Box **b) {
    free((*b)->data);
    free((*b));
}
/*
TEST: ./box < test.in
OUTPUT:
AVG = 4.00
box1 size = 10
box2 size = 1
box1 cap = 16
box2 cap = 2
-- b1
11
2
3
4
5
2
3
2
2
6
-- b2
2
--
-- b1 (after remove)
11
3
4
5
3
6
--
-- b2 (after remove)
--
*/
int main(int argc, char **argv)
{
    Box *b1 = NULL;
    Box *b2 = NULL;

    createBox(&b1, 1);
    createBox(&b2, 2);

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        insert(b1, tmp);
    }
    insert(b2, 2);

    printf("AVG = %0.2f\n",getMean(b1));
    printf("box1 size = %d\n",b1->size);
    printf("box2 size = %d\n",b2->size);
    printf("box1 cap = %d\n",b1->cap);
    printf("box2 cap = %d\n",b2->cap);

    printf("-- b1\n");
    printBox(b1);
    printf("-- b2\n");
    printBox(b2);
    printf("--\n");

    removeAll(b1, 2);
    printf("-- b1 (after remove)\n");
    printBox(b1);
    printf("--\n");
    removeAll(b2, 2);
    printf("-- b2 (after remove)\n");
    printBox(b2);
    printf("--\n");
    // Box *c = NULL;
    // insert(v,2);
    // printBox(v);

    dealloc(&b1);
    dealloc(&b2);
}
