#include<stdio.h>
#include<cs50.h>

int main(void){

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int price = get_int("price: ");
while(price>=25){
price -= 25;
a++;

}

while(price>=10){
price -= 10;
b++;

}
while(price>=5){
price -= 5;
c++;

}

while(price>=1){
price -= 1;
d++;

}
printf("25*%i\n",a);
printf("10*%i\n",b);
printf("5*%i\n",c);
printf("1*%i\n",d);







}
