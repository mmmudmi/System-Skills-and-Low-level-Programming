#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double compute_det(int **a, int n) {
//base cases
  if(n==0){return (double) 1;}
  if(n==1){return (double) a[0][0];}

//recursive part
  else{
    double result = 0;
  //allocate
    int ** temp = malloc(sizeof(int*)*n); 
    for(int i = 0 ; i<n-1 ; i++){
      *(temp+i)=malloc(sizeof(int)*n);
    }
  //add elements in temp
    for(int top = 0; top<n ;top++){ 
      int t = a[0][top];
      for(int row = 1; row<n ;row++){ 
        int count = 0;
        //temp[row-1] = malloc(sizeof(int)*n); 
        for(int col = 0; col <n ; col++){
          if(col!=top){
            temp[row-1][count++] = a[row][col];
          }
        }
      } 
    //recursively call the function 
      if(top%2!=0){result -= (double) t * compute_det(temp,n-1);}
      else{result += (double) t * compute_det(temp,n-1);}
    } 
  //deallocate
    for(int i = 0 ; i<n-1 ; i++){
      free(*(temp+i));
    }
    free(temp);
    return result;
  }
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/

int main(void) {
  int n;
  scanf("%d",&n);
  int *aa = malloc(sizeof(int)*n*n);
  for(int i = 0;i<n*n;i++){
    scanf("%d",&(aa[i]));
  }
  int count = 0;
  int ** a;
  a = malloc(sizeof(int*)*n);
  for(int i = 0; i<n ; i++){
    *(a+i) = malloc(sizeof(int)*n);
    for(int j = 0; j<n ; j++){
      a[i][j] = aa[count++];
    }
  }
  printf("%f\n", compute_det(a,n));
  for(int i = 0; i<n ; i++){
    free(*(a+i));
  }
  free(a);
  free(aa);
}
