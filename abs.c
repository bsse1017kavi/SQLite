#include<stdio.h>
#include<math.h>
#include<string.h>

#define SMALLEST_INT64 (pow(2,63)-1)*(-1)

long int parseINT(char s[20])
{
	int flag = 0, flag1 = 0;
    char c;
    int i,digit;
    long int number = 0;
    
    if(s[0]=='-')
    {
    	flag = 1;
    }
    
    for(i=0;i<strlen(s);i++)
    {
    	if(flag==1)
    	{
    		flag = 0;
    		flag1 = 1;
    		continue;
    	}
    	
    	c = s[i];
    	if(c>='0' && c<='9') //to confirm it's a digit
    	{
    		digit = c - '0';
    		number = number*10 + digit;
    	}
    }
    
    if(flag1==1) number = number*(-1);
    
    return number;
}

double parseDefult(char s[20])
{
	int flag = 0, flag1 = 0 , pointFlag = 0 , k = 10;
	char c;
	int i,digit;
	long double number = 0;
	double pointNumber = 0.0 ;
    
    	if(s[0]=='-')
    	{
    		flag = 1;
    	}

	else if(s[0] >= 48 && s[0] <= 57){ // digit 0-9
		flag = 2 ;
	}

	else flag = 3 ;
    
    for(i=0;i<strlen(s) && flag!= 3 ;i++)
    {
		if(flag==1)
		{
			flag = 0;
			flag1 = 1;
			continue;
		}
		
		c = s[i];
		if(c>='0' && c<='9' && pointFlag == 0) //to parse digits
		{
			digit = c - '0';
			number = number*10 + digit;
		}

		if(s[i] == '.'){

			if(pointFlag==1) break ;
			pointFlag = 1 ;
			i++ ;
			c = s[i] ;
		}

		if(c>='0' && c<='9' && pointFlag == 1) //to confirm it's a digit
			{
				digit = c - '0';
				pointNumber = pointNumber + digit*1.0/k;
				k = k * 10 ;
			}

		if( s[i+1] < 48 && s[i+1] > 57 && s[i+1]!=46){
			break ;
		}
    }

	if(pointFlag==1){
		//printf("%f\n",pointNumber);
		number = number + pointNumber ;	
	}
    
    if(flag1==1) number = number*(-1);
    
    return number;
}

int type(char s[20]){

	int flag = -1 ;
	if(s[0]=='-')
    	{
    		flag = 1 ;
    	}

	for(int i=0 ; i<strlen(s) ; i++){

		if(flag==1) {
			flag = 0 ;
			continue ;
		}
		
		//indicates character is non digit
		if( s[i] < 48 || s[i] > 57 ){
			return 0 ;
		}
	}

	return 1 ;

}

int main(void)
{
	char iVal[20];
 
	
	
	scanf("%s",iVal);
	
	//printf("%d\n",type(iVal));

	
	if(type(iVal) == 1){
		long int x = parseINT(iVal);
		
		if(x<0)
		{
			x = x*(-1);	
			//printf("%ld\n",x);
		}
		
		printf("Output: %ld\n",x);
	}

	else if(type(iVal) == 0){
		double x = parseDefult(iVal);
		
		if(x<0)
		{
			x = x*(-1);	
			
			if(x<=SMALLEST_INT64)
			{
				printf("Error: Number overflow\n");
				return -1;
			}
		}
		
		printf("Output: %f\n",x);
	}

}
