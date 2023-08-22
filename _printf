#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of printed characters

    while (*format) {
        if (*format == '%') {
            format++;  // Move past the '%'
            if (*format == '\0')  // If '%' is the last character, break the loop
                break;

            if (*format == 'c') {
                char c = (char) va_arg(args, int);
                char buffer[1] = {c};
                write(1, buffer, 1);
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
                char buffer[1] = {'%'};
                write(1, buffer, 1);
                count++;
            }
        } else {
            char buffer[1] = {*format};
            write(1, buffer, 1);
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

