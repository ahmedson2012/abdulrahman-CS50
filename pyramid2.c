



#include<stdio.h>
#include<cs50.h>

int main(void){

int rows = get_int("rows: ");
int r = rows;
int h = 0;

for(int i = 1; i<=rows; i++){

for(int t = r--; t>0; t--){

     printf(" ");

}
for(int p = 0; p<=h;p++){
printf("#");

}
  printf(" ");

for(int p = 0; p<=h;p++){
printf("#");

}

printf("\n");
h++;



}


}























