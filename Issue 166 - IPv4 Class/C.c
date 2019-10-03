#include <stdio.h>

char ipv4_class(char *addr)
{
/*  Get first octet */
    int oct1, oct2, oct3, oct4;
    sscanf(addr, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);

/*  If oct1 id invalid or 127 (reserved for loopback addresses), return NULL */
    if ( oct1 < 1 || oct1 == 127 || oct1 > 255
      || oct2 > 255
      || oct3 > 255
      || oct4 > 255 )
    return 0;

    if (oct1 <= 126) return 'A';
    if (oct1 <= 191) return 'B';
    if (oct1 <= 223) return 'C';
    if (oct1 <= 239) return 'D';
    /* oct1 <= 255*/ return 'E';
}

int main(void)
{
    char address[16];
    printf("Enter the IPv4 address: ");
    scanf("%15s", address);
    char class = ipv4_class(address);
    if (class) /* If class is valid */
	printf("This is a class %c IPv4 address.\n", ipv4_class(address));
    else
	printf("This is an invalid IPv4 address.\n");
    return 0;
}
