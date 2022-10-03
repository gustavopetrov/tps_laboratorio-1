int pedirInt(char mensaje[]);
int validarInt(char mensaje[], char mensajeError[], int minimo, int maximo);
float pedirFloat(char mensaje[]);
float validarFloat(char mensaje[], char mensajeError[], int minimo, int maximo);
char pedirChar(char mensaje[]);
void pedirString(char mensaje[], char cadena[]);

int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max);
int esNumerica(char* string);
