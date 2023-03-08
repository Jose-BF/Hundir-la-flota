
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

bool disparo(int tablero[6][6]){
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
    int Aleatorio3x1_1x3;
    int Aleatorio2x1_1x2;
    int Aleatorio1x2_2x1; 

    //Variables filasbarco y columnasbarco
    int filaBarco3x1;
    int columnaBarco3x1;

    int filaBarco1x3;
    int columnaBarco1x3;

    int filaBarco2x1_1;
    int columnaBarco2x1_1;

    int filaBarco1x2_1;
    int columnaBarco1x2_1;

    int filaBarco2x1_2;
    int columnaBarco2x1_2;      

    int filaBarco1x2_2;
    int columnaBarco1x2_2;

    //Randomificamos las variables
    filaBarco3x1 = rand()%6;
    columnaBarco3x1 = rand()%4;

    filaBarco1x3 = rand()%4;
    columnaBarco1x3 = rand()%6;

    filaBarco2x1_1 = rand()%6;
    columnaBarco2x1_1 = rand()%5;

    filaBarco1x2_1 = rand()%5;
    columnaBarco1x2_1 = rand()%6;
    
    filaBarco2x1_2 = rand()%6;
    columnaBarco2x1_2 = rand()%5;

    filaBarco1x2_2 = rand()%5;
    columnaBarco1x2_2 = rand()%6;
    

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


        //CREACION BARCO 3X1 O 1X3
        //randomificamos el numero aleatorio a 0 o 1
        Aleatorio3x1_1x3 = rand()%2;
    
        //si aleatorio3x1_1x3 es 0, creamos un barco de 3x1
        if(Aleatorio3x1_1x3 == 0){
            crearBarco31(tablero, filaBarco3x1, columnaBarco3x1); 
        }else{Aleatorio3x1_1x3 == 1;
            crearBarco13(tablero, filaBarco1x3, columnaBarco1x3);
        }


        //CREACION BARCO 2X1 O 1X2
        //randomificamos un numero aleatorio
        Aleatorio2x1_1x2 = rand()%2;

        //si aleatorio es 0, creamos un barco de 2x1
        if(Aleatorio2x1_1x2 == 0){
            crearBarco21(tablero, filaBarco2x1_1, columnaBarco2x1_1);
        }else{Aleatorio2x1_1x2 == 1;
            crearBarco12(tablero, filaBarco1x2_1, columnaBarco1x2_1);
        }

        //CREACION 2º BARCO 2X1 O 1X2
        //randomificamos un numero aleatorio
        Aleatorio1x2_2x1 = rand()%2;

        //si aleatorio es 0, creamos un barco de 2x1
        if(Aleatorio1x2_2x1 == 0){
            crearBarco21(tablero, filaBarco2x1_2, columnaBarco2x1_2);
        }else{Aleatorio1x2_2x1 == 1; 
            crearBarco12(tablero, filaBarco1x2_2, columnaBarco1x2_2);
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
    
    //mostramos todas las posiciones de los barcos

    cout<<"Si el barco de 3 es horizontal/vertical (0 horizontal, 1 vertical): "<<Aleatorio3x1_1x3<<endl; 

    
    cout<<"Si el barco de 3 es horizontal, la fila es: "<<filaBarco3x1<<endl;
    cout<<"Si el barco de 3 es horizontal, la columna es: "<<columnaBarco3x1<<endl;

    cout<<"Si el barco de 3 es vertical, la fila es: "<<filaBarco1x3<<endl;
    cout<<"Si el barco de 3 es vertical, la columna es: "<<columnaBarco1x3<<endl;


    
    cout<<"Si el primer barco es de 2 es horizontal/vertical (0 horizontal, 1 vertical): "<<Aleatorio2x1_1x2<<endl;
    
    cout<<"Si el primer barco de 2 es horizontal, la fila es: "<<filaBarco2x1_1<<endl;
    cout<<"Si el primer barco de 2 es horizontal, la columna es: "<<columnaBarco2x1_1<<endl;

    cout<<"Si el primer barco de 2 es vertical, la fila es: "<<filaBarco1x2_1<<endl;
    cout<<"Si el primer barco de 2 es vertical, la columna es: "<<columnaBarco1x2_1<<endl;



    cout<<"Si el segundo barco es de 2 es horizontal/vertical (0 horizontal, 1 vertical): "<<Aleatorio1x2_2x1<<endl;

    cout<<"Si el segundo barco de 2 es horizontal, la fila es: "<<filaBarco2x1_2<<endl;
    cout<<"Si el segundo barco de 2 es horizontal, la columna es: "<<columnaBarco2x1_2<<endl;

    cout<<"Si el segundo barco de 2 es vertical, la fila es: "<<filaBarco1x2_2<<endl;
    cout<<"Si el segundo barco de 2 es vertical, la columna es: "<<columnaBarco1x2_2<<endl;



    //Mostramos el tablero
    cout << "Mostar tablero con barcos" << endl;
    mostrarTablero(tablero);

    //Empezamos a disparar
        
    while(disparo(tablero) == true){
    disparo(tablero);
    }

    return 0;

}
