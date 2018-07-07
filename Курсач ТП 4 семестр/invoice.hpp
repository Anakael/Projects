#ifndef INVOICE_HPP
#define INVOICE_HPP
#include <stdio.h>
#include <stdlib.h>
#include "product.hpp"
struct Invoice
{
    unsigned int ID;
    struct InvoiceEntry* entries;
    char date[10];
    unsigned int entriesCount;
};
struct InvoiceEntry
{
    unsigned int productID;
    unsigned int count;
};
static Invoice* invoices;
void loadInvoices(FILE* source);
void saveInvoices(FILE* source);
void showInvoices();
void menuEntryInvoices(unsigned int countOfProducts);
#endif
