/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_strstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void *test_lib()
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return handle;
}

static char *(*load_my_strstr(void *test_lib))(const char *str, const char *needle)
{
    char *(*my_strstr)(const char *str, const char *needle) = dlsym(test_lib, "strstr");
    if (!my_strstr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_strstr;
}

Test(my_strstr, finds_needle_in_str)
{
    void *handle = test_lib();
    char *(*my_strstr)(const char *str, const char *needle) = load_my_strstr(handle);
    const char *str = "Hello, world!";
    const char *needle = "world";
    char *result = my_strstr(str, needle);
    cr_assert_not_null(result, "Expected needle '%s' to be found in str '%s'", needle, str);
    cr_assert_eq(result - str, 7, "Expected needle '%s' to be found at index 7, but was found at index %ld", needle, result - str);
    dlclose(handle);
}

Test(my_strstr, returns_null_if_needle_not_found)
{
    void *handle = test_lib();
    char *(*my_strstr)(const char *str, const char *needle) = load_my_strstr(handle);
    const char *str = "Hello, world!";
    const char *needle = "foo";
    char *result = my_strstr(str, needle);
    cr_assert_null(result, "Expected needle '%s' not to be found in str '%s'", needle, str);
    dlclose(handle);
}
