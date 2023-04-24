/*
** EPITECH PROJECT, 2021
** Cat
** File description:
** Recreate the system's cat command
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_putstr(char const *str);

int cat(char *filepath)
{
    int fd;
    int size = 30000;
    char buffer[size];

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("Error with open\n");
        return (1);
    }
    size = read(fd, buffer, size);
    write(1, buffer, size);
    close(fd);
    return (0);
}
