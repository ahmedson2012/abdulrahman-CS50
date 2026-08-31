



#include<stdio.h>
#include<cs50.h>

int main(void){

int rows = get_int("rows: ");

int r = rows;
int a = 0;
int h = rows;
h--;
for(int i = 1; i<=rows; i++){
     for(int p = 0; p<a;p++){

     printf(" ");

}
     for(int t = r--; t>0; t--){
printf("#");

}

printf(" ");

for(int p = 0; p<=h;p++){
printf("#");

}





printf("\n");

h--;

a++;
}


}























