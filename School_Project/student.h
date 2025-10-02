
typedef  unsigned char  u8;
typedef  signed char  s8;

typedef  unsigned int  u32;
typedef  signed int  s32;

typedef  unsigned long long u64;
typedef  signed long long  s64;

typedef unsigned char*  u8p;
typedef signed char*  s8p;

typedef  unsigned int*  u32p;
typedef  signed int*  s32p;

typedef  unsigned long long* u64p;
typedef  signed long long*  s64p;


typedef struct {
u8 adress[100];
u8 name[20];
u8 phone[11];
u32 age;
u32 Id;

}std_t;



void student_print(std_t s);//print one student data
u32 No_Of_Student(void);
u8 student_Add(void);
void student_printAll(std_t* AllStudents,u32 NoOfStudents);  //print all students on our school
void student_swap(std_t* s1,std_t* s2);
u32 student_SearchBy_Name(u8p std_Name);
u32 student_SearchBy_Id(u32 std_Id);
u8 student_DeleteBy_Name(u8p std_name);
u8 student_DeleteBy_Id(u32 std_Id);

u8 student_EditName_usingID(u32 Student_id);
u8 student_EditPhone_usingID(u32 Student_id);
u8 student_EditAdress_usingID(u32 Student_id);
u8 student_EditAge_usingID(u32 Student_id);

void Students_bubbleSort(std_t* school_std,u32 std_number);

//u8 student_EditID_usingName(u8p std_name);
u8 student_EditAge_usingName(u8p std_name);
u8 student_EditAdress_usingName(u8p std_name);
u8 student_EditPhone_usingName(u8p std_name);
