#include "StrList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node{
    struct _node *_next;
    const char* _data;}Node;

typedef struct _StrList{
    Node *_head;
    size_t _size;}StrList;

Node* Node_alloc(const char* data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->_data = data;
    p->_next = NULL;
    return p;}
void Node_free(Node* n){free(n);}
Node* Node_clone(Node* n){
    char* str = (char*)malloc(strlen(n->_data)*sizeof(char));
    strcpy(str, n->_data);
    Node* p = Node_alloc(str);
    return p;}
StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head = NULL;
    p->_size = 0;
    return p;}
void StrList_free(StrList* slist){
    if(slist==NULL) return;
    Node* p1 = slist->_head;
    Node* p2 = NULL;
    while(p1) {
        p2 = p1;
        p1=p1->_next;
        Node_free(p2);
    }
    free(slist);}
size_t StrList_size(const StrList* slist){return slist->_size;}
void StrList_insertLast(StrList* slist, const char* data){
    Node* p1 = slist->_head;
    while(p1->_next){
        p1 = p1->_next;
    }
    Node* n = Node_alloc(data);
    p1->_next = n;
    slist->_size++;}
void StrList_insertAt(StrList* slist, const char* data, int index){
    if(index>slist->_size || index<0){
        return;
    }
    slist->_size++;
    if(index == 0){
        Node* n = Node_alloc(data);
        n->_next = slist-> _head;
        slist-> _head = n;
        return;
    }
    Node* p1 = slist->_head;
    for(int i=0;i<index-1;i++){
        p1 = p1->_next;
    }
    Node* n = Node_alloc(data);
    n->_next = p1->_next;
    p1->_next = n;}
char* StrList_DataAt(const StrList* slist, int index){
    Node *p1= slist->_head;
    for(int i=0;i<index;i++){p1 = p1->_next;}


    char* ans = (char*)malloc(strlen(p1->_data)*sizeof(char));
    strcpy(ans, p1->_data);
    return ans;}
char* StrList_firstData(const StrList* slist){
    return StrList_DataAt(slist, 0);}
void StrList_print(const StrList* slist){
    if(slist->_size==0) return;
    Node* p1 = slist->_head;
    while(p1) {
        printf("%s", p1->_data);
    }}
void StrList_printAt(const StrList* slist,int index){
    char* str = StrList_DataAt(slist, index);
    printf("%s", str);}
int StrList_printLen(const StrList* slist){
    if(slist->_size == 0)return 0;
    Node* p1 = slist->_head;
    int sumChars = 0;
    while(p1){
        sumChars = sumChars + strlen(p1->_data);
    }
    return sumChars;}
int StrList_count(StrList* slist, const char* data){
    if(slist->_size == 0)return 0;
    Node* p1 = slist->_head;
    int count = 0;
    while(p1){
        if(strcmp(data, p1->_data) == 0){count++;}
        p1 = p1->_next;
    }
    return count;}
void StrList_remove(StrList* slist, const char* data){
    if(slist->_size == 0)return;
    Node* p1 = slist->_head;
    Node* p2 = NULL;
    while(p1->_next){
        if(strcmp(data, p1->_next->_data) == 0){
            p2 = p1->_next;
            p1->_next = p1->_next->_next;
            Node_free(p2);
            slist->_size--;
        }
        p1 = p1->_next;
    }}
void StrList_removeAt(StrList* slist, int index){
    if(index>slist->_size || index<0){
        return;
    }
    slist->_size--;
    if(index == 0){
        Node* n = slist->_head;
        slist->_head = slist->_head->_next;
        Node_free(n);
        return;
    }
    Node* p1 = slist->_head;
    for(int i=0;i<index-1;i++){
        p1 = p1->_next;
    }
    Node* n = p1->_next;
    n->_next = p1->_next->_next;
    Node_free(n);}
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->_size != StrList2->_size)return FALSE;
    const Node* p1= StrList1->_head;
    const Node* p2= StrList2->_head;

    while(p1){
        if(strcmp(p2->_data, p1->_data) != 0)return FALSE;
        p1 = p1->_next;
        p2 = p2->_next;
    }
    return TRUE;}
StrList* StrList_clone(const StrList* slist){
    Node* p1 = slist->_head;
    StrList* newList = StrList_alloc();
    newList->_head = Node_clone(p1);
    Node* p2 = newList->_head;
    newList->_size = slist->_size;

    while(p1){
        p2->_next = Node_clone(p1->_next);
        p1 = p1->_next;
        p2 = p2->_next;
    }
    return newList;}
void StrList_reverse( StrList* slist){
    Node* p1 = slist->_head;
    Node* p2 = p1->_next;
    Node* p3 = p2->_next;
    p1->_next = NULL;

    while(p2){
        p2->_next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->_next;
    }}
int StrList_isSorted(StrList* slist){
    Node* p1 = slist->_head;
    if(slist->_size==0)return TRUE;
    while(p1->_next){
        int condition = strcmp(p1->_data, p1->_next->_data);
        if(!condition)return FALSE;
    }
    return TRUE;}
void StrList_sort( StrList* slist){
    if (slist->_size < 2) {
        return;
    }

    int swapped;
    Node *current;
    Node *prev = NULL;
    do {
        swapped = FALSE;
        current = slist->_head;

        while (current->_next != prev) {
            if (strcmp(current->_data, current->_next->_data) > 0) {
                // Swap the data of the current node and the next node
                const char* temp = current->_data;
                current->_data = current->_next->_data;
                current->_next->_data = temp;

                swapped = TRUE;
            }
            current = current->_next;
        }
        prev = current;
    } while (swapped);}
