#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 80
#define ARSIZE 4
#define SOMENUM 10

typedef enum{False,True}Bool;

int SumRange(int low,int high);
int OnlyEven(int num);
int CheckArrays(int ar1[],int ar2[],int size);
int IsInArray(int ar5[],int size,int help, int value);
void UpdateArray(int ar[],int arsize, int someNum);
int RemoveDigit(long num3,int rem);
int FirstOccurenceUpper(char *);
Bool CheckString(char *,char *);

int main(){
    int low,high,num,n,i=0,size=3,s,val=2,ifval,help=0,rem,res=0,len,len1,len2;
    long num3;
    int ar1[size],ar2[size];
    int ar5[ARSIZE]={4,5,7,2};
    int ar[ARSIZE]={4,5,7,2};
    char str[LEN]="helloWorld";
    char string[]="PeacEpeace";
    char q;
    //getiing input for the SumRange function
    printf("Enter low limit:\n");
    scanf("%d",&low);
    printf("Enter high limit:\n");
    scanf("%d",&high);
    printf("Sum from %d to %d is:%d\n",low,high,SumRange(low,high));
    //getiing input for the Onlyeven function
    printf("Enter number to check if all his digits even:\n");
    scanf("%d",&num);
    n=OnlyEven(num);
    if(n==1)
        printf("All digits of %d are even.\n",num);
    else if(n==0)
        printf("Not all digits of %d are even.\n",num);

    //getiing input for the CheckArrays function
    printf("Enter size for the arrays:\n");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter number for ar1 in [%d] position:\n",i);
        scanf("%d",&(ar1[i]));
        printf("Enter number for ar2 in [%d] position:\n",i);
        scanf("%d",&(ar2[i]));
        }   
    s=CheckArrays(ar1,ar2,size);
    if(s==1)
        printf("ar1 equal to ar2 in the reverse order.\n");
    else
        printf("ar1  not equal to ar2 in the reverse order.\n");

    //getiing input for the CheckArrays function
    UpdateArray(ar,ARSIZE,SOMENUM);
    printf("}\n");

    //getiing input for the IsInArray a function
    printf("We will check this array for presence of %d\n",val);
    for(int i=0;i<ARSIZE;i++){
        printf("%d ",ar5[i]);
    }
     ifval=IsInArray(ar5,ARSIZE,help,val);
     if(ifval==1)
        printf("\nYou value in this array.\n");
    else if(ifval==0)
        printf("\nYou value not in this array.\n");
    
    //getiing input for the RemoveDigit a function
    printf("Enter some number:\n");
    scanf("%ld",&num3);
    printf("Enter number that you want to remove from previous number:\n");
    scanf("%d",&rem);
    printf("Result is:%d\n",RemoveDigit(num3,rem));
    
    //getiing input for the FirstOccurenceUpper a function
    q=FirstOccurenceUpper(str);
    printf("The first capital letter in '%s' is:%c\n",str,q);

    //getiing input for the CheckString a function
    len=strlen(string);
    char *pstr;
    pstr=string;
    if(CheckString(pstr,pstr+(len/2))==True)
        printf("First half of string is equal to the second.\n");
    else
        printf("First half of string isn't equal to the second.\n");
    return 0;
}

int SumRange(int low,int high){
    int sum=0;
    while(low<=high){
    if(low)
        sum+=low;
    else{
        sum+=SumRange(low,high);
    }
    low++;
    }
    return sum;
}


int OnlyEven(int num){
    int tmp;
    printf("%d\n",num);
        if(num%2!=0){
            tmp=0;
        }
        else if(num%2==0 && num!=0){
            tmp=OnlyEven(num/10);
            printf("Now tmmp is %d\n",tmp);
        }
        else if(num==0){
            tmp=1;
        }
    return tmp; 
}

int CheckArrays(int ar1[],int ar2[],int size){
    int i=0,j=size-1,n=0;
        for(i=0;i<size;i++){
            if(ar1[i]==ar2[j]){
                j--;
                if(j==0){}
                    n=1;
                }   
             CheckArrays(ar1,ar2,j);
            }
    return n;
}

void UpdateArray(int ar[],int arsize, int someNum){
        if(arsize==0)
            printf("{");
        else{
            UpdateArray(ar,arsize-1,someNum);
            printf("%d ",(ar[arsize-1])*someNum);
        }
}

int IsInArray(int ar5[],int size,int help, int value){
    if(help==size){
        return 0;
    }
    else if(ar5[help]==value){
        return 1;
    }
    if(help!=size){
        help=help+1;
        return IsInArray(ar5,size,help,value);
}
}

int RemoveDigit(long num3,int rem){
    if(num3==0 ){
        return 0;
    }
    else if(num3%10==rem)
        return RemoveDigit(num3/10,rem);
    else       
        return num3%10+10*RemoveDigit(num3/10,rem);
}

int FirstOccurenceUpper(char *str){
    static int i=0;
  if(i<strlen(str))
  {
    if(isupper(str[i]))
    {
      return str[i];
    }
    else
    {
      i=i+1;
      return FirstOccurenceUpper(str);
    }
  }
}

Bool CheckString(char *half1,char *half2){
    if(*half2=='\0')
        return True;
    else if(*half1==*half2 || *half2==*half1+32 || *half1==*half2+32)
         return CheckString(half1+1,half2+1);
    else
       return  False;
}