#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int TAM = 5; // Tama�o de los arreglos

// Definici�n de la clase Persona
class Persona {
private:
	int idPersona;
	string nombre;
	string apellido;
	string correoElectronico;
public:
	// Constructores
	
	// Constructor predeterminado
	Persona() {}
	
	// Constructor con par�metros
	Persona(int _idPersona, const string& _nombre, const string& _apellido, const string& _correoElectronico)
		: idPersona(_idPersona), nombre(_nombre), apellido(_apellido), correoElectronico(_correoElectronico) {}
	
	// Definici�n de los getters de la clase Persona
	
	// Getter para obtener el ID de la persona
	int getIdPersona() const { return idPersona; }
	
	// Getter para obtener el nombre de la persona
	string getNombre() const { return nombre; }
	
	// Getter para obtener el apellido de la persona
	string getApellido() const { return apellido; }
	
	// Getter para obtener el correo electr�nico de la persona
	string getCorreoElectronico() const { return correoElectronico; }
	
	// Definici�n de los setters de la clase Persona
	
	// Setter para establecer el ID de la persona
	void setIdPersona(int _idPersona) { idPersona = _idPersona; }
	
	// Setter para establecer el nombre de la persona
	void setNombre(const string& _nombre) { nombre = _nombre; }
	
	// Setter para establecer el apellido de la persona
	void setApellido(const string& _apellido) { apellido = _apellido; }
	
	// Setter para establecer el correo electr�nico de la persona
	void setCorreoElectronico(const string& _correoElectronico) { correoElectronico = _correoElectronico; }
};

class Libro {
private:
	string titulo;
	string ISBN;
	int anoPublicacion;
	string genero;
	string editorial;
	int numPaginas;
	string autor;
public:
	// Constructor predeterminado
	Libro() : titulo(""), ISBN(""), anoPublicacion(0), genero(""), editorial(""), numPaginas(0), autor("") {}
	
	// Constructor con par�metros
	Libro(const string& _titulo, const string& _ISBN, int _anoPublicacion, const string& _genero,
		  const string& _editorial, int _numPaginas, const string& _autor)
		: titulo(_titulo), ISBN(_ISBN), anoPublicacion(_anoPublicacion), genero(_genero),
		editorial(_editorial), numPaginas(_numPaginas), autor(_autor) {}
	
	// Getters
	string getTitulo() const { return titulo; }
	string getISBN() const { return ISBN; }
	int getAnoPublicacion() const { return anoPublicacion; }
	string getGenero() const { return genero; }
	string getEditorial() const { return editorial; }
	int getNumPaginas() const { return numPaginas; }
	string getAutor() const { return autor; } // M�todo para obtener el autor
	
	// Setters
	void setTitulo(const string& _titulo) { titulo = _titulo; }
	void setISBN(const string& _ISBN) { ISBN = _ISBN; }
	void setAnoPublicacion(int _anoPublicacion) { anoPublicacion = _anoPublicacion; }
	void setGenero(const string& _genero) { genero = _genero; }
	void setEditorial(const string& _editorial) { editorial = _editorial; }
	void setNumPaginas(int _numPaginas) { numPaginas = _numPaginas; }
	void setAutor(const string& _autor) { autor = _autor; }
};

// Clase Usuario que hereda de Persona
class Usuario : public Persona {
private:
	string direccion;
public:
	Usuario() {}
	Usuario(int _idUsuario, const string& _nombre, const string& _apellido, const string& _direccion,
			const string& _correoElectronico)
		: direccion(_direccion) {
		setIdPersona(_idUsuario); // Establecer el ID de Persona
		setNombre(_nombre);
		setApellido(_apellido);
		setCorreoElectronico(_correoElectronico);
	}
	
	// Getters
	string getDireccion() const { return direccion; }
	
	// Setters
	void setDireccion(const string& _direccion) { direccion = _direccion; }
};

// Clase Bibliotecario que hereda de Persona
class Bibliotecario : public Persona {
private:
	string departamento;
public:
	Bibliotecario() {}
	Bibliotecario(int _idEmpleado, const string& _nombre, const string& _apellido, const string& _departamento,
				  const string& _correoElectronico)
		: departamento(_departamento) {
		setIdPersona(_idEmpleado); // Establecer el ID de Persona
		setNombre(_nombre);
		setApellido(_apellido);
		setCorreoElectronico(_correoElectronico);
	}
	
	// Getters
	string getDepartamento() const { return departamento; }
	
	// Setters
	void setDepartamento(const string& _departamento) { departamento = _departamento; }
};

class GestorLibro {
private:
	Libro libros[TAM]; // Arreglo de objetos de tipo Libro
	int tamanoActual; // Variable para almacenar el tama�o actual del arreglo
public:
	// Constructor
	GestorLibro() : tamanoActual(0) {
		// Inicializa el tama�o actual en 0 y llena el arreglo de libros con objetos Libro vac�os
		for (int i = 0; i < TAM; ++i) {
			libros[i] = Libro("", "", 0, "", "", 0, ""); // Valores predeterminados para cada libro
		}
	}
	
	// M�todo para llenar datos aleatorios para los libros
	void LlenarDatos() {
		// Arrays con datos aleatorios para los libros
		string sTitulosLibros[] = {"Canci�n de hielo y fuego", "1984", "El juego de Ender", "Introducci�n a la programaci�n", "Programaci�n avanzada"};
		string sAutoresLibros[] = {"George R.R. Martin", "George Orwell", "Orson Scott Card", "Brian Kernighan", "Dennis Ritchie"};
		int nAnosLibros[] = {1985, 1949, 1956, 2020, 2022};
		string sISBNs[] = {"1", "2", "3", "4", "5"};
		string sGeneros[] = {"Fantas�a", "Ciencia ficci�n", "Ficci�n", "Tecnolog�a", "Tecnolog�a"};
		string sEditoriales[] = {"Editorial A", "Editorial B", "Editorial C", "Editorial D", "Editorial E"};
		
		// Llena cada libro con datos aleatorios
		for (int i = 0; i < TAM; ++i) {
			libros[i] = Libro(sTitulosLibros[i], sISBNs[i], nAnosLibros[i], sGeneros[i], sEditoriales[i], rand() % 401 + 100, sAutoresLibros[i]);
			tamanoActual++; // Incrementa el tama�o actual del arreglo de libros
		}
	}
	
	// M�todo para imprimir datos de los libros en diferentes formatos
	void Imprimir(string formato) {
		cout << "LISTADO DE LIBROS:" << endl;
		if (formato == "b") { // Formato breve
			for (int i = 0; i < tamanoActual; ++i) {
				// Imprime cada atributo del libro en l�neas separadas
				cout << "T�tulo: " << libros[i].getTitulo() << endl;
				cout << "Autor: " << libros[i].getAutor() << endl;
				cout << "ISBN: " << libros[i].getISBN() << endl;
				cout << "A�o de Publicaci�n: " << libros[i].getAnoPublicacion() << endl;
				cout << "G�nero: " << libros[i].getGenero() << endl;
				cout << "Editorial: " << libros[i].getEditorial() << endl;
				cout << "N�mero de P�ginas: " << libros[i].getNumPaginas() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") { // Formato tabular
			// Imprime los datos de los libros en formato de tabla
			// Se utiliza setw() para establecer el ancho de cada columna
			cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| T�tulo                          | Autor                    | ISBN | A�o Publicaci�n | G�nero            | Editorial  | N�m. P�ginas |" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "| " << left << setw(32) << libros[i].getTitulo()
					<< "| " << setw(25) << libros[i].getAutor()
					<< "| " << setw(5) << libros[i].getISBN()
					<< "| " << setw(16) << libros[i].getAnoPublicacion()
					<< "| " << setw(18) << libros[i].getGenero()
					<< "| " << setw(11) << libros[i].getEditorial()
					<< "| " << setw(13) << libros[i].getNumPaginas() << "|" << endl;
			}
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
		} else {
			cout << "Formato no v�lido." << endl;
		}
	}
	
	// M�todo para buscar libros por t�tulo
	void Buscar(const string& sBusqueda, int index = 0, int contadorCoincidencias = 0) {
		// Si se ha revisado todo el arreglo, muestra el resultado de la b�squeda
		if (index >= tamanoActual) {
			if (contadorCoincidencias == 0) {
				cout << "No se encontraron resultados para la b�squeda." << endl;
			} else {
				cout << "Se encontraron " << contadorCoincidencias << " coincidencias para la b�squeda." << endl;
			}
			return;
		}
		
		// Busca coincidencias en el t�tulo del libro
		if (libros[index].getTitulo().find(sBusqueda) != string::npos) {
			cout << "T�tulo: " << libros[index].getTitulo() << endl;
			contadorCoincidencias++;
		}
		
		// Llama recursivamente a la funci�n para buscar en el siguiente libro del arreglo
		Buscar(sBusqueda, index + 1, contadorCoincidencias);
	}
};

// Clase GestorUsuario
class GestorUsuario {
private:
	Usuario usuarios[TAM]; // Arreglo de objetos de tipo Usuario
	int tamanoActual; // Variable para almacenar el tama�o actual del arreglo
	
public:
	// Constructor
	GestorUsuario() : tamanoActual(0) {} // Inicializa el tama�o actual en 0
	
	// M�todo para llenar datos aleatorios para los usuarios
	void LlenarDatos() {
		// Arrays con datos aleatorios para los usuarios
		string sNombresUsuarios[] = {"Juan", "Maria", "Pedro", "Monica", "Migel"};
		string sApellidosUsuarios[] = {"Gomez", "Lopez", "Martinez", "Paniagua", "Montenegro"};
		string sDirecciones[] = {"CALLE PEREZ", "CALLE ABUNA", "CALLE ITENEZ", "CALLE MAMORE", "CALLE FLORES"};
		
		// Llena cada usuario con datos aleatorios
		for (int i = 0; i < TAM; ++i) {
			// Concatenaci�n para simular un correo electr�nico
			string correoElectronico = sNombresUsuarios[i] + sApellidosUsuarios[i] + "@gmail.com";
			// Crear un objeto Usuario con los datos aleatorios y agregarlo al arreglo
			usuarios[i] = Usuario(i + 1, sNombresUsuarios[i], sApellidosUsuarios[i], sDirecciones[i], correoElectronico);
			tamanoActual++; // Incrementa el tama�o actual del arreglo de usuarios
		}
	}
	
	// M�todo para imprimir datos de los usuarios en diferentes formatos
	void Imprimir(string formato) {
		cout << "LISTADO DE USUARIOS:" << endl;
		if (formato == "b") { // Formato breve
			for (int i = 0; i < tamanoActual; ++i) {
				// Imprime cada atributo del usuario en l�neas separadas
				cout << "ID: " << usuarios[i].getIdPersona() << endl;
				cout << "Nombre: " << usuarios[i].getNombre() << endl;
				cout << "Apellido: " << usuarios[i].getApellido() << endl;
				cout << "Correo Electr�nico: " << usuarios[i].getCorreoElectronico() << endl;
				cout << "Direcci�n: " << usuarios[i].getDireccion() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") { // Formato tabular
			// Imprime los datos de los usuarios en formato de tabla
			// Se utiliza setw() para establecer el ancho de cada columna
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << "| ID | Nombre       | Apellido     | Correo Electr�nico           | Direcci�n        |" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "| " << left << setw(2) << usuarios[i].getIdPersona()
					<< " | " << setw(12) << usuarios[i].getNombre()
					<< " | " << setw(12) << usuarios[i].getApellido()
					<< " | " << setw(28) << usuarios[i].getCorreoElectronico()
					<< " | " << setw(16) << usuarios[i].getDireccion() << " |" << endl;
			}
			cout << "-----------------------------------------------------------------------------" << endl;
		} else {
			cout << "Formato no v�lido." << endl;
		}
	}
	
	// M�todo para buscar usuarios por nombre completo
	void Buscar(const string& sBusqueda, int index = 0, int contadorCoincidencias = 0) {
		// Si se ha revisado todo el arreglo, muestra el resultado de la b�squeda
		if (index >= tamanoActual) {
			if (contadorCoincidencias == 0) {
				cout << "No se encontraron resultados para la b�squeda." << endl;
			} else {
				cout << "Se encontraron " << contadorCoincidencias << " coincidencias para la b�squeda." << endl;
			}
			return;
		}
		
		// Convertir la cadena de b�squeda a min�sculas para hacer la comparaci�n de manera insensible a may�sculas/min�sculas
		string busquedaMinuscula = sBusqueda;
		transform(busquedaMinuscula.begin(), busquedaMinuscula.end(), busquedaMinuscula.begin(), ::tolower);
		
		// Convertir el nombre completo del usuario a min�sculas
		string nombreCompletoMinuscula = usuarios[index].getNombre() + " " + usuarios[index].getApellido();
		transform(nombreCompletoMinuscula.begin(), nombreCompletoMinuscula.end(), nombreCompletoMinuscula.begin(), ::tolower);
		
		// Compara el nombre completo del usuario con la cadena de b�squeda
		if (nombreCompletoMinuscula.find(busquedaMinuscula) != string::npos) {
			// Muestra los datos del usuario encontrado
			cout << "ID: " << usuarios[index].getIdPersona() << ", "
				<< "Nombre: " << usuarios[index].getNombre() << " " 
				<< "Apellido: " << usuarios[index].getApellido() << ", "
				<< "Correo Electr�nico: " << usuarios[index].getCorreoElectronico() << ", "
				<< "Direcci�n: " << usuarios[index].getDireccion() << endl;
			
			contadorCoincidencias++; // Incrementa el contador de coincidencias
		}
		
		// Llamada recursiva con el siguiente �ndice
		Buscar(sBusqueda, index + 1, contadorCoincidencias);
	}
};

// Clase GestorBibliotecario
class GestorBibliotecario {
private:
	Bibliotecario bibliotecarios[TAM]; // Arreglo de objetos de tipo Bibliotecario
	int tamanoActual; // Variable para almacenar el tama�o actual del arreglo
	
public:
	// Constructor
	GestorBibliotecario() : tamanoActual(0) {} // Inicializa el tama�o actual en 0
	
	// M�todo para llenar datos aleatorios para los bibliotecarios
	void LlenarDatos() {
		// Arrays con datos aleatorios para los bibliotecarios
		string sNombresBibliotecarios[] = {"Sandra", "Carlos", "Luis", "Marco", "Laura"};
		string sApellidosBibliotecarios[] = {"Perez", "Rodriguez", "Garcia", "Yepez", "Saucedo"};
		string sDepartamentosBibliotecarios[] = {"Secci�n de Ficci�n", "Secci�n de No Ficci�n", "Secci�n Infantil", "Secci�n de Referencia", "Secci�n de Historia"};
		
		// Llena cada bibliotecario con datos aleatorios
		for (int i = 0; i < TAM; ++i) {
			// Concatenaci�n para simular un correo electr�nico
			string correoElectronico = sNombresBibliotecarios[i] + sApellidosBibliotecarios[i] + "@library.com";
			// Crear un objeto Bibliotecario con los datos aleatorios y agregarlo al arreglo
			bibliotecarios[i] = Bibliotecario(i + 1, sNombresBibliotecarios[i], sApellidosBibliotecarios[i], sDepartamentosBibliotecarios[i], correoElectronico);
			tamanoActual++; // Incrementa el tama�o actual del arreglo de bibliotecarios
		}
	}
	
	// M�todo para imprimir datos de los bibliotecarios en diferentes formatos
	void Imprimir(string formato) {
		cout << "LISTADO DE BIBLIOTECARIOS:" << endl;
		if (formato == "b") { // Formato breve
			for (int i = 0; i < tamanoActual; ++i) {
				// Imprime cada atributo del bibliotecario en l�neas separadas
				cout << "ID: " << bibliotecarios[i].getIdPersona() << endl;
				cout << "Nombre: " << bibliotecarios[i].getNombre() << endl;
				cout << "Apellido: " << bibliotecarios[i].getApellido() << endl;
				cout << "Correo Electr�nico: " << bibliotecarios[i].getCorreoElectronico() << endl;
				cout << "Departamento: " << bibliotecarios[i].getDepartamento() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") { // Formato tabular
			// Imprime los datos de los bibliotecarios en formato de tabla
			// Se utiliza setw() para establecer el ancho de cada columna
			cout << "----------------------------------------------------------------------------------------" << endl;
			cout << "| ID  | Nombre    | Apellido   | Correo Electr�nico           | Departamento           |" << endl;
			cout << "----------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "| " << left << setw(3) << bibliotecarios[i].getIdPersona()
					<< " | " << left << setw(9) << bibliotecarios[i].getNombre()
					<< " | " << left << setw(10) << bibliotecarios[i].getApellido()
					<< " | " << left << setw(28) << bibliotecarios[i].getCorreoElectronico()
					<< " | " << left << setw(22) << bibliotecarios[i].getDepartamento() << " |" << endl;
			}
			cout << "----------------------------------------------------------------------------------------" << endl;
		} else {
			cout << "Formato no v�lido." << endl;
		}
	}
	
	// M�todo para buscar bibliotecarios por nombre completo
	void Buscar(const string& sBusqueda, int index = 0, int contadorCoincidencias = 0) {
		// Si se ha revisado todo el arreglo, muestra el resultado de la b�squeda
		if (index >= tamanoActual) {
			if (contadorCoincidencias == 0) {
				cout << "No se encontraron resultados para la b�squeda." << endl;
			} else {
				cout << "Se encontraron " << contadorCoincidencias << " coincidencias para la b�squeda." << endl;
			}
			return;
		}
		
		// Convertir la cadena de b�squeda a min�sculas para hacer la comparaci�n de manera insensible a may�sculas/min�sculas
		string busquedaMinuscula = sBusqueda;
		transform(busquedaMinuscula.begin(), busquedaMinuscula.end(), busquedaMinuscula.begin(), ::tolower);
		
		// Convertir el nombre completo del bibliotecario a min�sculas
		string nombreCompletoMinuscula = bibliotecarios[index].getNombre() + " " + bibliotecarios[index].getApellido();
		transform(nombreCompletoMinuscula.begin(), nombreCompletoMinuscula.end(), nombreCompletoMinuscula.begin(), ::tolower);
		
		// Verificar si la cadena de b�squeda est� contenida en el nombre completo del bibliotecario
		if (nombreCompletoMinuscula.find(busquedaMinuscula) != string::npos) {
			// Mostrar los datos del bibliotecario encontrado
			cout << "ID: " << bibliotecarios[index].getIdPersona() << ", "
				<< "Nombre: " << bibliotecarios[index].getNombre() << " " 
				<< "Apellido: " << bibliotecarios[index].getApellido() << " "
				<< "Correo Electr�nico: " << bibliotecarios[index].getCorreoElectronico() << ", "
				<< "Departamento: " << bibliotecarios[index].getDepartamento() << endl;
			
			contadorCoincidencias++; // Incrementa el contador de coincidencias
		}
		
		// Llamada recursiva con el siguiente �ndice
		Buscar(sBusqueda, index + 1, contadorCoincidencias);
	}
};

// Funci�n principal
int main() {
	// Inicializaci�n de la semilla para la generaci�n de n�meros aleatorios
	srand(time(nullptr));
	
	// Declaraci�n de objetos de gestores
	GestorLibro gestorLibro;
	GestorUsuario gestorUsuario;
	GestorBibliotecario gestorBibliotecario;
	
	// Variable para almacenar la opci�n seleccionada en el men� principal
	char opcion;
	bool llenadoDatosRealizado = false; // Variable para verificar si el llenado de datos ha sido realizado
	do {
		// Men� principal
		cout << "MENU" << endl;
		cout << "1) Llenado de datos" << endl;
		cout << "2) Listados" << endl;
		cout << "3) B�squedas" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			// Llenado de datos
			gestorLibro.LlenarDatos();
			gestorUsuario.LlenarDatos();
			gestorBibliotecario.LlenarDatos();
			llenadoDatosRealizado = true; // Marcar que el llenado de datos ha sido realizado
			cout << "Datos llenados exitosamente." << endl;
			break;
		case '2': {
			if (!llenadoDatosRealizado) { // Verificar si el llenado de datos ha sido realizado
				cout << "Primero debe realizar el llenado de datos (opci�n 1)." << endl;
				break;
			}
			// Submen� de listados
			char subopcionListados;
			do {
				cout << "SUBMENU LISTADOS" << endl;
				cout << "A) Listado de Libros" << endl;
				cout << "B) Listado de Usuarios" << endl;
				cout << "C) Listado de Bibliotecarios" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese una opci�n: ";
				cin >> subopcionListados;
				
				switch (subopcionListados) {
				case 'A':
				case 'a':
					// Listado de Libros
					char formato;
					cout << "Desea ver los datos en forma de bloque o tabla? (b es para bloque, t es para tabla): ";
					cin >> formato;
					gestorLibro.Imprimir(formato == 'b' ? "b" : "t");
					break;
				case 'B':
				case 'b':
					// Listado de Usuarios
					cout << "Desea ver los datos en forma de bloque o tabla? (b es para bloque, t es para tabla): ";
					cin >> formato;
					gestorUsuario.Imprimir(formato == 'b' ? "b" : "t");
					break;
				case 'C':
				case 'c':
					// Listado de Bibliotecarios
					cout << "Desea ver los datos en forma de bloque o tabla? (b es para bloque, t es para tabla): ";
					cin >> formato;
					gestorBibliotecario.Imprimir(formato == 'b' ? "b" : "t");
					break;
				case 'X':
				case 'x':
					// Salir del submen� de listados
					break;
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
					break;
				}
			} while (subopcionListados != 'X' && subopcionListados != 'x');
			break;
		}
		case '3': {
			if (!llenadoDatosRealizado) { // Verificar si el llenado de datos ha sido realizado
				cout << "Primero debe realizar el llenado de datos (opci�n 1)." << endl;
				break;
			}
			// Submen� de b�squedas
			char subopcionBusquedas;
			do {
				cout << "SUBMENU BUSQUEDAS" << endl;
				cout << "A) Buscar Libros" << endl;
				cout << "B) Buscar Usuarios" << endl;
				cout << "C) Buscar Bibliotecarios" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese una opci�n: ";
				cin >> subopcionBusquedas;
				
				switch (subopcionBusquedas) {
				case 'A':
				case 'a': {
					// B�squeda de Libros
					string sBusquedaLibro;
					cout << "Ingrese el t�tulo del libro a buscar: ";
					cin.ignore(); // Ignorar el salto de l�nea del buffer
					getline(cin, sBusquedaLibro);
					gestorLibro.Buscar(sBusquedaLibro);
					break;
				}
				case 'B':
				case 'b': {
					// B�squeda de Usuarios
					string sBusquedaUsuario;
					cout << "Ingrese el nombre o apellido para encontrar usuarios: ";
					cin.ignore(); // Ignorar el salto de l�nea del buffer
					getline(cin, sBusquedaUsuario);
					gestorUsuario.Buscar(sBusquedaUsuario);
					break;
				}
				case 'C':
				case 'c': {
					// B�squeda de Bibliotecarios
					string sBusquedaBibliotecario;
					cout << "Ingrese el nombre o apellido para encontrar bibliotecarios: ";
					cin.ignore(); // Ignorar el salto de l�nea del buffer
					getline(cin, sBusquedaBibliotecario);
					gestorBibliotecario.Buscar(sBusquedaBibliotecario);
					break;
				}
				case 'X':
				case 'x':
					// Salir del submen� de b�squedas
					break;
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
					break;
				}
			} while (subopcionBusquedas != 'X' && subopcionBusquedas != 'x');
			break;
		}
		case '0':
			// Salir del programa
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
			break;
		}
	} while (opcion != '0');
	
	return 0;
}




