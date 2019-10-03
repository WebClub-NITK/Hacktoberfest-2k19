#include <stdio.h>

char ipv4_class(char *addr)
{
/*  Get first octet */
    int oct1;
    sscanf(addr, "%d", &oct1);

/*  If oct1 id invalid or 127 (reserved for loopback addresses), return NULL */
    if (oct1 < 1 || oct1 == 127 || oct1 > 255) return 0;

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
    printf("This is a class %c IPv4 address.\n", ipv4_class(address));
    return 0;
}
