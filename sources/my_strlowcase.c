/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** lowercase a string
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}
