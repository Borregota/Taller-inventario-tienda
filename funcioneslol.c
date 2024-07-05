#include <stdio.h>
#include <string.h>
#include "funcioneslol.h"

int productos_ingresados = 0;

void ingresarProductos(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz) {
    int i, cantidad;
    printf("Ingrese la cantidad de productos que desea ingresar: ");
    scanf("%d", &cantidad);
    if (productos_ingresados + cantidad > tamanomatriz) {
        printf("Error: No hay suficiente espacio en la matriz para almacenar %d productos.\n", cantidad);
        return;
    }
    for (i = productos_ingresados; i < productos_ingresados + cantidad; i++) {  
        printf("Ingrese el nombre del producto %d: ", i+1);
        fflush(stdin);
        scanf("%s", NProducto[i]);
        printf("Ingrese la cantidad del producto %d: ", i+1);
        scanf("%f", &cantidadPrecio[i][0]);
        printf("Ingrese el precio del producto %d: ", i+1);
        scanf("%f", &cantidadPrecio[i][1]);
    }
    productos_ingresados += cantidad;
}

void imprimirProductos(char NProducto[][30], float cantidadPrecio[][2]) {
    printf("N.producto\tCantidad\tPrecio\n");
    for (int i = 0; i < productos_ingresados; i++) {
        printf("%s\t\t%.2f\t\t%.2f\n", NProducto[i], cantidadPrecio[i][0], cantidadPrecio[i][1]);
    }
}

int* buscarProductoXNom(char NProducto[][30], char productoABus[], int tamanomatriz) {
    static int indices[30];
    int cantidad = 0;
    for (int i = 0; i < tamanomatriz; i++) {
        if (strcmp(NProducto[i], productoABus) == 0)  { // El 0 nos da por lo que las dos cadenas son iguales, valor negativo a primera cadena es menor, positivo la primera es mayor
            indices[cantidad] = i;
            cantidad++;
        }
    }
    indices[cantidad] = -1;
    return indices;
}

void imprimirProductoXIndex(char productoABus[], char NProducto[][30], float cantidadPrecio[][2], int* indices) {
    int i = 0;

    while (indices[i] != -1) {
        printf("Index: %d\n", indices[i]);
        printf("N.producto\tCantidad\tPrecio\n");
        printf("%s\t\t%.2f\t\t%.2f\n", NProducto[indices[i]], cantidadPrecio[indices[i]][0], cantidadPrecio[indices[i]][1]);
        i++;
    }
    if (indices[i] = -1)
    {
        printf ("No se ingreso ningun producto aun.");
    }
    
}

void editarProducto(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz) {
    char productoABus[30];
    float nuevaCant, nuevoPrecio;
    printf("Ingrese el nombre del producto que desea editar: ");
    fflush(stdin);
    scanf("%s", productoABus);
    int* indices = buscarProductoXNom(NProducto, productoABus, tamanomatriz);
    if (indices[0] != -1) {
        int i = 0;
        while (indices[i] != -1) {
            printf("%d. %s\t%.2f\t%.2f\n", i+1, NProducto[indices[i]], cantidadPrecio[indices[i]][0], cantidadPrecio[indices[i]][1]);
            i++;
        }
        int opcion;
        printf("Seleccione el numero del producto que desea editar: ");
        scanf("%d", &opcion);
        int index = indices[opcion-1];
        printf("Ingrese la nueva cantidad: ");
        scanf("%f", &nuevaCant);
        printf("Ingrese el nuevo precio: ");
        scanf("%f", &nuevoPrecio);
        cantidadPrecio[index][0] = nuevaCant;
        cantidadPrecio[index][1] = nuevoPrecio;
    } else {
        printf("El producto ingresado no existe.\n");
    }
}
void eliminarProducto(char NProducto[][30], float cantidadPrecio[][2], int tamanoMatriz) {
    char productoABus[30];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    scanf("%s", productoABus);
    int* indices = buscarProductoXNom(NProducto, productoABus, tamanoMatriz);
    if (indices[0] != -1) {
        int i = 0;
        while (indices[i] != -1) {
            printf("%d. %s\t%.2f\t%.2f\n", i+1, NProducto[indices[i]], cantidadPrecio[indices[i]][0], cantidadPrecio[indices[i]][1]);
            i++;
        }
        int opcion;
        printf("Seleccione el numero del producto que desea eliminar: ");
        scanf("%d", &opcion);
        int index = indices[opcion-1];
        for (int i = index; i < tamanoMatriz - 1; i++) {
            strcpy(NProducto[i], NProducto[i+1]);
            cantidadPrecio[i][0] = cantidadPrecio[i+1][0];
            cantidadPrecio[i][1] = cantidadPrecio[i+1][1];
        }
        productos_ingresados--;
    } else {
        printf("El producto ingresado no existe.\n");
    }
}

void guardarProductos(const char* filename, char NProducto[][30], float cantidadPrecio[][2], int tamanoMatriz) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }
    for (int i = 0; i < productos_ingresados; i++) {
        fprintf(file, "%s %.2f %.2f\n", NProducto[i], cantidadPrecio[i][0], cantidadPrecio[i][1]);
    }
    fclose(file);
}

void cargarProductos(const char* filename, char NProducto[][30], float cantidadPrecio[][2], int* tamanoMatriz) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo para cargar.\n");
        return;
    }
    productos_ingresados = 0;
    while (fscanf(file, "%s %f %f", NProducto[productos_ingresados], &cantidadPrecio[productos_ingresados][0], &cantidadPrecio[productos_ingresados][1]) != EOF) {
        productos_ingresados++;
    }
    fclose(file);
}
