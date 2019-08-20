#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int
main(void)
{
    int  n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("error\n");
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0)
    {
        printf("read error\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}