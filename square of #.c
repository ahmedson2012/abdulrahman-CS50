#include<stdio.h>
#include<cs50.h>

int main(void){


int count;


do{
count = get_int("count: ");

}while(count<1);
for(int t = 0; t < count; t++){
for(int i = 0; i < count; i++){
     printf("#");
}
printf("\n");
}
}
