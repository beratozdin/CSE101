#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 50
#define MAX_LINE 200
struct person{
	
	int id;
	char name[40];
	char surname[40];
	char mail[40];
};

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

int check_str(char a[],struct person *p){
	
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
			
		if(a[i]>='A' && a[i]<='Z'){
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

int main(){
	
	FILE *input,*output;
	
	struct person *temp;
	int a,i,status=10,j,number=0;
	char line[MAX_LINE+1],part[MAX_LEN+1],one[MAX_LEN+1],two[MAX_LEN+1],three[MAX_LEN+1],four[MAX_LEN+1];
	
	number=number_of_people(input);

	input=fopen("hw4_disordered_people.txt","r");
	output=fopen("orderedFile.txt","w");
	temp=(struct person*)malloc(number*sizeof(struct person));
	
	fprintf(output,"%-10s%-20s%-20s%-20s\n","Id","Name","Surname","Mail");
	i=0;	
	while(status!=EOF){
		
		status=fscanf(input,"%s %s %s %s",one,two,three,four);
		if(status==EOF){break;}
	 
	check_str(one,&temp[i]);	
	check_str(two,&temp[i]);	
	check_str(three,&temp[i]);	
	check_str(four,&temp[i]);	
	
	fprintf(output,"%-10d%-20s%-20s%-20s\n",temp[i].id,temp[i].name,temp[i].surname,temp[i].mail);
	
	one[0]=0;
	two[0]=0;
	three[0]=0;
	four[0]=0;
	i++;
	}

	free(temp);
	fclose(input);
	fclose(output);
	return 0;
}
