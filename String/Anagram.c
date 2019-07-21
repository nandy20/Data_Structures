#include<stdio.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    char a[100000],b[100000];
	    int i,j,n,k,c=0;
	    scanf("%s%s",a,b);
	    /* Compare each char from a with b, if thy r same make char in b
	     as 1 and break... Incase no matching char is found for a with 
	     b thn it is not an anagram.... Repeat this for all the chars of a*/
	    if(strlen(a)!=strlen(b)){
	        printf("NO\n");
	    }
	    else{
	        n=strlen(a);
	        for(i=0;i<n;i++){
	            k=0;
	            for(j=0;j<n;j++){
	               
	                if(a[i]==b[j]){
	                    b[j]='1';
	                    
	                    k=1;
	                    break;
	                }
	            }
	            if(k==0){
	               
	                printf("NO\n");
	                c=1;
	                break;
	            }
	        }
	         if(c==0){
	        printf("YES\n");
	        }
	    }
	   
	    t--;
	}
	return 0;
}