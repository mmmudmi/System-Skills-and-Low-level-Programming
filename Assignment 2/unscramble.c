#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Itemss{char word[51];char sortW[51];}dictionary;
dictionary jumb[500001];

typedef struct Itemsss{char word[51];char sortW[51];}dictionaryy;
dictionaryy dict[500001];

int compare(const void* a, const void* b){
	int input1 = *((char*)a);
	int input2 = *((char*)b); 
	if(input1 < input2) return -1;
	else if (input1 == input2) return 0;
	else return 1;
}

int main(int argc,char* argv[]){
    if(argc!=3){printf("./programeName firstFile.txt SecFile.txt");}
    FILE *jumblesF;
    char jumple_words[51];
    jumblesF = fopen(argv[2],"r");
    if(jumblesF==NULL){printf("Error");return 1;} //check file
    FILE *dictionaryF;
    char dict_words[51];
    dictionaryF = fopen(argv[1],"r");
    if(dictionaryF==NULL){printf("Error");return 1;} //check file
     //using qsort!
    int (*comp)(const void *a, const void *b);
    comp = compare;

    int countJ = 0;
    while(fgets(jumple_words,51,jumblesF)){
        jumple_words[strcspn(jumple_words, "\n")] = 0; //not include \n
        strcpy(jumb[countJ].word,jumple_words);
    //add sorted words
        strcpy(jumb[countJ].sortW,jumple_words);
        qsort(jumb[countJ].sortW, strlen(jumb[countJ].sortW), sizeof(char), comp);
        countJ++;
    }
    int countD = 0;
    while(fgets(dict_words,51,dictionaryF)){
        dict_words[strcspn(dict_words, "\n")] = 0; //not include \n
        strcpy(dict[countD].word,dict_words);
    //add sorted words
        strcpy(dict[countD].sortW,dict_words);
        qsort(dict[countD].sortW, strlen(dict[countD].sortW),sizeof(char), comp);
        countD++;
    }
    
    int c=0;
    for(int i = 0 ; i< countJ ; i++){
        printf("%s:",jumb[i].word);
        for(int j = 0 ; j<countD ; j++){
            if(strcmp(jumb[i].sortW,dict[j].sortW)==0){
                printf(" %s", dict[j].word);
                c++;
            }
        }
        if(c == 0){
            printf(" NO MATCHES");
        }
        c = 0;
        printf("\n");
    }
    fclose(dictionaryF);
    fclose(jumblesF);
    return 0;
}


