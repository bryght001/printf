#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
int char_count = 0;
va_list args;

va_start(args, format);

for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
putchar(format[i]);
char_count++;
}
else
{
i++;  /* Move to the next character after '%*/
switch (format[i])
{
case 'c':
{
char c = va_arg(args, int);   /*Promote char to int for va_arg*/
putchar(c);
char_count++;
break;
}
case 's':
{
char *str = va_arg(args, char *);
while (*str)
{
putchar(*str);
str++;
char_count++;
}
break;
}
case '%': {
putchar('%');
char_count++;
break;
}
default:
{
/*Handle invalid format specifier*/
fprintf(stderr, "Invalid format specifier: %c\n", format[i]);
char_count = -1;  /* Indicate error*/
goto cleanup;
}
}
}
}

cleanup:
va_end(args);
return (char_count);
}

#endif /* end of function */
