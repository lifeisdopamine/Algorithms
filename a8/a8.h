#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car {
        int inventoryID;
        char make[15];
        char model[15];
        int year;
        int mileage;
        int price;
};

struct ncar {
        int price;
        int year;
        int mileage;
        int inventoryID;
        struct ncar *Pleft;
        struct ncar *Pright;
        struct ncar *Yleft;
        struct ncar *Yright;
        struct ncar *Mleft;
        struct ncar *Mright;
};
struct mcar{
        struct ncar *minPrice;
        struct ncar *maxYear;
        struct ncar *maxMileage;
        char make[15];
        char model[15];
};
struct mcar **arr = NULL;
int size_arr = -1;

void addNewCar(struct car newCar);
void listAllCarsOfModelPriced(char model[], int minPrice, int maxPrice);
void listAllCarsOfModelWithMaxMileageOf(char model[], int maxMileage);
void listAllCarsOfModelNewerThan(char model[], int year);
void deleteCar(int inventoryID);
void insert(int index, struct car newCar);
struct ncar *insert_mileage(struct ncar *head, struct ncar *node);
struct ncar *insert_year(struct ncar *head, struct ncar *node);
struct ncar *insert_price(struct ncar *head, struct ncar *node);
struct ncar *create_ncar(struct car newCar);
int find_model(char model[]);
struct ncar *find_min_price(struct ncar *root);
struct car convert2car(struct mcar *a, struct ncar *node);
void search(struct ncar * root, int a, int b, int index);
void max_miles(struct ncar *root, int m, int index);
void listAllCarsOfModelNewerThan(char model[], int year);
void newest_car(struct ncar *root, int y, int index);
struct car findCheapestCarOfModel(char model[]);
void print_details(int index, struct ncar * root);

