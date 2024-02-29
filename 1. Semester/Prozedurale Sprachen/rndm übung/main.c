#include <stdio.h>
#include <stdlib.h>

struct node
{
    int userID;
    int productID;
    int anzahl;
    struct node* next;
} typedef userProducts;

void skipLineInFile(FILE* file);
void printUserProducts(userProducts* data);
userProducts* readUserProducts();

int main(){
    userProducts* data = readUserProducts("C:\\Users\\Technikum\\Documents\\Prozedurale Sprachen\\UserProducts.csv");
    printUserProducts(data);
    return 0;
}

void skipLineInFile(FILE* file){
    char c;
    do {
        c = fgetc(file);
    } while (c != '\n');
}

void printUserProducts(userProducts* data)
{
    while(data != NULL)
    {
        printf("%d;%d;%d\n", data->userID, data->productID, data->anzahl);
        data = data->next;
    }
}

userProducts* readUserProducts(char* path)
{
    FILE* file;
    file = fopen(path, "r"); //Open to read
    if(file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }
    else{
        printf("File opened\n");
        skipLineInFile(file);

        userProducts* data = NULL;
        userProducts* last = NULL;

        int userID;
        int productID;
        int anzahl;

        while(fscanf(file, "%d;%d;%d\n", &userID, &productID, &anzahl) != EOF)
        {
            userProducts* current = malloc(sizeof(userProducts));
            current->userID = userID;
            current->productID = productID;
            current->anzahl = anzahl;
            current->next = NULL;

            if(data == NULL)
            {
                data = current;
            }
            else
            {
                last->next = current;
            }

            last = current;
        }
        fclose(file);

        return data;
    }
}

createUserAnzahl(userProducts* data) {

}
