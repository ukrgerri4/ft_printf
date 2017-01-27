#include "ft_printf.h"

int     main(void)
{
    printf("%d\n", ft_printf("PF %12.20s 456 %.7s 789 %s %c )))\n", "Marooned", "Cluster_One", "Abitw", 'R'));
    printf("---------------------------------------------\n");
    printf("%d\n", printf("PF %12.20s 456 %.7s 789 %s %c )))\n", "Marooned", "Cluster_One", "Abitw", 'R')); 
//  printf("%d\n", printf("PF %s 456 %s 789 %s )))\n", "Marooned", "Cluster One", "Abitw"));
//	printf("%d\n", ft_printf("%#-6 .8+ 12++++.20s", "Marooned"));
//	printf("%d\n", printf("%12.20++s", "Marooned"));
    printf("%1.8s\n", "ONE");
    return (0);
}
