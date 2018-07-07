#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <stdio.h>
#include <stdlib.h>
struct Product
{
    unsigned int ID;
    char title[50];
    unsigned int price;
	unsigned int countOnStock;
};
unsigned int getCountOfProducts();
void loadProducts(FILE* source);
void saveProducts(FILE* source);
void loadBalance(FILE* source);
void saveBalance(FILE* source);
void showProducts();
void changeCountProductOnStock(unsigned int id, unsigned int count, char token);
void menuEntryProducts();
void menuEntrySales();
void showBalanceForProductID();
void flush();
#endif
