// contributor: K.Poon (Dsoop's TA)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Items{int value; char key;}map;
map alpha[26];

int main(){
	char alphaList[26] = "abcdefghijklmnopqrstuvwxyz";
	//initial
	for (int i = 0; i < 26 ;i++){
		alpha[i].key = alphaList[i];
		alpha[i].value = 0;
	}
	//printf("%d",kv[1].value);
	char words = getchar();
	int max =0;
	while(words!=EOF){
		if(isalpha(words) != 0){
			for(int i=0; i< 26; i++){
				if(alpha[i].key==tolower(words)){
					alpha[i].value++;
					if(alpha[i].value>max){max=alpha[i].value;}
				}
			}
		}
		words = getchar();
	}
	
	for(int row = max ; row > 0 ; row--){
		for(int col = 0 ; col < 26; col++){

			if(alpha[col].value==row){
				printf("*");
				alpha[col].value--;
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}


	printf("abcdefghijklmnopqrstuvwxyz\n");
	return 0;
	
}


//strcmp(items[i].key, key) == 0 compare 




