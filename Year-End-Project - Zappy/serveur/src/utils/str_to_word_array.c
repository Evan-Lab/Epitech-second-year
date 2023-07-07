/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** str_to_word_array
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void free_array(char **array)
{
    int count = 0;

    while (array[count] != NULL) {
        free(array[count]);
        ++count;
    }
    free(array);
}

static int rows(char *str, char separator)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator || str[i] == 9)
            y++;
    }
    return (y + 1);
}

static int spaces(char *str, char separator)
{
    int w = 0;
    int j = 0;

    while (str[w] == separator || str[w] == '\t') {
        j++;
        w++;
    }
    return (j);
}

static char **mem_alloc_2d_char_array(int rows, int columns)
{
    int i = 0;
    char **arr = malloc(sizeof(char *) * (rows + 1));

    while (i < rows) {
        arr[i] = malloc(sizeof(char) * columns + 1);
        i = i + 1;
    }
    return (arr);
}

char **str_to_word_array(char *str, char separator)
{
    char **tab = mem_alloc_2d_char_array(rows(str, separator), strlen(str));
    int i = spaces(str, separator);
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == separator || str[i] == '\t') {
            tab[j][k] = '\0';
            i++;
            j++;
            k = 0;
        }
        tab[j][k] = str[i];
        i++;
        k++;
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return tab;
}
