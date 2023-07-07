/*
** EPITECH PROJECT, 2023
** day05
** File description:
** string
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string_s {
    char *str;
    void (*assign_c)(struct string_s *this, const char *s);
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this , size_t pos);
    void (*clear)(struct string_s *this);
    int (*lenght)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    const char *(*c_str)(const struct string_s *this);
    int (*empty)(const struct string_s *this);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    int (*find_s)(const struct string_s *this,
    const struct string_s *str, size_t pos);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    void (*insert_c)(struct string_s *this, size_t pos, const char *str);
    void (*insert_s)(struct string_s *this, size_t pos,
    const struct string_s *str);
    int (*to_int)(const struct string_s *this);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this , size_t pos);
void clear(string_t *this);
int lenght (const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t * this, const char *str);
const char *c_str(const string_t *this);
int empty(const string_t *this);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
