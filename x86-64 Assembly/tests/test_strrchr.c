/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_strrchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>

static void* test_lib()
{
    void* handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return handle;
}

static char*(*load_my_strrchr(void* test_lib))(const char*, int)
{
    char*(*my_strrchr)(const char*, int) = dlsym(test_lib, "strrchr");
    if (!my_strrchr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_strrchr;
}

Test(strrchr, char_found)
{
    void* handle = test_lib();
    char*(*my_strrchr)(const char*, int) = load_my_strrchr(handle);
    const char* str = "Hello, world!";
    int ch = 'o';
    char* res = my_strrchr(str, ch);
    cr_assert_not_null(res, "Expected non-null pointer, but got NULL");
    cr_assert_eq(*res, ch, "Expected '%c', but got '%c'", ch, *res);
    dlclose(handle);
}

Test(strrchr, char_not_found)
{
    void* handle = test_lib();
    char*(*my_strrchr)(const char*, int) = load_my_strrchr(handle);
    const char* str = "Hello, world!";
    int ch = 'z';
    char* res = my_strrchr(str, ch);
    cr_assert_null(res, "Expected NULL pointer, but got non-null");
    dlclose(handle);
}
