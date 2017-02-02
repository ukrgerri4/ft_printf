#include "ft_printf.h"

int     main(void)
{
    int i;

    i = 5;
    ft_printf("%d\n", ft_printf("PF %12.20s 456 %.7s 789 %s %c |%#3X|)))\n", "Marooned", "Cluster_One", "Abitw", 'R', 123));
    printf("---------------------------------------------\n");
    printf("%d\n", printf("PF %12.20s 456 %.7s 789 %s %c |%#3X|)))\n", "Marooned", "Cluster_One", "Abitw", 'R', 123)); 
//  printf("%d\n", printf("PF %s 456 %s 789 %s )))\n", "Marooned", "Cluster One", "Abitw"));
//	printf("%d\n", ft_printf("%#-6 .8+ 12++++.20s", "Marooned"));
//	printf("%d\n", printf("%12.20++s", "Marooned"));
	ft_printf("%#30p\n", &i);
    printf("%30p\n", &i);
    return (0);
}
