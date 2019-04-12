#include <stdbool.h>
#include <stdio.h>

const int EDAD_USUARIO_MINIMA = 17;
const int INTE_USUARIO_MINIMA = 0;
const int INTE_USUARIO_MAXIMA = 10;
const int FUER_USUARIO_MINIMA = 0;
const int FUER_USUARIO_MAXIMA = 10;
const char DETENER_PROGRAMA = 'N';

/*PRECONDICIONES: Funcion que recibe un solo caracter en mayusculas.
 *
 *POSTCONDICIONES: El caracter saldra cargado dentro del programa.
 *
 */
void preguntar_ingreso_de_usuarios(char *continuar) {
  printf("\n Desea ingresar un alumno? (N para no, cualquier otra tecla para "
         "sí): ");
  scanf(" %c", continuar);
}

/*
 *PRECONDICIONES: Funcion que recibe un entero positivo equivalente a la edad
 *del usuario.
 *
 *POSTCONDICIONES: Saldra cargado con un entero positivo.
 */
void pedir_edad_usuarios(int *edad_usuario) {

  printf("\n Ingresar la edad del Usuario: ");
  scanf(" %i", edad_usuario);
}
/*
 *PRECONDICIONES: Funcion que recibe un entero positivo entre 0 y 10 equivalente
 *a la inteligencia del usuario.
 *
 *POSTCONDICIONES: Se cargara el entero positivo entre 0 y 10.
 */
void pedir_inteligencia_usuario(int *inte_usuario) {
  do {
    printf("\n Ingresar Inteligencia del Usuario (Esta sera un numero entre "
           "0 y 10): ");
    scanf("%i", inte_usuario);
  } while ((*inte_usuario) < INTE_USUARIO_MINIMA ||
           (*inte_usuario) > INTE_USUARIO_MAXIMA);
}
/*
 *PRECONDICIONES: Funcion que recibe un entero positivo entre 0 y 10 equivalente
 *a la fuerza del usuario.Atom Debugging UI Package

Provides a UI interface and basic functionality for building debugging inside
Atom.
 *
 *POSTCONDICIONES: Se cargara el entero positivo entre 0 y 10.
 */
void pedir_fuerza_usuario(int *fuer_usuario) {
  do {
    printf("\n Ingresar Fuerza del Usuario (Esta sera un numero entre 0 y "
           "10): ");
    scanf(" %i", fuer_usuario);
  } while ((*fuer_usuario) < FUER_USUARIO_MINIMA ||
           (*fuer_usuario) > FUER_USUARIO_MAXIMA);
}
/*
 *PRECONDICIONES: Funcion que recibe un solo caracter en mayusculas, dentro de
 *los caracteres permitidos se encuentran unicamente: B, R, M.
 *
 *POSTCONDICIONES: Se cargara un solo caracter en mayusculas dentro de
 *las condiciones de la funcion.
 */
void pedir_capacidad_magica_usuario(char *capacidad_mag_usuario) {
  do {
    printf("\n Ingresar Capacidad Magica del Usario (B)ueno, (R)egular o "
           "(M)ala: ");
    scanf(" %c", capacidad_mag_usuario);
  } while ((*capacidad_mag_usuario) != 'B' && (*capacidad_mag_usuario) != 'R' &&
           (*capacidad_mag_usuario) != 'M');
}
/*
 *PRECONDICIONES: Funcion que recibe y compara cada uno de los datos ingresados
 *por el usuario.
 *
 *POSTCONDICIONES: Devuelve un true o un false si se cumplen o no, las
 *condiciones de compracion.
 */
bool es_mejor_que_campeon(int inte_campeon, int fuer_campeon,
                          char capacidad_mag_campeon, int inte_usuario,
                          int fuer_usuario, char capacidad_mag_usuario) {

  if (inte_usuario > inte_campeon) {

    return true;

  } else if (inte_usuario == inte_campeon) {

    if (fuer_usuario > fuer_campeon) {

      return true;

    } else if (fuer_usuario == fuer_campeon) {

      if (capacidad_mag_campeon == 'B') {

        return true;
      }

      if (capacidad_mag_campeon == 'R' && capacidad_mag_usuario != 'B') {

        return true;
      }

      if (capacidad_mag_campeon == 'M' &&
          !(capacidad_mag_usuario == 'R' || capacidad_mag_usuario == 'B')) {

        return true;
      }
    }
  }
  return false;
}
/*
 *PRECONDICIONES: Funcion que recibe los datos ingresador por el usuario, ademas
 *de crear una condicion para el cambio de campeon.
 *
 *
 *POSTCONDICIONES: Se cargaran los datos ingresados por el usuario a la variable
 *indicada dentro de la funcion, ademas de asignar true a la varible
 *"cambio_campeon".
 */
void cambiar_el_campeon(int *inte_campeon, int *fuer_campeon,
                        char *capacidad_mag_campeon, int inte_usuario,
                        int fuer_usuario, char capacidad_mag_usuario,
                        bool *cambio_campeon) {

  *inte_campeon = inte_usuario;
  *fuer_campeon = fuer_usuario;
  *capacidad_mag_campeon = capacidad_mag_usuario;
  *cambio_campeon = true;
}
/*
 *PRECONDICIONES: Funcion que recibe la condicion de
 *"comparacion_datos_usuario_campeon" para llamar a "asignacion_de_campeon"
 *
 *POSTCONDICIONES: LLamara a la funcion "cambio_de_campeon" si se cumplen las
 *condiciones, y asignara un nuevo campeon.
 */
void es_campeon(int *inte_campeon, int *fuer_campeon,
                char *capacidad_mag_campeon, int inte_usuario, int fuer_usuario,
                char capacidad_mag_usuario, bool *cambio_campeon) {

  if (es_mejor_que_campeon(*inte_campeon, *fuer_campeon, *capacidad_mag_campeon,
                           inte_usuario, fuer_usuario, capacidad_mag_usuario)) {

    cambiar_el_campeon(inte_campeon, fuer_campeon, capacidad_mag_campeon,
                       inte_usuario, fuer_usuario, capacidad_mag_usuario,
                       cambio_campeon);
  }
}
/*
 *PRECONDICIONES: Funcion que recibe la posicion del campeon.
 *
 *POSTCONDICIONES: Imprime por consola la posicion del campeon.
 */
void imprimir_campeon(int numero_del_campeon) {
  if (numero_del_campeon == 0) {
    printf("\n No hay campeón :( \n");
  } else {
    printf("\n El campeón es el número %i :) \n", numero_del_campeon);
  }
}

int main() {

  int edad_usuario = 0;
  int inte_campeon = 0;
  int fuer_campeon = 0;
  char capacidad_mag_campeon = 0;
  int inte_usuario = 0;
  int fuer_usuario = 0;
  char capacidad_mag_usuario = 0;
  char continuar;
  int posicion_actual = 0;
  int posicion_campeon = 0;

  do {
    preguntar_ingreso_de_usuarios(&continuar);
    if (continuar != DETENER_PROGRAMA) {
      pedir_edad_usuarios(&edad_usuario);
      if (edad_usuario >= EDAD_USUARIO_MINIMA) {
        bool cambio_campeon = false;
        pedir_inteligencia_usuario(&inte_usuario);
        pedir_fuerza_usuario(&fuer_usuario);
        pedir_capacidad_magica_usuario(&capacidad_mag_usuario);
        es_mejor_que_campeon(inte_campeon, fuer_campeon, capacidad_mag_campeon,
                             inte_usuario, fuer_usuario, capacidad_mag_usuario);
        es_campeon(&inte_campeon, &fuer_campeon, &capacidad_mag_campeon,
                   inte_usuario, fuer_usuario, capacidad_mag_usuario,
                   &cambio_campeon);
        posicion_actual++;
        if (cambio_campeon) {
          posicion_campeon = posicion_actual;
        }
      }
    } else {
      imprimir_campeon(posicion_campeon);
    }
  } while (continuar != DETENER_PROGRAMA);

  return 0;
}
