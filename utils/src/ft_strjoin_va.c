#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>


char *ft_strjoin_va(int count, ...)
{
    if (count <= 0)
        return NULL;

    va_list args;
    va_start(args, count);

    // Calculate total length of the resulting string
    size_t total_length = 0;
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char *);
        if (str)
            total_length += ft_strlen(str);
    }
    va_end(args);

    // Allocate memory for the concatenated string
    char *result = malloc(total_length + 1);
    if (!result)
        return NULL;

    // Concatenate strings
    va_start(args, count);
    char *current_pos = result;
    for (int i = 0; i < count; i++)
    {
        const char *str = va_arg(args, const char *);
        if (str)
        {
            size_t len = ft_strlen(str);
            ft_memcpy(current_pos, str, len);
            current_pos += len;
        }
    }
    va_end(args);

    *current_pos = '\0'; // Null-terminate the result
    return result;
}