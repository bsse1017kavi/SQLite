#include<stdio.h>
#include<math.h>
#include<string.h>

#define SMALLEST_INT64 (pow(2,63)-1)*(-1)

long int parseInt(char s[20])
{
	int flag = 0, flag1 = 0;
    char c;
    int i,digit;
    long int number = 0;
    
    //Handling null value
    if( s[0]=='\n' )
    {
		printf("%d\n", (int)s[0] );    
    	return 0;
    }
    
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

double parseDouble(char s[20])
{
	return 0;
}

void parse(char s[20])
{
	int isDouble = 0;
	int i, dotLoc=0;
	double num=0, r=0, l=0;
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			isDouble = 1;
			dotLoc = i;
		}
	}
	
	if(isDouble)
	{
			
	}
}

int main(void)
{
	char iVal[20];
	long int x;
	
	scanf("%s",iVal);
	
	//printf("%s\n",iVal);
	
	parse(iVal);
	
	x = parseInt(iVal);
	
	if(x<0)
	{
		x = x*(-1);
		
		//printf("%ld\n",x);
		
		if(x<=SMALLEST_INT64)
		{
			printf("Error: Number overflow\n");
			return -1;
		}
	}
	
	
	printf("Output: %ld\n",x);
}
