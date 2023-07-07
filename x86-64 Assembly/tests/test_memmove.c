/*
** EPITECH PROJECT, 2023
** Assembly
** File description:
** test_memmove
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

static void *(*load_memmove(void *lib_handle))(void *, const void *, size_t)
{
    void *(*my_memmove)(void *, const void *, size_t) = dlsym(lib_handle, "memmove");
    if (!my_memmove) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    return my_memmove;
}

Test(memmove, copies_data_correctly) {
    void *handle = test_lib();

    void *(*my_memmove)(void *, const void *, size_t) = load_memmove(handle);
    char src_buffer[] = "This is a test";
    char *dest_buffer = (char *)malloc(strlen(src_buffer) + 1);
    my_memmove(dest_buffer, src_buffer, strlen(src_buffer) + 1);
    cr_assert_str_eq(dest_buffer, "This is a test");
    src_buffer[0] = 't';
    src_buffer[1] = 'h';
    src_buffer[2] = 'a';
    src_buffer[3] = 't';
    my_memmove(dest_buffer, src_buffer, strlen(src_buffer) + 1);
    cr_assert_str_eq(dest_buffer, "that is a test");
    dlclose(handle);
}
