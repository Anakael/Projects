#include "utils.hpp"

void init()
{
    files.products = fopen("products.txt", "r");
    loadProducts(files.products);
    fclose(files.products);
    files.balance = fopen("balance.txt", "r");
    loadBalance(files.balance);
    fclose(files.balance);
    files.invoices = fopen("invoices.txt", "r");
    loadInvoices(files.invoices);
    fclose(files.products);
}
void menu()
{
    char code;
    do
    {
        printf("Choose menu's item:\n"
               "1.Open product catalog\n"
               "2.Open invoice catalog\n"
               "3.Insert sale\n"
               "4.Show balance\n"
               "5.Exit\n");
        scanf("%c", &code);
        if (code != '\n')
            getchar();
        switch (code)
        {
        case '1':
            menuEntryProducts();
            break;
        case '2':
            menuEntryInvoices(getCountOfProducts());
            break;
        case '3':
			menuEntrySales();
            break;
        case '4':
			showBalanceForProductID();
            break;
        case '5':
            break;
        default:
            printf("Incorrect input\n");
            break;
        }
    } while (code != '5');
}

void saveFiles()
{
    files.products = fopen("products.txt", "w");
    saveProducts(files.products);
    fclose(files.products);
    files.balance = fopen("balance.txt", "w");
    saveBalance(files.balance);
    fclose(files.balance);
    files.invoices = fopen("invoices.txt", "w");
    saveInvoices(files.invoices);
    fclose(files.invoices);
}
