/* Name: Pearploy Chaicharoensin
 * ID: 6381278
 */
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

void sort(Entry *in, int nL, void *comparator) {
    for(int i = 0; i<nL ; i++){
        for(int j = 0; j< nL-i-1; j++){
            int (*comparator)(Entry, Entry) = compare;
            if(comparator(in[j],in[j+1])>0){
                Entry temp = in[j+1];
                in[j+1] = in[j];
                in[j] = temp;
            }
        }
    }
}

int compare(Entry a, Entry b) {
    int aa = a.data;
    int bb = b.data;
    if(aa>bb){return 1;}
    else if(aa==bb){return 0;}
    else{return-1;}
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int size;
    scanf("%d",&size);
    Entry* a = malloc(sizeof(Entry)*size);
    for (int i=0; i<size; i++) {
        a[i].name = malloc(sizeof(char*));
        scanf("%d%s",&(a[i].data),a[i].name);
    }

    printf("Before\n");
    for(int i = 0 ; i<size ; i++){
        printf("%d ",a[i].data);
        printf("%s\n",a[i].name);
    }
    sort(a,size,compare);
    printf("After\n");
    for(int i = 0 ; i<size ; i++){
        int a1 = a[i].data;
        char* a2 = a[i].name;
        printf("%d ",a1);
        printf("%s\n",a2);
    }
    for(int i = 0 ; i<size ; i++){
    	free(a[i].name);
    }
    free(a);
    
    return 0;
}
