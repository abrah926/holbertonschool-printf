#include "main.h"

/**
 * op_print - choose the correct function to print based on specifier
 * @s: char with the specifier
 * 
 * Return: pointer to the matching print function.
 */
int (*op_print(char s))(va_list)
{
    specifier_t print[] = {
        {'c', op_char},
        {'s', op_str},
        {'%', op_percent},
        {'d', op_int},
        {'i', op_int},
        {'\0', NULL}
    };

    int i;
    for (i = 0; print[i].spec != '\0'; i++)
    {
        if (print[i].spec == s)
            return (print[i].func);
    }
    return (NULL);
}
