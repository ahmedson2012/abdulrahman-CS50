#include<stdio.h>
#include<cs50.h>

int main(void){
long credit = get_long("credit: ");


int digits[16];
int digits1[8];
int digits2[8];

int l = 0;
int y = credit;
while (y > 0){
y /= 10;
  l++;
}

if( l != 13 && l != 15 && l!= 16){
  printf("INVALID\n");
  return 0;
}
for (int i = 0; i < 16; i++)
{
    digits[i] = credit % 10;
    credit /= 10;
}

int result = 0;
int h = 1;
for (int r = 0; r <= 7; r++){


  digits1[r] = digits[h];
h+=2;

}
int p = 0;
for (int r = 0; r <= 7; r++){


  digits2[r] = digits[p];
p+=2;

}


for (int r = 0; r <= 7; r++){


  digits1[r] *= 2;


}
int result1 = 0;
for (int r = 0; r <= 7; r++){
if (digits1[r] > 9){

result1+=digits1[r]/10;
result1+=digits1[r]%10;
}
else{

result1+=digits1[r];
}

}

int o = 0;

for(o=0;o<=7;o++){

result1+=digits2[o];

}

int result8 = result1%10;

if(result8==0){

if(digits[15]==4){printf("VISA");}





else if(digits[14]==3&&(digits[13]==4||digits[13]==7)){printf("AMEX");}
else if(digits[15]==5&&(digits[14]==1||digits[14]==2||digits[14]==3||digits[14]==4||digits[14]==55)){printf("AMEX");}












}
else{printf("INVALID");}
}
