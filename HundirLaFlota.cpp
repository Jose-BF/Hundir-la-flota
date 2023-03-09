//Codigo hecho por Jose Blanco Fleury ©

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//Funcion para mostrar el tablero
void mostrarTablero(char tablero[6][6]){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Funcion Para Crear Barcos 3x1
void crearBarco31(char tablero[6][6], int fila, int columna){
    tablero[fila][columna]='^';
    tablero[fila][columna+1]='^';
    tablero[fila][columna+2]='^';
}

//Funcion Para Crear Barcos 1x3
void crearBarco13(char tablero[6][6], int fila, int columna){
    tablero[fila][columna]='^';
    tablero[fila+1][columna]='^';
    tablero[fila+2][columna]='^';
}

//Funcion Para Crear Barcos 2x1
void crearBarco21(char tablero[6][6], int fila, int columna){
    tablero[fila][columna]='^';
    tablero[fila][columna+1]='^';
}

//Funcion Para crear barcos 1x2
void crearBarco12(char tablero[6][6], int fila, int columna){
    tablero[fila][columna]='^';
    tablero[fila+1][columna]='^';
}

bool disparo(char tablero[6][6]){
    bool quedanBarcos = false;
    
    int fila, columna;
    char entrada_fila, entrada_columna;

    // Solicitamos la fila y verificamos que sea un número entre 0 y 5
    do {
        cout << "Introduce la fila: ";
        cin >> entrada_fila;
        if (isdigit(entrada_fila)) {
            fila = entrada_fila - '0';
            if (fila < 0 || fila > 5) {
                cout << "Debe introducir un numero del 0 al 5." << endl;
            }

        } else {
            cout << "Debe introducir un numero del 0 al 5." << endl;
        }
    } while (fila < 0 || fila > 5);

    // Solicitamos la columna y verificamos que sea un número entre 0 y 5
    do {
        cout << "Introduce la columna: ";
        cin >> entrada_columna;
        if (isdigit(entrada_columna)) {
            columna = entrada_columna - '0';
            if (columna < 0 || columna > 5) {
                cout << "Debe introducir un numero del 0 al 5." << endl;
            }

        } else {
            cout << "Debe introducir un numero del 0 al 5." << endl;
        }
    } while (columna < 0 || columna > 5);

    // Comprobamos si la posición seleccionada es un barco, agua o una posición ya atacada
    if(tablero[fila][columna]=='^'){
        tablero[fila][columna]='#';
        cout << "\t\t///Tocado///" << endl;
    } else if(tablero[fila][columna]=='#'){
        cout << "\t\t///Ya habias Acertado///" << endl;
    } else if (tablero[fila][columna]=='~'){
        cout<<"\t\t///Agua///"<<endl;
        tablero[fila][columna]='+';
    }
     
    // Comprobamos si quedan barcos en el tablero
    int contadortocado=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(tablero[i][j]=='^'){
                quedanBarcos = true;
            }
            if (tablero[i][j]=='#'){
                contadortocado++;
            }
        }
    }
    
    if (contadortocado==7){
        cout<<"\n///Has ganado///"<<endl;
        quedanBarcos=false;
    }

    // Mostramos el tablero de disparos
    mostrarTablero(tablero);

    return quedanBarcos;
}


int main(){
cout<<endl;
cout<<"                                    ____       __      ___           __         _  _         _____    __         ______   ________  _____"<<endl;
cout<<"     //    / / //   / / /|    / / //    ) )   / /    //   ) )       / /        // | |       //   / / / /        //   ) ) /__  ___/ // | |"<<endl;
cout<<"    //___ / / //   / / //|   / / //    / /   / /    //___/ /       / /        //__| |      //___    / /        //   / /    / /    //__| |"<<endl;
cout<<"   / ___   / //   / / // |  / / //    / /   / /    / ___ (        / /        / ___  |     / ___    / /        //   / /    / /    / ___  |"<<endl;
cout<<"  //    / / //   / / //  | / / //    / /   / /    //   | |       / /        //    | |    //       / /        //   / /    / /    //    | |"<<endl;
cout<<" //    / / ((___/ / //   |/ / //____/ / __/ /___ //    | |      / /____/ / //     | |   //       / /____/ / ((___/ /    / /    //     | |"<<endl;



    //Preguntar por empezar el juego
    char respuesta;
    cout<<"\n \nBienvenido al juego de hundir la flota"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"-Debe de hundir todos los barcos para finalizar el juego"<<endl;
    cout<<"-Los barcos estan representados por este caracter ( ^ )"<<endl;
    cout<<"-Un disparo al agua se representa con este caracter ( + )"<<endl;
    cout<<"-Un disparo al barco se representa con este caracter ( # )"<<endl;
    cout<<"-Apareceran 3 barcos aleatoriamente entre 1x2, 2x1, 1x3 y 3x1"<<endl;
    cout<<"-El tablero es de 6x6"<<endl;
    cout<<"-Para disparar debe de introducir la fila y la columna"<<endl;
    cout<<"-En caso de introducir una instroduccion incorrecta, el juego finalizara"<<endl;
    cout<<"------------------------------------------------------------------------ \n"<<endl;

    char siono;
    while (true) {
    cout << "Quieres empezar el juego? (s/n):\n\n ";
    cout<<">> ";
    cin >> siono;
    if (siono == 'n' || siono == 'N') {
    cout << "Hasta la próxima" << endl;
    return 0;
    } else if (siono == 's' || siono == 'S') {
    cout << "\nComenzando..." << endl;
    break;
    } else {
    cout << "Respuesta incorrecta" << endl;
    }
    }
    cout<<endl<<endl;



    srand(time(NULL));

    //Creamos el tablero de 6x6
    char tablero[6][6];
    char disparos[6][6];
    
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
    filaBarco3x1 = rand()%5;
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
            disparos[i][j]= '~';
        }
    }
    
    do{
        //Inicializamos el tablero a 0
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
             tablero[i][j]= '~';
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

        //Comprobamos si hay 7 ^s en el tablero, en caso contrario, hay solapamiento y se vuelven a generar los barcos
        int contador = 0;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                if(tablero[i][j]=='^'){
                    contador++;
                }
            }
        }
        if(contador == 7){
            Solapan = false;
        }else{
            Solapan = true;
        }

    }while(Solapan == true);
    
    
    //Mostramos el tablero
    cout<<"TABLERO DE JUEGO"<<endl;
    mostrarTablero(tablero);

    //Empezamos a disparar
        
    while(disparo(tablero) == true){
    disparo(tablero);

    //Comprobamos los barcos hundidos
    if (Aleatorio3x1_1x3 == 0){
        if (tablero[filaBarco3x1][columnaBarco3x1] == '#' && tablero[filaBarco3x1][columnaBarco3x1+1] == '#' && tablero[filaBarco3x1][columnaBarco3x1+2] == '#'){
                cout<<"El barco de 3x1 esta hundido"<<endl;
        }
    }
    if (Aleatorio3x1_1x3 == 1){
        if (tablero[filaBarco1x3][columnaBarco1x3] == '#' && tablero[filaBarco1x3+1][columnaBarco1x3] == '#' && tablero[filaBarco1x3+2][columnaBarco1x3] == '#'){
                cout<<"El barco de 1x3 esta hundido"<<endl;
        }
    }

    if (Aleatorio2x1_1x2 == 0){
        if (tablero[filaBarco2x1_1][columnaBarco2x1_1] == '#' && tablero[filaBarco2x1_1][columnaBarco2x1_1+1] == '#'){
                cout<<"El primer barco de 2x1 esta hundido"<<endl;
        }
    }
    if (Aleatorio2x1_1x2 == 1){
        if (tablero[filaBarco1x2_1][columnaBarco1x2_1] == '#' && tablero[filaBarco1x2_1+1][columnaBarco1x2_1] == '#'){
                cout<<"El primer barco de 1x2 esta hundido"<<endl;
        }
    }

    if (Aleatorio1x2_2x1 == 0){
        if (tablero[filaBarco2x1_2][columnaBarco2x1_2] == '#' && tablero[filaBarco2x1_2][columnaBarco2x1_2+1] == '#'){
                cout<<"El segundo barco de 2x1 esta hundido"<<endl;
        }
    }
    if (Aleatorio1x2_2x1 == 1){
        if (tablero[filaBarco1x2_2][columnaBarco1x2_2] == '#' && tablero[filaBarco1x2_2+1][columnaBarco1x2_2] == '#'){
                cout<<"El segundo barco de 1x2 esta hundido"<<endl;
        }
    }

    }

    return 0;

}

