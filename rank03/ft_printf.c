#include <unistd.h>
#include <stdarg.h>

int	writestr(char *str)
{
	int	i;
	int	ct;

	if (str == NULL)
		return (write(1, "(null)", 6));
	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ct += write(1, &str[i], 1);
		i++;
	}
	return (ct);
}

int	writingnum(int num)
{
	int		i;
	int		ct;
	char	ch[11];

	ct = 0;
	i = 0;
	while (num > 0)
	{
		ch[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ct += write(1, &ch[i], 1);
		i--;
	}
	return (ct);
}

int	writenum(int num)
{
	int		ct;

	if (num == 0)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	ct = 0;
	if (num < 0)
	{
		ct += write(1, "-", 1);
		num *= -1;
	}
	ct += writingnum(num);
	return (ct);
}

int	writehex(unsigned int num)
{
	int		i;
	int		ct;
	char	ch[8];

	ct = 0;
	if (num == 0)
		return (write(1, "0", 1));
	i = 0;
	while (num > 0)
	{
		if (num % 16 >= 10 && num % 16 <= 16)
			ch[i] = num % 16 - 10 + 'a';
		else
			ch[i] = num % 16 + '0';
		num /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ct += write(1, &ch[i], 1);
		i--;
	}
	return (ct);
}

int	interpreter(int i, const char *format, va_list args)
{
	int	ct;

	ct = 0;
	if (format[i + 1] == 's')
		ct += writestr(va_arg(args, char *));
	if (format[i + 1] == 'd')
		ct += writenum(va_arg(args, int));
	if (format[i + 1] == 'x')
		ct += writehex(va_arg(args, unsigned int));
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ct;

	ct = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ct += interpreter(i, format, args);
			i++;
		}
		else
			ct += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ct);
}

/* Test (comment out this line only)
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int		ret;
	char	*str = NULL;

	printf("==========TEST=========\n");
	ret = printf("%s: %d\n", "Number", 0);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %d\n", "Number", 0);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %d\n", "Number", -2342);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %d\n", "Number", -2342);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %d\n", "Number", 3545);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %d\n", "Number", 3545);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %d\n", "Number", INT_MIN);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %d\n", "Number", INT_MIN);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %x\n", "Hex", 0);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %x\n", "Hex", 0);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %x\n", "Hex", 52345);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %x\n", "Hex", 52345);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	ret = printf("%s: %s\n", "String", str);
	printf("Out: %d\n", ret);
	ret = ft_printf("%s: %s\n", "String", str);
	printf("Out: %d\n", ret);
	printf("=======================\n");
	return (0);
}
//*/
