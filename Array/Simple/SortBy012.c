#include<stdio.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    long long int i,j,o=0,tw=0,z=0,n;
	    scanf("%lld",&n);
	    for(i=0;i<n;i++){
	        scanf("%lld",&j);
	        if(j==0){
	            z++;
	        }
	        else if(j==1){
	            o++;
	        }
	        else{
	            tw++;
	        }
	    
		}
		//Jus count no of zero,one and two and print thm
	    while(z>0||tw>0||o>0){
	        if(z>0){
	            printf("0 ");
	            z--;
	        }
	        else if(o>0){
	            printf("1 ");
	            o--;
	        }
	        else{
	            printf("2 ");
	            tw--;
	        }
	    }
	    printf("\n");
	    t--;
	}
	return 0;
}