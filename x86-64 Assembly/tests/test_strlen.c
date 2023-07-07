/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_strlen
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

static unsigned int(*load_my_strlen(void *test_lib))(const char *str)
{
    unsigned int(*my_strlen)(const char *str) = dlsym(test_lib, "strlen");
    if (!my_strlen) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
}

Test(strlen, returns_correct_length) {
    void *handle = test_lib();
    unsigned int(*my_strlen)(const char *str) = load_my_strlen(handle);
    const char *str = "Hello, world!";
    size_t len = my_strlen(str);
    cr_assert_eq(len, 13, "Expected length 13, but got %lu", len);
    dlclose(handle);
}
/*
redirection
del open du .so
ouvrer le .so
choper le symbole puis tester
*/