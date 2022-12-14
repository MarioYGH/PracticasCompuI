/*
Author:Mario Yahir García Hernández
email:marioygh15@gmail.com
october 11, 2022
*/

#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);


int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/* 
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/* 
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    int variables = miMatriz.size();
    cout << "\nSolución:" <<endl;
    for(int i = 0; i < variables; i++){
        cout <<"x" << i << " = "<< miMatriz[i][variables] << endl;
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    double upp;
    int index;
    double aux;
    double piv;

    int rows = miMatriz.size();
    for(int i = 0; i < rows; i++ ){
        upp = abs(miMatriz[i][i]);
        index = i;
        for(int j = i + 1; j < rows; j++){
            if(upp < abs(miMatriz[j][i])){
                upp = abs(miMatriz[j][i]);
                index = j;
            }
        }
        if(i != index){
            for(int m = 0; m < rows + 1; m++){
                aux = miMatriz[i][m];
                miMatriz[i][m] = miMatriz[index][m];
                miMatriz[index][m] = aux;
            }
        }
        if(miMatriz[i][i] == 0){
            cout << "No existe solucion\n";
        }
        else{
            for(int m = 0; m < rows; m++){
                if (m != i){
                    piv = -miMatriz[m][i];
                    for(int n = i; n < rows + 1; n++){
                        miMatriz[m][n] = miMatriz[m][n] + piv * miMatriz[i][n] / miMatriz[i][i];
                    }
                }
                else{
                    piv = miMatriz[i][i];
                    for(int n = i; n < rows + 1; n++){
                        miMatriz[m][n] = miMatriz[m][n] / piv;
                    }
                }
            }
        }
    }
}
