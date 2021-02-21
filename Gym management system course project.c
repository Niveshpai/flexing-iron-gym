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
#define ADDRESS "360 Hampton drive Venice, CA"
#define CONTACT "910-364-8659"
#define TIMINGS "From 6:00 AM to 10:00 PM"
#define PACKAGE1 "03-Months"
#define PACKAGE2 "06-Months"
#define PACKAGE3 "12-Months"



int staff_count=0;
int member_count=0;

struct GYMSTAFF
{
    char name[30];
    int age;
    char designation[20];
    int salary;
};

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

struct GYM
{
    struct GYMSTAFF staff[20];
    struct GYMMEMBER member[50];
};

typedef struct GYM gym;

gym g;

/*function declarations*/

void load_gym_details(gym *);
void load_staff_details(gym *);
void load_member_details(gym *);
void mainmenu();
void display_gym_details();
void display_gym_packages();
void display_all_staff(gym );
void display_all_members(gym );
void add_new_member(gym *);
int entry_new_member(gym *,int );
void search_member_and_display_details(gym );
void search_staff_and_display_details(gym );
int search_staff_by_name_to_display_details(gym ,char []);
int search_staff_by_age_to_display_details(gym ,int );
int search_staff_by_salary_to_display_details(gym ,int );
int search_staff_by_designation_to_display_details(gym ,char []);
int search_member_by_name_to_display_details(gym ,char []);
int search_member_by_age_to_display_details(gym ,int );
int search_member_by_phone_to_display_details(gym ,long long int );
int search_member_by_package_to_display_details(gym ,char []);

int main()
{

    load_gym_details(&g);
    mainmenu();

    return 0;

}

void load_gym_details(gym *g)
{

   load_staff_details(g);
   load_member_details(g);

}

void load_staff_details(gym *g)
{
    FILE *fp;

    fp = fopen("D:/Gym files/staffDetails.txt","r");

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

void load_member_details(gym *g)
{
    FILE *fp;

    fp = fopen("D:/Gym files/memberDetails.txt","r");

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

void mainmenu()
{
    while(1)
    {

    printf("\n\n\n\t\t\t\t|========== Welcome to %s ==========|\n\n\n",GYMNAME);
    printf("\t\t\t\t\t|MAIN MENU|\n\n");
    printf("\t\t\t\t<1> Display Gym details\n");
    printf("\t\t\t\t<2> Display Gym packages\n");
    printf("\t\t\t\t<3> Display Staff members\n");
    printf("\t\t\t\t<4> Display Gym members\n");
    printf("\t\t\t\t<5> Search Gym staff\n");
    printf("\t\t\t\t<6> Search Gym members\n");
    printf("\t\t\t\t<7> Add a new Gym member\n");
    printf("\t\t\t\t<8> Close Application\n\n");
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
                    search_staff_and_display_details(g);
                    break;
        case '6':
                    search_member_and_display_details(g);
                    break;
        case '7':
                    add_new_member(&g);
                    break;
        case '8':
                    printf("\n\n\t\t\t\t\t***** Closing application , THANK YOU! *****\n\n\n");
                    exit(0);
                    break;
        default :
                    printf("\n\n\t\t\t\tYou have entered an invalid choice,please re-enter a valid choice\n");
                    for(int i=0;i<120;i++)
                    printf("-");
    }

    }
}

void display_gym_details()
{

    printf("\n\t\t\t\tGym details :\n");

    printf("\n\t\t\t\tGym owner name : %s",OWNER);

    printf("\n\t\t\t\tGym manager name : %s",MANAGER);

    printf("\n\t\t\t\tGym address : %s",ADDRESS);

    printf("\n\t\t\t\tGym contact : %s",CONTACT);

    printf("\n\t\t\t\tGym timings : %s\n\n",TIMINGS);

    for(int i=0;i<120;i++)
        printf("-");
}

void display_gym_packages()
{

    printf("\n\t\t\t\tGym Packages are as follows:\n");

    printf("\n\t\t\t\tPackage 1 : %s",PACKAGE1);

    printf("\n\t\t\t\tPackage 2 : %s",PACKAGE2);

    printf("\n\t\t\t\tPackage 3 : %s\n",PACKAGE3);


    for(int i=0;i<120;i++)
        printf("-");
}

void display_all_staff(gym g)
{
    int flag=0;

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo display all staff names only press 1");
        printf("\n\t\t\t\tTo display all staff complete details press 2\n");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 3 to return to main menu\n");


        switch(getch())
        {
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
    for(int i=0;i<120;i++)
        printf("-");

}

void display_all_members(gym g)
{
    int flag=0;

    while(flag!=1)
    {
        printf("\n\t\t\t\tTo display all gym member names only, Press 1");
        printf("\n\t\t\t\tTo display all gym member complete details, Press 2\n");
        printf("\n\t\t\t\tIf you accidentally pressed this choice, Press 3 to return to main menu\n");


        switch(getch())
        {
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
    for(int i=0;i<120;i++)
        printf("-");

}

void search_staff_and_display_details(gym g)
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

                         if(j==-1)
                            {
                                printf("\n\t\t\t\tThere is no staff with %s salary\n",salary);
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
    for(int i=0;i<120;i++)
        printf("-");
}

void search_member_and_display_details(gym g)
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
    for(int i=0;i<120;i++)
        printf("-");
}

int search_staff_by_name_to_display_details(gym g,char p[])
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

int search_staff_by_age_to_display_details(gym g,int a)
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

int search_staff_by_designation_to_display_details(gym g,char p[])
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

int search_staff_by_salary_to_display_details(gym g,int amt)
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

int search_member_by_name_to_display_details(gym g,char p[])
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

int search_member_by_age_to_display_details(gym g,int a)
{
    int i,flag=-1;

    for(i=0;i<member_count;i++)
    {
        if(g.member[i].age==a)
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

int search_member_by_package_to_display_details(gym g,char p[])
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

int search_member_by_phone_to_display_details(gym g,long long int num)
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

void add_new_member(gym *g)
{
    int n,flag;

    printf("\n\t\t\t\tEnter the number of members for admission :\t");
    scanf("%d",&n);

    flag=entry_new_member(g,n);

    if(flag==1)
    {
        printf("\n\t\t\t\tAdmission successful\n");
    }
    else
    {
        printf("\n\t\t\t\tError admission\n");
    }
    for(int i=0;i<120;i++)
        printf("-");
}

int entry_new_member(gym *g,int n)
{
    int i,ch;

    FILE *fp;

    fp=fopen("D:/Gym files/memberDetails.txt","a");    ///fp=fopen("D:/c program kle tech/DS Files/files LP.Q.no.8.txt","w");

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

            printf("\n\t\t\t\tEnter the joining date as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].joindate);
            fprintf(fp,"%s\t",g->member[member_count].joindate);

            printf("\n\t\t\t\tEnter the expiry date of gym membership as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].lastdate);
            fprintf(fp,"%s\t",g->member[member_count].lastdate);

            printf("\n\t\t\t\tEnter the membership type\n1 - for 03-months\n2 - for 06-months\n3 - for 12-months\n\t\t\t\t");
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

            printf("\n\t\t\t\tEnter the joining date as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].joindate);
            fprintf(fp,"%s\t",g->member[member_count].joindate);

            printf("\n\t\t\t\tEnter the expiry date of gym membership as (dd/mm/yyyy)\n\t\t\t\t");
            scanf("%s",g->member[member_count].lastdate);
            fprintf(fp,"%s\t",g->member[member_count].lastdate);

            printf("\n\t\t\t\tEnter the membership type\n1 - for 03-months\n2 - for 06-months\n3 - for 12-months\n\t\t\t\t");
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

            printf("\n\t\t\t\tEnter the name\n\t\t\t\t");
            scanf(" %[^\n]s",g->member[member_count].name);
            fprintf(fp," %s\n",g->member[member_count].name);
        }

    }

    fclose(fp);

    return 1;
}
