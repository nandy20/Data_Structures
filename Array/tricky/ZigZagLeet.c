#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	//code
	int num;
	char b[10000],s[100000];
	scanf("%s%d",s,&num);
    int i,n,j,k=1,l,c=0;
    n=strlen(s);
    i=0;
   while(i<num){
        j=i;
        while(j<n){
            if(i==0||i==num-1){
                b[c]=s[j];
                c++;
                j=j+(num-i-1)+(num-i-2)+1;
            }
            else{
               if(j==i){
                   b[c]=s[j];
                   c++;
                   j=j+(num-i-1)+(num-i-2)+1;
               }
               else{
                   b[c]=s[j];
                   c++;
                   j=j+k+1;
                   
                   if(j<n){
                       b[c]=s[j];
                       c++;
                       j=j+(num-i-1)+(num-i-2)+1;
                   }
                   else{
                       break;
                   }
               }
               if(j>=n){
                   break;
               }
            }
        }
         if(i==num-2){
            break;
        }
        if(i>0||i==num-1){
            k=k+2;
        }
        i++;
    }
   
    i=num-1;
    j=num-1;
    while(j<n){
         b[c]=s[j];
         c++;
          j=j+(num-1)+(num-2)+1;
    }
        
    printf("%s ",b);
	return 0;
}