#include<string.h>
#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0){
int n,i,j,k;
char str[1000][1000]; // Can store 20 strings, each of length 20

scanf("%d",&n); //how many string

//input each string
for(i=0;i<n;i++)
{
   scanf("%s",str[i]);
}

//display each string
char a[1000];
strcpy(a,str[0]);
/* frst find the string with smallest len becoz prefix is not gng to exceed tht length*/
for(i=1;i<n;i++)
{
    if(strlen(a)>strlen(str[i])){
         strcpy(a,str[i]);
    }
}

/* Compare each charac of smallest string with all the other strings
if the char doesnt match then remove tht char ffrom string becox tht
char is not part of prefix since it doesnt appear in the other strngs*/
for(i=0;i<n;i++){
    for(j=0;j<strlen(a);j++){
        if(a[j]!=str[i][j]){
            a[j]='\0';
        }
    }
}
if(a[0]=='\0'){
    printf("-1\n");
}
else{
printf("%s\n",a);
}
t--;
    } 
}