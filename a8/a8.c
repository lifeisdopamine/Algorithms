#include "a8.h"

int main(void) 
{
        FILE *fp = fopen("notes.txt","r");
        char buf[256];
        struct car tmp;
        while(fgets(buf, 256, fp)) {
                tmp.inventoryID = atoi(strtok(buf, " "));
                strcpy(tmp.make, strtok(NULL, " "));
                strcpy(tmp.model, strtok(NULL, " "));
                tmp.year = atoi(strtok(NULL, " "));
                tmp.mileage = atoi(strtok(NULL, " "));
                tmp.price = atoi(strtok(NULL, "\n"));
                addNewCar(tmp);
        }
        printf("Model Camri newer than 2010: \n");
        listAllCarsOfModelNewerThan(tmp.model, 2010);
        printf("Model Camri price ranging between 10,000 and 20.000 \n");
        listAllCarsOfModelPriced("Camri", 10000, 200000);
        printf("Model Camri Mileage greater or equal to 10,000 \n");
        listAllCarsOfModelWithMaxMileageOf("Camri", 10000);
        fclose(fp);
        return 0;
}

struct car create_structure(int price, int year, int inventoryID, char make[], char model[], int mileage)
{
        struct car tmp;
        tmp.price = price;
        tmp.year = year;
        tmp.inventoryID = inventoryID;
        tmp.mileage = mileage;
        strcpy(tmp.make, make);
        strcpy(tmp.model, model);
        return tmp;
}
struct car findCheapestCarOfModel(char model[])
{
        int index = find_model(model);
        struct ncar *tmp = find_min_price(arr[index] -> minPrice);
        struct car r = convert2car(arr[index],tmp);
        return r;
}
void addNewCar(struct car newCar)
{
        int index = find_model(newCar.model);
        if (index == -1) {
                size_arr++;
                arr = realloc(arr, sizeof(struct mcar *) * (size_arr + 1));
                arr[size_arr] = calloc(1, sizeof(struct mcar));
                insert(size_arr, newCar);
        } 
         else {
                insert(index, newCar);
        }
} 
/** In BST, think about the equality case: where to put if the values are equal: left or right
 */
void insert(int index, struct car newCar)
{
        struct ncar* node = create_ncar(newCar);
        node -> inventoryID = newCar.inventoryID;
        node -> price = newCar.price;
        node -> year = newCar.year;
        node -> mileage = newCar.mileage;
        arr[index] -> minPrice = insert_price(arr[index] -> minPrice, node);
        arr[index] -> maxYear = insert_year(arr[index] -> maxYear, node);
        arr[index] -> maxMileage = insert_mileage (arr[index] -> maxMileage, node);
        strcpy(arr[index] -> model, newCar.model);
        strcpy(arr[index] -> make, newCar.make);
}
int find_model(char model[])
{
        int i = 0;
        int len = strlen(model);
        for (i = 0; i <= size_arr; i++) {
                if (strncmp(arr[i] -> model, model, len) == 0)
                        return i;
        }
        return -1;
}
struct ncar *insert_mileage(struct ncar *head, struct ncar *node)
{
        if (head == NULL || head -> mileage == node -> mileage) {
                head = node;
                return head;
        } 
        if (head -> mileage > node -> mileage)
                head -> Mleft = insert_mileage(head -> Mleft, node);
        else if (head -> mileage < node -> mileage)
                head  -> Mright = insert_mileage(head -> Mright, node);
        return head;
}
struct ncar *insert_year(struct ncar *head, struct ncar *node)
{
        if (head == NULL || head -> year == node -> year) {
                head = node;
                return head;
        } 
        if (head -> year > node -> year)
                head -> Yleft = insert_year(head -> Yleft, node);
        else if (head -> year < node -> year)
                head -> Yright = insert_year(head -> Yright, node);
        return head;
}
struct ncar *insert_price(struct ncar *head, struct ncar *node)
{
        if (head == NULL || head -> price == node -> price) {
                head = node;
                return head;
        } 
        if (head -> price > node -> price)
                head -> Pleft = insert_price(head -> Pleft, node);
        else if (head -> price < node -> price)
                head -> Pright = insert_price(head -> Pright, node);
        return head;
}
struct ncar *create_ncar(struct car newCar)
{
        struct ncar *node = calloc(1, sizeof(struct ncar));
        node -> price = newCar.price;
        node -> year = newCar.year;
        node -> mileage = newCar.mileage;
        node -> inventoryID = newCar.inventoryID;
        return node;
}

struct ncar *find_min_price(struct ncar *root) 
{
        struct ncar *tmp = root;
        while (tmp -> Pleft)
                tmp = tmp -> Pleft;
        return tmp;
}
struct car convert2car(struct mcar *a, struct ncar *node)
{
        struct car tmp;
        tmp.inventoryID = node -> inventoryID;
        tmp.year = node -> year;
        tmp.mileage = node -> mileage;
        tmp.price = node -> price;
        strcpy(tmp.make, a -> make);
        strcpy(tmp.model, a -> model);
        return tmp;
}
void listAllCarsOfModelPriced(char model[], int minPrice, int maxPrice)
{
        int index = find_model(model);
        search(arr[index] -> minPrice, minPrice, maxPrice, index);
        return;        
}
void search(struct ncar * root, int a, int b, int index)
{
        if (root == NULL)
                return;
        if (root -> price >= a && root -> price <= b) {
                print_details(index, root);
                
        }
        search(root -> Pleft, a, b, index);
        search(root -> Pright, a, b, index);
        return;
}

void listAllCarsOfModelWithMaxMileageOf(char model[], int maxMileage)
{
        int index = find_model(model);
        max_miles(arr[index] -> maxMileage, maxMileage, index);
        return;
}
void max_miles(struct ncar *root, int m, int index)
{
        if (root == NULL)
                return;
        if (root -> mileage <= m) {
                print_details(index, root);
        }
        print_details(index, root -> Mleft);
        print_details(index, root -> Mright);
        /*
        if (root -> mileage < m) {
                max_miles(root -> Mright, m, index);
        } else {
                print_details(index, root);
                max_miles(root -> Mleft, m, index);
        }*/
        return;
}
void listAllCarsOfModelNewerThan(char model[], int year) 
{
        int index = find_model(model);
        newest_car(arr[index] -> maxYear, year, index);
        return;
}
void newest_car(struct ncar *root, int y, int index)
{
        if (root == NULL)
                return;
        if (root -> year > y) {
                print_details(index, root);
                //newest_car(root -> Yleft, y, index);
        }
        newest_car(root -> Yleft, y, index);
        newest_car(root -> Yright, y, index);
        /*
        else if (root -> year < y)
                newest_car(root -> Yright, y, index);*/
        return;  
}
void print_details(int index, struct ncar * root)
{
        printf("Model: %s       Make: %s        Year: %d        Mileage: %d     Price:%d         \n\n\n", arr[index] -> model, arr[index] -> make, root -> year, root -> mileage, root -> price);
}
void delete_node(int inventoryID)
{

}