#include <libft.h>

char **ft_strconcat(char **array, const char *new_str) {
    if (!new_str) {
        return array; // If new_str is NULL, return the original array as is
    }

    // Count the current size of the array
    size_t size = 0;
    if (array) {
        while (array[size]) {
            size++;
        }
    }

    // Allocate memory for the new array (size + 1 for new string, +1 for NULL terminator)
    char **new_array = malloc((size + 2) * sizeof(char *));
    if (!new_array) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Copy existing strings to the new array
    for (size_t i = 0; i < size; i++) {
        new_array[i] = array[i];
    }

    // Add the new string to the array
    new_array[size] = ft_strdup((char *)new_str);
    if (!new_array[size]) {
        free(new_array);
        return NULL; // Return NULL if strdup fails
    }

    // Null-terminate the new array
    new_array[size + 1] = NULL;

    // Free the old array (but not the strings, as they are reused)
    free(array);

    return new_array;
}