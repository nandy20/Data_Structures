#include<stdio.h>
int main()
{
	//code
	int t;
	scanf("%d",&t);
	while(t>0){
	    int i,j,a[1005][1005],checkr[100000],checkc[100000],n,m;
	    scanf("%d%d",&n,&m);
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            scanf("%d",&a[i][j]);
	        }
	    }
	   for(i=0;i<n;i++){
	       checkr[i]=0;
	    }
	   for(i=0;i<m;i++){
	       checkc[i]=0;
	   }
	   for(i=0;i<n;i++){
	       for(j=0;j<m;j++){
	           if(a[i][j]==1){
	               checkr[i]=1;
	               checkc[j]=1;
	           }     
	       }
	   }
	   /* use two arrays,one to track 1 in row and one array
	   to track 1 in col so if either row array r col array
	   contains 1 thn tht element output is 1 else 0*/
	   for(i=0;i<n;i++){
	       for(j=0;j<m;j++){
	           if(checkr[i]==1||checkc[j]==1){
	               
	               printf("1 ");
	           }
	           else{
	               printf("0 ");
	           }
	       }
	       printf("\n");
	   }
	    t--;
	}
	return 0;
}