#include <iostream>
#include <iomanip> // Para setw y left
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 5; // Tama�o de los arreglos

// Clase base Persona
class Persona {
protected:
	string nombre;
	string apellido;
	string correoElectronico;
	int idPersona; // Nuevo campo para el ID de Persona
public:
	Persona() {}
	Persona(int _idPersona, const string& _nombre, const string& _apellido, const string& _correoElectronico)
		: idPersona(_idPersona), nombre(_nombre), apellido(_apellido), correoElectronico(_correoElectronico) {}
	
	// Getters
	int getIdPersona() const { return idPersona; }
	string getNombre() const { return nombre; }
	string getApellido() const { return apellido; }
	string getCorreoElectronico() const { return correoElectronico; }
	
	// Setters
	void setIdPersona(int _idPersona) { idPersona = _idPersona; }
	void setNombre(const string& _nombre) { nombre = _nombre; }
	void setApellido(const string& _apellido) { apellido = _apellido; }
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
	Libro libros[TAM];
	int tamanoActual;
public:
	// Constructor
	GestorLibro() : tamanoActual(0) {
		for (int i = 0; i < TAM; ++i) {
			libros[i] = Libro("", "", 0, "", "", 0, ""); // Valores predeterminados para cada libro
		}
	}
	// M�todo para llenar datos
	void LlenarDatos() {
		// Llenar datos aleatorios para los libros
		string sTitulosLibros[] = {"Canci�n de hielo y fuego", "1984", "El juego de Ender", "Introducci�n a la programaci�n", "Programaci�n avanzada"};
		string sAutoresLibros[] = {"George R.R. Martin", "George Orwell", "Orson Scott Card", "Brian Kernighan", "Dennis Ritchie"};
		int nAnosLibros[] = {1985, 1949, 1956, 2020, 2022};
		string sISBNs[] = {"1", "2", "3", "4", "5"};
		string sGeneros[] = {"Fantas�a", "Ciencia ficci�n", "Ficci�n", "Tecnolog�a", "Tecnolog�a"};
		string sEditoriales[] = {"Editorial A", "Editorial B", "Editorial C", "Editorial D", "Editorial E"};
		
		for (int i = 0; i < TAM; ++i) {
			libros[i] = Libro(sTitulosLibros[i], sISBNs[i], nAnosLibros[i], sGeneros[i], sEditoriales[i], rand() % 401 + 100, sAutoresLibros[i]);
			tamanoActual++;
		}
	}
	
	// M�todo para imprimir datos
	void Imprimir(string formato) {
		cout << "LISTADO DE LIBROS:" << endl;
		if (formato == "b") {
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "T�tulo: " << libros[i].getTitulo() << endl;
				cout << "Autor: " << libros[i].getAutor() << endl;
				cout << "ISBN: " << libros[i].getISBN() << endl;
				cout << "A�o de Publicaci�n: " << libros[i].getAnoPublicacion() << endl;
				cout << "G�nero: " << libros[i].getGenero() << endl;
				cout << "Editorial: " << libros[i].getEditorial() << endl;
				cout << "N�mero de P�ginas: " << libros[i].getNumPaginas() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") {
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
	
	void Buscar(const string& sBusqueda, int index = 0) {
		if (index >= tamanoActual) {
			cout << "No se encontraron resultados para la b�squeda." << endl;
			return;
		}
		if (libros[index].getTitulo().find(sBusqueda) != string::npos) {
			cout << "T�tulo: " << libros[index].getTitulo() << endl;
		}
		Buscar(sBusqueda, index + 1); // Llamada recursiva con el siguiente �ndice
	}
};

// Clase GestorUsuario
class GestorUsuario {
private:
	Usuario usuarios[TAM]; // Utilizando un arreglo de tama�o fijo
	int tamanoActual;
	
public:
	// Constructor
	GestorUsuario() : tamanoActual(0) {}
	
	// M�todo para llenar datos
	void LlenarDatos() {
		string sNombresUsuarios[] = {"Juan", "Maria", "Pedro", "Monica", "Migel"};
		string sApellidosUsuarios[] = {"Gomez", "Lopez", "Martinez", "Paniagua", "Montenegro"};
		string sDirecciones[] = {"CALLE PEREZ", "CALLE ABUNA", "CALLE ITENEZ", "CALLE MAMORE", "CALLE FLORES"};
		
		for (int i = 0; i < TAM; ++i) {
			string correoElectronico = sNombresUsuarios[i] + sApellidosUsuarios[i] + "@gmail.com"; // Concatenaci�n para simular un correo electr�nico
			usuarios[i] = Usuario(i + 1, sNombresUsuarios[i], sApellidosUsuarios[i], sDirecciones[i], correoElectronico);
			tamanoActual++;
		}
	}
	
	// M�todo para imprimir datos de usuarios
	void Imprimir(string formato) {
		cout << "LISTADO DE USUARIOS:" << endl;
		if (formato == "b") {
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "ID: " << usuarios[i].getIdPersona() << endl;
				cout << "Nombre: " << usuarios[i].getNombre() << endl;
				cout << "Apellido: " << usuarios[i].getApellido() << endl;
				cout << "Correo Electr�nico: " << usuarios[i].getCorreoElectronico() << endl;
				cout << "Direcci�n: " << usuarios[i].getDireccion() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") {
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "| ID | Nombre      | Apellido    | Correo Electr�nico | Direcci�n         |" << endl;
			cout << "-----------------------------------------------------------------------------" << endl;
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "| " << setw(2) << usuarios[i].getIdPersona()
					<< " | " << setw(11) << usuarios[i].getNombre()
					<< " | " << setw(11) << usuarios[i].getApellido()
					<< " | " << setw(19) << usuarios[i].getCorreoElectronico()
					<< " | " << setw(16) << usuarios[i].getDireccion() << " |" << endl;
			}
			cout << "-----------------------------------------------------------------------------" << endl;
		} else {
			cout << "Formato no v�lido." << endl;
		}
	}
	
	// M�todo para buscar
	void Buscar(const string& sNombreCompleto, int index = 0) {
		if (index >= tamanoActual) {
			cout << "No se encontraron resultados para la b�squeda." << endl;
			return;
		}
		if (usuarios[index].getNombre() + " " + usuarios[index].getApellido() == sNombreCompleto) {
			cout << "ID: " << usuarios[index].getIdPersona() << ", "
				<< "Nombre: " << usuarios[index].getNombre() << " " << usuarios[index].getApellido() << ", "
				<< "Correo Electr�nico: " << usuarios[index].getCorreoElectronico() << ", "
				<< "Direcci�n: " << usuarios[index].getDireccion() << endl;
		}
		Buscar(sNombreCompleto, index + 1); // Llamada recursiva con el siguiente �ndice
	}
};

// Clase GestorBibliotecario
class GestorBibliotecario {
private:
	Bibliotecario bibliotecarios[TAM]; // Utilizando un arreglo de tama�o fijo
	int tamanoActual;
	
public:
	// Constructor
	GestorBibliotecario() : tamanoActual(0) {}
	
	// M�todo para llenar datos
	void LlenarDatos() {
		string sNombresBibliotecarios[] = {"Sandra", "Carlos", "Luis", "Marco", "Laura"};
		string sApellidosBibliotecarios[] = {"Perez", "Rodriguez", "Garcia", "Yepez", "Saucedo"};
		string sDepartamentosBibliotecarios[] = {"Secci�n de Ficci�n", "Secci�n de No Ficci�n", "Secci�n Infantil", "Secci�n de Referencia", "Secci�n de Historia"};
		
		for (int i = 0; i < TAM; ++i) {
			string correoElectronico = sNombresBibliotecarios[i] + sApellidosBibliotecarios[i] + "@library.com"; // Concatenaci�n para simular un correo electr�nico
			bibliotecarios[i] = Bibliotecario(i + 1, sNombresBibliotecarios[i], sApellidosBibliotecarios[i], sDepartamentosBibliotecarios[i], correoElectronico);
			tamanoActual++;
		}
	}
	
	// M�todo para imprimir datos de bibliotecarios
	void Imprimir(string formato) {
		cout << "LISTADO DE BIBLIOTECARIOS:" << endl;
		if (formato == "b") {
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "ID: " << bibliotecarios[i].getIdPersona() << endl;
				cout << "Nombre: " << bibliotecarios[i].getNombre() << endl;
				cout << "Apellido: " << bibliotecarios[i].getApellido() << endl;
				cout << "Correo Electr�nico: " << bibliotecarios[i].getCorreoElectronico() << endl;
				cout << "Departamento: " << bibliotecarios[i].getDepartamento() << endl;
				cout << "-----------------------------" << endl;
			}
		} else if (formato == "t") {
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "| ID | Nombre    | Apellido   | Correo Electr�nico | Departamento           |" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < tamanoActual; ++i) {
				cout << "| " << setw(2) << bibliotecarios[i].getIdPersona()
					<< " | " << setw(9) << bibliotecarios[i].getNombre()
					<< " | " << setw(9) << bibliotecarios[i].getApellido()
					<< " | " << setw(19) << bibliotecarios[i].getCorreoElectronico()
					<< " | " << setw(22) << bibliotecarios[i].getDepartamento() << " |" << endl;
			}
			cout << "-------------------------------------------------------------------------------" << endl;
		} else {
			cout << "Formato no v�lido." << endl;
		}
	}
	
	// M�todo para buscar
	void Buscar(const string& sNombreCompleto, int index = 0) {
		if (index >= tamanoActual) {
			cout << "No se encontraron resultados para la b�squeda." << endl;
			return;
		}
		if (bibliotecarios[index].getNombre() + " " + bibliotecarios[index].getApellido() == sNombreCompleto) {
			cout << "ID: " << bibliotecarios[index].getIdPersona() << ", "
				<< "Nombre: " << bibliotecarios[index].getNombre() << " " << bibliotecarios[index].getApellido() << ", "
				<< "Correo Electr�nico: " << bibliotecarios[index].getCorreoElectronico() << ", "
				<< "Departamento: " << bibliotecarios[index].getDepartamento() << endl;
		}
		Buscar(sNombreCompleto, index + 1); // Llamada recursiva con el siguiente �ndice
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
					string sNombreCompletoUsuario;
					cout << "Ingrese el nombre completo del usuario a buscar (nombre y apellido): ";
					cin.ignore(); // Ignorar el salto de l�nea del buffer
					getline(cin, sNombreCompletoUsuario);
					gestorUsuario.Buscar(sNombreCompletoUsuario);
					break;
				}
				case 'C':
				case 'c': {
					// B�squeda de Bibliotecarios
					string sNombreCompletoBibliotecario;
					cout << "Ingrese el nombre completo del bibliotecario a buscar (nombre y apellido): ";
					cin.ignore(); // Ignorar el salto de l�nea del buffer
					getline(cin, sNombreCompletoBibliotecario);
					gestorBibliotecario.Buscar(sNombreCompletoBibliotecario);
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
