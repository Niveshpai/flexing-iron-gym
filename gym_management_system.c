/*
            _                             _
           | |                           | |
         =H| |========mn=======nm========| |H=
           |_|        ( \     / )        |_|
                       \ )(")( /
                       ( /\_/\ )
                        \     /
                         )=O=(
                        /  _  \
                       /__/ \__\
                       | |   | |
                       |_|   |_|
                       (_)   (_)
         =============FLEXING IRON GYM=========
*/

/*=============================================================================
 |   Project:  Gym Management System
 |
 |       Author:  Sujay , Aryan, Shreedhar and Nivesh.
 |     Language:  The program is written using "C" language.
 |                          The compiler used is GNU/GCC and the IDE used is CodeBlocks.
 |
 |   To Compile:  Build and run the code. On the output screen, enter the password to open a window
 |                           where all the functions can be used.
 |        Class:  Data Structure & Algorithms Lab
 |
 |   Instructor:  Mr. Prakash Hegade
 |     Due Date:  27-02-2021
 |
 +-----------------------------------------------------------------------------------------------------------------------------------+
 |
 |  Description: Gym Management System is designed for the purpose of
 |                         adding records in a gym. In this project, the user as well as
 |                         owner can store records depending on various categories.
 |                         The user can add, edit, view, delete records of the members of the gym.
 |
 |    Input:  Adding the details of the gym members.
 |
 |     Output:  Displays Gym details, packages, staff members, shortest distance to all branches of the gym.
 |
 |    Algorithm:  Brute force String search, Binary Search, Insertion Sort, Dijikstra algorithm, files and structures.
 |
 *=============================================================================*/

#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

#define GYMNAME "FLEXING IRON GYM"
#define OWNER "Bryan Dobson"
#define MANAGER "Hunter Labrada"
#define ADDRESS1 "360 Hampton drive Venice, CA"
#define CONTACT1 "910-364-8609"
#define TIMINGS1 "Monday to Saturday, From 6:00 AM to 10:00 PM"
#define TIMINGS2 "Sunday, From 7:00AM to 9:00PM"
#define PACKAGE1 "03-Months"
#define PACKAGE2 "06-Months"
#define PACKAGE3 "12-Months"

#define ADDRESS2 "257 Green Street Venice, CA"
#define CONTACT2 "910-364-8611"

#define ADDRESS3 "310 George Street Venice, CA"
#define CONTACT3 "910-364-8627"

#define ADDRESS4 "508 Marrison Garden Venice, CA"
#define CONTACT4 "910-364-8643"

#define ADDRESS5 "451 Split Arena Venice, CA"
#define CONTACT5 "910-364-8675"

/// We are going to define some global variables which works throughout the program.
/// We have used a password variable such that the admin is able to access sensitive data.

int staff_count=0;
int member_count=0;
int path_calculate=0;
int dist[5],sv,visited[5];
int weight[5][5]={0,2,5,5,11,2,0,999,4,999,5,999,0,999,3,5,4,999,0,3,11,999,3,3,0};
void Password();
char password[20]={"DSA3A-T2"};

/*
Structure Name: GYMSTAFF
Input Params: --NIL--
Description:  Data types are used to declare the variables of the gym staff.
*/
struct GYMSTAFF
{
    char name[30];
    int age;
    char designation[20];
    int salary;
};

/*
Structure Name: GYMMEMBER
Input Params: --NIL--
Description:  Data types are used to declare the variables of the gym members.
*/

struct GYMMEMBER
{
    char name[30];
    long long int phnum;
    int age;
    int weight;
    int height;
    char type[12];
    char joindate[12];
    char lastdate[12];
};

struct Gym
{
    struct GYMSTAFF staff[20];
    struct GYMMEMBER member[50];
};
/// We use typedef to reserve the keyword GYM throughout the program.
typedef struct Gym GYM;

GYM g;

/*function declarations*/

///We have declared a set of functions to be used in the program.
void load_gym_details(GYM *);
void load_staff_details(GYM *);
void load_member_details(GYM *);
void mainmenu();
void display_gym_details();
void display_gym_packages();
void display_all_staff(GYM );
void display_all_members(GYM );
void display_shortest_distance();
int minimum(int ,int );
int mindist(int [],int [],int );
void sort_members_by_age_(GYM *);
void add_new_member(GYM *);
int entry_new_member(GYM *,int );
void search_member_and_display_details(GYM );
void search_staff_and_display_details(GYM );
int search_staff_by_name_to_display_details(GYM ,char []);
int search_staff_by_age_to_display_details(GYM ,int );
int search_staff_by_salary_to_display_details(GYM ,int );
int search_staff_by_designation_to_display_details(GYM ,char []);
int search_member_by_name_to_display_details(GYM ,char []);
int search_member_by_age_to_display_details(GYM ,int );
int search_member_by_phone_to_display_details(GYM ,long long int );
int search_member_by_package_to_display_details(GYM ,char []);


int main()
{
    Password();
    load_gym_details(&g);
    mainmenu();
    getch();
    return 0;

}

/*
Function Name: load_gym_details
Input Params: --NIL--
Return Type:  void
Description:  It loads the details of the staff and members of the gym.
*/
void load_gym_details(GYM *g)
{

   load_staff_details(g);
   load_member_details(g);

}

/*
Function Name: load_staff_details
Input Params: Scans the details of the staff from the file.
Return Type:  void
Description:  It loads and scans the details of the staff from the input file.
*/
void load_staff_details(GYM *g)
{
    FILE *fp;
///Please specify the appropriate staff details text file.
    fp = fopen("D:/3rd SEM/DSA/Gym files/staffDetails.txt","r");

    if(fp == NULL)
    {
        printf("Oops!,failed to load staff details\n");
        exit(0);
    }

    while(!feof(fp))
    {
        fscanf(fp,"%d\t%d\t%s\t %[^\n]s",&g->staff[staff_count].age,&g->staff[staff_count].salary,g->staff[staff_count].designation,g->staff[staff_count].name);

        staff_count++;
    }

    fclose(fp);
    //for(int i=0;i<staff_count;i++)
    //    printf("%s\t%d\t%s\t%d\n",g->staff[staff_count].name,g->staff[staff_count].age,g->staff[staff_count].designation,g->staff[staff_count].salary);
}

/*
Function Name: load_member_details
Input Params: Scans the details of the members from the file.
Return Type:  void
Description:  It loads and scans the details of the members from the input file.
*/
void load_member_details(GYM *g)
{
    FILE *fp;
///Please specify the appropriate member details text file.
    fp = fopen("D:/3rd SEM/DSA/Gym files/memberDetails.txt","r");

    if(fp == NULL)
    {
        printf("Oops!,failed to load member details\n");
        exit(0);
    }

    while(!feof(fp))
    {
fscanf(fp,"%d%d%d%lld%s%s%s %[^\n]s",&g->member[member_count].age,&g->member[member_count].weight,&g->member[member_count].height,&g->member[member_count].phnum,g->member[member_count].joindate,g->member[member_count].lastdate,g->member[member_count].type,g->member[member_count].name);

        member_count++;
    }
}

/*
Function Name: mainmenu
Input Params: --NIL---
Return Type:  void
Description:  The primary list of options that is displayed on the screen to be selected by the user.
*/
void mainmenu()
{
    system("cls");
    sort_members_by_age_(&g);
    while(1)
    {

    printf("\n\n\n\t\t\t\t|========== Welcome to %s ==========|\n\n\n",GYMNAME);
    printf("\t\t\t\t\t|MAIN MENU|\n\n");
    printf("\t\t\t\t<1> Display Gym details\n");
    printf("\t\t\t\t<2> Display Gym packages\n");
    printf("\t\t\t\t<3> Display Staff members\n");
    printf("\t\t\t\t<4> Display Gym members\n");
    printf("\t\t\t\t<5> Display shortest distance to all branches of the Gym\n");
    printf("\t\t\t\t<6> Search Gym staff\n");
    printf("\t\t\t\t<7> Search Gym members\n");
    printf("\t\t\t\t<8> Add a new Gym member\n");
    printf("\t\t\t\t<9> Close Application\n\n");
    printf("\t\t\t\tEnter your choice : \n");

    switch(getch())
    {
        case '1':
                    display_gym_details();
                    break;
        case '2':
                    display_gym_packages();
                    break;
        case '3':
                    display_all_staff(g);
                    break;
        case '4':
                    display_all_members(g);
                    break;
        case '5':
                    display_shortest_distance();
                    break;
        case '6':
                    search_staff_and_display_details(g);
                    break;
        case '7':
                    search_member_and_display_details(g);
                    break;
        case '8':
                    add_new_member(&g);
                    break;
        case '9':
                    printf("\n\n\t\t\t\t\t***** Closing application , THANK YOU! *****\n\n\n");
                    exit(0);
                    break;
        default :
                    printf("\n\n\t\t\t\tYou have entered an invalid choice,please re-enter a valid choice\n");
                    for(int i=0;i<210;i++)
                    printf("-");
    }

    }
}

/*
Function Name: sort_members_by_age_
Input Params: --NIL---
Return Type:  void
Description:  The gym members are sorted in ascending order based on their respective age.
*/
void sort_members_by_age_(GYM *g)
{
    int i,j;
    struct GYMMEMBER temp;
    for(i=1;i<=member_count-1;i++)
    {
        temp=g->member[i];
        j=i-1;
        while(j>=0 && g->member[j].age>temp.age)
        {
            g->member[j+1]=g->member[j];
            j=j-1;
        }
        g->member[j+1]=temp;
    }
}

/*
Function Name: display_gym_details
Input Params: --NIL---
Return Type:  void
Description:  Displays the details of the gym which includes branch details, owner name,  manager name, address, contact and timings.
*/
void display_gym_details()
{
    int flag=0;

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo display Gym main branch details, press 1");
        printf("\n\t\t\t\tTo display 2nd Gym branch details, press 2");
        printf("\n\t\t\t\tTo display 3rd Gym branch details, press 3");
        printf("\n\t\t\t\tTo display 4th Gym branch details, press 4");
        printf("\n\t\t\t\tTo display 5th Gym branch details, press 5");
        printf("\n\t\t\t\tTo display all Gym branch details, press 6");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 7 to return to main menu\n");


        switch(getch())
        {
             case '1':

                        printf("\n\t\t\t\tGym main branch details :\n");

                        printf("\n\t\t\t\tGym owner name : %s",OWNER);

                        printf("\n\t\t\t\tGym manager name : %s",MANAGER);

                        printf("\n\t\t\t\tGym address : %s",ADDRESS1);

                        printf("\n\t\t\t\tGym contact : %s",CONTACT1);

                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);

                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        flag=1;
                        break;
            case '2':
                        printf("\n\t\t\t\tGym 2nd branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS2);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT2);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        flag=1;
                        break;

            case '3' :
                        printf("\n\t\t\t\tGym 3rd branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS3);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT3);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        flag=1;
                        break;

            case '4' :
                        printf("\n\t\t\t\tGym 4th branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS4);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT4);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        flag=1;
                        break;

            case '5':
                        printf("\n\t\t\t\tGym 5th branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS5);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT5);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        flag=1;
                        break;

            case '6':
                        printf("\n\t\t\t\tGym main branch details :\n");

                        printf("\n\t\t\t\tGym owner name : %s",OWNER);

                        printf("\n\t\t\t\tGym manager name : %s",MANAGER);

                        printf("\n\t\t\t\tGym address : %s",ADDRESS1);

                        printf("\n\t\t\t\tGym contact : %s",CONTACT1);

                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);

                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        printf("\n\t\t\t\tGym 2nd branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS2);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT2);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);


                        printf("\n\t\t\t\tGym 3rd branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS3);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT3);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        printf("\n\t\t\t\tGym 4th branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS4);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT4);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

                        printf("\n\t\t\t\tGym 5th branch details :\n");
                        printf("\n\t\t\t\tGym address : %s",ADDRESS5);
                        printf("\n\t\t\t\tGym contact : %s",CONTACT5);
                        printf("\n\t\t\t\tGym timings 1 : %s",TIMINGS1);
                        printf("\n\t\t\t\tGym timings 2 : %s\n\n",TIMINGS2);

            case '7':
                        flag=1;
                        break;

            default :
                        printf("\n\t\t\t\tYour choice is incorrect! re-enter your choice\n");
                        break;
        }
    }

    printf("\n");
    for(int i=0;i<210;i++)
        printf("-");

}

/*
Function Name: display_gym_packages
Input Params: --NIL---
Return Type:  void
Description:  Displays the details of the gym which includes branch details, owner name,  manager name, address, contact and timings.
*/
void display_gym_packages()
{

    printf("\n\t\t\t\tGym Packages are as follows:\n");

    printf("\n\t\t\t\tPackage 1 : %s",PACKAGE1);

    printf("\n\t\t\t\tPackage 2 : %s",PACKAGE2);

    printf("\n\t\t\t\tPackage 3 : %s\n",PACKAGE3);

    for(int i=0;i<210;i++)
        printf("-");
}

/*
Function Name: mindist
Input Params: --NIL---
Return Type:  int
Description:  Displays the minimum distance between gym centres.
*/
int mindist(int dist[5],int visited[5],int n)
{
    int min,i=0,j=0;

    for(i=0;i<n;i++)
    {
        if(visited[i]!=1)
        {
            min=i;
            break;
        }
    }
    for(j=0;j<n;j++)
    {
        if(visited[j]==0&&dist[j]<dist[min])
        {
            min=j;
        }
    }
    return min;
}


int minimum(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

/*
Function Name: display_shortest_distance
Input Params: --NIL---
Return Type:  void
Description:  Displays the shortest distance between the gym centres with respect to the metric unit, kilometres.
*/
void display_shortest_distance()
{
    int i,j,u,n=5;
    if(path_calculate==0)
    {
    sv=0;

    for(i=0;i<n;i++)
    {
      dist[i]=weight[sv][i];
      if(i==sv)
      {
          visited[sv]=1;
      }
      else
        visited[i]=0;
    }

    for(i=0;i<n;i++)
    {
        u = mindist(dist,visited,n);
        visited[u]=1;
        for(j=0;j<n;j++)
           {
               if(visited[j]==0)
               {
                   dist[j]=minimum(dist[j],(weight[u][j]+dist[u]));
               }
           }

    }
      path_calculate=1;
      for(i=1;i<n;i++)
      {
         if(i+1==2)
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %dnd branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
         else if(i+1==3)
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %drd branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
         else
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %dth branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
      }

    }

    else
    {
       for( i=1;i<n;i++)
        {
         if(i+1==2)
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %dnd branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
         else if(i+1==3)
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %drd branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
         else
         {
              printf("\n\t\t\t\tShortest distance from main branch of Gym to %dth branch of Gym is %d kilometers\n",i+1,dist[i]);
         }
      }
    }
}

/*
Function Name: display_all_staff
Input Params: --NIL---
Return Type:  void
Description:  Displays the staff details i.e name, age, designation and salary. We can also
                        display only the total number of staff, staff names only and/or their complete details.
*/
void display_all_staff(GYM g)
{
    int flag=0;

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo display total number of staff, press 0");
        printf("\n\t\t\t\tTo display all staff names only, press 1");
        printf("\n\t\t\t\tTo display all staff complete details, press 2\n");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 3 to return to main menu\n");


        switch(getch())
        {
             case '0':
                        printf("\n\t\t\t\tThere are %d staffs",staff_count);
                        flag=1;
                        break;
            case '1':
                        for(int i=0;i<staff_count;i++)
                        printf("\n\t\t\t\t%d.%s",i+1,g.staff[i].name);
                        flag=1;
                        break;

            case '2':
                        printf("\n\tNAME\t\tAGE\tDESIGNATION\tSALARY\n\n");
                        for(int i=0;i<staff_count;i++)
                            printf("\t%s\t%d\t%s\t\t%d\n",g.staff[i].name,g.staff[i].age,g.staff[i].designation,g.staff[i].salary);
                        flag=1;
                        break;

            case '3':
                        flag=1;
                        break;

            default :
                        printf("\n\t\t\t\tYour choice is incorrect! re-enter your choice\n");
                        break;
        }
    }

    printf("\n");
    for(int i=0;i<210;i++)
        printf("-");

}

/*
Function Name: display_all_members
Input Params: --NIL---
Return Type:  void
Description:  Displays the member details i.e name, age, designation and salary. We can also
                        display only the total number of members, member names only and/or their complete details.
*/
void display_all_members(GYM g)
{
    int flag=0;

    while(flag!=1)
    {
         printf("\n\t\t\t\tTo display total number of members in the gym, press 0");
        printf("\n\t\t\t\tTo display all gym member names only, Press 1");
        printf("\n\t\t\t\tTo display all gym member complete details, Press 2");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 3 to return to main menu\n\n");

        switch(getch())
        {
            case '0':

                        printf("\n\t\t\t\tThere are %d members in the Gym",member_count);

                        flag=1;
                        break;
            case '1':
                        for(int i=0;i<member_count;i++)
                            printf("\n\t\t\t\t%d.%s",i+1,g.member[i].name);

                        flag=1;
                        break;

            case '2':
                        printf("Name\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n\n");
                        for(int i=0;i<member_count;i++)
                                printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[i].name,g.member[i].age,g.member[i].weight,g.member[i].height,g.member[i].phnum,g.member[i].type,g.member[i].joindate,g.member[i].lastdate);

                        flag=1;
                        break;

            case '3':
                        flag=1;
                        break;

            default :
                        printf("\n\t\t\t\tYour choice is incorrect! re-enter your choice\n");
                        break;
        }
    }

    printf("\n");
    for(int i=0;i<210;i++)
        printf("-");

}

/*
Function Name: search_staff_and_display_details
Input Params: name, age, salary, designation
Return Type:  void
Description:  Based on user input option, the staff details are displayed. Also we can search based on only
                        age, designation, salary and/or complete details using name.
*/
void search_staff_and_display_details(GYM g)
{
    int flag=0,j=-1,age,salary;
    char p[100];

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo search staff name and display details, Press 1");
        printf("\n\t\t\t\tTo search staff age and display details, Press 2");
        printf("\n\t\t\t\tTo search staff designation and display details, Press 3");
        printf("\n\t\t\t\tTo search staff salary and display details, Press 4\n");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 5 to return to main menu\n");

        switch(getch())
        {
            case '1':
                        printf("\n\t\t\t\tEnter name to search : ");
                        scanf(" %[^\n]s",p);

                        j=search_staff_by_name_to_display_details(g,p);

                          if(j==-1)
                            {
                                printf("\n\t\t\t\tStaff not found!\n");
                            }

                        flag=1;
                        break;

            case '2':
                        printf("\n\t\t\t\tEnter the age : ");
                        scanf("%d",&age);

                        j=search_staff_by_age_to_display_details(g,age);

                         if(j==-1)
                            {
                                printf("\n\t\t\t\tStaff with age %d not found!\n",age);
                            }
                        flag=1;
                        break;

            case '3':
                        printf("\n\t\t\t\tEnter designation to search : ");
                        scanf(" %[^\n]s",p);

                        j=search_staff_by_designation_to_display_details(g,p);

                          if(j==-1)
                            {
                                printf("\n\t\t\t\tDesignation not found!\n");
                            }

                        flag=1;
                        break;

            case '4':
                        printf("\n\t\t\t\tEnter the salary : ");
                        scanf("%d",&salary);

                        j=search_staff_by_salary_to_display_details(g,salary);
                            /*
                         if(j==-1)
                            {
                                printf("\n\t\t\t\tThere is no staff with %s salary\n",salary);
                            }*/
                        flag=1;
                        break;

            case '5':
                        flag=1;
                        break;

            default : printf("\n\t\t\t\tYour choice is incorrect! re-enter your choice\n");
                        break;
        }
    }

    printf("\n");
    for(int i=0;i<210;i++)
        printf("-");
}

/*
Function Name: search_member_and_display_details
Input Params: name, age, package, contact number
Return Type:  void
Description:  Based on user input option, the member details are displayed. Also we can search based on only
                        age, package, contact number and/or complete details using name.
*/
void search_member_and_display_details(GYM g)
{
    int flag=0,j=-1,age;
    char p[100];
    long long int num;

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo search member name and display details, Press 1");
        printf("\n\t\t\t\tTo search member age and display details, Press 2");
        printf("\n\t\t\t\tTo search member package and display details, Press 3");
        printf("\n\t\t\t\tTo search member contact number and display details, Press 4\n");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 5 to return to main menu\n");

        switch(getch())
        {
            case '1':
                        printf("\n\t\t\t\tEnter name to search : ");
                        scanf(" %[^\n]s",p);

                        j=search_member_by_name_to_display_details(g,p);

                          if(j==-1)
                            {
                                printf("\n\t\t\t\tMember not found!\n");
                            }

                        flag=1;
                        break;

            case '2':
                        printf("\n\t\t\t\tEnter the age : ");
                        scanf("%d",&age);

                        j=search_member_by_age_to_display_details(g,age);

                         if(j==-1)
                            {
                                printf("\n\t\t\t\tThere is no member with age %d\n",age);
                            }
                        flag=1;
                        break;

            case '3':
                        printf("\n\t\t\t\tEnter number of months in package, to search : ");
                        scanf(" %[^\n]s",p);

                        j=search_member_by_package_to_display_details(g,p);

                          if(j==-1)
                            {
                                printf("\n\t\t\t\tThere is no member with %s-months package\n",p);
                            }

                        flag=1;
                        break;

            case '4':
                        printf("\n\t\t\t\tEnter the contact number : ");
                        scanf("%lld",&num);

                        j=search_member_by_phone_to_display_details(g,num);

                         if(j==-1)
                            {
                                printf("\n\t\t\t\tMember with contact number %lld not found\n",num);
                            }
                        flag=1;
                        break;

            case '5':
                        flag=1;
                        break;

            default : printf("\n\t\t\t\tYour choice is incorrect! re-enter your choice\n");
                        break;
        }
    }

    printf("\n");
    for(int i=0;i<210;i++)
        printf("-");
}

/*
Function Name: search_staff_by_name_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a staff by his/her name and display the details i.e name, age, designation and salary
*/
int search_staff_by_name_to_display_details(GYM g,char p[])
{
    int i,j,k=0,n,m,flag=-1,h=0;

    n=strlen(g.staff[k].name);
    m=strlen(p);


    while(k<staff_count)
    {
        for(i=0;i<=n-m;i++)
        {
            j=0;
            while(j<m&&p[j]==g.staff[k].name[i+j])
            {
                j++;
            }

            if (j==m)
            {
                printf("\n\tNAME\t\tAGE\tDESIGNATION\tSALARY\n\n");
                printf("\t%s\t%d\t%s\t\t%d\n",g.staff[k].name,g.staff[k].age,g.staff[k].designation,g.staff[k].salary);
                flag=0;
                k++;
                h=1;
            }
             n=strlen(g.staff[k].name);
        }
           if(h!=1)
        {
            k++;
        }
        h=0;
    }
    if(flag==0)
    {
       return flag;
    }
    else
    {
            return -1;
    }
}

/*
Function Name: search_staff_by_age_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a staff by his/her age and display the details i.e name, age, designation and salary
*/
int search_staff_by_age_to_display_details(GYM g,int a)
{
    int i,flag=-1;

    for(i=0;i<staff_count;i++)
    {
        if(g.staff[i].age==a)
        {
           printf("\n\tNAME\t\tAGE\tDESIGNATION\tSALARY\n\n");
           printf("\t%s\t%d\t%s\t\t%d\n",g.staff[i].name,g.staff[i].age,g.staff[i].designation,g.staff[i].salary);
           flag=1;
        }
    }

    if(flag==1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/*
Function Name: search_staff_by_designation_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a staff by his/her designation and display the details i.e name, age, designation and salary
*/
int search_staff_by_designation_to_display_details(GYM g,char p[])
{
    int i,j,k=0,n,m,flag=-1,h=0;

    n=strlen(g.staff[k].designation);
    m=strlen(p);

    while(k<staff_count)
    {
        for(i=0;i<=n-m;i++)
        {
            j=0;
            while(j<m&&p[j]==g.staff[k].designation[i+j])
            {
                j++;
            }

            if (j==m)
            {
                printf("\n\tNAME\t\tAGE\tDESIGNATION\tSALARY\n\n");
                printf("\t%s\t%d\t%s\t\t%d\n",g.staff[k].name,g.staff[k].age,g.staff[k].designation,g.staff[k].salary);
                flag=0;
                k++;
                h=1;
            }
             n=strlen(g.staff[k].designation);
        }
        if(h!=1)
        {
            k++;
        }
        h=0;
    }
    if(flag==0)
    {
        return flag;
    }
    else
    {
        return -1;
    }
}

/*
Function Name: search_staff_by_salary_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a staff by his/her salary and display the details i.e name, age, designation and salary
*/
int search_staff_by_salary_to_display_details(GYM g,int amt)
{
    int i,flag=-1;

    for(i=0;i<staff_count;i++)
    {
        if(g.staff[i].salary==amt)
        {
           printf("\n\tNAME\t\tAGE\tDESIGNATION\tSALARY\n\n");
           printf("\t%s\t%d\t%s\t\t%d\n",g.staff[i].name,g.staff[i].age,g.staff[i].designation,g.staff[i].salary);
           flag=1;
        }
    }

    if(flag==1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/*
Function Name: search_member_by_name_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a member by his/her name and display the details i.e name, age, designation and salary
*/
int search_member_by_name_to_display_details(GYM g,char p[])
{
    int i,j,k=0,n,m,flag=-1,h=0;

    n=strlen(g.member[k].name);
    m=strlen(p);


    while(k<member_count)
    {
        for(i=0;i<=n-m;i++)
        {
            j=0;
            while(j<m&&p[j]==g.member[k].name[i+j])
            {
                j++;
            }

            if (j==m)
            {
                printf("\nName\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n");
                printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[k].name,g.member[k].age,g.member[k].weight,g.member[k].height,g.member[k].phnum,g.member[k].type,g.member[k].joindate,g.member[k].lastdate);

                flag=0;
                k++;
                h=1;
            }
             n=strlen(g.member[k].name);
        }
           if(h!=1)
        {
            k++;
        }
        h=0;
    }
    if(flag==0)
    {
       return flag;
    }
    else
    {
            return -1;
    }
}

/*
Function Name: search_member_by_age_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a member by his/her age and display the details i.e name, age, designation and salary
*/
int search_member_by_age_to_display_details(GYM g,int a)
{
    int i,flag=-1,beg=0,end,mid,tempmid;
    end=member_count-1;

    printf("%d",end);
    while(beg<=end)
    {
        mid=(beg+end)/2;
        tempmid=mid;
        if(a==g.member[mid].age)
        {
            printf("\nName\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n");
                printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[mid].name,g.member[mid].age,g.member[mid].weight,g.member[mid].height,g.member[mid].phnum,g.member[mid].type,g.member[mid].joindate,g.member[mid].lastdate);

            while(a==g.member[++tempmid].age)
            {
                printf("\nName\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n");
printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[tempmid].name,g.member[tempmid].age,g.member[tempmid].weight,g.member[tempmid].height,g.member[tempmid].phnum,g.member[tempmid].type,g.member[tempmid].joindate,g.member[tempmid].lastdate);

            }
            return 1;
        }
        else if(a<g.member[mid].age)
            end=mid-1;
        else
            beg=mid+1;


    }

    if(flag==-1)
    {
        return -1;
    }

}

/*
Function Name: search_member_by_package_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a member by his/her package and display the details i.e name, age, designation and salary
*/
int search_member_by_package_to_display_details(GYM g,char p[])
{
    int i,j,k=0,n,m,flag=-1,h=0;

    n=strlen(g.member[k].type);
    m=strlen(p);


    while(k<member_count)
    {
        for(i=0;i<=n-m;i++)
        {
            j=0;
            while(j<m&&p[j]==g.member[k].type[i+j])
            {
                j++;
            }

            if (j==m)
            {
                printf("\nName\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n");
                printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[k].name,g.member[k].age,g.member[k].weight,g.member[k].height,g.member[k].phnum,g.member[k].type,g.member[k].joindate,g.member[k].lastdate);

                flag=0;
                k++;
                h=1;
            }
             n=strlen(g.member[k].type);
        }
           if(h!=1)
        {
            k++;
        }
        h=0;
    }
    if(flag==0)
    {
       return flag;
    }
    else
    {
            return -1;
    }
}

/*
Function Name: search_member_by_phone_to_display_details
Input Params: --NIL--
Return Type:  int
Description:   Function to search a member by his/her phone number and display the details i.e name, age, designation and salary
*/
int search_member_by_phone_to_display_details(GYM g,long long int num)
{
    int i,flag=-1;

    for(i=0;i<member_count;i++)
    {
        if(g.member[i].phnum==num)
        {
            printf("\nName\t\tAge\tWeight\tHeight\tNumber\t\tMembership\tJoin date\tLast date\n");
            printf("%s\t%d\t%d\t%d\t%lld\t%s\t%s\t%s\n",g.member[i].name,g.member[i].age,g.member[i].weight,g.member[i].height,g.member[i].phnum,g.member[i].type,g.member[i].joindate,g.member[i].lastdate);
            flag=1;
        }
    }

    if(flag==1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/*
Function Name: add_new_member
Input Params: number of members for admission
Return Type:  void
Description: This function is used to take the input of members admitting for the Gym.
*/
void add_new_member(GYM *g)
{
    int n,flag;

    printf("\n\t\t\t\tEnter the number of members for admission : ");
    scanf("%d",&n);

    flag=entry_new_member(g,n);

    if(flag==1)
    {
        printf("\n\t\t\t\tAdmission sucessfull\n");
    }
    else
    {
        printf("\n\t\t\t\tError admission\n");
    }
    for(int i=0;i<210;i++)
        printf("-");
}

/*
Function Name: entry_new_member
Input Params: age, weight, height, phone number, package type, joining date, expiry date
Return Type:  int
Description: This function is used to take the input of details of members (age, weight, height, phone number, package type) admitting for the Gym.
                     Also the joining date and expiry date of the membership is inputted
*/
int entry_new_member(GYM *g,int n)
{
    int i,ch;

    FILE *fp;

    fp=fopen("D:/3rd SEM/DSA/Gym files/memberDetails.txt","a");    ///fp=fopen("D:/c program kle tech/DS Files/files LP.Q.no.8.txt","w");

    if(fp==NULL)
    {
        printf("Error! opening the file\n");
        return -1;
    }

    for(int i=0;i<n;i++)
    {
      member_count++;

      if(i==n-1)
      {
            printf("\n\t\t\t\t\tEnter the details of member %d\n",i+1);

            if(n==1)
            fprintf(fp,"\n");

            printf("\n\t\t\t\tEnter the age\n\t\t\t\t");
            scanf("%d",&g->member[member_count].age);
            fprintf(fp,"%d\t",g->member[member_count].age);

            printf("\n\t\t\t\tEnter the weight in kilograms\n\t\t\t\t");
            scanf("%d",&g->member[member_count].weight);
            fprintf(fp,"%d\t",g->member[member_count].weight);

            printf("\n\t\t\t\tEnter the Height in centimeters\n\t\t\t\t");
            scanf("%d",&g->member[member_count].height);
            fprintf(fp,"%d\t",g->member[member_count].height);

            printf("\n\t\t\t\tEnter Phone number\n\t\t\t\t");
            scanf("%lld",&g->member[member_count].phnum);
            fprintf(fp,"%lld\t",g->member[member_count].phnum);

            printf("\n\t\t\t\tEnter the membership type\n\t\t\t\t1 - for 03-months\n\t\t\t\t2 - for 06-months\n\t\t\t\t3 - for 12-months\n\t\t\t\t");
            scanf("%d",&ch);
            if(ch==1)
            {
                strcpy(g->member[member_count].name,PACKAGE1);
                fprintf(fp,"%s\t",PACKAGE1);
            }

            else if(ch==2)
            {
                strcpy(g->member[member_count].name,PACKAGE2);
                fprintf(fp,"%s\t",PACKAGE2);
            }
            else
            {
                strcpy(g->member[member_count].name,PACKAGE3);
                fprintf(fp,"%s\t",PACKAGE3);
            }

            printf("\n\t\t\t\tEnter the joining date as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].joindate);
            fprintf(fp,"%s\t",g->member[member_count].joindate);

            printf("\n\t\t\t\tEnter the expiry date of gym membership as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].lastdate);
            fprintf(fp,"%s\t",g->member[member_count].lastdate);

            printf("\n\t\t\t\tEnter the name\n\t\t\t\t");
            scanf(" %[^\n]s",g->member[member_count].name);
            fprintf(fp," %s",g->member[member_count].name);

        }

        else
        {
            printf("\n\t\t\t\t\tEnter the details of member %d\n",i+1);

            fprintf(fp,"\n");

            printf("\n\t\t\t\tEnter the age\n\t\t\t\t");
            scanf("%d",&g->member[member_count].age);
            fprintf(fp,"%d\t",g->member[member_count].age);

            printf("\n\t\t\t\tEnter the weight in kilograms\n\t\t\t\t");
            scanf("%d",&g->member[member_count].weight);
            fprintf(fp,"%d\t",g->member[member_count].weight);

            printf("\n\t\t\t\tEnter the Height in centimeters\n\t\t\t\t");
            scanf("%d",&g->member[member_count].height);
            fprintf(fp,"%d\t",g->member[member_count].height);

            printf("\n\t\t\t\tEnter Phone number\n\t\t\t\t");
            scanf("%lld",&g->member[member_count].phnum);
            fprintf(fp,"%lld\t",g->member[member_count].phnum);

            printf("\n\t\t\t\tEnter the membership type\n\t\t\t\t1 - for 03-months\n\t\t\t\t2 - for 06-months\n\t\t\t\t3 - for 12-months\n\t\t\t\t");
            scanf("%d",&ch);
            if(ch==1)
            {
                strcpy(g->member[member_count].name,PACKAGE1);
                fprintf(fp,"%s\t",PACKAGE1);
            }

            else if(ch==2)
            {
                strcpy(g->member[member_count].name,PACKAGE2);
                fprintf(fp,"%s\t",PACKAGE2);
            }

            else
            {
           strcpy(g->member[member_count].name,PACKAGE3);
            fprintf(fp,"%s\t",PACKAGE3);
            }

            printf("\n\t\t\t\tEnter the joining date as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].joindate);
            fprintf(fp,"%s\t",g->member[member_count].joindate);

            printf("\n\t\t\t\tEnter the expiry date of gym membership as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].lastdate);
            fprintf(fp,"%s\t",g->member[member_count].lastdate);

            printf("\n\t\t\t\tEnter the name\n\t\t\t\t");
            scanf(" %[^\n]s",g->member[member_count].name);
            fprintf(fp," %s\n",g->member[member_count].name);
        }

    }

    fclose(fp);

    return 1;
}

/*
Function Name: Password
Input Params: --NIL--
Return Type:  void
Description: This function is used to secure the login page using a password. A password is preset,
                      and when the user logins, the options window is displayed.
*/
void Password(void)
{
system("cls");
char d[25]="Password Protected";
char ch,pass[20];
int i=0,j;

printf(" _____ _           _                            \n");
printf("|  ___| | _____  _(_)_ __   __ _        \n");
printf("| |_  | |/ _ \\ \\/ / | '_ \\ / _` |                    \n");
printf("|  _| | |  __/>  <| | | | | (_| |                   \n");
printf("|_|   |_|\\___/_/\\_\\_|_| |_|\\__, |              \n");
printf("                           |___/                       \n");

printf(" ___             \n");
printf("|_ _|_ __ ___  _ __  \n");
printf(" | || '__/ _ \\| '_ \\  \n");
printf(" | || | | (_) | | | | \n");
printf("|___|_|  \\___/|_| |_| \n");

printf("  ____        \n");
printf(" / ___|_   _ _ __ ___  \n");
printf("| |  _| | | | '_ ` _ \\   \n");
printf("| |_| | |_| | | | | | | \n");
printf(" \\____|\\__, |_| |_| |_|  \n");
printf("       |___/             \n");


	printf("\t \n\n\n Enter Password:");
while(ch!=13)
{
ch=getch();
if(ch!=13 && ch!=8)
{
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

printf("\n\n\n\t\tPassword matched!!");
printf("\n\n\tPress any key to countinue.....");
getch();
mainmenu();
}
else
{
printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
getch();
Password();
}
}
