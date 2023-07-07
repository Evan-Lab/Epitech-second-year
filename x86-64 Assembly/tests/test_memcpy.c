/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_memcpy
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

static void *(*load_my_memcpy(void *handle))(void *, const void *, size_t)
{
    void *(*my_memcpy)(void *, const void *, size_t) = dlsym(handle, "memcpy");
    if (!my_memcpy) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_memcpy;
}


Test(memcpy, copies_data_correctly) {
    void *handle = test_lib();
    void *(*my_memcpy)(void *, const void *, size_t) = load_my_memcpy(handle);
    char src[] = "Hello, world!";
    char dest[20];
    size_t n = sizeof(src);
    my_memcpy(dest, src, n);
    cr_assert_str_eq(dest, src, "Expected destination buffer to be equal to source buffer, but they are different");
    dlclose(handle);
}
