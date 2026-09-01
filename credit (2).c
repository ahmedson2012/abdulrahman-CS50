#include<stdio.h>
#include<cs50.h>

int main(void){
long credit = get_long("credit: ");


int digits[16];
int digits1[8];
int digits2[8];

int l = 0;
long y = credit;
while (y > 0)
{
    y /= 10;
    l++;
}



if (l != 13&& l != 15&& l != 16)
{
    printf("INVALID\n");
    return 0;
}
for (int i = 0; i < l; i++)
{
    digits[i] = credit % 10;
    credit /= 10;
}


int h;
int p;
int count1;
int count2;

h = 1;
p = 0;

if (l % 2 == 0)
{
    count1 = l / 2;
    count2 = l / 2;
}
else
{
    count1 = l / 2;
    count2 = (l + 1) / 2;
}


for (int r = 0; r < count1; r++)
{
    digits1[r] = digits[h];
    h += 2;
}

for (int r = 0; r < count2; r++)
{
    digits2[r] = digits[p];
    p += 2;
}


for (int r = 0; r < count1; r++)
{
    digits1[r] *= 2;
}
int result1 = 0;
for (int r = 0; r < count1; r++)
{
    if (digits1[r] > 9)
    {
        result1 += digits1[r] / 10;
        result1 += digits1[r] % 10;
    }
    else
    {
        result1 += digits1[r];
    }
}



for (int o = 0; o < count2; o++)
{
    result1 += digits2[o];
}

int result8 = result1%10;



if(result8==0){

if(((digits[15]==4)&&(l==16))||((digits[12]==4) && (l==13))){printf("VISA\n");}





else if(digits[14]==3&&(digits[13]==4||digits[13]==7)&&(l==15)){   printf("AMEX\n");}
else if( digits[15]==5&&( digits[14]==1|| digits[14]==2|| digits[14]==3|| digits[14]==4|| digits[14]==5  )  &&  (l==16)){    printf("MASTERCARD\n");}

else{printf("INVALID\n");}
}
else{printf("INVALID\n");}
}
