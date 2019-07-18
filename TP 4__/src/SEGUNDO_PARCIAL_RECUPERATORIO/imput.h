
/**
  *\brief toma un string del usuario con un maximo y minimo de caracteres.
  *\param minimo y maximo de caracteres.
  *\param ubicacion de memoria donde se guardara el string.
  *\return el valor 0 si todo es correcto y -1 si los datos son incorrectos.
*/
int getString(char* msg,int minimo,int maximo,char *resultado);

/**
  *\brief indica con un TRUE cuando los datos son solo LETRAS.
  *\param el string a validad.
  *\return 0 cuando los datos son incorrectos y 1 cuando son correctos.
**/
int isValidName(char str[]);

/**
  *\brief Toma un string y valida que todos los caracteres sean numericos devolviendo un TRUE.
  *\param El string a validar.
  *\return TRUE(1) cuando los datos son correctos y FALSE(0) cuando no son correctos.
**/
int isValidNumber(char strNumber[]);

/**
  *\brief valida un rango de valores numericos devolviendo TRUE cuando el dato se encuentra en el rango.
  *\param un valor maximo y minimo y el entero que queremos validar.
  *\return TRUE(1) cuando el numero se encuentra en el rango y FALSE(0) en caso contrario.
**/
int isValidRange(int desde,int hasta,int numero);

/**
  *\brief Valida si el array de DNI es completo.
  *\param Recibe el array con la cadena de numerica.
  *\return TRUE o FALSE.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidDni(char str[]);

/**
  *\brief Obtiene un string por teclado y lo valida que sea numerico.
  *\param el msg, el minimo y maximo de caracteres y el resultado.
  *\return -1 en caso de error y 0 si todo es correcto.
**/
int getInt(char* msg,int minCaracter ,int maxCaracter,int *result);
