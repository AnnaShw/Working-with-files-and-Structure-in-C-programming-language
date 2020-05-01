/*Declaration of structures*/
#define SIZE 30
#define ERROR -1
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/* Structures declarations */
typedef struct{
    char* CourseName;
    int grade;
}Course;
typedef struct{
    char* StudentName;
    Course *course_arr;
    int size;
}Student;

 /*Declaration of functions*/   
void InputCourse(Course* pCourse);
void PrintCourse(Course Cours);
void InputStudent(Student* pSt);
void PrintStudent(Student st);
int Build(Student** pSt);
void FreeAll(Student** pSt,int size);
void PrintAll(Student* arSt,int size);
void CourseList(Student* arrSt,int size,char* CourseName);
void FreeCourse(Course* pCourse);
void FreeStudent(Student* pSt);

int main(){	
    Student* arr=NULL;
    int size;
    size=Build(&arr);

    PrintAll(arr,size);

	printf("We will check who have greater than 56 in calculus.\n");
    CourseList(arr,size,"calculus");
		
   // FreeAll(&arr,size);

	
    return 0;
}


int Build(Student** pSt){
    int size, i;
	printf("Enter the number of Students:\n");
	scanf("%d",&size);
	*pSt=(Student*)malloc(sizeof(Student)*size);
	if (*pSt==NULL){
		printf("Error\n");
		exit(1);
	}
	
	for (i = 0;i<size;i++){
		printf("Data for  %d courses\n", i+1);
		InputStudent(&((*pSt)[i]));
	}	
	return size;
}
/*scan data  about course*/
void InputCourse(Course* pCourse){
    char help[SIZE];
    printf("Enter name of Course:\n");
    scanf("%s",help);
	printf("Enter grade:\n");
	scanf("%d",&(pCourse->grade));
    pCourse->CourseName=(char*)malloc(strlen(help)+1);
    strcpy(pCourse->CourseName,help);
}

/*print data  about course*/
void PrintCourse(Course Cours){
	printf("Course is:%s\nGrade:=%d\n",Cours.CourseName,Cours.grade);
}

/*scan data about each student,courses too*/
void InputStudent(Student* pSt){
	char temp[SIZE];
	int c;
	printf("Enter name of student:\n");
	scanf("%s",temp);
	printf("Enter number of courses:\n");
	scanf("%d",&(pSt->size));

	pSt->StudentName=(char*)malloc(strlen(temp)+1);
	strcpy(pSt->StudentName,temp);


	pSt->course_arr=(Course*)malloc(sizeof(Course)* (pSt->size));

	for(int i=0;i<pSt->size;i++){
		InputCourse(&(pSt->course_arr[i]));
	}
}
/*print data about student*/
void PrintStudent(Student st){
	printf("Student name:%s\n",st.StudentName);
	for(int i =0;i<st.size;i++)
    	PrintCourse(st.course_arr[i]);
}

//Just print
void PrintAll(Student* arrStudents,int size){
	for(int i=0;i<size;i++){
		PrintStudent(arrStudents[i]);
	}


}
//Free aliocating memory
void FreeAll(Student** pSt,int size){
	//A function will free all dynamic memory
	for(int i=0;i<size;i++){
		FreeStudent(&(*pSt[i]));
	}
	free(*pSt);
}

//help function
void FreeCourse(Course* pCourse){
	printf("1111\n");
	free(pCourse->CourseName);
}

//help function 
void FreeStudent(Student* pSt){
printf("2222\n");
	free(pSt->StudentName);
	//for(int i=0 ;i<pSt->size;i++)
		//FreeCourse(&(pSt->course_arr[i]));
	free(pSt->course_arr);
}

/*Fuction will print name of student that his grade greater than 56*/
void CourseList(Student* arrSt,int size,char* CourseName){
	for(int i=0;i<size;i++){
		for(int j=0;j<arrSt[i].size;j++){
			if(strcmp(arrSt[i].course_arr[j].CourseName,
						CourseName)==0 
						&&
						arrSt[i].course_arr[j].grade > 56
				)
					printf("Student name:%s\n",arrSt[i].StudentName);
		}
	}
    	
}