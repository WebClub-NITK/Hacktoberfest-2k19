#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_number(char *num)
{
    while (*num) {
	if (*num < '0' || *num > '9') return 0;
	++num;
    }
    return 1;
}

int valid_ipv4_address(char *addr)
{
    char *split = strtok(addr, ".");
    int dots = -1;
    long long oct;

    while (split != NULL) {
	++dots;

	if (!valid_number(split)) return 0;
	
	oct = atoll(split);
	if (oct < 0 || oct > 255) return 0;

	split = strtok(NULL, ".");
    }

    return (dots == 3);
}

char ipv4_class(char *addr)
{
/*  Get first octet */
    int oct1, oct2, oct3, oct4;
    sscanf(addr, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);

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
    char address[1024];
    printf("Enter the IPv4 address: ");
    scanf("%1023s", address);
    char class = ipv4_class(address);
    if (valid_ipv4_address(address) && class) /* If class is valid */
	printf("This is a class %c IPv4 address.\n", class);
    else
	printf("This is an invalid IPv4 address.\n");
    return 0;
}
