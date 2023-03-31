#include <iostream>
#include <array>
#include <cstdlib> //To clear the console

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
    system("cls || clear");
    //Some ASCII art from: https://textkool.com/en/ascii-art-generator
    //Had to add \ to every \ using M.Word, because of being special character
    cout<<" __      __         .__                                         __                __   .__                 ___.                .___                         "<<endl;
    cout<<"/  \\    /  \\  ____  |  |    ____   ____    _____    ____      _/  |_  ____      _/  |_ |  |__    ____      \\_ |__  _____     __| _/_____     ______  ______ "<<endl;
    cout<<"\\   \\/\\/   /_/ __ \\ |  |  _/ ___\\ /  _ \\  /     \\ _/ __ \\     \\   __\\/  _ \\     \\   __\\|  |  \\ _/ __ \\      | __ \\ \\__  \\   / __ | \\__  \\   /  ___/ /  ___/ "<<endl;
    cout<<" \\        / \\  ___/ |  |__\\  \\___(  <_> )|  Y Y  \\\\  ___/      |  | (  <_> )     |  |  |   Y  \\\\  ___/      | \\_\\ \\ / __ \\_/ /_/ |  / __ \\_ \\___ \\  \\___ \\  "<<endl;
    cout<<"  \\__/\\  /   \\___  >|____/ \\___  >\\____/ |__|_|  / \\___  >     |__|  \\____/      |__|  |___|  / \\___  >     |___  /(____  /\\____ | (____  //____  >/____  > "<<endl;
    cout<<"       \\/        \\/            \\/              \\/      \\/                                   \\/      \\/          \\/      \\/      \\/      \\/      \\/      \\/  "<<endl;
    //       cout<<endl;                                                                                                                                                     
    cout<<"                              __           .__                            .__                            ._.._.._.                                          "<<endl;
    cout<<"              _____  _____  _/  |_ _______ |__|___  ___      ______ ____  |  | ___  __  ____ _______     | || || |                                          "<<endl;
    cout<<"             /     \\ \\__  \\ \\   __\\\\_  __ \\|  |\\  \\/  /     /  ___//  _ \\ |  | \\  \\/ /_/ __ \\\\_  __ \\    | || || |                                          "<<endl;
    cout<<"            |  Y Y  \\ / __ \\_|  |   |  | \\/|  | >    <      \\___ \\(  <_> )|  |__\\   / \\  ___/ |  | \\/     \\| \\| \\|                                          "<<endl;
    cout<<"            |__|_|  /(____  /|__|   |__|   |__|/__/\\_ \\    /____  >\\____/ |____/ \\_/   \\___  >|__|        __ __ __                                          "<<endl;
    cout<<"                  \\/      \\/                         \\/         \\/                         \\/             \\/ \\/ \\/                                          "<<endl;


    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    //Probamos la función miMatriz
    cout<<"Imprimimos la matriz:"<<endl;
    ImprimirMatriz(miMatriz);

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
    int variables = miMatriz[0].size()-1;
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
    cout<<"---------------------------"<<endl;
    int variables = miMatriz[0].size()-1;
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
    //TODO
    cout<<"\nSolucion:"<<endl;
    cout<<"x0 = "<<miMatriz[0][3]<<endl;
    cout<<"x1 = "<<miMatriz[1][3]<<endl;
    cout<<"x2 = "<<miMatriz[2][3]<<endl;
    return;
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    //TODO
    
    float divisor00 = miMatriz[0][0];
    for(int i=0; i<miMatriz[0].size() && divisor00!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[0][i] /= divisor00;
    } 
    
    cout<<"Divido fila 0"<<endl;
    ImprimirMatriz(miMatriz);

    float divisor10 = miMatriz[1][0] / divisor00;
    cout<<divisor10;
    for(int i=0; i<miMatriz[0].size(); i++){ //recorre todos los valores de la matriz en la segunda ecuación
        miMatriz[1][i] -= miMatriz[0][i] * divisor10;
    }
    
    cout<<"Resto a fila 1 su.. complemento? de la fila 0"<<endl;

    ImprimirMatriz(miMatriz);

    float divisor20 = miMatriz[2][0]; // divisor00; antes dividiamos aquí
    for(int i=0; i<miMatriz[0].size(); i++){ //recorre todos los valores de la matriz en la tercera ecuación
        miMatriz[2][i] -= miMatriz[0][i] * divisor20;
    }
    cout<<"Resto a fila 2 su.. complemento? de la fila 0"<<endl;

    ImprimirMatriz(miMatriz);


    cout<<"En este punto sólo se tiene un 1 en la primera columna. Seguimos escalonando..."<<endl;


    float divisor11 = miMatriz[1][1];
    cout<<divisor11<<endl;
    for(int i=0; i<miMatriz[0].size() && divisor11!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[1][i] /= divisor11;
    } 
    
    cout<<"Divido segunda fila"<<endl;
    ImprimirMatriz(miMatriz);

    float divisor21 = miMatriz[2][1];// / divisor11;
    cout<<divisor21<<endl;
    for(int i=0; i<miMatriz[0].size(); i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[2][i] -= miMatriz[1][i] * divisor21;
    }
    
    cout<<"Resto a 2da fila su.. complemento? de la fila 1"<<endl;

    ImprimirMatriz(miMatriz);

    cout<<"Ya tenemos dos 1 escalonados, nos queda el final"<<endl;
    
    float divisor22 = miMatriz[2][2];
    cout<<divisor22<<endl;
    for(int i=0; i<miMatriz[0].size() && divisor22!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[2][i] /= divisor22;
    } 
    
    cout<<"Divido tercera fila"<<endl;
    ImprimirMatriz(miMatriz);

    cout<<"Ya está Gaussssssssssssssssssssssssssssssssssssssssssss, queda el Jordan!"<<endl;


    float divisor12 = miMatriz[1][2];
    cout<<divisor12<<endl;
    for(int i=0; i<miMatriz[0].size() && divisor12!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[1][i] -= miMatriz[2][i] * divisor12;
    } 
    
    cout<<"resto la tercer fila a la segunda"<<endl;
    ImprimirMatriz(miMatriz);

    float divisor02 = miMatriz[0][2];
    cout<<divisor02<<endl;
    for(int i=0; i<miMatriz[0].size() && divisor02!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[0][i] -= miMatriz[2][i] * divisor02;
    } 
    
    cout<<"resto la tercer fila a la primera"<<endl;
    ImprimirMatriz(miMatriz);

    cout<<"Ya está casi... sólo falta la última columna..."<<endl;
    float divisor01 = miMatriz[0][1];
    cout<<divisor01<<endl;
    for(int i=0; i<miMatriz[0].size() && divisor01!=0; i++){ //recorre todos los valores de la matriz en la primera ecuación
        miMatriz[0][i] -= miMatriz[1][i] * divisor01;
    } 
    
    cout<<"resto la tercer fila a la segunda"<<endl;
    ImprimirMatriz(miMatriz);

    return;
}

/*
1
2
3
4
2
3
4
5
6
9
8
7

1
-2
-2
-24
1
1
1
48
2
-6
4
12

Debería dar: 40, 10, -2
*/

//Key changes: Changed miMatriz.size() to miMatriz[0].size()
