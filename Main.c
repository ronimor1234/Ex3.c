#include <stdio.h>
#include "StrList.h"
#include <string.h>

int main(){


    //reminder to check for memory leacks
    //it is known there are!!!!!!!!!!!!!!



    char isA='\0';
    while(isA!='A'){
        scanf("%c", &isA);
    }
    char nextChar = '\0';
    char str[64] = {'\0'};
;
    StrList* myList = StrList_alloc();
    int current = 0;
    while(nextChar!='\n'){
        scanf("%c", &nextChar);
        if(nextChar!=' '){
            str[current]= nextChar;
            current++;
        }
        else{
            int len = strlen(str);
            char* full_str = (char*)malloc(sizeof(char)*len);
            strcpy(full_str, str);
            StrList_insertLast(myList, full_str);
            full_str = NULL;
            current = 0;
            for(int i;i<len+2;i++){
                str[i] = '\0';
            }
        }
        
    }
    







    printf("its working! frankenstine is alive!!!!!!!");
    return 0;
}