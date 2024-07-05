#ifndef FUNCIONESLOL_H
#define FUNCIONESLOL_H

void ingresarProductos(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz);
void imprimirProductos(char NProducto[][30], float cantidadPrecio[][2]);
int* buscarProductoXNom(char NProducto[][30], char productoABus[], int tamanomatriz);
void imprimirProductoXIndex(char productoABus[], char NProducto[][30], float cantidadPrecio[][2], int* indices);
void editarProducto(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz);
void eliminarProducto(char NProducto[][30], float cantidadPrecio[][2], int tamanoMatriz);
void guardarProductos(const char* filename, char NProducto[][30], float cantidadPrecio[][2], int tamanoMatriz);
void cargarProductos(const char* filename, char NProducto[][30], float cantidadPrecio[][2], int* tamanoMatriz);

#endif
