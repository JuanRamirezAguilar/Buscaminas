#include <iostream>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10

#define VB "\x1b[1;32m" // 1
#define AQB "\x1b[1;36m" // 2
#define MB "\x1b[1;35m" // 3
#define AB "\x1b[1;33m" // 4
#define RB "\x1b[1;31m" // 5
#define RF "\x1b[0;31m"
#define RTNC "\x1b[0m"
#define ROJOFONDO "\x1b[1;31;41m"

using namespace std;

class Buscaminas {
    private:
        bool Tablero[FILAS][COLUMNAS];
        int tableroDeMinas[FILAS][COLUMNAS];
        char tablero_de_juego[FILAS][COLUMNAS];

    public:
        Buscaminas() {
            srand(time(NULL));
            int seed = 0;
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    seed = (1 + rand() % 10);
                    if (seed == 5 || seed == 10) {
                        //Tablero[i][j] = char(1);
                        Tablero[i][j] = true;
                    } else {
                        Tablero[i][j] = false;
                    }
                }
            }
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    if (Tablero[i][j] == true) {
                        tableroDeMinas[i][j] = -1;
                    } else {
                        tableroDeMinas[i][j] = calcular_minas(i, j);
                    }
                }
            }
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    tablero_de_juego[i][j] = char(254);
                }
            }
        }
        void imprimir_tablero_juego () {
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    cout << tablero_de_juego[i][j] << " ";
                }
                cout<<endl;
            }
        }
        short calcular_minas(int fila, int columna) {
            short cont = 0;
            for (int i = fila - 1; i <= fila + 1; i++) {
                for (int j = columna - 1; j <= columna + 1; j++) {
                    if (i >= 0 && i < FILAS && j >= 0 && j < COLUMNAS && !(i == fila && j == columna) && Tablero[i][j] == 1) {
                        cont++;
                    }
                }
            }
            return cont;
        }
        void imprimir_tablero_binario () {
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    if (Tablero[i][j]) {
                        cout << RB << 1 << RTNC << " ";
                    } else {
                        cout << VB << 0 << RTNC << " ";
                    }
                }
                cout<<endl;
            }
        }
        void imprimir_tablero () {
            short total_minas;
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    total_minas = tableroDeMinas[i][j];
                    if (total_minas == -1) {
                        cout  << RF << "*" << RTNC << " ";
                    } else {
                        if (total_minas == 1) {
                            cout << VB << total_minas << RTNC << " ";
                        } else {
                            if (total_minas == 2) {
                                cout << AQB << total_minas << RTNC << " ";
                            } else {
                                if (total_minas == 3) {
                                    cout << MB << total_minas << RTNC << " ";
                                } else {
                                    if (total_minas == 4) {
                                        cout << AB << total_minas << RTNC << " ";
                                    } else {
                                        if (total_minas >= 5) {
                                            cout << RB << total_minas << RTNC << " ";
                                        } else {
                                            cout << total_minas << " ";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                cout<<endl;
            }
        }
};


void gotoxy (int x,int y) {

    printf("%c[%d;%df",0x1B,y,x);

}

/* Marco del programa(Cuadrado) */

void setborder (int columaTam, int filaTam) {

    int columnaX, FilaY;

    for (columnaX = 1; columnaX <= columaTam; columnaX++) {
            
        gotoxy(columnaX, 0);
        putchar(char(223));
        gotoxy(columnaX, filaTam);
        putchar(char(220));

    }

    for (FilaY = 1; FilaY <= filaTam; FilaY++) {
            
        gotoxy(0, FilaY);
        putchar(char(219));
        gotoxy(columaTam, FilaY);
        putchar(char(219));

    }

}

int main () {

    Buscaminas juego;

    system("cls");
    juego.imprimir_tablero_binario();
    cout<<endl<<endl;
    juego.imprimir_tablero();
    cout<<endl<<endl;
    juego.imprimir_tablero_juego();

    return 0;
}