/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_strcmp
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

static int(*load_my_strcmp(void *test_lib))(const char *, const char *)
{
    int(*my_strcmp)(const char *, const char *) = dlsym(test_lib, "strcmp");
    if (!my_strcmp) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_strcmp;
}

Test(strcmp, returns_correct_result) {
    void *handle = test_lib();
    int(*my_strcmp)(const char *, const char *) = load_my_strcmp(handle);
    const char *s1 = "Hello";
    const char *s2 = "World";
    int result = my_strcmp(s1, s2);
    cr_assert_lt(result, 0, "Expected negative result, but got %d", result);
    s1 = "Hello";
    s2 = "Hello";
    result = my_strcmp(s1, s2);
    cr_assert_eq(result, 0, "Expected zero result, but got %d", result);
    s1 = "World";
    s2 = "Hello";
    result = my_strcmp(s1, s2);
    cr_assert_gt(result, 0, "Expected positive result, but got %d", result);
    dlclose(handle);
}
