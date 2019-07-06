/* THIS PROGRAM SORTS ARRAY DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int PrintSelection(int selection){
 printf("Selected Menu item is:");
 printf("%d\n",selection);
 return 1;
 
}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // clears screen
 
 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection:");	
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
int array_element=0;
int number1, number2, sum,subtract;
double num_1,num_2;
double divide;
int summarize_number;
int a;
int digit=1;
int digit_number;
int digit_control=0;
char wanttoexit = FALSE;
char c;
int x,y,result_pow;
int choice;
int i,j;
int myArray[100];
int summarize_array[10]={0,0,0,0,0,0,0,0,0,0};
int max;
int pivot;
int temp;


// main loop
while(wanttoexit == FALSE){

	// display menu and get result	
	choice = DisplayMenu();
	
	
	if(choice == 1){
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		sum = number1 + number2;
		printf("The result is: ");
		printf("%d\n",sum);
		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("%s","Enter numbers for array and 0 for end\n");
		for(i=0;i<100;i++){
			scanf("%d",&array_element);
			if(array_element == 0) break;
			myArray[i] = array_element;
			max = i ;
		}
		printf("Numbers are entered.. \n");
		printf("Now sorting.. ");
	    for(i=0;i<=max;i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }
		    
		}
		printf("finished..\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");
	        
		    
		c=getchar();
		c=getchar();
	}
	if(choice==3){
		
		printf("Please enter first number");
		scanf("%d",&number1);
		printf("Please enter second number");
		scanf("%d",&number2);
		subtract=number1-number2;
		printf("The result of subtract:%d\n",subtract);
		
		c=getchar();
		c=getchar();
		
	}
	if(choice==4){
		
		printf("Please enter first number:");
		scanf("%lf",&num_1);
		printf("Please enter second number:");
		scanf("%lf",&num_2);
		
		
		if(number2!=0){
			divide=number1/number2;
			printf("The result of dividing:%.2lf\n",divide);
		}
		else{
			
			
			printf("Error,second number can not zero");
		}
		c=getchar();
		c=getchar();
		
		
	}
	if(choice==5){
		
		printf("Enter a number(max number of digit 10):");
		scanf("%d",&summarize_number);
		digit_control=0;
		
		while(summarize_number!=0){	
			digit_number=summarize_number%10;
			summarize_number=summarize_number/10;
			summarize_array[digit_control]=	digit_number;
			digit_control++;
		}
		
		for(i=digit_control-1; i>=0; i--){
			
			if(summarize_array[i]!=0){
				digit=1;
				for(a=0; a<i; a++){
					digit=digit*10;
					
				}
				if(i!=0){
				
			
				printf("%d.%d",summarize_array[i],digit);
			}
				else{
				printf("%d",summarize_array[i]);	
				}
			}
			if(i!=0){
			
			if(summarize_array[i-1]!=0){
				printf("+");
			}
			}
		}
		
		c=getchar();
		c=getchar();
	}
	
	if(choice==6){
		
		printf("Please enter base number");
		scanf("%d",&number1);
		printf("Please enter exponent number");
		scanf("%d",&number2);
		if(number1!=0 && number2==0){
			number1=1;
			printf("%d\n",number1);
		}
		else if(number1==0 && number2==0){
			number1=1;
			printf("%d",number1);
		}
		else{
		
		result_pow=1;
		a=0;
		while(a<number2){
		
			result_pow=result_pow*number1;
			a++;
		}
		
		printf("The result of power process:%d\n",result_pow);
		}
		c=getchar();
		c=getchar();
		
	}
	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} // end of while

}
