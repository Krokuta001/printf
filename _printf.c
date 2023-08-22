#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; 

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c') {
                char c = (char) va_arg(args, int);
                write(1, &c, 1);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                int len = 0;
                while (s[len] != '\0') {
                    len++;
                }
                write(1, s, len);
                count += len;
            } else if (*format == '%') {
                char percent = '%';
                write(1, &percent, 1);
                count++;
            }
        } else {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percentage sign: %%\n");

    return 0;
}
