#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include"help.h"
#include "student.h"
#define MaxNo_Students 6

extern std_t School_students[MaxNo_Students];
extern u32 NoOfStudents;
extern u32 NumberOF_vacancies;
extern u32 Students_Deleted_IDs[MaxNo_Students];

void saveStudentsToFile() {
    FILE *file = fopen("students.txt", "w");
    FILE *deletedFile = fopen("deleted.txt", "w");
    if (file == NULL || deletedFile == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    // Save student data
    for (unsigned int i = 0; i < NoOfStudents; i++) {
        fprintf(file, "REGISTERED %s %u %s %s %u\n",
                School_students[i].name,
                School_students[i].age,
                School_students[i].adress,
                School_students[i].phone,
                School_students[i].Id);
    }

    // Save deleted IDs
    for (unsigned int i = 0; i < NumberOF_vacancies; i++) {
        fprintf(deletedFile, "%u\n", Students_Deleted_IDs[i]);
    }

    fclose(file);
    fclose(deletedFile);
}

void loadStudentsFromFile() {
    FILE *file = fopen("students.txt", "r");
    FILE *deletedFile = fopen("deleted.txt", "r");

    if (file == NULL) {
        return;
    }

    // Load student data
    unsigned int i = 0; // Start from index 1
    while (fscanf(file,"REGISTERED %s %u %s %s %u\n",
                  School_students[i].name,
                  &School_students[i].age,
                  School_students[i].adress,
                  School_students[i].phone,
                  &School_students[i].Id) == 5) {
        i++;
        NoOfStudents++; // Update number of students
    }
    fclose(file);

    // Load deleted IDs
    if (deletedFile != NULL) {
        while (fscanf(deletedFile, "%u\n", &Students_Deleted_IDs[NumberOF_vacancies]) == 1) {
            NumberOF_vacancies++;
        }
        fclose(deletedFile);
    }

}

u32 string_len(u8*str)
{
    int i;
    for(i=0;str[i];i++);
    return i;
}
u8 check_Name(u8*Name,u32 max_size)
{
    for(int i=0;i<max_size;i++)
    {
        if(Name[i]<'A'||Name[i]>'Z'&&Name[i]<'a'||Name[i]>'z')
            return 0;
    }
    return 1;
}
u8 check_Phone(u8*phone,u32 max_size)
{
    for(int i=0;i<max_size;i++)
    {
        if (phone[max_size] != '\0'||string_len(phone)<11)
         return 0;
        else if(phone[i]<'0'||phone[i]>'9')
            return 0;
    }
    return 1;
}





void setColor(u32 color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void printWelcome()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    setColor(13);// أحمر بنفسجي
    printf("\t\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    setColor(12); // لون أحمر
    printf("\t\t\t\t\t=\t\t\tWW           WW  EEEEEEEEEEE   LL          CCCCCCCCC     OOOOOOO     MM         MM  \t\t\t  =\n");
    printf("\t\t\t\t\t=\t\t\tWW           WW  EEEEEEEEEEE   LL          CCCCCCCCC     OOOOOOO     MM         MM  \t\t\t  =\n");
    setColor(3);
    printf("\t\t\t\t\t=\t\t\t WW    WW   WW   EE            LL         CC           OO       OO   MMM       MMM  \t\t\t  =\n");
    printf("\t\t\t\t\t=\t\t\t WW    WW   WW   EE            LL         CC           OO       OO   MMMMM    MMMM  \t\t\t  =\n");
    setColor(15); // العودة إلى اللون الافتراضي
    printf("\t\t\t\t\t=\t\t\t  WW WW WW WW    EEEEEEEEEE    LL         CC           OO       OO   MM    MM   MM  \t\t\t  =\n");
    printf("\t\t\t\t\t=\t\t\t  WW WW WW WW    EEEEEEEEEE    LL         CC           OO       OO   MM    MM   MM  \t\t\t  =\n");
    setColor(3);
    printf("\t\t\t\t\t=\t\t\t    WW    WW     EE            LL         CC           OO       OO   MM         MM  \t\t\t  =\n");
    printf("\t\t\t\t\t=\t\t\t    WW    WW     EE            LL         CC           OO       OO   MM         MM  \t\t\t  =\n");
    setColor(12);//ظظلون أزرق
    printf("\t\t\t\t\t=\t\t\t    WW WW WW     EEEEEEEEEEE   LLLLLLLLL   CCCCCCCCC     OOOOOOO     MM         MM  \t\t\t  =\n");
    printf("\t\t\t\t\t=\t\t\t    WW WW WW     EEEEEEEEEEE   LLLLLLLLL   CCCCCCCCC     OOOOOOO     MM         MM  \t\t\t  =\n");
    setColor(3);
    printf("\t\t\t\t\t=                                                                                                          STUDENTS\t\t  =\n");
    setColor(13);//بنفسجي
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t=                                                                                                \t\t\t\t  =\n");
    printf("\t\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    setColor(15); // العودة إلى اللون الافتراضي
}



void students_options(void)
{
        setColor(6);
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t===================================================================================\n");
        printf("\t\t\t\t\t\t\t\t=                                                                                 =\n");
        printf("\t\t\t\t\t\t\t\t=                               STUDENTS OPTIONS                                  =\n");
        printf("\t\t\t\t\t\t\t\t=                                                                                 =\n");
        setColor(3);
        printf("\t\t\t\t\t\t\t\t===================================================================================\n\n\n\n");
        setColor(2);
        printf("\t\t\t\t\t\t\t\t\t\t  1. Add Student\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  2. Find Student By his/her Name\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  3. Find Student By his/her ID\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  4. Delete Student By his/her Name\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  5. Delete Student By his/her ID\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  6. Update Student Using Name\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  7. Update Student Using ID\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  8. Show All Registered Students\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  9. Sorting Students By Name\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  10. Sorting Students By Id\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t  11. To Exit\n\n");
        setColor(3);
        printf("\n\n\n\t\t\t\t\t\t\t\t==================================================================================\n\n\n");
        setColor(15);
}

void student_swap(std_t* s1,std_t *s2 )
{
    std_t temp=*s1;
    *s1=*s2;
    *s2=temp;

}

u8 string_compareNotCaseSensetive(u8p std_name1,u8p std_name2)
{
    char ch1,ch2;
    int i;
    for(i=0;std_name1[i]||std_name2[i];i++)
    {
        if(std_name1[i]>='A'&&std_name1[i]<='Z')
        {
            ch1=std_name1[i]-'A'+'a';
        }
        else
            ch1=std_name1[i];

        if(std_name2[i]>='A'&&std_name2[i]<='Z')
        {
            ch2=std_name2[i]-'A'+'a';
        }
       else
        ch2=std_name2[i];

        if(ch1!=ch2)
        return 0;
    }
    return 1;
}


u32 string_compareNotCaseSensetive2(u8p str1,u8p str2)
{
    char ch1,ch2;
    int i;
    for(i=0;str1[i]||str2[i];i++)
    {
        if(str1[i]>='A'&&str1[i]<='Z')
        {
            ch1=str1[i]-'A'+'a';
        }
        else
            ch1=str1[i];

        if(str2[i]>='A'&&str2[i]<='Z')
        {
            ch2=str2[i]-'A'+'a';
        }
       else
        ch2=str2[i];

        if(ch1>ch2)
        {
            return 1;
        }
        else if(ch1<ch2)
        {
            return 2;
        }
    }
    return 0;
}
