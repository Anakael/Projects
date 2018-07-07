#include "invoice.hpp"
static unsigned int count;
void loadInvoices(FILE* source)
{
    count = 0;
    if (fscanf(source, "%u", &count) != EOF)
    {
        invoices = (Invoice*)malloc(count * sizeof(Invoice));
        if (invoices)
        {
			for (size_t i = 0; i < count; ++i)
			{
				fscanf(source, "%u %s %u\n", &invoices[i].ID, invoices[i].date, &invoices[i].entriesCount);
				invoices[i].entries = (InvoiceEntry*)malloc(invoices[i].entriesCount * sizeof(InvoiceEntry));
				for (size_t j = 0; j < invoices[i].entriesCount; ++j)
				fscanf(source, "%u %u\n", &invoices[i].entries[j].productID, &invoices[i].entries[j].count);
			}
        }
    }
}
void saveInvoices(FILE* source)
{
	fprintf(source, "%u\n", count);
    for (size_t i = 0; i < count; ++i)
	{
        fprintf(source, "%u %s %u\n", invoices[i].ID, invoices[i].date, invoices[i].entriesCount);
		for (size_t j = 0; j < invoices[i].entriesCount; ++j)
			fprintf(source, "\t%u %u\n", invoices[i].entries[j].productID, invoices[i].entries[j].count);
	}
}
void showInvoices()
{
    for (size_t i = 0; i < count; ++i)
    {
        printf("%d %s:\n", invoices[i].ID, invoices[i].date);
        for (size_t j = 0; j < invoices[i].entriesCount; ++j)
            printf("\t%u %u\n", invoices[i].entries[j].productID, invoices[i].entries[j].count);
    }
}
void menuEntryInvoices(unsigned int countOfProducts)
{
    if (count > 0)
        showInvoices();
    else
        printf("Empty invoice file\n");
    printf("Do you want to add new invoice[y/N]");
    char code;
    scanf("%c", &code);
    if (code != '\n')
        getchar();
    if (code == 'y')
    {
        invoices = (Invoice*)realloc(invoices, (count + 1) * sizeof(Invoice));
        unsigned int entriesCount = 0;
        do
        {
            invoices[count].entries = (InvoiceEntry*)realloc(invoices[count].entries, (entriesCount + 1) * sizeof(InvoiceEntry));
            unsigned int productID;
            printf("Enter product's ID: ");
            while (scanf("%u", &productID) != 1 || productID < 1 || productID > countOfProducts)
            {
				flush();
                printf("Enter product's ID: ");
            }
            unsigned int countOfProductsInInvoice;
            printf("Enter product's count: ");
            while (scanf("%u", &countOfProductsInInvoice) != 1)
            {
                flush();
                printf("Enter product's count: ");
            }
			char flag = 0;
			for (size_t i = 0;i < entriesCount;++i)
			{
				if (invoices[count].entries[i].productID == productID)
				{
					invoices[count].entries[i].count += countOfProductsInInvoice;
					changeCountProductOnStock(productID, countOfProductsInInvoice, '+');
					flag = 1;
				}
			}
			if (!flag)
			{
				invoices[count].entries[entriesCount].productID = productID;
				invoices[count].entries[entriesCount].count = countOfProductsInInvoice;
				changeCountProductOnStock(productID, countOfProductsInInvoice, '+');
				++entriesCount;
			}
            printf("Do you want to add new invoice entry[y/N]\n");
            getchar();
            scanf("%c", &code);
            if (code != '\n')
                getchar();
        } while (code == 'y');
        invoices[count].entriesCount = entriesCount;
        invoices[count].ID = count + 1;
        printf("Enter invoice's date: ");
        scanf("%s", invoices[count].date);
        printf("%u %s %u Succesfull added\n", invoices[count].ID, invoices[count].date, invoices[count].entriesCount);
        ++count;
        getchar();
    }
}

