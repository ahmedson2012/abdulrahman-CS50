#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node* next;
}node;
node* list = NULL;
node *insert(){
    node *temp = malloc(sizeof(node));
    temp -> num = get_int("Enter number: ");
    temp -> next = NULL;
    node *traverse = list;
    node *pretraverse = list;
    if(traverse == NULL){
        temp -> next = list;
        list = temp;
    }else{
        while(true){
            if(traverse -> num > temp -> num){
                if(pretraverse == list){
                    temp -> next = list;
                    list = temp;
                    break;
                }
                pretraverse -> next = temp;
                temp -> next = traverse;
                break;
            }else{
                if(traverse -> next == NULL){
                traverse -> next = temp;
                break;
            }
                pretraverse = traverse;
                traverse = traverse -> next;
            }

        }
    }
    return temp;
}

void print_list(){
    node *traverse = list;
    if(traverse != NULL){
        do{
            printf("%i\n",traverse -> num);
            traverse = traverse -> next;

        }while(traverse != NULL);
    }
}
int main(void){
    // for(int i = 0; i < 4; i++){
    //     list = insert(i);
    // }
    node* n = malloc(sizeof(node));
    n -> num = get_int("number: ");
    n -> next = NULL;
    list = n;
    for(int i = 5; i >= 0; i--){
            insert();
    }
    print_list();
}
