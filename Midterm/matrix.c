#include<stdio.h>
#include<stdlib.h>
#define DEBUG 1

/*  input1: X*Y              input2: Y*Z               output: X*Z
    [a11 , a12]           [b11 , b12 , b13]            [. , . , .]
    [a21 , a22]           [b21 , b22 , b23]            [. , . , .]
    [a31 , a33]                                        [. , . , .]
*/
int ** matrixMultiply(int **input1, int **input2, int sizeX, int sizeY, int sizeZ){
//create a matrix 
    //row
    int **output = malloc(sizeof(int*) *sizeX); //output row = sizeX
    //column
    for(int i = 0; i<sizeX;i++){  //output col = sizeZ
        *(output+i) = malloc(sizeof(int) *sizeZ);
    }
//insert the numbers
int count = 0;
for(int row=0 ; row< sizeX ; row++ ){
    for(int col = 0 ; col < sizeZ ; col++){
        for(int v = 0 ; v < sizeY; v++){
            int f = (int)(*(*(input1+row)+v));
            int s = (int)(*(*(input2+v)+col));
            *(*(output+row)+col) += f*s ;
        }
    }
}
return output;
}
int main(){
    int **a;
	int **b;
	int i,j;
	int sizeX = 4;
	int sizeZ = 3;
	int sizeY = 3;
	a = malloc(sizeof(int*) * sizeX);
	b = malloc(sizeof(int*) * sizeZ);
	for(i=0;i<sizeX;i++){
		*(a+i) = malloc(sizeof(int)*sizeY);
		*(b+i) = malloc(sizeof(int)*sizeY);
	}
	//if(DEBUG) printf("%p, %p, %p, %p, %p\n", a, *a, (*a)+1, *(a+1), *(a+1)+1);
	//if(DEBUG) printf("size of int is %ld, size of pointer is %ld\n", sizeof(int), sizeof(int*));
    int inputA[] = {1,0,1,
                    2,1,1,
                    0,1,1,
                    1,1,2};
    int inputB[] = {1,2,1,
                    2,3,1,
                    4,2,2}; 
    printf("a = {\n");
    int countA = 0 ;
	for(i = 0;i<sizeX;i++)
	{
		for(j=0;j<sizeY;j++)
		{
			*(*(a+i)+j) = inputA[countA++];
			printf("%d, ", *(*(a+i)+j));
		}
		printf("\n");
	}
	printf("}\n");
    int countB = 0 ;
	printf("b = {\n");
	for(int i = 0;i<sizeY;i++)
	{
		for(int j=0;j<sizeZ;j++)
		{
			*(*(b+i)+j) = inputB[countB++];
			printf("%d, ", *(*(b+i)+j));
		}
		printf("\n");
	}
	printf("}\n");

    int **c ;
	c = matrixMultiply(a,b,4,3,3);

	printf("c = {\n");
	for(i = 0;i<sizeX;i++)
	{
		for(j=0;j<sizeY;j++)
			printf("%d, ", *(*(c+i)+j));
			printf("\n");
	}

	for(i=0;i<sizeX;i++)
	{
		free(*(a+i));
		free(*(b+i));
		free(*(c+i));
	}
	free(a);
	free(b);
	free(c);

    return 0;
}