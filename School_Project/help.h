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


void printWelcome();
void saveStudentsToFile();
void loadStudentsFromFile();
void setColor(u32 color);
void students_options(void);
u8 check_Name(u8*str,u32 max_size);
u8 check_Phone(u8*str,u32 max_size);
u32 string_len(u8*str);
u8 string_compareNotCaseSensetive(u8p str1,u8p str2);
u32 string_compareNotCaseSensetive2(u8p str1,u8p str2);

/*setColor(4, 0); // نص أحمر
    printf("هذا نص باللون الأحمر\n");

    setColor(2, 0); // نص أخضر
    printf("هذا نص باللون الأخضر\n");

    setColor(6, 0); // نص أصفر
    printf("هذا نص باللون الأصفر\n");

    setColor(1, 0); // نص أزرق
    printf("هذا نص باللون الأزرق\n");

    setColor(8, 0); // نص رمادي
    printf("هذا نص باللون الرمادي\n");

    setColor(12, 0); // نص وردي (أحمر فاتح)
    printf("هذا نص باللون الوردي\n");

    setColor(6, 0); // نص بني (يمكن استخدام الأصفر الفاتح)
    printf("هذا نص باللون البني\n");

    setColor(5, 0); // نص بنفسجي
    printf("هذا نص باللون البنفسجي\n");

    // العودة إلى اللون الافتراضي
    setColor(7, 0);
    printf("العودة إلى اللون الافتراضي\n");
*/
