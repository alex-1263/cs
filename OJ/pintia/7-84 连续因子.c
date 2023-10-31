#include<stdio.h>
#include<math.h>
int main(){
   int N;
   scanf("%d",&N);
    int i;
    int count =0;
    int first =0;//first factor
    int totalCount =0;// record the total of longest continuous factor 
   for(i=2; i<=sqrt(N);i++){//loop
        int j;
        count =0;
        int t=N;
        for(j=i; t%j==0;j++){//check continuous factor
            t = t/j; 
            count++ ;
        }    //if not continuous again then quit loop
        
        
        if (count>totalCount){//if got continuos factor,then let the i be the first factor
            totalCount = count;
            first =i;
        }
    }  
    if(first ==0 ){//prime number
        printf("%d\n%d",1,N);
    }else{
        printf("%d\n",totalCount);
        printf("%d",first);
        for(i=1;i<totalCount;i++){
            printf("*%d",first+i);
        }    
    }    
    return 0;
}

