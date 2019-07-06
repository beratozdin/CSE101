#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 50
#define MAX_LINE 200
typedef struct person{
	
	int id;
	char name[40];
	char surname[40];
	char mail[40];
}person;

int number_of_people(){
	
	FILE *input;
	input=fopen("hw4_disordered_people.txt","r");
	char line[MAX_LINE];
	char one[50],two[50],three[50],four[50];
	int status=10,number=0;
	
	while(status!=EOF){
			
		status=fscanf(input,"%s %s %s %s",one,two,three,four);
		if(status==EOF){
			break;
		}
		number++;
	}
	fclose(input);
	
	return number;
}
int check_str(char a[],person *p){
	
	int i,j=0;

	for(i=0; a[i]!=0; i++){

		if(a[i]>='0' && a[i]<='9'){
			j++;
		}
	}
	if(strlen(a)==j){
		sscanf(a,"%d",&p->id);
		return 1;
	}
	j=0;
	for(i=0; a[i]!=0; i++){
			
		if((a[i]>='A' && a[i]<='Z') || a[i]=='-'){
			j++;
		}
	}
	if(strlen(a)==j){
		strcpy(p->surname,a);
		return 2;
	}
	j=0;
	for(i=0; a[i]!=0; i++){
			
		if(a[i]=='@'){
			j++;
		}
	}
	if(j==1){
		strcpy(p->mail,a);
		return 3;
	}
	strcpy(p->name,a);
	return 4;
}
void sorting_function(person *temp,int number,int sort_type){

	int temp_number,small_value_index,i,j;
	char temp_string[40];

	for(i=0; i<number-1; i++){

		small_value_index=i;
		for(j=i; j<number; j++){

			if(sort_type==1){
			if((temp[j].id)<(temp[small_value_index].id)){
				small_value_index=j;
			}
			}
			else if(sort_type==2){
				if(strcmp(temp[j].name,temp[small_value_index].name)<0){
				small_value_index=j;
			}
			}	
			else if(sort_type==3){
				if(strcmp(temp[j].surname,temp[small_value_index].surname)<0){
				small_value_index=j;
			}
			}
			else if(sort_type==4){
				if(strcmp(temp[j].mail,temp[small_value_index].mail)<0){
				small_value_index=j;
			}
			}
		}

		temp_number=temp[i].id;
		temp[i].id=temp[small_value_index].id;
		temp[small_value_index].id=temp_number;

		strcpy(temp_string,temp[i].name);
		strcpy(temp[i].name,temp[small_value_index].name);
		strcpy(temp[small_value_index].name,temp_string);

		strcpy(temp_string,temp[i].surname);
		strcpy(temp[i].surname,temp[small_value_index].surname);
		strcpy(temp[small_value_index].surname,temp_string);

		strcpy(temp_string,temp[i].mail);
		strcpy(temp[i].mail,temp[small_value_index].mail);
		strcpy(temp[small_value_index].mail,temp_string);
	}
}
int main(){

	FILE *input,*output;

	person *temp;
	int a,i=0,status=10,j,number=0;
	char line[MAX_LINE+1],part[MAX_LEN+1],one[MAX_LEN+1],two[MAX_LEN+1],three[MAX_LEN+1],four[MAX_LEN+1],selection;
	
	number=number_of_people(input);/*Finds number of people*/

	input=fopen("hw4_disordered_people.txt","r");
	output=fopen("orderedFile.txt","w");
	temp=(person*)malloc(number*sizeof(person));
			
	while(status!=EOF){
		
		status=fscanf(input,"%s %s %s %s",one,two,three,four);
		if(status==EOF){break;}

		check_str(one,&temp[i]);	
		check_str(two,&temp[i]);	
		check_str(three,&temp[i]);	
		check_str(four,&temp[i]);	
		one[0]=0;
		two[0]=0;
		three[0]=0;
		four[0]=0;
		i++;
	}
	/*Selection menu*/
	printf("Enter the selection:\n");
	scanf("%c",&selection);

	if(selection=='I' || selection=='i'){/*Id sorting*/
		sorting_function(temp,number,1);
		fprintf(output,"%-10s%-20s%-20s%-20s\n","Id","Name","Surname","Mail");
		for(i=0; i<number; i++){	
			fprintf(output,"%-10d%-20s%-20s%-20s\n",temp[i].id,temp[i].name,temp[i].surname,temp[i].mail);
		}
	}
	else if(selection=='N' || selection=='n'){/*Name sorting*/
		sorting_function(temp,number,2);
		fprintf(output,"%-20s%-10s%-20s%-20s\n","Name","Id","Surname","Mail");
		for(i=0; i<number; i++){	
			fprintf(output,"%-20s%-10d%-20s%-20s\n",temp[i].name,temp[i].id,temp[i].surname,temp[i].mail);
		}
	}
	else if(selection=='S' || selection=='s'){/*Surname sorting*/
		sorting_function(temp,number,3);
		fprintf(output,"%-20s%-10s%-20s%-20s\n","Surname","Id","Name","Mail");
		for(i=0; i<number; i++){
			fprintf(output,"%-20s%-10d%-20s%-20s\n",temp[i].surname,temp[i].id,temp[i].name,temp[i].mail);
		}
	}
	else if(selection=='M' || selection=='m'){/*Mail sorting*/
		sorting_function(temp,number,4);
		fprintf(output,"%-25s%-10s%-20s%-20s\n","Mail","Id","Name","Surname");
		for(i=0; i<number; i++){
			fprintf(output,"%-25s%-10d%-20s%-20s\n",temp[i].mail,temp[i].id,temp[i].name,temp[i].surname);
		}
	}

	free(temp);
	fclose(input);
	fclose(output);
	return 0;
}
