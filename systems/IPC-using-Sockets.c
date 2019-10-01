#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DATA1 "What is Hacktoberfest?"
#define DATA2 "It is a celebration of Open Source:)"

int main()
{
    int sockets[2], child;
    char buf[10];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
    {
        perror("opening stream socket pair");
        exit(1);
    }

    if ((child = fork()) == -1)
        perror("fork");

    else if (child)
    {
        close(sockets[0]);
        read(sockets[1], buf, sizeof(buf));
        printf("-->%s\n", buf);
        write(sockets[0], DATA2, sizeof(DATA2));
        close(sockets[1]);
    }

    else
    {
        close(sockets[1]);
        write(sockets[0], DATA1, sizeof(DATA1));
        read(sockets[1], buf, sizeof(buf));
        printf("-->%s\n", buf);
        close(sockets[0]);
    }

    return 0;
}
