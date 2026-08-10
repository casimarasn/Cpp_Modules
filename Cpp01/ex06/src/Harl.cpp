# include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout	<< "[DEBUG]" << std::endl;
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "[INFO]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "[WARNING]" << std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve been coming for ears, whereas you started working here just last month."
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<< "[ERROR]" << std::endl;
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	instructions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Complain	functions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (instructions[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout	<< "Wrong instructions for Harl"
				<< std::endl;
}


/*3. Punteros a función miembro (Complain, &Harl::debug, ->*)

Esto es lo más "raro" sintácticamente en todo el módulo, así que vamos despacio.

Paso 1: el typedef
cpp
typedef void(Harl::*Complain)(void);

Esto declara un tipo: "puntero a una función miembro de la clase Harl, que no 
recibe argumentos y devuelve void". Compáralo con un puntero a función normal:

cpp
typedef void(*FuncionNormal)(void);   // puntero a función suelta
typedef void(Harl::*Complain)(void);  // puntero a función MIEMBRO de Harl

La diferencia clave: un puntero a función normal apunta directamente a una dirección 
de memoria ejecutable. Un puntero a función miembro no es simplemente una dirección — 
es más bien un "desplazamiento" o descriptor que le dice al compilador cuál método es, 
dentro de la tabla de métodos de la clase (piensa en ello casi como un índice en la v-table,
 aunque la implementación exacta depende del compilador). Por eso no puedes convertirlo 
 a un puntero normal ni compararlo con una dirección directamente — necesita un objeto 
 (this o cualquier instancia de Harl) para poder "resolverse" en una llamada real.

Paso 2: tomar la dirección
cpp
Complain functions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

Aquí &Harl::debug no significa "la dirección de una función suelta" — significa 
"el puntero al método debug de la clase Harl", sin ligarlo todavía a ningún objeto 
concreto. Es como una promesa: "cuando tenga un objeto Harl, sabré ejecutar esto en él". 
Por eso obligatoriamente se escribe con el nombre de la clase por delante (&Harl::debug), 
no &debug a secas.

Paso 3: invocarlo — por qué (this->*functions[i])() y no this->functions[i]()

Aquí está la trampa sintáctica real. functions[i] es un puntero a miembro, y para 
"activarlo" sobre un objeto concreto necesitas el operador especial ->* (si tienes un 
puntero al objeto, como this) o .* (si tienes el objeto directamente, no un puntero).

cpp
(this->*functions[i])();

Se lee: "toma el objeto apuntado por this, y en él, resuelve el puntero a miembro 
functions[i]" — eso te da una función miembro ya ligada a this, y entonces la llamas 
con (). Los paréntesis alrededor de this->*functions[i] son obligatorios por precedencia 
de operadores: sin ellos, this->*functions[i]() se interpretaría mal (el compilador 
intentaría aplicar () a functions[i] antes del ->*, lo cual no tiene sentido y no compila).

Si tuvieras un objeto en vez de un puntero, sería con punto:

cpp
Harl h;
Complain f = &Harl::debug;
(h.*f)();   // en vez de ->*, usas .*

Por qué no puedes escribir simplemente this->functions[i](): porque this->algo() es la sintaxis 
para llamar a un método nombrado directamente en el objeto (this->debug()), pero functions[i] 
no es un nombre de método, es una variable que contiene un puntero a miembro. El compilador no 
tiene forma de saber, solo viendo this->functions[i](), que quieres decir "usa el valor de esta 
variable como si fuera el nombre de un método" — para eso existe expresamente el operador ->*, que 
le dice al compilador "lo que viene después es un puntero a miembro que hay que resolver sobre este 
objeto, no un nombre de método literal".

Resumen para la defensa, en una frase: "Un puntero a función normal apunta a código; un puntero a 
función miembro apunta a un método dentro de una clase, y necesita un objeto concreto (vía ->* o .*) 
para poder ejecutarse, porque el método necesita un this sobre el que operar."*/