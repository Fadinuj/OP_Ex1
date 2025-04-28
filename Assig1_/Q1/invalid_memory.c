#include <stdio.h>

int main() {
    int *p = (int *)0xdeadbeef; // כתובת לא חוקית
    *p = 42; // ניסיון כתיבה
    return 0;
}
