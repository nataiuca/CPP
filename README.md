1. Estructura básica de un programa en C++
   
La estructura mínima de un programa en C++ incluye:
#include <iostream>: Incluye la librería de entrada/salida estándar.
int main(): La función principal donde comienza la ejecución del programa.
return 0;: Indica que el programa terminó correctamente.
#include <iostream>

int main() {
    std::cout << "Hola, Mundo!" << std::endl;
    return 0;
}
 - std::cout: Es la salida estándar, que imprime información en la consola.
 - std::endl: Es un manipulador que imprime una nueva línea y vacía el buffer de salida.
 - return 0;: Esto termina el programa y devuelve un valor al sistema operativo. El valor 0 generalmente indica que el programa terminó sin errores.

TIPOS DE DATOS
En C++, hay varios tipos de datos fundamentales que usamos para almacenar valores. Algunos de los más comunes son:
int: Números enteros.
float: Números con decimales (precisión simple).
double: Números con mayor precisión decimal.
char: Caracteres (como letras o símbolos).
bool: Verdadero o falso (true o false).
std::string: Cadenas de texto (en la librería estándar).

OPERADORES EN C++
- Operadores aritméticos:
    +, -, *, /, % (módulo)
- Operadores de comparación:
   ==, !=, <, >, <=, >=
- Operadores lógicos:
  && (Y lógico), || (O lógico), ! (Negación)

ESTRUCTURAS DE CONTROL
Las estructuras de control son fundamentales para decidir qué hacer dependiendo de las condiciones o repetir algo varias veces. Las más comunes son condicionales y bucles.
Condicionales: if, else if, else
#include <iostream>

int main() {
    int edad = 18;

    if (edad >= 18) {
        std::cout << "Eres mayor de edad." << std::endl;
    } else {
        std::cout << "Eres menor de edad." << std::endl;
    }

    return 0;
}
if: Si la condición es verdadera, ejecuta el bloque de código.
else if: Si la condición anterior no se cumple, pero esta sí, ejecuta su bloque.
else: Si ninguna de las condiciones anteriores se cumple, ejecuta este bloque.
Bucle for
Se usa para repetir un bloque de código un número determinado de veces.
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Iteración número " << i << std::endl;
    }

    return 0;
}
La variable i comienza en 0 y se incrementa hasta que sea menor que 5.
Bucle while
El bucle while se repite mientras se cumpla una condición:#include <iostream>

int main() {
    int i = 0;
    while (i < 5) {
        std::cout << "Iteración número " << i << std::endl;
        i++;
    }

    return 0;
}
while: Se ejecuta mientras la condición sea verdadera.
Bucle do-while
El bucle do-while siempre se ejecuta al menos una vez, luego verifica la condición:#include <iostream>

int main() {
    int i = 0;
    do {
        std::cout << "Iteración número " << i << std::endl;
        i++;
    } while (i < 5);

    return 0;
}
El bloque de código se ejecuta al menos una vez, y luego la condición se evalúa.


2. Funciones y Parámetros en C++
   FUNCION
   Una función es un bloque de código que realiza una tarea específica. Las funciones permiten que un programa
   sea más organizado y fácil de entender. Además, las funciones te permiten evitar la repetición de código al
   agrupar operaciones comunes que puedes reutilizar.

Estructura básica de una función
   // TipoDeRetorno NombreDeLaFuncion(Parámetros) {
    // Bloque de código
    // return valor;  // Solo si la función tiene un tipo de retorno distinto de void
}
TipoDeRetorno: Es el tipo de valor que la función devuelve (por ejemplo, int, float, void si no devuelve nada).
NombreDeLaFuncion: Es el nombre de la función, que debe ser único dentro de su ámbito.
Parámetros: Son los valores que le pasamos a la función para que realice su tarea. Si no hay parámetros, dejamos los paréntesis vacíos.
Bloque de código: Contiene las instrucciones que se ejecutan cuando se llama a la función.
return: Especifica el valor que la función devuelve (si tiene tipo de retorno distinto de void).

  FUNCIONES SIN RETORNO (void)
Algunas funciones no necesitan devolver ningún valor. En este caso, usamos el tipo de retorno void

  PARAMETRO POR VALOR
Cuando pasas un valor a una función, lo que realmente estás pasando es una copia de ese valor. Esto se llama paso por valor

  PARAMETROS POR REFERENCIA
A veces quieres que los cambios hechos en los parámetros de una función afecten directamente a las variables que pasas. 
Para esto, puedes usar referencias. Esto se logra anteponiendo el operador & al tipo del parámetro en la función.
#include <iostream>

void cambiarValor(int& num) {
    num = 100;  // Cambia el valor de la variable original
}

int main() {
    int x = 50;
    cambiarValor(x);  // Pasamos x por referencia
    std::cout << "El valor de x después de la función: " << x << endl;  // x ahora es 100
    return 0;
}
Paso por referencia: Cuando usas int& num, cualquier cambio que se haga en num dentro de la función afectará directamente a x.

FUNCIONES CON MULTIPLES PARAMETROS
Puedes pasar varios parámetros a una función. Solo tienes que separarlos por comas.

FUNCIONES CON VALORES PREDETERMINADOS
Puedes establecer un valor predeterminado para un parámetro, lo que significa que si no pasas un valor al llamarla, la función usará ese valor por defecto.

FUNCIONES RECURSIVAS
Una función recursiva es aquella que se llama a sí misma. Las funciones recursivas son útiles para resolver problemas complejos que pueden ser descompuestos en subproblemas más pequeños.
Ejemplo: Factorial de un número
El factorial de un número n se define como el producto de todos los números enteros desde n hasta 1. El factorial de n se calcula de forma recursiva:
n! = n * (n-1)!
Caso base: 1! = 1


3. Clases y Objetos en C++

CLASE
Una clase es una plantilla o un "molde" para crear objetos. Define atributos (variables) y métodos (funciones) que los objetos de esa clase pueden tener.
Atributos: Representan el estado o las propiedades del objeto.
Métodos: Son las funciones que operan sobre los datos del objeto
Estructura básica de una clase:
class NombreDeLaClase {
public:
    // Atributos (propiedades)
    TipoDeDato atributo1;
    TipoDeDato atributo2;

    // Métodos (funciones)
    void metodo1() {
        // Acción
    }

    TipoDeDato metodo2() {
        // Acción
        return valor;
    }
};
class: La palabra clave para definir una clase.
public: Es un modificador de acceso que indica que los miembros (atributos o métodos) de la clase son accesibles desde fuera de la clase.
Ejemplo de clase simple:
#include <iostream>

class Persona {
public:
    // Atributos
    string nombre;
    int edad;

    // Método
    void saludar() {
        std::cout << "¡Hola, mi nombre es " << nombre << " y tengo " << edad << " años!" << endl;
    }
};

int main() {
    // Crear un objeto de la clase Persona
    Persona persona1;
    persona1.nombre = "Juan";
    persona1.edad = 30;

    // Llamar al método
    persona1.saludar();

    return 0;
}

INSTANCIAS DE UNA CLASE (OBJETOS)
Cuando creas un objeto, estás creando una instancia de una clase. Cada objeto tiene su propio conjunto de atributos y puede ejecutar 
los métodos definidos en la clase. En el ejemplo anterior, persona1 es una instancia de la clase Persona. Cada vez que declares un 
nuevo objeto de la clase, tendrás una nueva instancia de esa clase:

Persona persona2;  // Otra instancia de la clase Persona
persona2.nombre = "Ana";
persona2.edad = 25;
persona2.saludar();  // Imprime: ¡Hola, mi nombre es Ana y tengo 25 años!

MODIFICADORES DE ACCESO
En C++, los atributos y métodos de una clase pueden ser accesibles desde fuera de la clase o protegidos. 
Esto se controla mediante los modificadores de acceso:
 - public: Los miembros públicos pueden ser accedidos desde fuera de la clase.
 - private: Los miembros privados no pueden ser accedidos directamente desde fuera de la clase.
 - protected: Los miembros protegidos solo pueden ser accedidos desde la propia clase o clases derivadas (en caso de herencia).
Ejemplo de uso de private:
#include <iostream>

class Persona {
private:
    string nombre;  // Atributo privado
    int edad;       // Atributo privado

public:
    // Métodos públicos
    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;  // Establece el nombre
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;  // Establece la edad
    }

    void saludar() {
        std::cout << "¡Hola, mi nombre es " << nombre << " y tengo " << edad << " años!" << endl;
    }
};

int main() {
    Persona persona1;
    persona1.setNombre("Carlos");
    persona1.setEdad(35);
    persona1.saludar();  // Imprime: ¡Hola, mi nombre es Carlos y tengo 35 años!
    
    // No podemos acceder directamente a 'nombre' o 'edad' desde aquí.
    // persona1.nombre = "Luis";  // Error: 'nombre' es privado

    return 0;
}
En este ejemplo, los atributos nombre y edad son privados y no pueden ser modificados 
directamente desde fuera de la clase. En su lugar, usamos métodos públicos (setNombre y setEdad) 
para modificar esos valores.

CONSTRUCTORES Y DESTRUCTORES.
Un constructor es un método especial que se llama automáticamente cuando se crea un objeto de una clase. 
Se usa para inicializar los atributos del objeto.
El constructor tiene el mismo nombre que la clase y no tiene valor de retorno.
Un destructor es un método especial que se llama cuando el objeto se destruye (cuando deja de existir).
Constructor:
#include <iostream>

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string nom, int ed) {
        nombre = nom;
        edad = ed;
    }

    // Método
    void saludar() {
        std::cout << "¡Hola, mi nombre es " << nombre << " y tengo " << edad << " años!" << endl;
    }
};

int main() {
    // Crear un objeto utilizando el constructor
    Persona persona1("Juan", 30);
    persona1.saludar();  // Imprime: ¡Hola, mi nombre es Juan y tengo 30 años!

    return 0;
}
El constructor Persona(string nom, int ed) se llama automáticamente cuando se crea el objeto persona1. 
Inicializa los atributos nombre y edad con los valores que se pasan como parámetros al constructor.

Destructor:
El destructor se llama automáticamente cuando el objeto es destruido (por ejemplo, cuando sale del ámbito de la función).
class Persona {
public:
    // Destructor
    ~Persona() {
        std::cout << "Destructor llamado. El objeto Persona ha sido destruido." << endl;
    }
};

int main() {
    Persona persona1;  // El destructor se llama cuando persona1 sale del ámbito
    return 0;
}
El destructor ~Persona() se llama automáticamente cuando el objeto persona1 sale del ámbito y se destruye.

METODOS ESTATICOS
A veces, hay métodos o atributos que no necesitan estar asociados a un objeto en particular. 
En lugar de pertenecer a una instancia de la clase, pueden ser comunes para toda la clase. 
Estos se definen con la palabra clave static.
class Contador {
public:
    static int contador;  // Atributo estático

    static void incrementar() {  // Método estático
        contador++;
    }
};

// Inicialización del atributo estático
int Contador::contador = 0;

int main() {
    Contador::incrementar();
    Contador::incrementar();
    std::cout << "Contador: " << Contador::contador << endl;  // Imprime: Contador: 2
    return 0;
}
 - Métodos estáticos: Se pueden llamar sin crear una instancia de la clase, como Contador::incrementar().
 - Atributos estáticos: Son compartidos por todas las instancias de la clase.


4. Punteros y Referencias en C++

PUNTERO
Un puntero es una variable que almacena la dirección de memoria de otra variable. 
En lugar de almacenar el valor directo, el puntero almacena la dirección en la que se encuentra 
la variable en la memoria.
Sintaxis básica para declarar un puntero:
    TipoDeDato* nombreDelPuntero;
Ejemplo de puntero:
#include <iostream>

int main() {
    int x = 10;
    int* ptr = &x;  // 'ptr' es un puntero que almacena la dirección de 'x'

    std::cout << "Valor de x: " << x << endl;        // Imprime el valor de 'x'
    std::cout << "Dirección de memoria de x: " << &x << endl;  // Imprime la dirección de memoria de 'x'
    std::cout << "Valor de ptr (dirección de x): " << ptr << endl;  // Imprime la dirección de 'x'
    std::cout << "Valor apuntado por ptr: " << *ptr << endl;  // Imprime el valor en la dirección que apunta 'ptr'

    return 0;
}
En este ejemplo:
&x: El operador & obtiene la dirección de memoria de x.
ptr: Es un puntero que almacena la dirección de memoria de x.
*ptr: El operador * se usa para acceder al valor almacenado en la dirección de memoria que apunta el puntero.

DECLARACION Y USO DE PUNTEROS
Un puntero puede almacenar la dirección de cualquier variable de un tipo compatible con él. Para declarar un puntero, 
simplemente se antepone un asterisco * al tipo de la variable.
  int* ptr;  // Un puntero a un entero
  double* ptr2;  // Un puntero a un double
Para inicializar un puntero, le asignamos la dirección de una variable mediante el operador &:
  int x = 10;
  int* ptr = &x;
  std::cout << *ptr << endl;  // Imprime 10, ya que *ptr accede al valor de x

PUNTEROS Y ARRAYS
Los punteros y los arrays están estrechamente relacionados en C++. De hecho, el nombre de un array es equivalente 
a un puntero al primer elemento del array.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    int* ptr = arr;  // Apunta al primer elemento del array

    std:: cout << *ptr << endl;    // Imprime 10
    std:: cout << *(ptr + 1) << endl;  // Imprime 20, accediendo al segundo elemento
    std:: cout << *(ptr + 2) << endl;  // Imprime 30, accediendo al tercer elemento

    return 0;
}
En este caso, ptr apunta al primer elemento del array arr, y podemos acceder a los otros elementos incrementando 
la dirección almacenada en el puntero.

PUNTEROS NULOS
Un puntero puede no apuntar a ninguna dirección válida. Esto se conoce como un puntero nulo. Para esto, 
se utiliza la constante nullptr.
  int* ptr = nullptr;  // Un puntero nulo
Cuando un puntero es nulo, no podemos desreferenciarlo, ya que causaría un error de acceso a memoria.

PUNTEROS A PUNTEROS
Un puntero también puede almacenar la dirección de otro puntero, creando lo que se conoce como punteros a punteros.

REFERENCIAS
Una referencia es simplemente un alias para una variable existente. A diferencia de un puntero, una referencia 
siempre debe apuntar a una variable válida y no puede ser nula.
Se declara con el operador & en la declaración de la variable.
  int x = 10;
  int& ref = x;  // 'ref' es una referencia a 'x'
  std:: cout << ref << endl;  // Imprime 10, ya que 'ref' es una referencia a 'x'
  ref = 20;  // Modifica el valor de 'x' a través de la referencia
  std:: cout << x << endl;  // Imprime 20, porque 'ref' es un alias de 'x'

DIFERENCIAS ENTRE PUNTEROS Y REFERENCIAS
| Característica     | Puntero                                              | Referencia                                                  |
| ------------------ | ---------------------------------------------------- | ----------------------------------------------------------- |
| **Declaración**    | `TipoDeDato* ptr`                                    | `TipoDeDato& ref`                                           |
| **Puede ser nulo** | Sí (`nullptr`)                                       | No                                                          |
| **Reasignación**   | Se puede hacer (`ptr = &y`)                          | No se puede reasignar (siempre refiere a una sola variable) |
| **Acceso**         | `*ptr` (desreferencia)                               | No necesita desreferenciación, se usa directamente          |
| **Operaciones**    | Puede realizar operaciones de aritmética de punteros | No se puede realizar aritmética                             |

PUNTEROS Y ASIGNACION DE MEMORIA
C++ también permite la asignación dinámica de memoria utilizando los operadores new y delete. Esto es útil cuando no sabemos el tamaño de 
los datos de antemano.
 - new: Asigna memoria dinámicamente.
 - delete: Libera la memoria previamente asignada.

PUNTEROS A FUNCIONES
En C++, también puedes tener punteros a funciones. Esto es útil cuando deseas pasar funciones como parámetros o llamarlas dinámicamente.


5. Herencia y Polimorfismo en C++

La herencia y el polimorfismo son dos conceptos fundamentales de la programación orientada a objetos (OOP). 
Permiten organizar y extender el código de manera eficiente. Aquí te explico estos conceptos con ejemplos aplicados a C++.

HERENCIA
La herencia permite que una clase herede atributos y métodos de otra clase. Esto permite reutilizar código y crear jerarquías de clases. 
En C++, la herencia se establece con la palabra clave class o struct, seguida de la clase base y la clase derivada.
Sintaxis básica de la herencia:
class ClaseBase {
public:
    // Atributos y métodos de la clase base
    void metodoBase() {
        // Acción de la clase base
    }
};

class ClaseDerivada : public ClaseBase {
public:
    // Atributos y métodos adicionales o sobrecargados
    void metodoDerivado() {
        // Acción de la clase derivada
    }
};
En este ejemplo:
ClaseBase es la clase base de la cual se derivan otras clases.
ClaseDerivada hereda todos los miembros públicos de ClaseBase y puede agregar nuevos miembros o sobrecargar los existentes.
Ejemplo de herencia simple:
#include <iostream>

class Animal {
public:
    // Método común para todos los animales
    void comer() {
        std::cout << "Este animal está comiendo." << std::endl;
    }
};

class Perro : public Animal {
public:
    // Método específico de la clase Perro
    void ladrar() {
        std::cout << "¡Guau! ¡Guau!" << std::endl;
    }
};

int main() {
    Perro miPerro;
    miPerro.comer();  // Método heredado de Animal
    miPerro.ladrar(); // Método propio de Perro
    
    return 0;
}
En este ejemplo, Perro hereda el método comer de la clase Animal. 
Por lo tanto, cualquier objeto de la clase Perro tiene acceso a ese método, además de sus propios métodos.

MODIFICADORES DE ACCESO EN HERENCIA
En C++, puedes controlar la visibilidad de los miembros heredados mediante los modificadores de acceso:
 - public: Los miembros públicos de la clase base son accesibles desde fuera de la clase derivada.
 - protected: Los miembros protegidos de la clase base son accesibles desde las clases derivadas, pero no desde fuera.
 - private: Los miembros privados de la clase base no son accesibles desde la clase derivada ni desde fuera de la clase.
Ejemplo de herencia con modificadores de acceso:
#include <iostream>

class Base {
public:
    int publico;      // Miembro público
protected:
    int protegido;    // Miembro protegido
private:
    int privado;      // Miembro privado
};

class Derivada : public Base {
public:
    void mostrar() {
        // 'publico' es accesible
        std::cout << "publico: " << publico << std::endl;
        
        // 'protegido' es accesible
        std::cout << "protegido: " << protegido << std::endl;

        // 'privado' no es accesible, daría error
        // std::cout << "privado: " << privado << std::endl; // Error
    }
};

int main() {
    Derivada obj;
    obj.publico = 10;
    obj.protegido = 20;
    obj.mostrar();

    return 0;
}
publico es accesible desde cualquier lugar, incluidas las clases derivadas.
protegido es accesible dentro de las clases derivadas, pero no fuera de ellas.
privado no es accesible ni siquiera dentro de las clases derivadas.

POLIMORFISMOS
El polimorfismo permite que una misma operación (como un método) tenga diferentes comportamientos en función del 
tipo de objeto que lo invoque. En C++, esto se logra mediante métodos virtuales y funciones de sobrecarga.
Polimorfismo con funciones virtuales:
Cuando un método de una clase base se declara como virtual, las clases derivadas pueden sobrescribir ese método 
para proporcionar su propia implementación.
Sintaxis de funciones virtuales:
class Base {
public:
    virtual void metodo() {
        std::cout << "Método de la clase base." << std::endl;
    }
};

class Derivada : public Base {
public:
    void metodo() override {
        std::cout << "Método de la clase derivada." << std::endl;
    }
};
La palabra clave virtual indica que el método puede ser sobrescrito por una clase derivada. El modificador override 
es opcional pero es una buena práctica, ya que asegura que estás realmente sobrescribiendo el método de la clase base.
Ejemplo de polimorfismo con punteros:
#include <iostream>

class Animal {
public:
    virtual void hacerSonido() {
        std::cout << "El animal hace un sonido." << std::endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        std::cout << "El perro dice: ¡Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        std::cout << "El gato dice: ¡Miau!" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();

    animal1->hacerSonido(); // Imprime: El perro dice: ¡Guau!
    animal2->hacerSonido(); // Imprime: El gato dice: ¡Miau!

    delete animal1;
    delete animal2;

    return 0;
}
En este ejemplo:
La clase Animal tiene un método virtual hacerSonido.
Las clases Perro y Gato sobrescriben este método para proporcionar 
implementaciones específicas.
Cuando se llama al método a través de un puntero de tipo Animal, el polimorfismo asegura que el método correcto 
se invoca en función del tipo real del objeto (en este caso, Perro o Gato).

DESTRUCCION Y HERENCIA
Cuando usas herencia, también debes asegurarte de que el destructor de la clase base sea virtual si tienes 
punteros a la clase base que apuntan a objetos de las clases derivadas. Esto garantiza que se invoque el destructor 
correcto cuando el objeto se elimine.
Sintaxis de destructor virtual:
class Base {
public:
    virtual ~Base() {
        std::cout << "Destructor de la clase base." << std::endl;
    }
};

class Derivada : public Base {
public:
    ~Derivada() override {
        std::cout << "Destructor de la clase derivada." << std::endl;
    }
};

HERENCIA MULTIPLE
En C++98, puedes heredar de más de una clase. Esto se llama herencia múltiple.
#include <iostream>

class Animal {
public:
    void comer() {
        std::cout << "El animal está comiendo." << std::endl;
    }
};

class Vehiculo {
public:
    void conducir() {
        std::cout << "El vehículo está conduciendo." << std::endl;
    }
};

class Híbrido : public Animal, public Vehiculo {
public:
    void mover() {
        comer();
        conducir();
    }
};

int main() {
    Híbrido hibrido;
    hibrido.mover(); // Imprime: El animal está comiendo. El vehículo está conduciendo.
    
    return 0;
}
En este ejemplo, la clase Híbrido hereda tanto de Animal como de Vehiculo y puede acceder 
a los métodos de ambas clases base.

6. Sobrecarga de operadores en C++









