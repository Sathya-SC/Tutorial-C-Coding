#include <stdio.h>  //Standard input-output header
#include <stdlib.h> //Standard library header
#include <string.h> //String header

void addEmployee();
void displayEmployee();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

// Create a structure called Employee
struct Employee  // Structure declaration
{
    char firstName[20]; // String
    char lastName[20]; //String
    int Id; //Integer (whole number)
    long long NICNo; // Long Long Integer (whole number)
    char nicFormat[5]; // String
    char gender; // Character
    int year;  // Integer (whole number)
    int month;  // Integer (whole number)
    int day; // Integer (whole number)
    int age; // Integer (whole number)
    char status[15]; // String
    char email[50]; // String
    long int mobile_no; // Long Integer (whole number)
    char address[50]; // String
    char designation[20]; // String
    char department[10]; // String
    float basicSalary; // Floating point number
    float allowance; // Floating point number
    int travelMode; // Integer (whole number)
    int travelCharge; // Integer (whole number)
    float travelingKilometers; // Floating point number
    float travelingAllowance; // Floating point number
    float Tax; // Floating point number
    float netSalary; // Floating point number
}; // End the structure with a semicolon

int main()
{
    system("color 1F");
    // Create variables
    int Choice;
    char userName[20],passWord[12];
    int n=3,i=1;

    printf("\n\n\t\t********************************************** LOGIN FORM ******************************************\n\n");

    for(i=1; i<=n; i++)
    {
        printf("\n\n\t\t\t\tEnter Your UserName                       : ");
        scanf("%s",&userName);

        printf("\n\n\t\t\t\tEnter Your PassWord                       : ");
        scanf("%s",&passWord);

        if(strcmp(userName,"user")==0 && strcmp(passWord,"pass")==0)
        {
                printf("\n\n\t\t************************************************************************************************\n\n");
                printf("\n\n\t\t\t\t\t\t\tLOGIN IS SUCCESSFUL\n\n");
                printf("\n\n\t\t************************************************************************************************\n\n");
                while(1)
                {
                    printf("\n\t\t\t ******************************************************************");
                    printf("\n\t\t\t ******************************************************************");
                    printf("\n\t\t\t ******************************************************************");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t *******  WELCOME TO ABC COMPANY EMPLOYEE MANAGEMENT SYSTEM *******");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t *******                                                    *******");
                    printf("\n\t\t\t ******************************************************************");
                    printf("\n\t\t\t ******************************************************************");
                    printf("\n\t\t\t ******************************************************************");

                    printf("\n\n\n\t\t\t\t\t 1.ADD EMPLOYEE DETAILS\n");
                    printf("\t\t\t\t\t 2.DISPLAY EMPLOYEE DETAILS\n");
                    printf("\t\t\t\t\t 3.SEARCH EMPLOYEE DETAILS\n");
                    printf("\t\t\t\t\t 4.MODIFY EMPLOYEE DETAILS\n");
                    printf("\t\t\t\t\t 5.DELETE EMPLOYEE DETAILS\n");
                    printf("\t\t\t\t\t 6.EXIT\n");
                    printf("\t\t\t\t\t --------------------------------------\n");
                    printf("\t\t\t\t\t PLEASE SELECT AN OPTION : \n");
                    printf("\t\t\t\t\t ");
                    scanf("%d",&Choice);

                    switch(Choice){
                        case 1:
                             system("color DF");
                             addEmployee();
                             break;
                        case 2:
                            system("color 5F");
                            displayEmployee();
                            break;
                        case 3:
                            system("color 4F");
                            searchEmployee();
                            break;
                        case 4:
                            system("color AF");
                            modifyEmployee();
                            break;
                        case 5:
                            system("color 3F");
                            deleteEmployee();
                            break;
                        case 6:
                            system("color 8F");
                            system("cls");
                            printf("\n\n\t\t\t\t************************************************************************************************\n");
                            printf("\n\n\t\t\t\t\t\t\tTHANK YOU FOR USING EMPLOYEE MANAGEMENT SYSTEM\n");
                            printf("\n\n\t\t\t\t************************************************************************************************\n\n");
                            exit(0);
                            break;
                        default:
                            printf("\n\n\t\t\t\tPLEASE ENTER THE VALID OPTION\n\n");
                    }
                }
            }
        else if(strcmp(userName,"user")!=0 && strcmp(passWord,"pass")!=0)
        {
            printf("\n\n\t\t\t\tINCORRECT USER NAME AND PASSWORD\n",i);
        }
        else if(strcmp(userName,"user")!=0)
        {
                printf("\n\n\t\t\t\tINCORRECT USER NAME PLEASE TRY AGAIN\n",i);
        }
        else if(strcmp(passWord,"pass")!=0)
        {
            printf("\n\n\n\t\t\t\tINCORRECT PASSWORD PLEASE TRY AGAIN\n",i);
        }

    }
    printf("\n\t\t\t\tLOGIN ERROR PLEASE TRY AGAIN");


}

void addEmployee()
{
    system("cls");
    // Create variables
    char another;
    int d;

    FILE *fp;
    struct Employee e;   // Create a structure variable of Employee called e

    do{
        printf("\n\n\t\t\t\t************************************* ADD EMPLOYEE DETAILS *************************************\n\n");
        // Open all file in append mode
        fp = fopen("Employee_Details.txt","a");
        printf("\n\t\t\t\tEnter The Employee ID                                                 : ");
        scanf("%d",&e.Id);
        printf("\n\t\t\t\tEnter The First Name Of The Employee                                  : ");
        scanf("%s",&e.firstName);
        printf("\n\t\t\t\tEnter The Last Name Of The  Employee                                  : ");
        scanf("%s",&e.lastName);

while(1)
{
        printf("\n\t\t\t\tEnter Employee's NIC Format(Like \"New Or Old\")                        : ");
        scanf("%s",&e.nicFormat);

        if(strcmp(e.nicFormat,"New")==0)
        {
            printf("\n\t\t\t\tEnter Employee NIC No                                                 : ");
            scanf("%lld",&e.NICNo);
            int firstSevenDigit,nextThreeDigit;
            firstSevenDigit = (e.NICNo)/100000;
            nextThreeDigit = firstSevenDigit%1000;

            if(nextThreeDigit > 500)
            {
                e.gender='F';
                printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                d = nextThreeDigit-500;
            }
            else
            {
                e.gender='M';
                printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                d = nextThreeDigit;
            }
            e.year = firstSevenDigit/1000;

            if (0 < d && d <= 31)
            {
                e.month = 1;
                e.day = d;
            }
            else if(31 < d && d <=60)
            {
                e.month = 2;
                e.day = d-31;
            }
            else if(60 < d && d <= 91)
            {
                e.month = 3;
                e.day = d-60;
            }
            else if(91 < d && d <= 121)
            {
                e.month = 4;
                e.day = d-91;
            }
            else if(121 < d && d <= 152)
            {
                e.month = 5;
                e.day = d-121;
            }
            else if(152 < d && d <= 182)
            {
                e.month = 6;
                e.day = d-152;
            }
            else if(182 < d && d <= 213)
            {
                e.month = 7;
                e.day = d-182;
            }
            else if(213 < d && d <= 244)
            {
                e.month = 8;
                e.day = d-213;
            }
            else if(244 < d && d <= 274)
            {
                e.month = 9;
                e.day = d-244;
            }
            else if(274 < d && d <= 305)
            {
                e.month = 10;
                e.day = d-274;
            }
            else if(305 < d && d <=335)
            {
                e.month = 11;
                e.day = d-305;
            }
            else if(335 < d && d <=366)
            {
                e.month = 12;
                e.day = d-335;
            }
            printf("\n\t\t\t\tEmployee's Date of Birth                                              : %d/%d/%d\n",e.day,e.month,e.year);
            e.age = 2022 - e.year;
            printf("\n\t\t\t\tEmployee's Age                                                        : %d\n",e.age);

        }
        else if(strcmp(e.nicFormat,"Old")==0)
        {
            printf("\n\t\t\t\tEnter Employee NIC No \"Don't Use The Text Format\"                     : ");
            scanf("%lld",&e.NICNo);
            int firstFiveDigit,nextThreeDigit;
            firstFiveDigit = (e.NICNo)/10000;
            nextThreeDigit = firstFiveDigit%1000;

            if(nextThreeDigit > 500)
            {
                e.gender = 'F';
                printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                d = nextThreeDigit-500;
            }
            else
            {
                e.gender = 'M';
                printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                d = nextThreeDigit;
            }
            e.year = firstFiveDigit/1000 + 1900;

            if (0 < d && d <= 31)
            {
                e.month = 1;
                e.day = d;
            }
            else if(31 < d && d <=60)
            {
                e.month = 2;
                e.day = d-31;
            }
            else if(60 < d && d <= 91)
            {
                e.month = 3;
                e.day = d-60;
            }
            else if(91 < d && d <= 121)
            {
                e.month = 4;
                e.day = d-91;
            }
            else if(121 < d && d <= 152)
            {
                e.month = 5;
                e.day = d-121;
            }
            else if(152 < d && d <= 182)
            {
                e.month = 6;
                e.day = d-152;
            }
            else if(182 < d && d <= 213)
            {
                e.month = 7;
                e.day = d-182;
            }
            else if(213 < d && d <= 243)
            {
                e.month = 8;
                e.day = d-213;
            }
            else if(243 < d && d <= 274)
            {
                e.month = 9;
                e.day = d-244;
            }
            else if(274 < d && d <= 305)
            {
                e.month = 10;
                e.day = d-274;
            }
            else if(305 < d && d <=335)
            {
                e.month = 11;
                e.day = d-305;
            }
            else if(335 < d && d <=366)
            {
                e.month = 12;
                e.day = d-335;
            }
            printf("\n\t\t\t\tEmployee's Date of Birth                                              : %d/%d/%d\n",e.day,e.month,e.year);
            e.age = 2022 - e.year;
            printf("\n\t\t\t\tEmployee's Age                                                        : %d\n",e.age);

        }
        else
        {
            printf("\n\t\t\t\tEmployee's NIC Format Is Incorrect\n");
            continue;
        }
        break;
}

while(1)
{

        printf("\n\t\t\t\tEnter The Status Of The Employee(Like \"Married Or Unmarried\")         : ");
        scanf("%s",&e.status);

        if(strcmp(e.status , "Married")==0 || strcmp(e.status , "Unmarried")==0){}
        else
        {
            printf("\n\t\t\t\tYour Input Is Incorrect\n");
            continue;
        }
        break;
}

        int x,E1=0,E2=0;

while(1)
{
        printf("\n\t\t\t\tEnter The Email ID Of The Employee                                    : ");//Enter the Email Address with @ sign
        scanf("%s",&e.email);

        for(x=0;e.email[x]!='\0';x++)
        {
            if(e.email[x]=='@')
                E1=x;
            if(e.email[x]=='.')
                E2=x;
        }
        if(E1>1 && (E2-E1)>3){}
        else
        {
            printf("\n\t\t\t\tIncorrect Email ID\n");
            continue;
        }
        break;
}

        printf("\n\t\t\t\tEnter The Mobile Number Of The Employee                               : "); // Do not include the '+' sign and do not start at '0' , only include 9 numbers
        scanf("%ld",&e.mobile_no);
        printf("\n\t\t\t\tEnter The Address Of The Employee(\"District\")                         : ");
        scanf("%s",&e.address);

        printf("\n\n\t\t\t\t*********************************EMPLOYEE'S DESIGNATION CATEGORY********************************\n\n");
        printf("\n\t\t\t\t\t*Manager\t\t*AssistantManager\t\t*AccountingOfficer\n");
        printf("\n\t\t\t\t\t\t*Supervisor\t\t\t\t*Staff\n");

while(1)
{
        printf("\n\t\t\t\tEnter The Designation Of The Employee                                 : ");
        scanf("%s",&e.designation);

        if(strcmp(e.designation,"Manager")==0){}
        else if(strcmp(e.designation,"AssistantManager")==0){}
        else if(strcmp(e.designation,"AccountingOfficer")==0){}
        else if(strcmp(e.designation,"Supervisor")==0){}
        else if(strcmp(e.designation,"Staff")==0){}
        else
        {
            printf("\n\t\t\t\tEmployee's Designation Is Invalid\n");
            continue;
        }
        break;
}


        printf("\n\t\t\t\tEnter The Department Of The Employee (Like \"Dept-A\")                  : ");
        scanf("%s",&e.department);

        printf("\n\n\t\t\t\t***********************************BASIC SALARY INFORMATION*************************************\n\n");
        printf("\n\t\t\t\t\t\t\tManager\t\t\t\t:- 100001 To 120000\n");
        printf("\n\t\t\t\t\t\t\tAssistantManger\t\t\t:- 80001 To 100000\n");
        printf("\n\t\t\t\t\t\t\tAccountingOfficer\t\t:- 60001 To  80000\n");
        printf("\n\t\t\t\t\t\t\tSupervisor\t\t\t:- 50001 To 60000\n");
        printf("\n\t\t\t\t\t\t\tStaff\t\t\t\t:- 30001 To  50000\n\n");

while(1)
{
        printf("\n\t\t\t\tEnter The Basic Salary Of The Employee                                : ");
        scanf("%f",&e.basicSalary);

        if(strcmp(e.designation,"Manager")==0)
        {
            if((e.basicSalary>100000) && (e.basicSalary<=120000)){}
            else
            {
                printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                continue;
            }
        }

        else if(strcmp(e.designation,"AssistantManager")==0)
        {
            if((e.basicSalary>80000) && (e.basicSalary<=100000)){}
            else
            {
                printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                continue;
            }
        }

        else if(strcmp(e.designation,"AccountingOfficer")==0)
        {
            if((e.basicSalary>60000) && (e.basicSalary<=80000)){}
            else
            {
                printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                continue;
            }
        }

        else if(strcmp(e.designation,"Supervisor")==0)
        {
            if((e.basicSalary>50000) && (e.basicSalary<=60000)){}
            else
            {
                printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                continue;
            }
        }

        else if(strcmp(e.designation,"Staff")==0)
        {
            if((e.basicSalary>30000) && (e.basicSalary<=50000)){}
            else
            {
                printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                continue;
            }

        }
        break;
}
        if(e.basicSalary>50000)
        {
                e.allowance=(e.basicSalary*30)/100;
        }
        else
        {
                e.allowance=(e.basicSalary*25)/100;
        }
        printf("\n\t\t\t\tAllowance is                                                          : %.2f\n",e.allowance);
while(1)
{
        printf("\n\t\t\t\tEmployee Travel Mode");
        printf("\n\t\t\t\t\t\t\t1.Private Vehicle\n\t\t\t\t\t\t\t2.Public Vehicle\n");
        printf("\n\t\t\t\t\t\t\tPlease Select An Option: ");
        scanf("%d",&e.travelMode);

        switch(e.travelMode)
        {
            case 1:
                e.travelCharge = 20;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
                e.travelingAllowance = (e.travelingKilometers*20);
                printf("\n\t\t\t\tTraveling Allowance is                                                : %.2f\n",e.travelingAllowance);
                break;

            case 2:
                e.travelCharge = 15;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
                e.travelingAllowance = (e.travelingKilometers*15);
                printf("\n\t\t\t\tTraveling Allowance is                                                : %.2f\n",e.travelingAllowance);
                break;

            default:
                printf("\n\n\t\t\t\tPLEASE ENTER THE VALID OPTION\n\n");
                continue;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
        }
        break;
}

        //Tax
        if(e.basicSalary>50000)
        {
            e.Tax=(e.basicSalary*5)/100;
        }
        else
        {
            e.Tax=(e.basicSalary*0)/100;
        }
        printf("\n\t\t\t\tTax is                                                                : %.2f\n",e.Tax);

        //NetSalary of the employee
        e.netSalary = e.basicSalary + e.allowance + e.travelingAllowance - e.Tax;
        printf("\n\t\t\t\tNet Salary is                                                         : %.2f\n\n",e.netSalary);
        printf("\n\n\t\t\t\t**************************************************************************************************\n\n");

        if(fp==NULL)
        {
            printf("\n\n\n\t\t\t\tSOMETHING WENT WRONG, TRY AGAIN\n");
        }
        else
        {
            printf("\n\t\t\t\t\t\t\tEMPLOYEE DETAILS ADD SUCCESSFULLY\n");
        }
        printf("\n\n\t\t\t\t**************************************************************************************************\n\n");
        // write struct to file
        fwrite(&e,sizeof(struct Employee),1,fp); // Write all employee details to file
        fclose(fp);

        printf("\n\n\t\t\t\tDo You Want To Add Another Employee Details?(Y/N) : ");
        scanf("%s",&another);

}
    while(another=='Y' || another=='y');
}

void displayEmployee()
{
    system("cls");
    FILE *fp;
    int dataFound=0;
    struct Employee e; // Create a structure variable of Employee called e

    fp = fopen("Employee_Details.txt","r");

    if(fp==NULL)
    {
        printf("\n\n\n\t\t\t\tSOMETHING WENT WRONG, TRY AGAIN\n");
        exit(1);
    }

    printf("\n\n\t\t\t\t*********************************** DISPLAY EMPLOYEE DETAILS ***********************************\n\n");
    // read file contents till end of file
    while(fread(&e,sizeof(struct Employee),1,fp)==1)  // Read all employee details from file
    {
        dataFound=1;
        printf("\n\t\t\t\tEmployee's ID                     : %d",e.Id);
        printf("\n\t\t\t\tEmployee's FullName               : %s %s",e.firstName,e.lastName);
        printf("\n\t\t\t\tEmployee's NIC Number             : %lld",e.NICNo);
        printf("\n\t\t\t\tEmployee's Gender                 : %c",e.gender);
        printf("\n\t\t\t\tEmployee's Date of Birth          : %d/%d/%d",e.day,e.month,e.year);
        printf("\n\t\t\t\tEmployee's age                    : %d",e.age);
        printf("\n\t\t\t\tEmployee's status                 : %s",e.status);
        printf("\n\t\t\t\tEmployee's Email Address          : %s",e.email);
        printf("\n\t\t\t\tEmployee's Mobile Number          : %ld",e.mobile_no);
        printf("\n\t\t\t\tEmployee's Address                : %s",e.address);
        printf("\n\t\t\t\tEmployee's Designation            : %s",e.designation);
        printf("\n\t\t\t\tEmployee's Department             : %s",e.department);
        printf("\n\t\t\t\tEmployee's Basic Salary           : %.2f",e.basicSalary);
        printf("\n\t\t\t\tEmployee's Allowance              : %.2f",e.allowance);
        printf("\n\t\t\t\tEmployee's Traveling Kilometers   : %.2f",e.travelingKilometers);
        printf("\n\t\t\t\tEmployee's Traveling Allowance    : %.2f",e.travelingAllowance);
        printf("\n\t\t\t\tEmployee's Tax                    : %.2f",e.Tax);
        printf("\n\t\t\t\tEmployee's Net Salary             : %.2f",e.netSalary);
        printf("\n\n\t\t\t\t************************************************************************************************\n\n");
    }
//close the file
fclose(fp);

if(dataFound==0)
{
    printf("\n\t\t\t\tEMPLOYEE'S DETAILS NOT FOUND\n");
}
else
{
    printf("\n\t\t\t\t\t\t\tEMPLOYEE'S DETAILS SUCCESSFULLY DISPLAYED\n");
}

printf("\n\n\t\t\t\t************************************************************************************************\n\n\n\n");
}

void searchEmployee()
{
    system("cls");
    FILE *fp;
    struct Employee e; // Create a structure variable of Employee called e
    int Id,dataFound=0;
    char another;

do
{
    fp = fopen("Employee_Details.txt","r");

    if(fp==NULL)
    {
        printf("\n\n\n\t\t\t\tSOMETHING WENT WRONG, TRY AGAIN\n");
        exit(1);
    }

    printf("\n\n\t\t\t\t*********************************** SEARCH EMPLOYEE DETAILS ************************************\n\n");

    printf("\n\t\t\t\tEnter The Employee ID No To Search: ");
    scanf("%d",&Id);

        // read file contents till end of file
    while(fread(&e,sizeof(struct Employee),1,fp)==1)  // Read all employee details from file
    {
        if(e.Id==Id)
        {
            dataFound=1;
            printf("\n\t\t\t\tEmployee's ID                     : %d",e.Id);
            printf("\n\t\t\t\tEmployee's FullName               : %s %s",e.firstName,e.lastName);
            printf("\n\t\t\t\tEmployee's NIC Number             : %lld",e.NICNo);
            printf("\n\t\t\t\tEmployee's Gender                 : %c",e.gender);
            printf("\n\t\t\t\tEmployee's Date of Birth          : %d/%d/%d",e.day,e.month,e.year);
            printf("\n\t\t\t\tEmployee's age                    : %d",e.age);
            printf("\n\t\t\t\tEmployee's status                 : %s",e.status);
            printf("\n\t\t\t\tEmployee's Email Address          : %s",e.email);
            printf("\n\t\t\t\tEmployee's Mobile Number          : %ld",e.mobile_no);
            printf("\n\t\t\t\tEmployee's Address                : %s",e.address);
            printf("\n\t\t\t\tEmployee's Designation            : %s",e.designation);
            printf("\n\t\t\t\tEmployee's Department             : %s",e.department);
            printf("\n\t\t\t\tEmployee's Basic Salary           : %.2f",e.basicSalary);
            printf("\n\t\t\t\tEmployee's Allowance              : %.2f",e.allowance);
            printf("\n\t\t\t\tEmployee's Traveling Kilometers   : %.2f",e.travelingKilometers);
            printf("\n\t\t\t\tEmployee's Traveling Allowance    : %.2f",e.travelingAllowance);
            printf("\n\t\t\t\tEmployee's Tax                    : %.2f",e.Tax);
            printf("\n\t\t\t\tEmployee's Net Salary             : %.2f",e.netSalary);
            printf("\n\n\t\t\t\t************************************************************************************************\n\n");
            break;

        }
        else
        {
            dataFound=0;
        }
    }

    if(dataFound==1)
    {
        printf("\n\t\t\t\t\t\t\tEMPLOYEE'S DETAILS SUCCESSFULLY SEARCHED\n");

    }
    else
    {
        printf("\n\t\t\t\tEMPLOYEE'S DETAILS NOT FOUND\n");
    }

    printf("\n\n\t\t\t\t************************************************************************************************\n\n\n\n");

    //close the file
    fclose(fp);

    printf("\n\n\t\t\t\tDo You Want To Search Another Employee Details?(Y/N) : ");
    scanf("%s",&another);

}
    while(another=='Y'|| another=='y');
}

void modifyEmployee()
{
    system("cls");
    FILE *fp;
    struct Employee e; // Create a structure variable of Employee called e
    int Id,d,dataFound=0;
    char another;

    if(fp==NULL)
    {
        printf("\n\n\n\t\t\t\tSOMETHING WENT WRONG, TRY AGAIN\n");
        exit(1);
    }

do
{
    printf("\n\n\t\t\t\t*********************************** MODIFY EMPLOYEE DETAILS ************************************\n\n");

    fp = fopen("Employee_Details.txt","r+");

    printf("\n\t\t\t\tEnter The Employee ID No To Modify                                    : ");
    scanf("%d",&Id);

    while(fread(&e,sizeof(struct Employee),1,fp)==1)  // Read all employee details from file
    {
        if(Id == e.Id)
        {
            dataFound=1;
            printf("\n\n\t\t\t\t*********************************** ENTER NEW EMPLOYEE DETAILS *********************************\n\n");
            printf("\n\t\t\t\tEnter The New Employee ID                                             : ");
            scanf("%d",&e.Id);
            printf("\n\t\t\t\tEnter The New First Name Of The Employee                              : ");
            scanf("%s",&e.firstName);
            printf("\n\t\t\t\tEnter The New Last Name Of The  Employee                              : ");
            scanf("%s",&e.lastName);
            while(1)
            {
                printf("\n\t\t\t\tEnter Employee's NIC Format(Like \"New Or Old\")                        : ");
                scanf("%s",&e.nicFormat);

                if(strcmp(e.nicFormat,"New")==0)
                {
                    printf("\n\t\t\t\tEnter Employee NIC NO                                                 : ");
                    scanf("%lld",&e.NICNo);
                    int firstSevenDigit,nextThreeDigit;
                    firstSevenDigit = (e.NICNo)/100000;
                    nextThreeDigit = firstSevenDigit%1000;

                    if(nextThreeDigit > 500)
                    {
                        e.gender='F';
                        printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                        d = nextThreeDigit-500;
                    }
                    else
                    {
                        e.gender='M';
                        printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                        d = nextThreeDigit;
                    }
                    e.year = firstSevenDigit/1000;

                    if (0 < d && d <= 31)
                    {
                        e.month = 1;
                        e.day = d;
                    }
                    else if(31 < d && d <=60)
                    {
                        e.month = 2;
                        e.day = d-31;
                    }
                    else if(60 < d && d <= 91)
                    {
                        e.month = 3;
                        e.day = d-60;
                    }
                    else if(91 < d && d <= 121)
                    {
                        e.month = 4;
                        e.day = d-91;
                    }
                    else if(121 < d && d <= 152)
                    {
                        e.month = 5;
                        e.day = d-121;
                    }
                    else if(152 < d && d <= 182)
                    {
                        e.month = 6;
                        e.day = d-152;
                    }
                    else if(182 < d && d <= 213)
                    {
                        e.month = 7;
                        e.day = d-182;
                    }
                    else if(213 < d && d <= 244)
                    {
                        e.month = 8;
                        e.day = d-213;
                    }
                    else if(244 < d && d <= 274)
                    {
                        e.month = 9;
                        e.day = d-244;
                    }
                    else if(274 < d && d <= 305)
                    {
                        e.month = 10;
                        e.day = d-274;
                    }
                    else if(305 < d && d <=335)
                    {
                        e.month = 11;
                        e.day = d-305;
                    }
                    else if(335 < d && d <=366)
                    {
                        e.month = 12;
                        e.day = d-335;
                    }
                    printf("\n\t\t\t\tEmployee's Date of Birth                                              : %d/%d/%d\n",e.day,e.month,e.year);
                    e.age = 2022 - e.year;
                    printf("\n\t\t\t\tEmployee's Age                                                        : %d\n",e.age);

                }
                else if(strcmp(e.nicFormat,"Old")==0)
                {
                    printf("\n\t\t\t\tEnter Employee NIC No \"Don't Use The Text Format\"                     : ");
                    scanf("%lld",&e.NICNo);
                    int firstFiveDigit,nextThreeDigit;
                    firstFiveDigit = (e.NICNo)/10000;
                    nextThreeDigit = firstFiveDigit%1000;

                    if(nextThreeDigit > 500)
                    {
                        e.gender = 'F';
                        printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                        d = nextThreeDigit-500;
                    }
                    else
                    {
                        e.gender = 'M';
                        printf("\n\t\t\t\tEmployee's Gender Is                                                  : %c\n",e.gender);
                        d = nextThreeDigit;
                    }
                    e.year = firstFiveDigit/1000 + 1900;

                    if (0 < d && d <= 31)
                    {
                        e.month = 1;
                        e.day = d;
                    }
                    else if(31 < d && d <=60)
                    {
                        e.month = 2;
                        e.day = d-31;
                    }
                    else if(60 < d && d <= 91)
                    {
                        e.month = 3;
                        e.day = d-60;
                    }
                    else if(91 < d && d <= 121)
                    {
                        e.month = 4;
                        e.day = d-91;
                    }
                    else if(121 < d && d <= 152)
                    {
                        e.month = 5;
                        e.day = d-121;
                    }
                    else if(152 < d && d <= 182)
                    {
                        e.month = 6;
                        e.day = d-152;
                    }
                    else if(182 < d && d <= 213)
                    {
                        e.month = 7;
                        e.day = d-182;
                    }
                    else if(213 < d && d <= 243)
                    {
                        e.month = 8;
                        e.day = d-213;
                    }
                    else if(243 < d && d <= 274)
                    {
                        e.month = 9;
                        e.day = d-244;
                    }
                    else if(274 < d && d <= 305)
                    {
                        e.month = 10;
                        e.day = d-274;
                    }
                    else if(305 < d && d <=335)
                    {
                        e.month = 11;
                        e.day = d-305;
                    }
                    else if(335 < d && d <=366)
                    {
                        e.month = 12;
                        e.day = d-335;
                    }
                    printf("\n\t\t\t\tEmployee's Date of Birth                                              : %d/%d/%d\n",e.day,e.month,e.year);
                    e.age = 2022 - e.year;
                    printf("\n\t\t\t\tEmployee's Age                                                        : %d\n",e.age);

                }
                else
                {
                    printf("\n\t\t\t\tEmployee's NIC Format Is Incorrect\n");
                    continue;
                }
                break;
            }

            while(1)
            {
                printf("\n\t\t\t\tEnter The Status Of The Employee(Like \"Married Or Unmarried\")         : ");
                scanf("%s",&e.status);

                if(strcmp(e.status , "Married")==0 || strcmp(e.status , "Unmarried")==0){}
                else
                {
                    printf("\n\t\t\t\tYour Input Is Incorrect\n");
                    continue;
                }
                break;
            }

            int x,E1=0,E2=0;

            while(1)
            {
                printf("\n\t\t\t\tEnter The Email ID Of The Employee                                    : ");//Enter the Email Address with @ sign
                scanf("%s",&e.email);

                for(x=0;e.email[x]!='\0';x++)
                {
                    if(e.email[x]=='@')
                        E1=x;
                    if(e.email[x]=='.')
                        E2=x;
                }
                if(E1>1 && (E2-E1)>3){}
                else
                {
                    printf("\n\t\t\t\tIncorrect Email ID\n");
                    continue;
                }
                break;
            }

            printf("\n\t\t\t\tEnter The Mobile Number Of The Employee                               : "); // Do not include the '+' sign and do not start at '0' , only include 9 numbers
            scanf("%ld",&e.mobile_no);
            printf("\n\t\t\t\tEnter The Address Of The Employee(\"District\")                         : ");
            scanf("%s",&e.address);

            printf("\n\n\t\t\t\t*********************************EMPLOYEE'S DESIGNATION CATEGORY********************************\n\n");
            printf("\n\t\t\t\t\t*Manager\t\t*AssistantManager\t\t*AccountingOfficer\n");
            printf("\n\t\t\t\t\t\t*Supervisor\t\t\t\t*Staff\n");

        while(1)
        {
            printf("\n\t\t\t\tEnter The Designation Of The Employee                                 : ");
            scanf("%s",&e.designation);

            if(strcmp(e.designation,"Manager")==0){}
            else if(strcmp(e.designation,"AssistantManager")==0){}
            else if(strcmp(e.designation,"AccountingOfficer")==0){}
            else if(strcmp(e.designation,"Supervisor")==0){}
            else if(strcmp(e.designation,"Staff")==0){}
            else
            {
                printf("\n\t\t\t\tEmployee's Designation Is Invalid\n");
                continue;
            }
            break;
        }


        printf("\n\t\t\t\tEnter The Department Of The Employee (Like \"Dept-A\")                  : ");
        scanf("%s",&e.department);

        printf("\n\n\t\t\t\t***********************************BASIC SALARY INFORMATION*************************************\n\n");
        printf("\n\t\t\t\t\t\t\tManager\t\t\t\t:- 100001 To 120000\n");
        printf("\n\t\t\t\t\t\t\tAssistantManger\t\t\t:- 80001 To 100000\n");
        printf("\n\t\t\t\t\t\t\tAccountingOfficer\t\t:- 60001 To  80000\n");
        printf("\n\t\t\t\t\t\t\tSupervisor\t\t\t:- 50001 To 60000\n");
        printf("\n\t\t\t\t\t\t\tStaff\t\t\t\t:- 30001 To  50000\n\n");

        while(1)
        {
            printf("\n\t\t\t\tEnter The Basic Salary Of The Employee                                : ");
            scanf("%f",&e.basicSalary);

            if(strcmp(e.designation,"Manager")==0)
            {
                if((e.basicSalary>100000) && (e.basicSalary<=120000)){}
                else
                {
                    printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                    continue;
                }
            }

            else if(strcmp(e.designation,"AssistantManager")==0)
            {
                if((e.basicSalary>80000) && (e.basicSalary<=100000)){}
                else
                {
                    printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                    continue;
                }
            }

            else if(strcmp(e.designation,"AccountingOfficer")==0)
            {
                if((e.basicSalary>60000) && (e.basicSalary<=80000)){}
                else
                {
                    printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                    continue;
                }
            }

            else if(strcmp(e.designation,"Supervisor")==0)
            {
                if((e.basicSalary>50000) && (e.basicSalary<=60000)){}
                else
                {
                    printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                    continue;
                }
            }

            else if(strcmp(e.designation,"Staff")==0)
            {
                if((e.basicSalary>30000) && (e.basicSalary<=50000)){}
                else
                {
                    printf("\n\t\t\t\tEmployee's Basic Salary Is Incorrect\n");
                    continue;
                }

            }
            break;
        }
        if(e.basicSalary>50000)
        {
                e.allowance=(e.basicSalary*30)/100;
        }
        else
        {
                e.allowance=(e.basicSalary*25)/100;
        }
        printf("\n\t\t\t\tAllowance is                                                          : %.2f\n",e.allowance);
    while(1)
    {
        printf("\n\t\t\t\tEmployee Travel Mode");
        printf("\n\t\t\t\t\t\t\t1.Private Vehicle\n\t\t\t\t\t\t\t2.Public Vehicle\n");
        printf("\n\t\t\t\t\t\t\tPlease Select An Option: ");
        scanf("%d",&e.travelMode);

        switch(e.travelMode)
        {
            case 1:
                e.travelCharge = 20;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
                e.travelingAllowance = (e.travelingKilometers*20);
                printf("\n\t\t\t\tTraveling Allowance is                                                : %.2f\n",e.travelingAllowance);
                break;

            case 2:
                e.travelCharge = 15;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
                e.travelingAllowance = (e.travelingKilometers*15);
                printf("\n\t\t\t\tTraveling Allowance is                                                : %.2f\n",e.travelingAllowance);
                break;

            default:
                printf("\n\n\t\t\t\tPLEASE ENTER THE VALID OPTION\n\n");
                continue;
                printf("\n\t\t\t\tEnter The Traveling Kilometers Of The Employee                        : ");
                scanf("%f",&e.travelingKilometers);
        }
        break;
    }

        //Tax
        if(e.basicSalary>50000)
        {
            e.Tax=(e.basicSalary*5)/100;
        }
        else
        {
            e.Tax=(e.basicSalary*0)/100;
        }
        printf("\n\t\t\t\tTax is                                                                : %.2f\n",e.Tax);

        //NetSalary of the employee
        e.netSalary = e.basicSalary + e.allowance + e.travelingAllowance - e.Tax;
        printf("\n\t\t\t\tNet Salary is                                                         : %.2f\n\n",e.netSalary);
        printf("\n\n\t\t\t\t**************************************************************************************************\n\n");
        fseek(fp,-sizeof(struct Employee),SEEK_CUR); //Sets the details pointer to the beginning of the details
        fwrite(&e,sizeof(struct Employee),1,fp); // Write all employee details to file
        rewind(fp);//sets the file pointer to the beginning of the file
        break;
    }
    }

    if(dataFound==1)
    {
        printf("\n\t\t\t\t\t\t\tEMPLOYEE'S DETAILS SUCCESSFULLY MODIFIED\n");
    }
    else
    {
        printf("\n\t\t\t\tEMPLOYEE'S DETAILS NOT FOUND\n");
    }

    printf("\n\n\t\t\t\t************************************************************************************************\n\n\n\n");
    fclose(fp);

    printf("\n\n\t\t\t\tDo You Want To Modify Another Employee Details?(Y/N) : ");
    scanf("%s",&another);

}
    while(another=='Y'|| another=='y');
}

void deleteEmployee()
{
    system("cls");
    FILE *fp,*ft;
    struct Employee e; // Create a structure variable of Employee called e
    int Id,dataFound=0;
    char another;

    printf("\n\n\t\t\t\t*********************************** DELETE EMPLOYEE DETAILS ************************************\n\n");
    fp = fopen("Employee_Details.txt","r");
    ft = fopen("Temp.txt","a"); // create a intermediate file for temporary storage

    printf("\n\t\t\t\tEnter The Employee ID To Be Deleted   : ");
    scanf("%d",&Id);

    if(fp==NULL)
    {
        printf("\n\n\n\t\t\t\tSOMETHING WENT WRONG, TRY AGAIN\n");
        exit(1);
    }

    while(fread(&e,sizeof(struct Employee),1,fp)==1)  // Read all employee details from file
    {
            if(e.Id==Id)
            {
                dataFound=1;
            }
            else
            {
                fwrite(&e,sizeof(struct Employee),1,ft); // Write all employee details to file
            }
    }
    fclose(fp);
    fclose(ft);

    remove("Employee_Details.txt"); // Remove the Original File
    rename("Temp.txt","Employee_Details.txt"); // Rename the Temp File to Original File Name

    if(dataFound==1)
    {
        printf("\n\t\t\t\tEMPLOYEE'S DETAILS SUCCESSFULLY DELETED\n");
    }
    else
    {
        printf("\n\t\t\t\tEMPLOYEE'S DETAILS NOT FOUND\n");
    }

    printf("\n\n\t\t\t\t************************************************************************************************\n\n\n\n");
}
