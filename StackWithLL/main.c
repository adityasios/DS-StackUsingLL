//
//  main.c
//  StackWithLL
//
//  Created by inncrewin on 21/12/23.
//

#include <stdio.h>
#include  <stdlib.h>


struct Node {
    int data;
    struct Node * next;
};
struct Node * top = NULL;

void displayStack(struct Node * );
void pushStack(struct Node * ,int);
int popStack(struct Node * );
int peekStack(struct Node * ,int);
int isEmpty(struct Node * );
int lengthStack(struct Node * );


int main(int argc, const char * argv[]) {
    pushStack(top, 2);
    pushStack(top, 4);
    pushStack(top, 6);
    pushStack(top, 8);
    
    
//    printf("Pop = %d\n", popStack(top));
//    printf("Pop = %d\n", popStack(top));
    
    displayStack(top);
    printf("peekStack = %d\n", peekStack(top,5));
    
    return 0;
}

void displayStack(struct Node * p){
    while (p) {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}

void pushStack(struct Node * p,int data) {
    struct Node * t =  (struct Node * )malloc(sizeof(struct Node));
    t->data = data;
    t->next = p;
    top = t;
}

int popStack(struct Node * p){
    int data = -1;
    //check if stack isEmpty
    if(isEmpty(p)){printf("Stack isEmpty\n");return data;}
    top = p->next;
    data = p->data;
    free(p);
    return data;
}


int peekStack(struct Node * p,int pos){
    int data = -1;
    //check if stack isEmpty
    if(isEmpty(p)){printf("Stack isEmpty\n");return data;}
    //check if pos is valid
    if(lengthStack(p) < pos || pos < 1){printf("position is invalid \n");return data;}
    
    for (int i = 1; i<pos; i++) {
        p = p->next;
    }
    return p->data;
    
}



int isEmpty(struct Node * p){
    return p ? 0:1;
}
int lengthStack(struct Node * p){
    int data = 0;
    while (p) {
        data++;
        p=p->next;
    }
    return  data;
}
