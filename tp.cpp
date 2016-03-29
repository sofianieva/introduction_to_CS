#include <iostream>
#include <string>

using namespace std;

//1-Función esPrimo
//Toma como argumento un número entero n y devuelve un booleano.

/**no se llaman parámetros? */

/* Hacemos una función que determine si el número n es primo.
Para eso, vamos comprobando si algún número entero, entre 2 y n, lo divide. La variable i va recorriendo esos valores mientras no divida a n.
En el caso de que n tenga un divisor distinto de 1 y n, se corta el ciclo antes de que i alcance el valor de n, y por lo tanto, la función devuelve el valor "false". Caso contrario, i alcanza el valor de n, y la función devuelve el valor "true". */

bool esPrimo(int n){	
	int i=2;
	while(i <n && n%i!=0){
		i=i+1;
	}
	return i==n;  
}

/* La línea "return i==n;" de la función anterior es equivalente al bloque:
	"if (i==n){
   		return true;
	}else{
		return false;
    	}"
*/ 


//2-Función cantidadPrimosMenoresOIguales
//Toma como argumento un número entero n y devuelve otro entero.

/**no se llaman parámetros? */

/* Hacemos una función que obtenga la cantidad de números primos menores o iguales a un número n.
Para eso, definimos la variable i, que recorre los números de 2 a n, y otra llamada contador. La última guarda la cantidad de primos hasta ese momento,incrementándose en uno cada vez que la función esPrimo evaluada en i devuelve "true". Finalmente, la función devuelve el valor contador. */

int cantidadPrimosMenoresOIguales(int n){
	int i=2;
	int contador=0;
	while(i<=n){
		if(esPrimo(i)){
		   contador=contador+1;
		}
		i=i+1;
	}
	return contador;
}

//3-Función cantidadDivisoresPrimos
//Toma como argumento un número entero n y devuelve otro entero.

/**no se llaman parámetros? */

/* Hacemos una función que obtenga la cantidad de divisores primos del número n.
Para eso, definimos nuevamente a la variable i, que recorre los enteros de 2 a n, y a otra contador.Esta última guarda la cantidad de divisores#FFA500 primos hasta ese momento, incrementándose en uno cada vez que la expresión esPrimo(i) es verdadera e i divida a n. Finalmente, la función devuelve el valor contador. */

int cantidadDivisoresPrimos(int n){
	int contador=0;
	int i=2;
	while(i<=n){
		if(esPrimo(i) && n%i==0){
		   contador=contador+1;
		}
		i=i+1;
	}
	return contador;
}

//4-Función iesimoDivisorPrimo
/*Toma como argumentos*/ /**no se llaman parámetros? */ /*dos enteros n e i y devuelve un entero.*/

/* Hacemos una función que obtenga el i-ésimo divisor primo de n.
***************************************************** */

/**
 * return dentro del while o el if?
 */


int iesimoDivisorPrimo(int n, int i){
	if(cantidadDivisoresPrimos(n)<i){
		return -1;
	}else{
		int contador=0;
		int j=2;
		while(j<=n){
			if(n%j==0 && esPrimo(j)){
				contador=contador+1;
			}
			if(contador==i){
				return j;
			j=j+1;
		}			
	}
}

//-1 si n no tiene i divisores primos

	/*int j=0;
	int k=2;
	int l;
	while(k<=n && j<=i){
		if(esPrimo(k) && n%k==0 && j<i){
			l=k;
			j=j+1;
		}
		k=k+1;
		
	}
	if((k-1)==n && j<=i && i<=cantidadDivisoresPrimos(n)){
	    	return l;
	}else{
		return -1;
	} 
}*/

//5-Función potenciaIesimoDivisorPrimo
//Toma como argumentos dos enteros n e i y devuelve un entero.

/**no se llaman parámetros? */

/* Hacemos una función para obtener la potencia del i-ésimo divisor primo de n en su descomposión en factores primos.
Para eso, primero vemos si la cantidad de divisores primos de n es menor que i, utilizando la función cantidadDivisoresPrimos.En este caso, la función devuelve -1. Si no, definimos dos variables: iesimo, que es el i-ésimo divisor primo de n, y potencia. Esta última la iniciamos en cero, y la incrementamos en uno hasta que iesimo^(potencia+1) no divide a n.Finalmente el programa devuelve el valor de potencia. */

int potenciaIesimoDivisorPrimo(int n, int i){
	if(cantidadDivisoresPrimos(n)<i){
		return -1;
	}else{	
		int iesimo= iesimoDivisorPrimo(n,i);
		int potencia=0;
		while(n%iesimo==0){
			potencia=potencia +1;
			n=n/iesimo;
		}
		return potencia;
	}
}

		
//Función main
/* Con esta función podemos elegir por línea de comandos, cuál de las funciones anteriores utilizar y con qué argumentos.*/

/**no se llaman parámetros? */

/*Para esto utilizamos un condicional que evalúa que el primer argumento de la línea de comandos sea igual a la función con el mismo nombre. De acuerdo a eso, utiliza la misma e imprime por pantalla los valores que se esperan. */		

/**redactar mejor */

int main(int argc, char* argv[]){
	string funcion=argv[1];
	int n=atoi(argv[2]);
	
	if(funcion.compare("esPrimo")==0){
		if (esPrimo(n)){
		cout << "Si" << endl;
		}else{
		cout << "No" << endl;
		}

	}else if(funcion.compare("cantidadPrimosMenoresOIguales")==0){
		int j=cantidadPrimosMenoresOIguales(n);
		cout << j << endl;
	
	}else if(funcion.compare("cantidadDivisoresPrimos")==0){
		int j=cantidadDivisoresPrimos(n);
		cout << j << endl;
		
	}else if(funcion.compare("iesimoDivisorPrimo")==0){
		int i=atoi(argv[3]);
		int j=iesimoDivisorPrimo(n,i);
		if(j==-1){
			cout << n << " no tiene " << i << " divisores primos."<< endl;
		}else{
		cout << j << endl;
		}

	}else if(funcion.compare("potenciaIesimoDivisorPrimo")==0){
		int i=atoi(argv[3]);
		int j=potenciaIesimoDivisorPrimo(n,i);
		if(j==-1){
			cout << n << " no tiene " << i << " divisores primos."<< endl;
		}else{
		cout << j << endl;
		}
	}return 0;
}	

	
	  
