/*Declaration of structures*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

/*Function that check if password is weal an 
                return his score*/
int Check(char *);

int main(){
    FILE *f1,*f2;
    char text[SIZE];
    printf("Enter name of file that you want to save:\n");
    scanf("%s",text);
    f1=fopen("passwords.txt","r");
    f2=fopen(text,"w");

    if(f1==NULL || f2==NULL){
		printf("Can't open this file.\n");
		exit(1);
	}

    while(!feof(f1)){
        fscanf(f1,"%s",text);//reading from passwords.txt
        printf("%s\n",text);
         if(Check(text)<7) {
            //if password that we will chek is weak-->writing hit into f2
            fprintf(f2,"%s\n",text);
         }
    }
    //Closing file becouse we end to work with them
    fclose(f1);
	fclose(f2);
    return 0;
}
//Help Function
int Check(char *text){
    int count=0;
    if((*text>='A' && *text<='Z')&&(*text>='a' && *text<='z'))
        count+=2;
    else if(strlen(text)>6)
        count+=7;
    printf("count is% d\n",count);
    return count;
}