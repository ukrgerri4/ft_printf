#include "ft_printf.h"

int     main(void)
{
	int *s;

	s = 0;
	ft_printf("%p %p\n", s, NULL);
	printf("%p %p\n", s, NULL);

	ft_printf("%D\n", -2147483647);
	printf("%D\n", -2147483647);
	ft_printf("%D\n", 4294959296);
	printf("%D\n", 4294959296);

/*
	ft_printf("%jx", -4294967296);
printf("%jx", -4294967296);
printf("\n");
	ft_printf("%jx", -4294967297);
printf("%jx", -4294967297);
printf("\n");
	ft_printf("%#x", 0);
printf("%#x", 0);
printf("\n");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
printf("@moulitest: %#.x %#.0x", 0, 0);
printf("\n");
	ft_printf("@moulitest: %.x %.0x", 0, 0);
printf("@moulitest: %.x %.0x", 0, 0);
printf("\n");
	ft_printf("@moulitest: %5.x %5.0x", 0, 0);
printf("@moulitest: %5.x %5.0x", 0, 0);
printf("\n");
	ft_printf("%-10s is a string", "this");
printf("%-10s is a string", "this");
printf("\n");
	ft_printf("%-5.2s is a string", "this");
printf("%-5.2s is a string", "this");
printf("\n");
	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
printf("\n");
	ft_printf("@moulitest: %s", NULL);
printf("@moulitest: %s", NULL);
printf("\n");
	ft_printf("%5c", 42);
printf("%5c", 42);
printf("\n");
	ft_printf("%-5c", 42);
printf("%-5c", 42);
printf("\n");
	ft_printf("%2c", 0);
printf("%2c", 0);
printf("\n");
	ft_printf("@moulitest: %.o %.0o", 0, 0);
printf("@moulitest: %.o %.0o", 0, 0);
printf("\n");
	ft_printf("@moulitest: %5.o %5.0o", 0, 0);
printf("@moulitest: %5.o %5.0o", 0, 0);
printf("\n");
	ft_printf("@moulitest: %#.o %#.0o", 0, 0);
printf("@moulitest: %#.o %#.0o", 0, 0);
printf("\n");
	ft_printf("% +d", 42);
printf("% +d", 42);
printf("\n");
	ft_printf("%+ d", 42);
printf("%+ d", 42);
printf("\n");
	ft_printf("%  +d", 42);
printf("%  +d", 42);
printf("\n");
	ft_printf("%+  d", 42);
printf("%+  d", 42);
printf("\n");
	ft_printf("% ++d", 42);
printf("% ++d", 42);
printf("\n");
	ft_printf("%++ d", 42);
printf("%++ d", 42);
printf("\n");
	ft_printf("@moulitest: %.d %.0d", 0, 0);
printf("@moulitest: %.d %.0d", 0, 0);
printf("\n");
	ft_printf("@moulitest: %5.d %5.0d", 0, 0);
printf("@moulitest: %5.d %5.0d", 0, 0);
printf("\n");
	ft_printf("%lu", "-42");
printf("%lu", "-42");
printf("\n");
	ft_printf("%hU", "4294967296");
printf("%hU", "4294967296");
printf("\n");
	ft_printf("%U", "4294967296");
printf("%U", "4294967296");
printf("\n");
*/
    return (0);
}
