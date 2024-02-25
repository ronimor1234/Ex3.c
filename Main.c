#include <stdio.h>
#include "StrList.h"
#include <string.h>
#include <stdlib.h>

#define HELP "Enter the number to command:\n1-add string to list\n2-Add in index\n3-PrintList\n4-Print length\n5-Print string in index\n6-Print all strings length\n7-Check how many times a string repeats\n8-Delete by string\n9-Delete in index\n10-Reverse list\n11-Delete list\n12-Sort list\n13-Check if sorted\n0-Exit program\n"
#define WORD_SIZE_LIM 2048
//we know we should support unlimited string size but we have 3 more days to submit.
//we are stuck on this, no one could help us inluding the authers of this assignment.


char flush_buffer(){
    char c;while ((c = getchar()) != '\n' && c != EOF) {}
    return c;
}
// char* reciveLine(int * should_flush){
//     char* str_ans = (char*)malloc(2*sizeof(char));
//     str_ans[0] = '\0';
//     str_ans[1] = '\0';
//     char nextChar = '\0';
//     if(*should_flush){
//         nextChar = flush_buffer();
//         *sould_flush = 0;
//     }
//     else nextChar = getchar();
//     while(nextChar == '\n')nextChar = getchar();
//     while(nextChar != '\n'){
//         int len = strlen(str_ans);
//         str_ans = (char*)realloc(str_ans, len + 2*sizeof(char));
//         str_ans[len] = nextChar;
//         str_ans[len + 1] = '\0';
//         nextChar = getchar();
//     }
//     return str_ans;
// }

// char* readWord(){
//     printf("in readWord\n");
//     char* str_ans = (char*)malloc(WORD_SIZE_LIM * sizeof(char));
//     scanf("%s", str_ans);
//     int len = strlen(str_ans);
//     str_ans = (char*)realloc(str_ans, len + sizeof(char));
//     printf("readWord returned: %s\n", str_ans);
//     return str_ans;
// }



char* readWord(int* should_flush){
    char* str_ans = (char*)malloc(2*sizeof(char));
    str_ans[0] = '\0';
    str_ans[1] = '\0';
    char nextChar = '\0';
    if(*should_flush){
        nextChar = flush_buffer();
        *should_flush = 0;
    }
    else nextChar = getchar();
    while(nextChar == '\n')nextChar = getchar();
    while(nextChar != ' ' && nextChar != '\n'){
        int len = strlen(str_ans);
        str_ans = (char*)realloc(str_ans, len + 2*sizeof(char));
        str_ans[len] = nextChar;
        str_ans[len + 1] = '\0';
        nextChar = getchar();
    }
    return str_ans;
}

int main(){
    
    //reminder to check for memory leacks (add size)
    //it is known there are!!!!!!!!!!!!!!

    StrList* mySL = StrList_alloc();
    int first_flush = 1;
    //printf("%s", HELP);
    int stayProgram = 1;
    int command = -1;
    while(stayProgram){
        if(scanf("%d", &command)!=1)command = -1;
        switch (command) {
            case 0:
                stayProgram = 0;
                StrList_free(mySL);
                break;
            case 1: 
                int NumWords = 0;
                if(scanf("%d", &NumWords)!=1){printf("scan failed!\n");exit(1);}
                for(int i=0;i<NumWords;i++){
                    char* word = readWord(&first_flush);
                    StrList_insertLast(mySL, word);
                }
                break;
            case 2: 
                int index_to_insert = -1;
                if(scanf("%d", &index_to_insert)!=1){printf("scan failed!");exit(1);}
                char* word = readWord(&first_flush);
                StrList_insertAt(mySL, word, index_to_insert);
                break;
            case 3: 
                StrList_print(mySL);
                break;
            case 4:
                int ListSize = StrList_size(mySL);
                printf("%d\n", ListSize);
                break;
            case 5: 
                int index_to_print = -1;
                if(scanf("%d", &index_to_print)!=1){printf("scan failed!\n");exit(1);}
                StrList_printAt(mySL, index_to_print);
                break;
            case 6: 
                int num_chars = StrList_printLen(mySL);
                printf("%d\n", num_chars);
                break;
            case 7: 
                char* strToCount = readWord(&first_flush);
                int counter = StrList_count(mySL, strToCount);
                printf("%d\n", counter);
                break;
            case 8:
                char* strToDelete = readWord(&first_flush);
                StrList_remove(mySL, strToDelete);
                break;
            case 9: 
                int index_to_remove = -1;
                if(scanf("%d", &index_to_remove)!=1){printf("scan failed!");exit(1);}
                StrList_removeAt(mySL, index_to_remove);
                break;
            case 10: 
                StrList_reverse(mySL);
                break;
            case 11: 
                ListSize = StrList_size(mySL);
                for(int i=0;i<ListSize;i++){
                    StrList_removeAt(mySL, 0);
                }
                break;
            case 12: 
                StrList_sort(mySL);
                break;
            case 13:
                int sorted = StrList_isSorted(mySL);
                if(sorted)printf("true\n");
                else printf("false\n");
                break;
            default:
                printf("%s\nPlease consider this in your next attempt.\n", HELP);
                exit(1);
        }
    }

    return 0;
}