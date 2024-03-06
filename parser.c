#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *buffer = calloc(1, sizeof(char));
    if (buffer == NULL)
    {
        return 1;
    }
    int count = 0;

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (argv[i][j])
            {
                char *tmp = (char *)realloc(buffer, count + 1);
                if (tmp == NULL)
                {
                    free(buffer);
                    return 1;
                }
                buffer = tmp;
                buffer[count] = (char) argv[i][j];
                count++;
            }
        }
        buffer[count] = ' ';
        count++;
    }

    buffer[count] = '\0';

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
    free(buffer);
    return 0;
}
