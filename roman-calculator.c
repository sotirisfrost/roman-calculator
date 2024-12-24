#include <stdio.h>

int convert();
void symbol(int, int);
void roman(int);

int main(){
	int num1,num2;
	printf("Enter the first number:\n");
	scanf("%d",&num1);
	num1=convert();
	printf("%d\n",num1);
	printf("Enter the second number:\n");
	scanf("%d",&num2);
	num2=convert();
	printf("%d\n",num2);
	printf("Enter the desired arithmetic operation:\n");
	symbol(num1,num2);
return 0;
}

int convert(){
	int roman,I=0,V=0,X=0,L=0,C=0,D=0,M=0,num,i=0;
	while((roman=getchar())!='\n'){
		switch(roman){
			case 'M':
				M+=1000;
				if(D!=0 || C!=0 || L!=0 || X!=0 || V!=0 || I!=0)
					i++;
				break;
			case 'D':
				D+=500;
				if(C!=0 || L!=0 || X!=0 || V!=0 || I!=0)
					i++;
				break;
			case 'C':
				C+=100;
				if(L!=0 || X!=0 || V!=0 || I!=0)
					i++;
				break;
			case 'L':
				L+=50;
				if(X!=0 || V!=0 || I!=0)
					i++;
				break;
			case 'X':
				X+=10;
				if(V!=0 || I!=0)
					i++;
				break;
			case 'V':
				V+=5;
				if(I!=0)
					i++;
				break;
			case 'I':
				I+=1;
				break;
			default:
				i++;
				break;
		}
	}
	num=M+D+C+L+X+V+I;
	if(i!= 0 || D>500 || C>400 || L>50 || X>40 || V>5 || I>4){
		printf("Incorrect roman number, try again:\n");
		num=convert(); 
	}
	return num;
}

void symbol(int x, int y){
	int i,result;
	char xar;
	do{
		i=0;
		scanf("%c",&xar);
		if(xar=='+'){
			result=x+y;
			printf("The sum of ");
		}
		else if(xar=='-'){
			result=x-y;
			printf("The difference of ");
		}
		else if(xar=='*'){
			result=x*y;
			printf("The multiplication of ");
		}
		else if(xar=='/'){
			result=x/y;
			printf("The division of ");
		}
		else if(xar!='+' || xar!='-' || xar!='*' || xar!='/'){
			printf("Incorrect symbol, try again:\n");
			i++;
		}		
	}while(i!=0);
	roman(x);
	printf(" and ");
	roman(y);
	printf(" is ");
	roman(result);
	printf(" (%d)\n", result);
}

void roman(int num){
	int i;
	for(i=1;i<=num/1000;i++)
		printf("M");
	if(num%1000/100>=5)
		printf("D");
	for(i=1;i<=num%1000/100%5;i++)
		printf("C");
	if(num%1000%100/10>=5)
		printf("L");
	for(i=1;i<=num%1000%100/10%5;i++)
		printf("X");
	if(num%10>=5)
		printf("V");
	for(i=1;i<=num%10%5;i++)
		printf("I");
}
