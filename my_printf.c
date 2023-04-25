#include <stdio.h>
#include <stdarg.h>
/**
 * printf - it produces output according to a format.
 * @format: is a character string.
 * Return: s
 */
int _printf(const char *format, ...)
{
	int count;

	va_list args;

	va_start(args, format);

	count = 0;
	while (*format != '\0')
	{
	if (*format == '%')
	{
		format++;
		if (*format == 'c')
		{
			int c = va_arg(args, int);

			putchar(c);
			count++;
		}
		else if (*format == 's')
		{
			char *s = va_arg(args, char *);

			while (*s != '\0')
			{
				putchar(*s);
				s++;
				count++;
			}
		}
		else if (*format == '%')
		{
			putchar('%');
			count++;
		}
	}
	else
	{
		putchar(*format);
		count++;
	}
	format++;
	}
	va_end(args);
	return (count);
}
int main()
{
	int a = 65;
	char b[] = "world";

	_printf("Hello, %c! Welcome to the %s!\n", a, b);
	_printf("This is a percent sign: %%\n");
	return (0);
}
