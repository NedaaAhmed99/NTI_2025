#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include"student.h"
#include"help.h"
#define MaxNo_Students 6
extern std_t School_students[MaxNo_Students];
extern u32 NoOfStudents;
extern u32 NumberOF_vacancies;

int main()
{

    char ch;

    printWelcome();
    loadStudentsFromFile();
    setColor(15);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t=================> Welcome!\n\n\t\t\t\t\t\t\t\t\t=================> Would you like some help navigating the system(y/n)?");
    fflush(stdin);
    scanf("%c",&ch);
    setColor(15);
    u32 choice, count;
    while(1)
    {

        if(ch=='y'||ch=='Y')
        {
            system("cls");
            while (1)
            {
                students_options();
                u8 name[100];
                u8 click;
                u32 id;
                setColor(15);
                printf("\t\t\t\t\t\t\t\t\t=================> Please select the option you would like to proceed with(1-9):");
                fflush(stdin);
                scanf("%d",&choice);
                setColor(15);
                if(choice>0&&choice<12)
                {

                    switch (choice)
                    {
                    case 1:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        while(1)
                        {
                            u8 ch;
                            if(student_Add()==0)
                            {
                                setColor(15);

                                printf("\n\n\n\t\t\t\t\t\t\t\t\t===============>You want to Add Another student?(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    if(NoOfStudents<MaxNo_Students)
                                        continue;
                                    else
                                    {
                                        printf("\t\t\t\t\t\t\t\t\t---------------->Sorry! All places are Full\n");
                                        setColor(15);
                                        printf("\n\n\n\t\t\t\t\t\t\t\t\t===============>You want return to main options?(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            system("cls");
                                            break;
                                        }
                                        else
                                        {
                                            printf("\n\n\n\n\n\n\n\n\n\n");
                                            system("cls");
                                            exit(0);
                                        }
                                    }
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t---------------->Sorry! All places are Full\n");
                                setColor(15);
                                printf("\n\n\n\t\t\t\t\t\t\t\t\t===============>You want return to main options?(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    //saveStudentsToFile();
                                    system("cls");
                                    exit(0);
                                }
                            }



                        }


                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        while(1)
                        {
                            setColor(15);
                            printf("\n\t\t\t\t\t\t\t\t\t----------------> For Search\n:");
                            printf("\n\t\t\t\t\t\t\t\t\t                  Enter Full Name:");
                            fflush(stdin);
                            scanf("%s",&name);
                            setColor(15);
                            u32 indx=student_SearchBy_Name(name);
                            if(indx!=-1)
                            {
                                setColor(6);
                                printf("\n\t\t\t\t\t\t\t\t\t                  Student is registered \n");
                                setColor(15);
                                printf("\n\t\t\t\t\t\t\t\t\t----------------> you want to show student data!(y/n):");
                                setColor(15);
                                fflush(stdin);
                                scanf(" %c",&ch);
                                if(ch=='y'||ch=='Y')
                                {
                                    setColor(6);
                                    student_print(School_students[indx]);
                                    setColor(15);
                                    printf("\n\t\t\t\t\t\t\t\t\t----------------> you want another search!(y/n):");
                                    fflush(stdin);
                                    scanf(" %c",&ch);
                                    setColor(15);
                                    if(ch=='y'||ch=='Y')
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        system("cls");
                                        break;
                                    }
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }
                            else
                            {
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                 Student Not Registered Before\n");

                                setColor(15);
                                printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want another search!(y/n):");
                                fflush(stdin);
                                scanf(" %c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }

                        }
                        system("cls");
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        while(1)
                        {
                            setColor(15);
                            printf("\n\t\t\t\t\t\t\t\t\t----------------> For Search By ID\n:");
                            printf("\n\t\t\t\t\t\t\t\t\t                  Enter Id:");
                            fflush(stdin);
                            scanf("%d",&id);
                            setColor(15);
                            u32 indx=student_SearchBy_Id(id);
                            if(indx!=-1)
                            {
                                setColor(6);
                                printf("\n\t\t\t\t\t\t\t\t\t                  Student is registered\n");
                                setColor(15);
                                printf("\n\t\t\t\t\t\t\t\t\t----------------> you want to show student data!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                if(ch=='y'||ch=='Y')
                                {
                                    setColor(6);
                                    student_print(School_students[indx]);
                                    setColor(15);
                                    printf("\n\t\t\t\t\t\t\t\t\t----------------> you want another search!(y/n):");
                                    fflush(stdin);
                                    scanf("%c",&ch);
                                    setColor(15);
                                    if(ch=='y'||ch=='Y')
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        system("cls");
                                        break;
                                    }
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }
                            else
                            {
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                 Student Not Registered Before\n");

                                setColor(15);
                                printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want another search!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }

                        }
                        system("cls");
                        break;

                    }
                    case 4:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");

                        while(1)
                        {
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t----------------> To delete student By name:\n");
                            printf("\t\t\t\t\t\t\t\t\t                  Enter Name :");
                            scanf("%s",&name);
                            setColor(15);
                            if(student_DeleteBy_Name(name)==1)
                            {
                                saveStudentsToFile();
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                  student Deleted\n");
                                setColor(15);
                                printf("\n\t\t\t\t\t\t\t\t\t----------------> you want to Delete Another Student!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else if(ch=='n'||ch=='N')
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    fflush(stdin);
                                    setColor(4);
                                    printf("\n\t\t\t\t\t\t\t\t\t                  Not Correct enter\n");
                                    printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                                    fflush(stdin);
                                    scanf("%c",&ch);
                                    setColor(15);
                                    if(ch=='y'||ch=='Y')
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        system("cls");
                                        break;
                                    }

                                }

                            }
                            else
                            {
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                  This Name Not Registered Before\n");
                                setColor(15);
                                printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want to Delete Another Student!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }

                        }
                        system("cls");
                        break;
                    }
                    case 5:
                    {

                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");

                        while(1)
                        {
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t----------------> To delete student By Id:\n");
                            printf("\t\t\t\t\t\t\t\t\t----------------> Enter Id:");
                            scanf("%d",&id);
                            setColor(15);
                            if(student_DeleteBy_Id(id)==1)
                            {
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                  student Deleted\n");
                                setColor(15);
                                printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Delete Another Student!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }

                            }
                            else
                            {
                                setColor(6);
                                printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                setColor(15);
                                printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Delete Another Student!(y/n):");
                                fflush(stdin);
                                scanf("%c",&ch);
                                setColor(15);
                                if(ch=='y'||ch=='Y')
                                {
                                    continue;
                                }
                                else
                                {
                                    system("cls");
                                    break;
                                }
                            }

                        }
                        system("cls");
                        break;

                    }

                    case 6:
                    {
                        u32 choice;
                        while(1)
                        {
                            system("cls");
                            setColor(15);
                            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t===================================================================================\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t=                          Update OPTIONS USING NAME                                    =\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n");
                            setColor(2);
                            printf("\n\t\t\t\t\t\t\t\t\t                  1. Update Student Name:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  2. Update Student Age:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  3. Update Student Adress:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  4. Update Student Phone:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  5. Return To main options Page:\n");
                            setColor(6);
                            printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t----------------> Choose Update Type(1-5) :");

                            scanf("%d",&choice);
                            switch(choice)
                            {
                            case 1:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter Your ID for Update:");
                                    scanf("%d",&id);
                                    if(student_EditName_usingID(id)==1)
                                    {
                                        saveStudentsToFile();
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Name updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }

                            case 2:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter Your Name for edit:");
                                    scanf("%s",&name);
                                    if(student_EditAge_usingName(name)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Age updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This Name Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }

                            case 3:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter Your Name for edit:");
                                    scanf("%s",&name);
                                    if(student_EditAdress_usingName(name)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Adress updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This Name Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter your Name for edit:");
                                    scanf("%s",&name);
                                    if(student_EditPhone_usingName(name)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Phone updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This Name Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }
                            case 5:
                            {
                                system("cls");
                                break;

                            }
                            }
                            if(choice==5)
                            {
                                system("cls");
                                break;
                            }

                        }

                        if(choice==5)
                        {
                            system("cls");
                            break;
                        }


                    }
                    case 7:
                    {
                        u32 choice;
                        while(1)
                        {
                            system("cls");
                            setColor(15);
                            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t===================================================================================\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t=                           Update OPTIONS USING ID                                     =\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n");
                            setColor(2);
                            printf("\n\t\t\t\t\t\t\t\t\t                  1. Update Student Name:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  2. Update Student Age:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  3. Update Student Adress:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  4. Update Student Phone:\n");
                            printf("\n\t\t\t\t\t\t\t\t\t                  5. Return To main options Page:\n");
                            setColor(6);
                            printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n");
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t----------------> Choose Update Type :");

                            scanf("%d",&choice);
                            switch(choice)
                            {
                            case 1:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter your Id for Update:");
                                    scanf("%d",&id);
                                    if(student_EditName_usingID(id)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Name updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }

                            case 2:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter your Id for edit:");
                                    scanf("%d",&id);
                                    if(student_EditAge_usingID(id)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Age updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To Update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }

                            case 3:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter your Id for edit:");
                                    scanf("%d",&id);
                                    if(student_EditAdress_usingID(id)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Adress updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\n\n\n\n");
                                while(1)
                                {
                                    setColor(15);
                                    printf("\t\t\t\t\t\t\t\t\t----------------> Enter your Id for edit:");
                                    scanf("%d",&id);
                                    if(student_EditPhone_usingID(id)==1)
                                    {

                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                    Student Phone updated successfully\n");
                                        setColor(15);
                                        printf("\n\t\t\t\t\t\t\t\t\t----------------> you want To update Another student !(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }


                                    }
                                    else
                                    {
                                        setColor(6);
                                        printf("\t\t\t\t\t\t\t\t\t                  This ID Not Registered Before\n");
                                        setColor(15);
                                        printf("\n\n\t\t\t\t\t\t\t\t\t----------------> you want To update Another student!(y/n):");
                                        fflush(stdin);
                                        scanf("%c",&ch);
                                        setColor(15);
                                        if(ch=='y'||ch=='Y')
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            system("cls");
                                            break;
                                        }
                                    }

                                }

                                system("cls");
                                break;
                            }
                            case 5:
                            {
                                system("cls");
                                break;

                            }
                            }
                            if(choice==5)
                            {
                                system("cls");
                                break;
                            }

                        }

                        if(choice==5)
                        {
                            system("cls");
                            break;
                        }


                    }

                    case 8:
                    {

                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        student_printAll(School_students,NoOfStudents);
                        setColor(15);
                        printf("\n\n\n\t\t\t\t\t\t\t\t\t---------------->you want to return to main options:(y/n):");
                        fflush(stdin);
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='y')
                        {
                            system("cls");
                            break;
                        }
                        else if (ch=='n'||ch=='n')
                        {
                            saveStudentsToFile();
                            exit(0);
                        }
                        else
                        {
                            fflush(stdin);
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                            fflush(stdin);
                            scanf("%c",&ch);
                            if(ch=='y'||ch=='y')
                            {
                                system("cls");
                                break;
                            }
                            else
                            {
                                saveStudentsToFile();
                                exit(0);
                            }


                        }

                        break;

                    }
                    case 9:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        Students_bubbleSort(School_students,NoOfStudents);
                        setColor(15);
                        printf("\n\n\n\t\t\t\t\t\t\t\t\t---------------->you want to return to main options:(y/n):");
                        fflush(stdin);
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='y')
                        {
                            system("cls");
                            break;
                        }
                        else if (ch=='n'||ch=='n')
                        {
                            saveStudentsToFile();
                            exit(0);
                        }
                        else
                        {
                            fflush(stdin);
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                            fflush(stdin);
                            scanf("%c",&ch);
                            if(ch=='y'||ch=='y')
                            {
                                system("cls");
                                break;
                            }
                            else
                            {
                                saveStudentsToFile();
                                exit(0);
                            }


                        }

                        break;

                    }
                    case 10:
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n");
                        student_printAll(School_students,NoOfStudents);
                        setColor(15);
                        printf("\n\n\n\t\t\t\t\t\t\t\t\t---------------->you want to return to main options:(y/n):");
                        fflush(stdin);
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='y')
                        {
                            system("cls");
                            break;
                        }
                        else if (ch=='n'||ch=='n')
                        {
                            saveStudentsToFile();
                            exit(0);
                        }
                        else
                        {
                            fflush(stdin);
                            setColor(15);
                            printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                            fflush(stdin);
                            scanf("%c",&ch);
                            if(ch=='y'||ch=='y')
                            {
                                system("cls");
                                break;
                            }
                            else
                            {
                                saveStudentsToFile();
                                exit(0);
                            }


                        }

                        break;

                    }

                    case 11:
                    {
                        saveStudentsToFile();
                        exit(0);
                    }

                    default:
                    {
                        setColor(2);
                        printf("\t\t\t\t\t\t\t\t\t                  Contact with the responsible 0115464\n");
                        fflush(stdin);
                        setColor(15);
                        printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                        fflush(stdin);
                        scanf("%c",&ch);
                        if(ch=='y'||ch=='y')
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            saveStudentsToFile();
                            exit(0);
                        }


                    }
                    }
                }
                else if(choice>=12)
                {
                    setColor(4);
                    printf("\n\t\t\t\t\t\t\t\t\t                  Not Correct enter\n");
                    printf("\t\t\t\t\t\t\t\t\t                  Try Again(y/n):");
                    fflush(stdin);
                    scanf("%c",&ch);
                    setColor(15);

                    if(ch=='N'||ch=='n')
                    {
                        setColor(6);
                        printf("\n\t\t\t\t\t\t\t\t\t                  You Are Welcom thanks for contat\n\n ");
                        exit(0);
                        setColor(15);
                        break;
                    }
                    else if(ch=='Y'||ch=='y')
                    {
                        continue;
                    }

                }
                else
                {
                    exit(0);
                }
            }

        }
        else if(ch=='n'||ch=='N')
        {
            setColor(6);
            printf("\n\t\t\t\t\t\t\t\t\t                  You Are Welcom thanks for contat\n\n ");
            exit(0);
            setColor(15);
            break;

        }
        else
        {
            fflush(stdin);
            setColor(4);
            while(1)
            {
                printf("\n\t\t\t\t\t\t\t\t\t                  Not Correct enter\n");
                printf("\t\t\t\t\t\t\t\t\t                    Try Again(y/n):");
                fflush(stdin);
                scanf("%c",&ch);
                if(ch=='y'||ch=='y')
                {
                    system("cls");
                    break;
                }
                else if(ch=='N'||ch=='n')
                {
                    exit(0);
                }
                else
                {
                    continue;
                }

            }
            continue;
            setColor(15);

        }

    }


    saveStudentsToFile();
    return 0;
}
