#include <assert.h>  
#include <ctype.h>   
#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>

#define ErrorMinaEncontrada 1
#define ErrorEspacioYaUsado 2
#define NingunoError 3

#define COLUMNAS 5
#define FILAS 5
#define EspacioSinDescubrir '.'
#define EspacioDescubierto ' '
#define Minas 'X'
#define CuantasMinas 7  
#define DescubrirMinas 0 


int obtenerMinasCercanas(int fila, int columna, char tablero[FILAS][COLUMNAS]);
int aleatorioEnRango(int minimo, int maximo);
void iniciarTablero(char tablero[FILAS][COLUMNAS]);
void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]);
void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]);
void imprimirSeparadorEncabezado();
void imprimirSeparadorFilas();
void imprimirEncabezado();
char enteroACaracter(int numero);
void imprimirTablero(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas);
int abrirCasilla(char filaLetra, int columna, char tablero[FILAS][COLUMNAS]);
int noHayCasillasSinAbrir(char tablero[FILAS][COLUMNAS]);


int main() {
  printf("BUSCAMINAS\n");
  char tablero[FILAS][COLUMNAS];
  int deberiaMostrarMinas = 0;
  
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  
  while (1) {
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("Fila: ");
    scanf(" %c", &fila);
    printf("Columna: ");
    scanf("%d", &columna);
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("Has ganado!!!:)\n");
      deberiaMostrarMinas = 1;
    } else if (status == ErrorEspacioYaUsado) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ErrorMinaEncontrada) {
      printf("Has perdido!!!:(\n");
      deberiaMostrarMinas = 1;
    }
  }
  return 0;
}

int obtenerMinasCercanas(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= FILAS) {
    filaFin = FILAS - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNAS) {
    columnaFin = COLUMNAS - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (tablero[m][l] == Minas) {
        conteo++;
      }
    }
  }
  return conteo;
}

int aleatorioEnRango(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
  
void iniciarTablero(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      tablero[l][m] = EspacioSinDescubrir;
    }
  }
}

void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = Minas;  
}  

void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < CuantasMinas; l++) {
    int fila = aleatorioEnRango(0, FILAS - 1);
    int columna = aleatorioEnRango(0, COLUMNAS - 1);
    colocarMina(fila, columna, tablero);
  }
}

void imprimirSeparadorEncabezado() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("----");
    if (m + 2 == COLUMNAS) {
      printf("-");
    }
  }
  printf("\n");
}

void imprimirSeparadorFilas() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("+---");
    if (m == COLUMNAS) {
      printf("+");
    }
  }
  printf("\n");
}

void imprimirEncabezado() {
  imprimirSeparadorEncabezado();
  printf("|   ");
  int l;
  for (l = 0; l < COLUMNAS; l++) {
    printf("| %d ", l + 1);
    if (l + 1 == COLUMNAS) {
      printf("|");
    }
  }
  printf("\n");
}

char enteroACaracter(int numero) {
  return numero + '0';
}

void imprimirTablero(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  imprimirEncabezado();
  imprimirSeparadorEncabezado();
  char letra = 'A';
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    
    printf("| %c ", letra);
    letra++;
    for (m = 0; m < COLUMNAS; m++) {
      
      char verdaderaLetra = EspacioSinDescubrir;
      char letraActual = tablero[l][m];
      if (letraActual == Minas) {
        verdaderaLetra = EspacioSinDescubrir;
      } else if (letraActual == EspacioDescubierto) {
        
        int minasCercanas = obtenerMinasCercanas(l, m, tablero);
        verdaderaLetra = enteroACaracter(minasCercanas);
      }
      
      if (letraActual == Minas && (DescubrirMinas || deberiaMostrarMinas)) {
        verdaderaLetra = Minas;
      }
      printf("| %c ", verdaderaLetra);
      if (m + 1 == COLUMNAS) {
        printf("|");
      }
    }
    printf("\n");
    imprimirSeparadorFilas();
  }
}

int abrirCasilla(char filaLetra, int columna, char tablero[FILAS][COLUMNAS]) {
  
  filaLetra = toupper(filaLetra);
  
  columna--;
  
  int fila = filaLetra - 'A';
  assert(columna < COLUMNAS && columna >= 0);
  assert(fila < FILAS && fila >= 0);
  if (tablero[fila][columna] == Minas) {
    return ErrorMinaEncontrada;
  }
  if (tablero[fila][columna] == EspacioDescubierto) {
    return ErrorEspacioYaUsado;
  }
  
  tablero[fila][columna] = EspacioDescubierto;
  return NingunoError;
}

int noHayCasillasSinAbrir(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      char actual = tablero[l][m];
      if (actual == EspacioDescubierto) {
        return 0;
      }
    }
  }
  return 1;
}
