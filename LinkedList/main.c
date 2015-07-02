//
//  main.c
//  LinkedList
//
//  Created by Auston Salvana on 7/1/15.
//  Copyright (c) 2015 ASolo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printNode(Node *header){
    while (header != NULL) {
        printf("%d\n",header->data);
        header = header->next;
    }
}

void removeNode(Node *header, Node *findDelete) {
    
    
    while (header->next != NULL) {
        if (findDelete == header->next) {
            printf("found the node to delete: %d\n", header->next->data);
            
            free(header->next);
            header->next = header->next->next;
            
            break;
            
        } else {
            header = header->next;
        }
    }
}

Node *nodePointer(int data, Node *next) {
    Node *node = malloc(sizeof(Node));
    
    node->data = data;
    node->next = next;
    return node;
}

void delete(Node *header, Node *del){
    if (header == del) {
        
        
        while (header != NULL) {
            Node *temp = header;
            header = header->next;
            free(temp);
        }
        header = NULL;
        }
    }
Node *searchPointer (Node *header, int lookFor){
    while (header != NULL) {
        
        if (header->data == lookFor) {
            printf("Found it!: %d", header->data);
            return header;
        }
        else{
            printf("%d\n", header->data);
            header = header->next;
        }
    }
    return NULL;
}

void add(Node *header, Node *insert){
    while (header != NULL) {
        if (header->next == NULL) {
            header->next = insert;
            return;
        }
        else{
            header = header->next;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    Node *n3 = nodePointer(3, NULL);
    
    Node *n2 = nodePointer(2, n3);
    
    Node *n1 = nodePointer(1, n2);
    
    printNode(n1);
    add(n1,nodePointer(4, NULL));
    printNode(n1);
    
    //on second printNode n1 has different number in address. ask about it tomorrow.
    //!! Memory at address was marked as free but pointer is still accessible may or may not caus crash. But is essential considered deleted!.
    
    return 0;
}
