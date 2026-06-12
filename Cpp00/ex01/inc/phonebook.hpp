#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int	_index;
		int	_totalContacts;

		
	public:
		PhoneBook();
		~PhoneBook();
		void	searchContact(void);
		void	addContact(void);
		void	printTable()const;
		void	printDetails(int index)const;
};

#endif

/*
	2. La función para Añadir (Comando ADD)
Necesitas crear una función en tu PhoneBook que 
se encargue exclusivamente de añadir un nuevo contacto
 al comando del usuario.

El proceso: Esta función debe pedir, uno por uno, l
os cinco datos requeridos usando la entrada estándar 
(tecla a tecla del usuario).
El guardado: Cada vez que el usuario escriba un dato,
 usarás el setter correspondiente de tu objeto Contact 
 que toca en ese momento en tu array _contacts.
La regla de los 8: Aquí es donde usas tu variable 
_index. Cuando añades un contacto, usas la posición _index. 
Luego sumas uno a _index. Si _index llega a 8 (el máximo), 
debes hacer que vuelva a ser 0. Así lograrás que, al 
llegar al noveno contacto, se sobrescriba el más antiguo. 
También debes sumar a tu _totalContacts asegurándote de que 
nunca pase de 8.
Validación: El subject dice que un contacto no puede 
tener campos vacíos. Tu función tendrá que comprobar
 que el usuario realmente ha escrito algo antes de 
 aceptarlo.
3. La función para Buscar (Comando SEARCH)
Esta función va a ser la compañera de la tabla 
que acabas de hacer.

Primer paso: Lo primero que hará esta función es 
llamar a tu función printTable() para mostrar la 
lista completa.
Segundo paso: Pedirá al usuario que introduzca el 
índice (el número) del contacto que quiere cotillear.
Tercer paso (El más delicado): Tienes que proteger 
tu programa. ¿Qué pasa si te piden el índice 9 pero 
solo tienes 3 contactos? ¿Y si en vez de un número el 
usuario te escribe la letra "Hola"? Debes comprobar que lo 
que ha introducido el usuario tiene sentido y es un número 
válido dentro de tus contactos actuales.
Cuarto paso: Una vez te aseguras de que el número es 
válido, usas tus getters para obtener los 5 datos de ese 
contacto específico e imprimirlos por pantalla, uno debajo del 
otro, sin truncar.
4. La función o bucle Principal (El menú)
Necesitarás un bucle (ya sea en el main o en un método 
de inicio de PhoneBook) que se quede esperando órdenes 
indefinidamente.

Deberá leer una línea del usuario.
Si la línea es "ADD", llamará a tu función de añadir.
Si es "SEARCH", llamará a tu función de buscar.
Si es "EXIT", romperá el bucle, el programa terminará, y se llamará 
automáticamente a tu destructor (que por lo que veo tienes listo 
imprimiendo "Everything Deleted").
Cualquier otra palabra deberá ser ignorada, 
volviendo a esperar una orden.

*/