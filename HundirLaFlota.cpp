
//Codigo hecho por Jose Blanco Fleury ©

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//Funcion para mostrar el tablero
void mostrarTablero(int tablero[6][6]){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Funcion Para Crear Barcos 3x1
void crearBarco31(int tablero[6][6], int fila, int columna){
    tablero[fila][columna]=1;
    tablero[fila][columna+1]=1;
    tablero[fila][columna+2]=1;
}

//Funcion Para Crear Barcos 1x3
void crearBarco13(int tablero[6][6], int fila, int columna){
    tablero[fila][columna]=1;
    tablero[fila+1][columna]=1;
    tablero[fila+2][columna]=1;
}

//Funcion Para Crear Barcos 2x1
void crearBarco21(int tablero[6][6], int fila, int columna){
    tablero[fila][columna]=1;
    tablero[fila][columna+1]=1;
}

//Funcion Para crear barcos 1x2
void crearBarco12(int tablero[6][6], int fila, int columna){
    tablero[fila][columna]=1;
    tablero[fila+1][columna]=1;
}

bool disparo(int tablero[6][6], int disparos[6][6]){
    bool quedanBarcos = false;
    
    int fila, columna;
    cout << "Introduce la fila: ";
    cin >> fila;
    cout << "Introduce la columna: ";
    cin >> columna;

    if(tablero[fila][columna]==1){
        tablero[fila][columna]=2;
        cout << "\t\tTocado" << endl;
       
    }
    else if(tablero[fila][columna]==2){
        cout << "\t\tYa habias Acertado" << endl;
    }
    if (tablero[fila][columna]==0){
        cout<<"\t\tAgua"<<endl;
        tablero[fila][columna]=8;
    }
     
    //comprobamos si despues del disparo quedan barcos
    int contadortocado=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(tablero[i][j]==1){
                quedanBarcos = true;
            }
            if (tablero[i][j]==2){
                contadortocado++;
                
            }
        }
    }
    
    if (contadortocado==7){
        cout<<"Has ganado"<<endl;
        quedanBarcos=false;
    }

    //mostramos el tablero de disparos
    mostrarTablero(tablero);
    return quedanBarcos;

}

int main(){

    srand(time(NULL));

    //Creamos el tablero de 6x6
    int tablero[6][6];
    int disparos[6][6];
    
    //Creamos una variable aleatoria
    int aleatorio = 2;

    //Creamos una variable para saber si quedan barcos
    bool quedanBarcos = false;
    //Creamos una variable para saber si hay solapamiento
    bool Solapan = false;

    //inicializamos el tablero disparos a 0
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            disparos[i][j]= 0;
        }
    }

    do{
        //Inicializamos el tablero a 0
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
             tablero[i][j]= 0;
            }
        }

        //randomificamos un numero aleatorio
        aleatorio = rand()%2;

        //si aleatorio es 0, creamos un barco de 3x1
        if(aleatorio == 0){
            crearBarco31(tablero, rand()%6, rand()%4);
        }else{aleatorio == 1;
            crearBarco13(tablero, rand()%4, rand()%6);
        }

        //randomificamos un numero aleatorio
        aleatorio = rand()%2;

        //si aleatorio es 0, creamos un barco de 2x1
        if(aleatorio == 0){
            crearBarco21(tablero, rand()%6, rand()%5);
        }else{aleatorio == 1;
            crearBarco12(tablero, rand()%5, rand()%6);
        }

        //randomificamos un numero aleatorio
        aleatorio = rand()%2;

        //si aleatorio es 0, creamos un barco de 2x1
        if(aleatorio == 0){
            crearBarco21(tablero, rand()%6, rand()%5);
        }else{aleatorio == 1;
            crearBarco12(tablero, rand()%5, rand()%6);
        }

        //Comprobamos si hay 7 1s en el tablero
        int contador = 0;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                if(tablero[i][j]==1){
                    contador++;
                }
            }
        }

        //si hay 7 1s en el tablero, no hay solapamiento
        if(contador == 7){
            Solapan = false;
        }else{
            Solapan = true;
        }

    }while(Solapan == true);
    

    //Mostramos el tablero
    cout << "Mostar tablero con barcos" << endl;
    mostrarTablero(tablero);

    //Empezamos a disparar
        
    while(disparo(tablero, disparos) == true){
    disparo(tablero, disparos);
    }

    return 0;

}
