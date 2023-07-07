/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_memset
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

static void *(*load_my_memset(void *test_lib))(void *, int, size_t)
{
    void *(*my_memset)(void *, int, size_t) = dlsym(test_lib, "memset");
    if (!my_memset) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_memset;
}

Test(memset, sets_memory_correctly) {
    void *handle = test_lib();
    void *(*my_memset)(void *, int, size_t) = load_my_memset(handle);
    char dest[20] = { 0 };
    int c = 'a';
    size_t n = 10;
    my_memset(dest, c, n);
    for (size_t i = 0; i < n; i++) {
        cr_assert_eq(dest[i], c, "Expected destination buffer to be filled with %d, but got %d at index %lu", c, dest[i], i);
    }
    dlclose(handle);
}
