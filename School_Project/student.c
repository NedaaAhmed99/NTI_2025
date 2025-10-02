#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "student.h"
#include"help.h"

#define MaxNo_Students 6
std_t School_students[MaxNo_Students];
u32 NoOfStudents=0;
u32 Students_Deleted_IDs[MaxNo_Students];  //array of Deleted Id in array School_students
u32 NumberOF_vacancies=0;   //Number of deleted places in array School_students
u32 All_Registerd_std;

u32 No_Of_Student(void)
{
    u32 All_Registerd_std=NoOfStudents-NumberOF_vacancies;
    return All_Registerd_std;
}
u8 student_Add(void)
{
    std_t s;
    if(NoOfStudents<MaxNo_Students||NumberOF_vacancies>0)
    {
        setColor(15);
        printf("\n\t\t\t\t\t\t\t\t\t----------------> To Add Student:\n");
        setColor(6);
        for(int i=0; i<3; i++)
        {
            printf("\t\t\t\t\t\t\t\t\t                 Enter Name:");
            fflush(stdin);
            scanf("%s",&s.name);
            if(check_Name(s.name,string_len(s.name)))
            {
                break;
            }
            else
            {
               if(i>2)
               {
                    exit(0);

               }


                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);
            }
        }

        for(int i=0; i<3; i++)
        {
            printf("\t\t\t\t\t\t\t\t\t                 Enter Age:");
            scanf("%d",&s.age);
            if(s.age>0&&s.age<100)
            {
                break;
            }
            else
            {
                if(i>2)
                    exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);

            }

        }
        fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t                 Enter Adress:");
        scanf("%s",&s.adress);

         for(int i=0; i<3; i++)
        {
            fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t                 Enter phone number (11 digits):");
        scanf("%s",&s.phone);
            if(check_Phone(s.phone,string_len(s.phone)))
            {
                break;
            }
            else
            {
               if(i>2)
                exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);
            }
        }
        if(NoOfStudents<MaxNo_Students)
        {
            s.Id=NoOfStudents+1;
            School_students[NoOfStudents]=s;
            NoOfStudents++;
            printf("\t\t\t\t\t\t\t\t\t                 Your ID:%d\n",s.Id);
            setColor(15);
            saveStudentsToFile();

            return 0;  //exist places
        }
        else if(NumberOF_vacancies>0&&NoOfStudents==MaxNo_Students)
        {

            s.Id=Students_Deleted_IDs[NumberOF_vacancies-1];
            --NumberOF_vacancies;
            printf("\t\t\t\t\t\t\t\t\t                 Your ID:%d\n",s.Id);
            School_students[s.Id-1]=s;
            saveStudentsToFile();
            setColor(15);

            return 0;  //exist places

        }
        else
        {
            saveStudentsToFile();
            return 1; //No places
        }


    }

    else
    {

        return 1; //No places
    }



}


u32 student_SearchBy_Name(u8p std_name) //if student exist return index else return -1
{
    u32 i;
    for(i=0; i<NoOfStudents; i++)
    {
        if(string_compareNotCaseSensetive(std_name,School_students[i].name)==1)
            return i;
    }
    return -1;
}

u32 student_SearchBy_Id(u32 std_id) //if student exist return index else return -1
{
    u32 i;

    for(i=0; i<NoOfStudents; i++)
    {

        if(School_students[i].Id==std_id)
        {

            return i;

        }

    }

    return -1;
}

u8 student_DeleteBy_Name(u8p std_name)
{
    u32 stu_indx=student_SearchBy_Name(std_name);
    if(stu_indx==-1)
    {
        return -1;
    }
    else
    {

        Students_Deleted_IDs[NumberOF_vacancies]=School_students[stu_indx].Id;  //index=student_id
        NumberOF_vacancies++;
        strcpy(School_students[stu_indx].name,"-1"); // أو استخدام علامة خاصة
        strcpy(School_students[stu_indx].adress,"-1");
        strcpy(School_students[stu_indx].phone,"-1");
        School_students[stu_indx].age = 0;
        School_students[stu_indx].Id = 0; // أو قيمة غير منطقية

        saveStudentsToFile();
        return 1;    //student deletes
    }

}

u8 student_DeleteBy_Id(u32 std_Id)
{

    u32 stu_indx=student_SearchBy_Id(std_Id);
    if(stu_indx==-1)
    {
        return -1;
    }
    else
    {


        Students_Deleted_IDs[NumberOF_vacancies]=School_students[stu_indx].Id;  //index=student_id
        NumberOF_vacancies++;

        strcpy(School_students[stu_indx].name, "-1");
        strcpy(School_students[stu_indx].adress, "-1");
        strcpy(School_students[stu_indx].phone, "-1");
        School_students[stu_indx].age = 0;
        School_students[stu_indx].Id = 0;



        saveStudentsToFile();
        return 1;    //student deletes
    }

}


u8 student_EditName_usingID(u32 std_id)
{
    u32 indx=student_SearchBy_Id(std_id);
    if(indx!=-1)
    {


        for(int i=0; i<3; i++)
        {
            fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t----------------> Enter New Name:");
        scanf("%s",&School_students[indx].name);
            if(check_Name(School_students[indx].name,string_len(School_students[indx].name)))
            {
                break;
            }
            else
            {
               if(i>2)
                exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);
            }
        }
        saveStudentsToFile();
        return 1;
    }
    else
    {
        return -1;
    }


}

u8 student_EditAge_usingID(u32 std_id)
{
    u8 indx=student_SearchBy_Id(std_id);
    if(indx!=-1)
    {

        for(int i=0; i<3; i++)
        {
            printf("\t\t\t\t\t\t\t\t\t---------------->Enter New Age:");
             scanf("%d",&School_students[indx].age);
            if(School_students[indx].age>0&&School_students[indx].age<100)
            {
                break;
            }
            else
            {
                if(i>2)
                    exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);

            }

        }
        saveStudentsToFile();
        return 1;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t---------------->your Id Not Correct or Not Registered Before\n");
        return -1;
    }


}
u8 student_EditPhone_usingID(u32 std_id)
{
    u8 indx=student_SearchBy_Id(std_id);
    if(indx!=-1)
    {

        for(int i=0; i<3; i++)
        {
            fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t---------------->Enter New Phone Number(0-11)digits:");
        scanf("%s",&School_students[indx].phone);
            if(check_Phone(School_students[indx].phone,string_len(School_students[indx].phone)))
            {
                break;
            }
            else
            {
               if(i>2)
                exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);
            }
        }
        saveStudentsToFile();
        return 1;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t---------------->your Id Not Correct or Not Registered Before\n");
        return -1;
    }

}
u8 student_EditAdress_usingID(u32 std_id)
{
    u8 indx=student_SearchBy_Id(std_id);
    if(indx!=-1)
    {
        fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t---------------->Enter New Address:");
        scanf("%s",&School_students[indx].adress);
        saveStudentsToFile();
        return 1;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\t\t---------------->your Id Not Correct or Not Registered Before\n");
        return -1;
    }
}

u8 student_EditPhone_usingName(u8p std_name)
{
    u32 indx=student_SearchBy_Name(std_name);
    if(indx!=-1)
    {
        for(int i=0; i<3; i++)
        {
            fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t---------------->Enter New Phone Number(0-11)digits:");
        scanf("%s",&School_students[indx].phone);
            if(check_Phone(School_students[indx].phone,string_len(School_students[indx].phone)))
            {
                break;
            }
            else
            {
               if(i>2)
                exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);
            }
        }
        saveStudentsToFile();
        return 1;
    }
    else
    {
        return -1;
    }


}
u8 student_EditAdress_usingName(u8p std_name)
{
    u32 indx=student_SearchBy_Name(std_name);
    if(indx!=-1)
    {
        fflush(stdin);
        printf("\t\t\t\t\t\t\t\t\t----------------> Enter New Address:");
        scanf("%s",&School_students[indx].adress);
        saveStudentsToFile();
        return 1;
    }
    else
    {
        return -1;
    }


}

u8 student_EditAge_usingName(u8p std_name)
{
    u32 indx=student_SearchBy_Name(std_name);
    if(indx!=-1)
    {
        for(int i=0; i<3; i++)
        {
            fflush(stdin);
            printf("\t\t\t\t\t\t\t\t\t---------------->Enter New Age:");
             scanf("%d",&School_students[indx].age);
            if(School_students[indx].age>0&&School_students[indx].age<100)
            {
                break;
            }
            else
            {
                if(i>2)
                    exit(0);

                setColor(4);
                printf("\t\t\t\t\t\t\t\t\t                -->Not Allowed try again\n\n");
                setColor(6);

            }

        }

        saveStudentsToFile();
        return 1;
    }
    else
    {
        return -1;
    }


}

void Students_bubbleSort(std_t*school_std,u32 std_number)
{
    int j,i,Flag;
std_t*arr=malloc(std_number*sizeof(std_t));
for(i=0;i<std_number;i++)
{
    arr[i]=school_std[i];
}
    for(j=0; j<std_number-1; j++)
    {
       Flag=1;
        for(i=0; i<std_number-j-1; i++)
        {
            if(string_compareNotCaseSensetive2(arr[i].name,arr[i+1].name)==1)
            {

                student_swap(&arr[i],&arr[i+1]);
               Flag=0;
            }
        }
        if(Flag==1)
        {
            break;
        }
    }

    student_printAll(arr,std_number);
}




void student_print(std_t s)
{
    fflush(stdin);
    printf("\n\t\t\t\t\t\t\t\t\t                 name:%s\n",s.name);
    printf("\t\t\t\t\t\t\t\t\t                 age:%d\n",s.age);
    printf("\t\t\t\t\t\t\t\t\t                 adress:%s\n",s.phone);
    printf("\t\t\t\t\t\t\t\t\t                 phone:%s\n",s.adress);
    printf("\t\t\t\t\t\t\t\t\t                 ID:%d\n\n",s.Id);

}

void student_printAll(std_t* School_students,u32 NoOfStudents)
{
    u32 i;
    if(NoOfStudents==0)
    {
        setColor(4);
        printf("\t\t\t\t\t\t\t\t===================================================================================\n");
        printf("\n\t\t\t\t\t\t\t\t\t*** **** **** **** No Registerd Student yet **** **** **** ***\n");
        printf("\n\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n\n");
        exit(0);
    }
    else
    {
        setColor(3);
        printf("\t\t\t\t\t\t\t\t===================================================================================\n");
        printf("\t\t\t\t\t\t\t\t=                          All Our Registered Students:%d                         =\n",No_Of_Student());
        printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n");
        setColor(15); //return colorr to default
        for(i=0; i<NoOfStudents; i++)
        {
            if(School_students[i].Id!=0)
            {
                setColor(3);
                printf("\t\t\t\t\t\t\t\t\t---------------->Student%d:\n",i+1);
                setColor(15);
                student_print(School_students[i]);
                printf("\n\t\t\t\t\t\t\t\t===================================================================================\n");

            }

        }

    }



}
