#ifndef UTILS_HPP
#define UTILS_HPP
#include "invoice.hpp"
#include "product.hpp"
#include <stdio.h>
#include <stdlib.h>
struct Files
{
    FILE* products;
    FILE* invoices;
    FILE* balance;
};
static Files files;
void init();
void menu();
void saveFiles();
#endif
