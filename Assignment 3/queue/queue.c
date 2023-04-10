/* Name: Pearploy  Chaicharoensin
 * ID: 6381278
 * Collaborator : Kanladaporn Sirithatthamrong 6480952
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    if((*q)==NULL){
        (*q) = (Queue *) malloc(sizeof(Queue));
        (*q)->head = NULL;
        (*q)->tail = NULL;
    }
    Node *newN = malloc(sizeof(Node));
    newN->next = NULL;
    newN->data = malloc(sizeof(char)*strlen(word));
    strcpy(newN->data, word);
    
    //first value
    if((*q)->head == NULL){
        (*q)->head = newN;
        (*q)->tail = (*q)->head;
    }
    //add
    else{
        (*q)->tail->next=newN;
        (*q)->tail=newN;
    }
}

char *pop(Queue *q) {
    if(isEmpty(q)==1){return NULL;}
    else{
        char * ans = malloc(sizeof(char)*strlen(q->head->data));
        strcpy(ans,q->head->data);
        free(q->head->data);

        Node *temp = q->head->next;
        free(q->head);
        q->head = temp;
        return ans;
    }
}


int isEmpty(Queue *q) {
    if(q == NULL){return 1;}
    if (q->head == NULL) { return 1; }
    return 0;
}

void print(Queue *q) 
{
    if (isEmpty(q)) {
        printf("No items\n");
    }
    else {
        Node *temp = q->head;
        while(temp!=NULL){
            printf("%s\n", temp->data);
            temp = temp->next;
        }
        free(temp); //u
    }   
}

void delete(Queue **q) 
{
    while ((*q)->head != NULL) {
        Node *temp = (*q)->head->next;
        free((*q)->head->data);    
        free((*q)->head);
        (*q)->head = temp;
    }
    free(*q);
    (*q) = NULL;
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    //pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }

    char *item = pop(q);
    assert(item == NULL);

    //push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(&q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
