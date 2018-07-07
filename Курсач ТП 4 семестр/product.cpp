#include "product.hpp"
static Product* products;
static unsigned int count;
unsigned int getCountOfProducts()
{
	return count;
}
void loadProducts(FILE* source)
{
    count = 0;
    if (fscanf(source, "%u", &count) != EOF)
    {
        products = (Product*)malloc(count* sizeof(Product));
        if (products)
        {
            for (size_t i = 0; i < count; ++i)
            {
                fscanf(source, "%u%s%u", &products[i].ID,
                    products[i].title,
                    &products[i].price);
				products[i].countOnStock = 0;
            }
        }
    }
}
void loadBalance(FILE* source)
{
	for (size_t i = 0; i < count; ++i)
	{
		unsigned int currentID;
		unsigned int currentCount;
		fscanf(source, "%u%u", &currentID, &currentCount);
		changeCountProductOnStock(currentID, currentCount, '=');
	}
}
void saveProducts(FILE* source)
{
    fprintf(source, "%u\n", count);
    for (size_t i = 0; i < count; ++i)
        fprintf(source, "%u %s %u\n", products[i].ID, products[i].title, products[i].price);
}
void saveBalance(FILE* source)
{
	for (size_t i = 0; i < count; ++i)
	{
		fprintf(source, "%u %u\n", products[i].ID, products[i].countOnStock);
	}
}
void showProducts()
{
    for (size_t i = 0; i < count; ++i)
        printf("%u %s %u\n", products[i].ID,
            products[i].title,
            products[i].price);
}

void menuEntryProducts()
{
    if (count > 0)
        showProducts();
    else
        printf("Empty product file\n");
    printf("Do you want to add new product[y/N]");
    char code;
    scanf("%c", &code);
    if (code != '\n')
        getchar();
    if (code == 'y')
    {
        products = (Product*)realloc(products, (count + 1) * sizeof(Product));
        unsigned int price;
        printf("Enter product's name: ");
        scanf("%s", products[count].title);
        printf("Enter product's cost: ");
        while (scanf("%u", &price) != 1)
            printf("invalid input\n");
        products[count].ID = count + 1;
        products[count].price = price;
		changeCountProductOnStock(count+1, 0, '=');
        printf("%u %s %u Succesfull added\n", products[count].ID, products[count].title, products[count].price);
        ++count;
        getchar();
    }
}
void menuEntrySales()
{
	unsigned int IDProduct;
	printf("Enter product ID\n");
	while (scanf("%u", &IDProduct) != 1 || IDProduct > getCountOfProducts() || IDProduct  < 1)
	{
		flush();
		printf("Enter product's ID: ");
	}
	unsigned int soldCount;
	printf("Enter count of sold products\n");
	while (scanf("%u", &soldCount) != 1)
	{
		flush();
		printf("Enter count of sold products: ");
	}
	changeCountProductOnStock(IDProduct, soldCount, '-');
	getchar();
}
void flush()
{
    while ((getchar()) != '\n')
        printf("invalid input\n");
}
void changeCountProductOnStock(unsigned int id, unsigned int newCount, char token)
{
	switch(token)
	{
	case '+':
		products[id-1].countOnStock += newCount;
		break;
	case '-':
		products[id-1].countOnStock -= newCount;
		break;
	case '=':
		products[id-1].countOnStock = newCount;
		break;
	}
}
void showBalanceForProductID()
{
	unsigned int IDProduct;
	printf("Enter product's ID: ");
	while (scanf("%u", &IDProduct) != 1)
	{
		flush();
		printf("Enter product's ID: ");
	}
	printf("Input product's ID count: %u\n", products[IDProduct-1].countOnStock * products[IDProduct-1].price);
    getchar();
}
