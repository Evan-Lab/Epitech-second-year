/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_strncmp
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

static int(*load_my_strncmp(void *test_lib))(const char *, const char *, size_t)
{
    int(*my_strncmp)(const char *, const char *, size_t) = dlsym(test_lib, "strncmp");
    if (!my_strncmp) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_strncmp;
}

Test(strncmp, equal_strings)
{
    void *handle = test_lib();
    int(*my_strncmp)(const char *, const char *, size_t) = load_my_strncmp(handle);
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";
    size_t n = strlen(str1);
    int res = my_strncmp(str1, str2, n);
    cr_assert_eq(res, 0, "Expected 0, but got %d", res);
    dlclose(handle);
}

Test(strncmp, different_strings)
{
    void *handle = test_lib();
    int(*my_strncmp)(const char *, const char *, size_t) = load_my_strncmp(handle);
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, there!";
    size_t n = strlen(str1);
    int res = my_strncmp(str1, str2, n);
    cr_assert_neq(res, 0, "Expected not 0, but got %d", res);
    dlclose(handle);
}
