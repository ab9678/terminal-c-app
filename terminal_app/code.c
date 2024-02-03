#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define PUR "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define RESET "\e[0m"
//Operating system
#ifdef _WIN32
    const char *os = "Windows";
    int osflag = 1;
#elif __linux__
    const char *os = "Linux";
    int osflag = 0;
#else
    const char *os = "Unknown";
    int osflag = -1;
#endif
long long int factorial(int n);
void asciiHello(){
    printf("\n\n");
    printf(" ## ##              ##     ### ##   ### ##   \n");
    printf("##   ##              ##     ##  ##   ##  ##  \n");
    printf("##                 ## ##    ##  ##   ##  ##  \n");
    printf("##                 ##  ##   ##  ##   ##  ##  \n");
    printf("##                 ######   ## ##    ## ##   \n");
    printf("##   ##            ##  ##   ##       ##      \n");
    printf(" ## ##            ###  ##  ####     ####     \n");
    printf("\n\n");
}


void asciiThankYou(){
    printf("\n\n");
    printf("                                                                                                 \n");
    printf("                                                                                                 \n");
    printf(PUR" /__  ___/                                              \\    / /                               // \n");
    printf(PUR"   / /        / __        ___         __       / ___     \\  / /      ___                      //  \n");
    printf(GRN"  / /        //   ) )   //   ) )   //   ) )   //\\ \\       \\/ /     //   ) )    //   / /       //   \n");
    printf(GRN" / /        //   / /   //   / /   //   / /   //  \\ \\       / /     //   / /   //   / /           \n");
    printf(BLU"/ /        //   / /   ((___( (   //   / /   //    \\ \\     / /     ((___/ /   ((___( (       ##     \n"RESET);
    printf("\n\n");

}


/*
1. Array
    1. addition of its elements
    2 addition of corrsponding elements
    3 subtraction of its elements
    4 subtraction of its corresponding elements
    5 multiplication of its elements 
    6 multiplication of corresponding elements

2. matrix
    1.matrix calculator 

3. Integers
    1. palindrome check
    2. calculator 

4. File
    1 create file 
    2 read an existing file 
    3 create and read a file
    4 append an existing file 

5. structure
    1. structure of students with marks of 5 subjects of each student, calculate sum , average , 
        and name the topper in each subject , and the class topper 

    2. structure employee ,total salary, who has the highest salary, name of the HR .

6. special series 
    1. fibonaci series till a certain stopping integer 'n'
    2. Sum of n numbers 
    3. sum of even numbers till n
    4. sum of odd numbers till n 
    5. product of numbers till n (declare long integer here)

7. Colour Codes
    1. RED for warnings like invalid input
    2. GRN for light or feature not available warnings
    3. YEL for all application prompts
*/


int array(int size){

//int returnedValue;

int i,j,product,diff;    
    
int numOfArray;

printf("Enter how many array do you need: ");
scanf("%d",&numOfArray);

int array[numOfArray][size];

printf("\n\nPlease Enter the Elements:-\n");
for(i=0;i<numOfArray;i++){
    printf("Enter Array %d\n",i+1);
    for(j=0;j<size;j++){
        
        scanf("%d",&array[i][j]);
    }
}

for(i=0;i<numOfArray;i++){
    printf("\n\nArray %d:-\n\n",i+1);
    for(j=0;j<size;j++){
        printf("%d\t",array[i][j]);
    }
}

//calculator part
int sum;
char operation;
int insideOperation;

printf(YEL"\n\nSpecify arithmetic operation for you array ('+' , '-' , '*')\nInput: "RESET);
scanf(" %c",&operation);

//ADDITION PART
if(operation == '+'){
    if(numOfArray > 1){
    printf(YEL"\nDo yo want \n(1)sum of corresponding elements or \n(2)All elements of the arrays\nInput: "RESET); // I have lets say 3 array so for sum of elements i need is for loop , essesntially it is sumrow of all indivisual rows;   
    scanf("%d",&insideOperation);
    }else{
        insideOperation = 2;
    }

    if(insideOperation == 1){
        printf("\n\nRESULT\n\n");
        for(i=0;i<size;i++){                    //if I need sum row in the opposite direction then i has to be the value of j and j the value of I essentially transpose ;
            sum=0;
            for(j=0;j<numOfArray;j++){
                sum=sum+array[j][i];
            }
            printf("%d\t",sum);

        }

    }else if(insideOperation == 2){
        printf("\n\nRESULT\n\n");
        for(i=0;i<numOfArray;i++){
            sum=0;
            for(j=0;j<size;j++){
                sum =sum + array[i][j];
            }
            printf("Array %d = %d\t",i+1,sum);
        }
    }else{
        printf(RED"Invalid Input\n"RESET);
        return 1;
    }


//SUBTRACTION PART

}else if (operation == '-'){
    if(numOfArray>1){
    printf(YEL"Do yo want \n(1)Difference of corresponding elements or \n(2)All elements of the arrays"RESET); // I have lets say 3 array so for sum of elements i need is for loop , essesntially it is sumrow of all indivisual rows;
    
    scanf("%d",&insideOperation);
    }else{
        insideOperation = 2;
    }

    if(insideOperation == 1){


        for(i=0;i<size;i++){                    //if I need sum row in the opposite direction then i has to be the value of j and j the value of I essentially transpose ;

            diff=array[0][i];

            for(j=1;j<numOfArray;j++){

                diff=diff-array[j][i];
            }
            printf("%d\t",diff);


        }

    }else if(insideOperation == 2){
        for(i=0;i<numOfArray;i++){
            diff=array[i][0];
            for(j=1;j<size;j++){
                diff =diff - array[i][j];
            }
            printf("Array %d = %d\t",i+1,diff);
        }
    }else{
        printf(RED"Invalid Input\n"RESET);
        return 1 ;
    }
//MULTIPLICATION PART
}else if (operation == '*'){
    int operation1;
    if(numOfArray>1){
    printf(YEL"Specify what type:-\n1)Elements of the array\n2)Corresponding elements of the arrays\nInput: "RESET);
    scanf("%d",&operation1);
    }else{
        operation1 = 1;
    }
    if(operation1 == 1){
        int productRow;
        //Elements of array
        for(i=0;i<numOfArray;i++){
            productRow=1;
            for(j=0;j<size;j++){
                productRow=productRow*array[i][j];
            }
            printf("\nProduct of elements of Array(%d) is %d ",i+1,productRow);
        }

        printf("\nDone!\n");


    }else if(operation1 == 2){
        //Elements of corresponding array
        int productColumn;
        for(j=0;j<size;j++){
            productColumn = 1;
            for(i=0;i<numOfArray;i++){
                productColumn = productColumn * array[i][j];
            }
            printf("\nProduct of %dth element of Arrays is %d",j+1,productColumn);
        }

        printf("\nDone!\n");
    }else{
        printf(RED"\nInvalid Input\n"RESET);
        return 1;
    }
    
}else{
    printf(RED"\nInvalid Input\n"RESET);
    return 1;
}

//END OF ARRAY FUNCTION
}


int matrix(){
//Matrix calculator
int rowSize,columnSize;
printf("\nEnter Row size of matrix\nInput: ");
scanf("%d",&rowSize);
printf("\nEnter Column Size of the matrix\nInput: ");
scanf("%d",&columnSize);

int a[rowSize][columnSize],i,j;
int b[rowSize][columnSize];
int typeOfOperation;

printf(YEL"Specify the Kind of Matrix operation\n(1)Matrix manipulation\n(2)Arithmetic calculation\nInput(1/2): "RESET);
scanf("%d",&typeOfOperation);
if(typeOfOperation == 1){

// This is type 1 i.e., matrix manipulation
printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n\n");

    printf("Option 1- MATRIX MANIPULATION IS SELECTED\n");

printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);

    printf("\nEnter the matrix:-\n");
    for(i=0;i<rowSize;i++){
        printf("Row %d\n",i+1);
        for(j=0;j<columnSize;j++){
            scanf("%d",&a[i][j]);
        }

    }
    int insideType1;
    printf(YEL"Please select any one of the following:-\n(1)Transpose\n(2)Square of a matrix\nInput: "RESET);
    scanf("%d",&insideType1);
        //do square and transpose ##
        if(insideType1 == 1){

    printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");
            printf("You have selected Transpose of a matrix\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);
            printf("\nOriginal matrix is \n");

            for(i=0;i<rowSize;i++){
                for(j=0;j<columnSize;j++){
                    printf("%d\t",a[i][j]);
                }
                printf("\n");
            }
            printf("Transpose of the matrix is \n");

            for(i=0;i<columnSize;i++){
                for(j=0;j<rowSize;j++){
                    printf("%d\t",a[j][i]);
                }
                printf("\n");
            }


        }else if(insideType1 == 2){
    printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");
            printf("You have selected Square of a matrix\n");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);
            printf("Original matrix is \n");

            for(i=0;i<rowSize;i++){
                for(j=0;j<columnSize;j++){
                    printf("%d\t",a[i][j]);
                }
                printf("\n");
            }

            printf("\nSquare of the Matrix is\n");

            for(i=0;i<rowSize;i++){
                for(j=0;j<columnSize;j++){
                    int result = a[i][j] * a[i][j];
                    printf("%d\t",result);
                }
                printf("\n");
            }


        }else{
            printf(RED"\n\nInvalid Input\n"RESET);
            return 1;
        }





    // ##   


}else{          // if 2 is selected we will have matrix calculator 

// This is type 2 i.e, Arithmetic opearation
printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("Option 2- ARITHMETIC CALCULATION IS SELECTED \n\n");
    printf(RED"!!PLEASE NOTE MULTIPLICATION IS AVAILABLE ONLY FOR SQUARE MATRICES!!\n"RESET);
printf(YEL"----------------------------------------------------------------------------------------------------------------------\n\n"RESET);


printf("\nEnter the first matrix:-\n");
for(i=0;i<rowSize;i++){
    printf("Row %d\n",i+1);
    for(j=0;j<columnSize;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("\nEnter the second matrix:-\n");
for(i=0;i<rowSize;i++){
    printf("Row %d\n",i+1);
    for(j=0;j<columnSize;j++){
        scanf("%d",&b[i][j]);
    }
}

printf("\nYour Matrices are:-\n");
for(i=0;i<rowSize;i++){
    for(j=0;j<columnSize;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
}
printf("\nAND\n\n");

for(i=0;i<rowSize;i++){
    for(j=0;j<columnSize;j++){
        printf("%d\t",b[i][j]);
    }
    printf("\n");
}

char insideType2;
printf(GRN"\nPlease select one of the following \n\n +  ,  -  ,  * \nInput: "RESET);
scanf(" %c",&insideType2);

if(insideType2 == '+'){
printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("ADDITION OF MATRICES");
printf("\n----------------------------------------------------------------------------------------------------------------------\n\n");

    int sum=0;
    printf("\n\nRESULTANT MATRIX:-\n\n");
    for(i=0;i<rowSize;i++){
        for(j=0;j<columnSize;j++){
            sum=a[i][j] + b[i][j];
            printf("%d\t",sum);
        }
        printf("\n");
    }
}else if(insideType2 == '-'){
printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("DIFFERENCE OF MATRICES");
printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);
    int diff=0;
    printf("\n\nRESULTANT MATRIX:-\n\n");
    for(i=0;i<rowSize;i++){
        for(j=0;j<columnSize;j++){
            if(a[i][j]>b[i][j]){
                diff = a[i][j] - b[i][j];
            }else{
                diff = b[i][j] - a[i][j];
            }
            printf("%d\t",diff);
        }
        printf("\n");
    }
}else if(insideType2 == '*'){
printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("MULTIPLICATION OF MATRICES");
printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);
    printf(GRN"\n\n!!PLEASE NOTE MULTIPLICATION IS AVAILABLE ONLY FOR SQUARE MATRICES!!\n\n"RESET);
    int r[rowSize][columnSize];
    if(rowSize==columnSize){    //multiplication if 
    for(i=0;i<rowSize;i++){
    for(j=0;j<columnSize;j++){

        r[i][j]=0;

        for(int k=0;k<rowSize;k++){
            r[i][j]=r[i][j]+a[i][k]*b[k][j];
        }
    }
    }
    for(i=0;i<rowSize;i++){
        for(j=0;j<columnSize;j++){
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }                            //end of multiplication if

    }else{
        printf(RED"\n\nThe matrix is not a square matrix\n"RESET);
        return 1;
    }                            //end of multiplication else

}else{//end of __else if (insideType2=='*')__
    printf(RED"\n\nNone of the Arithmatic opeartor selected/Invalid input\n"RESET);
    return 1;
}

}//end of else if 2 is selected line:265

}//Matrix() close


int integer(){

int operation;
printf(YEL"Specify operation\n(1)Calculator\n(2)Other\nInput: "RESET);
scanf("%d",&operation);

if(operation == 1){
    printf("\e[0;93m");
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("You Chose Calculator");
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("\e[0m");

    int calType;
    printf("Select one\n(1)Arithmetic(+,-,/,*)\n(2)Factorial Calculator\nInput: ");
    scanf("%d",&calType);
    
    if(calType == 1){
    //Calculator

        float num1;
        float num2;
        float result=0;
        printf("\nNum1: ");
        scanf("%f",&num1);
        printf("\nNum2: ");
        scanf("%f",&num2);
        char calOperator;
        printf(GRN"Select one among the Following\n\n'+'\t'-'\t'/'\t'*'\nInput: ");
        scanf(" %c",&calOperator);
        if(calOperator == '+'){
            result = num1 + num2;
            printf("\n\n%f + %f = %f\n",num1,num2,result);
        }
        else if(calOperator == '-'){
            result = num1 - num2;
            printf("\n\n%f - %f = %f\n",num1,num2,result);
        }
        else if(calOperator == '/'){
            result = num1 / num2;
            printf("\n\n%f / %f = %f\n",num1,num2,result);
        }
        else if(calOperator == '*'){
            result = num1 * num2;
            printf("\n\n%f x %f = %f\n",num1,num2,result);
        }
        else{
            printf(RED"\nInvalid Operator\n"RESET);
            return 1;
        }
    }else if(calType == 2){
        int number;
        //calculate factorial of a number
        printf("Enter the Number\nInput: ");
        scanf("%d",&number);
        printf(GRN"Factorial of %d is = %lld\n",number,factorial(number));
        printf(RESET);        
    }else{
        printf(RED"\nInvalid Input\n"RESET);
    }
}else if(operation == 2){
    int insideOperation;
    printf(YEL"\n------------------------------------------------------------------------------------------------------\n");
    printf("You Chose Other");
    printf("\n------------------------------------------------------------------------------------------------------\n"RESET);
    
    printf("\nSelect one of the following"RESET);
    printf("\n\n(1)Check prime\n(2)Check if No. is Armstrong No.\n(3)Check if a Number belongs to Fibonacci sequence\n\n"YEL"Input: "RESET);
    
    scanf("%d",&insideOperation);
    int number;
    printf("Enter the Number\nInput: ");
    scanf("%d",&number);
    if(insideOperation == 1){
        //check if a number is prime
        //a number is said to be prime if and only if it is divisible by 1 and the number itself
        int i,flag=0;
        if(number < 2){
            flag = 2;
            
        }else{
            for(i=2;i<number;i++){
            if(number%i==0){
                flag = 1;
                break;
                
                }
            }
        }

        if(flag==2){
            printf(GRN"The Number entered is smaller than 2, which is the smallest prime number\n"RESET);
        }else if(flag == 1){
            printf(GRN"The Number is not a Prime Number\n"RESET);
        }else if(flag == 0){
            printf(GRN"The Number is a Prime Number\n"RESET);
        }



    }
    
    else if(insideOperation == 2){
        //check if a number is armstrong number
        //A number is an armstrong number if the cube of its indivisual digits add up to be the same number

        int Original=number;
        int sum=0,num,cube;
        while(number){
            num = number %10;
            number = number/10;

            cube = num*num*num;
            sum = sum + cube;

        }
        
        if(sum == Original){
            printf(GRN"The Number %d is an Armstrong Number\n",Original);
            printf(RESET);
        }else{
            printf(GRN"The Number is Not an Armstrong Number\n"RESET);
        }
    }
    else if(insideOperation == 3){
        //check if a number belongs to the fibonacci sequence
        int flag=0;
        int first=0,second=1,next=0;
        printf(GRN"%d\t%d\t",first,second);
        do {
        next = first + second;
        printf(GRN"%d\t", next);

        first = second;
        second = next;
        if(next == number){
            flag=1;
            break;
        }
    } while (next <= number);
    if(flag == 1){
        printf(GRN"\nThe Number Belongs to the Fibonacci sequence\n"RESET);
    }else{
        printf(GRN"\nThe Number does not belong to the Fibonacci sequence\n");
    }
    }else{
        printf(RED"\n\nInvalid Input"RESET);
        return 1;
    }


}else{
    printf(RED"\nInvalid Input\n"RESET);
    return 1;
}


}


int structures(){

const char *home;
const char *fileName;

if(osflag == 0){
    home = getenv("HOME");
    fileName = ".structure-student-c-program-saved-options.txt";
}else{
    home = getenv("USERPROFILE"); // On Windows, use "USERPROFILE" instead of "HOME"
    fileName = "\\structure-student-c-program-saved-options.txt"; // Use backslashes for Windows path
}
// Make a structure to store the details of n students. Store their marks of n subject which is total
// Now the code shall chose best of 5 and store it in best array.
// Then it will calculate the average and the percentage, and this will be printed with the details.
// Now in a saperate block, it will calculate the topper and print his details saperately.
int nOfSub;
printf(YEL"\nHow many subject are to be considered?\nInput: "RESET);
scanf("%d",&nOfSub);

struct student
{
    char name[20];
    int rollNumber;
    char course[20];
    int sem;
    int marks[nOfSub];
    int avg;
    int bestMarks;

    

}s1;
struct employee
{
    char name[20];
    int empID;
    int basesalary;
    int performanceBonus;
    int totalSalary;
};

int numOfoptions;//variable for the size of saveOptions array
numOfoptions = 7;
int savedOptions[numOfoptions];

int i=0,j=0,sum=0,avg=0,highest=0;
//store 0 in all the indexes ;
for(i=0;i<numOfoptions;i++){
    savedOptions[i]=0;
}

int tempScan;
char filePath[100];  // Adjust the size based on your needs
if(osflag == 0){//if linux
    snprintf(filePath, sizeof(filePath), "/%s/%s", home, fileName);
}else{//if windows
    snprintf(filePath, sizeof(filePath), "%s%s", home, fileName);
}
//open the file in write mode initially
FILE *fp=fopen(filePath,"r");



int option;
char prompt;
printf("(1)Create a structure to store details of students\n(2)Create a structure to store details of employees\nInput: ");
scanf("%d",&option);
if (option == 1){
    printf("\n\nCOURSE: ");
    scanf(" %s",s1.course);

    printf("\nSEMESTER: ");
    scanf("%d",&s1.sem);

    

    printf("Use previous layout?(y,n)\nInput: ");
    scanf(" %c",&prompt);
    if(prompt == 'y'){
        //create file to store saved values(will be used when the user is using this for the first time)
        if(fp == NULL){
            fp = fopen(filePath,"w");
            printf(RED"\n\nNo previous config available\n\n"RESET);
            fclose(fp);
            return 1;
        }

        //File is already opened in read mode so no need to open again
        rewind(fp);
        while(!feof(fp)){
            fscanf(fp , "%1d" , &tempScan);
            savedOptions[i++]=tempScan;
        }
        fclose(fp);
        //temp
        fp=fopen(filePath,"r");
        rewind(fp);
        int a;
        int k=0;
        while(!feof(fp)){
            fscanf(fp,"%1d",&savedOptions[k]);
            //printf("%d\t",savedOptions[k]);
            k++;
        }

        
        //The user doesnt want to use the previous configuration
    }else if(prompt == 'n'){
        //create new set of options and save then in the file.
        int inputOption;
        printf("Please select the required fields\n\n(1)Name\n(2)Roll Number\n(3)Section\n(4)Average Marks\n(5)Indivisual Best\n(6)Subject Topper\n(7)Class Topper\nPress k when done\nInput: ");
        scanf("%d",&inputOption);

        //writing the saved numbers, i.e, the input number in inputOption variable , to the file
        fp = fopen(filePath,"w");
        fprintf(fp , "%1d" , inputOption);
        fclose(fp);

        //open the file to read the data and store it in the variable
        fp = fopen(filePath,"r");
        //copy the numbers/options selected from the file to the array, here j is the iterator
        while(!feof(fp)){
            fscanf(fp,"%1d",&savedOptions[j]);
            
            j++;
        }

            
    }
}
//print the options which are saved for my reference
    printf("\n\n");
    for(i=0;i<numOfoptions;i++){
        printf("%d\t",savedOptions[i]);
    }

    
//_________________________
// Now let's search for elements in the array , so that we can tell the user which options he chose

















//function close
}
    

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
printf("\e[0;93m");
asciiHello();
printf("\e[0m");

int operation;

printf("Specify the operation to be performed (Enter the corresponding number)\n\n1. Array \n2. Matrix \n3. Integers \n4. File Handling \n5. Structure \n6. Special series\nInput:  "RESET);

scanf("%d",&operation);
printf("%d",operation);
int returnedValue;
char yesORno;

// ARRAY PART {Start}
if(operation==1){
    int arrSize;
    
    printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");
    printf("You have selected Array");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);

    printf("Enter the size of your array:\t");
    scanf("%d",&arrSize);
    returnedValue=array(arrSize);
    if(returnedValue == 1){
        printf(GRN"\n\nDo You Want to try Again?(y/n)\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno == 'y'){
            array(arrSize);
        }
        
    }else{//To be able to run array again
        printf(GRN"\n\nOnce More?(y/n)\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno=='y'){
            array(arrSize);
        }
    }
    // ARRAY PART {End}



// MATRIX START
}else if(operation == 2){
    printf(YEL"\n----------------------------------------------------------------------------------------------------------------------\n");

    printf("You Have selected Matrix");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n\n"RESET);

    returnedValue=matrix();


    if(returnedValue == 1){
        printf(GRN"\n\nDo You want to try Again?(y/n)\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno == 'y'){
            matrix();
        }
    }else{
        printf(GRN"\n\nOnce More(y/n)?\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno == 'y'){
            matrix();
        }
    }
    




//MATRIX END
}else if(operation == 3){
//INTEGER START
printf(YEL"\n------------------------------------------------------------------------------------------------------\n");
    printf("You have selected Integers");
printf("\n------------------------------------------------------------------------------------------------------\n"RESET);
    returnedValue=integer();
    if(returnedValue == 1){
        printf(GRN"\n\nDo You want to try Again?(y/n)\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno == 'y'){
            integer();
        }
    }else{
        printf(GRN"\n\nOnce More(y/n)?\n"RESET);
        scanf(" %c",&yesORno);
        if(yesORno == 'y'){
            integer();
        }
    }
    


//INTEGER END
}else if(operation == 5){
    printf(YEL"\n------------------------------------------------------------------------------------------------------\n");
    printf("You have selected Stuctures");
    printf("\n------------------------------------------------------------------------------------------------------\n"RESET);
    structures();
    

    
}




printf("\e[0;93m");
printf("\n\n\nThank You\n\n");
printf("\e[0m");
printf("\e[0;35m");
asciiThankYou();
printf("\e[0m");
//Main Function End
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int factorial(int n){
    if(n==1){
        return 1;
    }else if (n==0){
        return 0;
    }
    return n * factorial(n-1);
}