#include<stdio.h>
#include<cs50.h>
#include<string.h>


int main(void){

string player1 = get_string("player1:  ");
string player2 = get_string("player2:  ");
int length1 = strlen (player1);
int length2 = strlen (player2);

char player1a[length1 + 1];
char player2a[length2 + 1];

int i;
for(i = 0; i <= length1; i++)
{
player1a[i] = player1[i];
}

player1a[length1] = '\0';


for(i = 0; i <= length2; i++)
{
player2a[i] = player2[i];
}

player2a[length2] = '\0';







int values1[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int result1 = 0;
for(i = 0; i <= length1; i++){
if (player1a[i] > 64 && player1a[i] < 91){
    player1a[i] = values1[player1a[i] - 'A'];
result1 +=  player1a[i];

}else if(player1a[i] > 96 && player1a[i] < 123){

 player1a[i] = values1[player1a[i] - 'a'];
result1 +=  player1a[i];
}
else{

    result1 += 0;
}

}

int result2 = 0;
for(i = 0; i <= length2; i++){
if (player2a[i] > 64 && player2a[i] < 91){
    player2a[i] = values1[player2a[i] - 'A'];
result2 +=  player2a[i];

}else if(player2a[i] > 96 && player2a[i] < 123){

 player2a[i] = values1[player2a[i] - 'a'];
result2 +=  player2a[i];
}
else{

    result2 += 0;
}


}


if (result1 > result2){

    printf("player1 wins!\n");
}
else if(result1 < result2){

printf("player2 wins!\n");

}
else if (result1 == result2){

    printf("tie!\n");
}















}
