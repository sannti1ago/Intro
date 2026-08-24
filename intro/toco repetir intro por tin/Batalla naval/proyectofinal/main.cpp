#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int TAM = 10;

// ESTRUCTURA: Jugador

// Almacena TODA la información necesaria según los requerimientos:
//   - Nombre completo
//   - Usuario único
//   - Contraseña
//   - ID generado aleatoriamente (1 a 10 000)
//   - Estadísticas de juego (victorias y derrotas)

struct Jugador {
    string nombre;
    string usuario;
    string contrasena;
    int id;
    int victorias;
    int derrotas;
};

// ESTRUCTURA: Tablero

// Representa el estado de la partida para cada jugador:
//   - `propio`   → donde coloca sus barcos
//   - `oponente` → donde marca los disparos que realiza
//   - `barcosRestantes` → se usa para determinar fin del juego

struct Tablero {
    string dueno;
    char propio[TAM][TAM];
    char oponente[TAM][TAM];
    int barcosRestantes;
};

// UTILIDADES DEL SISTEMA

// Funciones varias usadas en todo el programa para evitar repetir
// código y mejorar la claridad.

// Verifica si un archivo existe
bool archivoExiste(const string &nombre) {
    ifstream f(nombre.c_str());
    return f.good();
}

// Convierte una cadena a mayúsculas
string mayusculas(string s) {
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    return s;
}

// Pausa amigable entre turnos
void pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

// MANEJO DEL ARCHIVO Jugadores.txt

// Esta sección incluye todas las funciones necesarias para:
//   - Registrar jugadores
//   - Iniciar sesión
//   - Guardar y cargar información persistente
//   - Actualizar estadísticas al finalizar partidas

// Verifica si un usuario ya está registrado
bool usuarioExiste(const string &usuario) {
    ifstream in("Jugadores.txt");
    if (!in.good()) return false;

    string u, n, c;
    int id, v, d;

    while (in >> u >> n >> c >> id >> v >> d)
        if (u == usuario) return true;

    return false;
}

// Verifica si un ID ya existe en el archivo
bool idExiste(int idBuscado) {
    ifstream in("Jugadores.txt");
    if (!in.good()) return false;

    string u, n, c;
    int id, v, d;

    while (in >> u >> n >> c >> id >> v >> d)
        if (id == idBuscado) return true;

    return false;
}

// Genera un ID aleatorio y único entre 1 y 9999
int generarID() {
    srand(time(NULL));
    int id = 1 + rand() % 9999;
    while (idExiste(id)) id = 1 + rand() % 9999;
    return id;
}

// Guarda un jugador en el archivo
bool guardarJugador(const Jugador &j) {
    ofstream out("Jugadores.txt", ios::app);
    if (!out.good()) return false;
    
    out << j.usuario << " " << j.nombre << " " << j.contrasena << " "
        << j.id << " " << j.victorias << " " << j.derrotas << "\n";
    return true;
}

// Busca un jugador según usuario y contraseña
bool buscarJugador(const string &usuario, const string &contrasena, Jugador &res) {
    ifstream in("Jugadores.txt");
    if (!in.good()) return false;

    Jugador temp;
    while (in >> temp.usuario >> temp.nombre >> temp.contrasena
           >> temp.id >> temp.victorias >> temp.derrotas)
    {
        // Credenciales correctas
        if (temp.usuario == usuario && temp.contrasena == contrasena) {
            res = temp;
            return true;
        }
    }
    return false;
}

// ACTUALIZACIÓN DE ESTADÍSTICAS TRAS LA PARTIDA

void actualizarEstadisticas(const Jugador &ganador, const Jugador &perdedor) {
    ifstream in("Jugadores.txt");
    ofstream out("temp.txt");

    Jugador j;
    while (in >> j.usuario >> j.nombre >> j.contrasena >> j.id >> j.victorias >> j.derrotas) {

        // Incrementar estadísticas
        if (j.usuario == ganador.usuario) j.victorias++;
        if (j.usuario == perdedor.usuario) j.derrotas++;

        // Guardar en archivo temporal
        out << j.usuario << " " << j.nombre << " " << j.contrasena << " "
            << j.id << " " << j.victorias << " " << j.derrotas << "
";
    }

    // Reemplazar archivo original
    remove("Jugadores.txt");
    rename("temp.txt", "Jugadores.txt");
}

// REGISTRO DE JUGADORES

bool registrarJugador() {
    Jugador j;

    cin.ignore();
    cout << "Nombre (sin espacios): ";
    cin >> j.nombre;

    cout << "Usuario (sin espacios): ";
    cin >> j.usuario;

    if (usuarioExiste(j.usuario)) {
        cout << "Ese usuario ya existe.
";
        return false;
    }

    cout << "Contraseña: ";
    cin >> j.contrasena;

    j.id = generarID();
    j.victorias = 0;
    j.derrotas = 0;

    if (!guardarJugador(j)) {
        cout << "Error al guardar.
";
        return false;
    }

    cout << "Registrado con éxito. ID asignado: " << j.id << "
";
    return true;
}

// INICIO DE SESIÓN

bool iniciarSesion(Jugador &j) {
    string usuario, contrasena;
    cout << "Usuario: "; cin >> usuario;
    cout << "Contraseña: "; cin >> contrasena;
    return buscarJugador(usuario, contrasena, j);
}

// INICIALIZACIÓN DEL TABLERO

void inicializarTablero(Tablero &t, const string &dueno) {
    t.dueno = dueno;
    t.barcosRestantes = 6; // 3S, 2C, 1B

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) {
            t.propio[i][j] = '~';   // agua
            t.oponente[i][j] = '~'; // sin disparos
        }
}


// TAMAÑO DE BARCOS

int tamBarco(char tipo) {
    switch (tipo) {
        case 'S': return 2; // Submarino
        case 'C': return 3; // Crucero
        case 'B': return 4; // Buque
    }
    return 0;
}

// COLOCACIÓN DE BARCOS EN EL TABLERO

bool colocarBarco(Tablero &t, char tipo, int fila, int col, char ori) {
    int n = tamBarco(tipo);
    if (n == 0) return false;


    // Colocación Horizontal

    if (ori == 'H') {
        if (col + n > TAM) return false; // Se sale del tablero

        for (int c = col; c < col + n; c++)
            if (t.propio[fila][c] != '~') return false;

        for (int c = col; c < col + n; c++)
            t.propio[fila][c] = tipo;
    }

    // Colocación Vertical

    else {
        if (fila + n > TAM) return false; // Se sale del tablero

        for (int f = fila; f < fila + n; f++)
            if (t.propio[f][col] != '~') return false;

        for (int f = fila; f < fila + n; f++)
            t.propio[f][col] = tipo;
    }

    return true;
}

// PARSEAR LAS LÍNEAS DE Posiciones#.txt

bool parsearLinea(const string &linea, char &tipo, int &fila, int &col, char &ori) {
    tipo = 0; fila = -1; col = -1; ori = 0;
    int estado = 0;

    for (int i = 0; i < (int)linea.size(); i++) {
        char c = linea[i];

        if (estado == 0 && (c == 'S' || c == 'C' || c == 'B' || c == 's' || c == 'c' || c == 'b')) {
            tipo = mayusculas(string(1, c))[0];
            estado = 1;
        }
        else if (estado == 1 && c >= '0' && c <= '9') {
            fila = c - '0';
            estado = 2;
        }
        else if (estado == 2 && c >= '0' && c <= '9') {
            col = c - '0';
            estado = 3;
        }

        // Detección de orientación H/V al final de la línea
        else if (estado == 3 && (c == 'H' || c == 'V' || c == 'h' || c == 'v')) {
            ori = mayusculas(string(1, c))[0];
            return true; // La línea ya es válida
        }
    }

    return false; // Si no se encontró patrón válido
}

// CARGA Y VALIDACIÓN COMPLETA DE Posiciones#.txt

// El archivo debe cumplir estas reglas:
//   ✔ Contener exactamente 6 barcos:
//       - 3 Submarinos (S)
//       - 2 Cruceros   (C)
//       - 1 Buque      (B)
//   ✔ NO tener solapamientos
//   ✔ NO salirse del área del tablero 10x10
//   ✔ Formato flexible (acepta "S,0,0,H" o "S 0 0 H")

bool cargarPosiciones(int num, Tablero &t) {
    string nombre = "Posiciones" + to_string(num) + ".txt";
    ifstream in(nombre.c_str());

    if (!in.good()) {
        cout << "No existe el archivo: " << nombre << "
";
        return false;
    }

    // Contadores para validar la cantidad correcta de cada tipo de barco
    int cS = 0, cC = 0, cB = 0;
    string linea;

    // Tablero temporal para validar posiciones antes de copiar
    Tablero temp = t;

    int lineaNum = 0;
    while (getline(in, linea)) {
        lineaNum++;
        if (linea.size() < 3) continue;

        char tipo, ori;
        int fila, col;

        // Intentar parsear la línea
        if (!parsearLinea(linea, tipo, fila, col, ori)) {
            cout << "Error de formato en línea " << lineaNum
                 << " del archivo " << nombre << "
";
            return false;
        }

        // Intentar colocar el barco en el tablero
        if (!colocarBarco(temp, tipo, fila, col, ori)) {
            cout << "Error colocando barco en línea " << lineaNum
                 << " del archivo " << nombre << "
";
            return false;
        }

        // Contar tipos
        if (tipo == 'S') cS++;
        if (tipo == 'C') cC++;
        if (tipo == 'B') cB++;
    }

    // Validar cantidades exactas
    if (!(cS == 3 && cC == 2 && cB == 1)) {
        cout << "El archivo " << nombre
             << " debe contener exactamente 3S, 2C, 1B
";
        cout << "Se encontró: S=" << cS << " C=" << cC << " B=" << cB << "
";
        return false;
    }

    // Si todo está bien: copiar el tablero validado
    t = temp;
    return true;
}

// SISTEMA DE DISPAROS

// Funcionalidad del juego principal:
//   ✔ Convertir coordenada texto → fila/columna
//   ✔ Detectar impactos
//   ✔ Registrar agua
//   ✔ Marcar disparos repetidos


bool convertirCoordenada(string s, int &fila, int &col) {
    s = mayusculas(s);
    if (s.size() != 2) return false;

    // Letra A-J → fila 0-9
    if (s[0] < 'A' || s[0] > 'J') return false;
    fila = s[0] - 'A';

    // Dígito 0-9 → columna 0-9
    if (s[1] < '0' || s[1] > '9') return false;
    col = s[1] - '0';

    return true;
}

// Determina si un barco ha sido completamente destruido
bool barcoDestruido(Tablero &t, char tipo) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (t.propio[i][j] == tipo)
                return false; // Aún quedan partes del barco
    return true;
}

// REALIZAR DISPARO

bool disparar(Tablero &atacado, Tablero &tirador, int fila, int col) {
    // Verificar si ya se disparó en esta coordenada
    if (tirador.oponente[fila][col] != '~') {
        cout << "Ya disparaste en esta casilla.
";
        return false; // No avanza turno
    }

    char objetivo = atacado.propio[fila][col];

    // IMPACTO

    if (objetivo == 'S' || objetivo == 'C' || objetivo == 'B') {
        atacado.propio[fila][col] = 'X';      // Marcar impacto en tablero enemigo
        tirador.oponente[fila][col] = 'X';    // Marcar impacto en tablero del tirador

        cout << "¡Impacto!
";

        // Revisar si el barco fue destruido totalmente
        if (barcoDestruido(atacado, objetivo)) {
            atacado.barcosRestantes--;
            cout << "¡Barco destruido!
";
        }
        return true;
    }

    // AGUA

    atacado.propio[fila][col] = 'O';
    tirador.oponente[fila][col] = 'O';
    cout << "Agua...
";
    return false;
}

// VISUALIZACIÓN DE TABLEROS EN CONSOLA

// Presentación clara = criterio de calificación


// Muestra un tablero 10x10 (propio u oponente)
void mostrarTablero(const Tablero &t, bool mostrarPropio) {
    cout << "    0 1 2 3 4 5 6 7 8 9
";
    for (int i = 0; i < TAM; i++) {
        cout << (char)('A' + i) << "  ";
        for (int j = 0; j < TAM; j++) {
            char simbolo = mostrarPropio ? t.propio[i][j] : t.oponente[i][j];
            cout << simbolo << " ";
        }
        cout << "
";
    }
}

// Pantalla completa para el jugador en turno
void mostrarPantallaJuego(const Jugador &j, const Tablero &t) {
    cout << "==============================
";
    cout << "     TURNO DE: " << j.usuario << "
";
    cout << "==============================
";

    cout << "
Tu océano (tus barcos):
";
    mostrarTablero(t, true);

    cout << "
Tus disparos:
";
    mostrarTablero(t, false);

    cout << "
";
}


// DESARROLLO DE PARTIDA COMPLETA

// Reglas manejadas aquí:
//   ✔ Jugador 2 inicia
//   ✔ Si falla→cambia turno
//   ✔ Si acierta→continúa
//   ✔ Z0 para rendirse
//   ✔ Fin cuando barcosRestantes = 0

void jugar(Jugador &j1, Jugador &j2, Tablero &t1, Tablero &t2) {
    int turno = 2; // Regla del enunciado: jugador 2 empieza

    while (true) {
        Jugador *J = (turno == 1 ? &j1 : &j2);
        Jugador *O = (turno == 1 ? &j2 : &j1);
        Tablero *T = (turno == 1 ? &t1 : &t2);
        Tablero *TO = (turno == 1 ? &t2 : &t1);

        mostrarPantallaJuego(*J, *T);

        cout << "Coordenada (A0-J9) o Z0 para rendirse: ";
        string entrada;
        cin >> entrada;

        // Rendición
        if (entrada == "Z0" || entrada == "z0") {
            cout << J->usuario << " se rinde.
";
            actualizarEstadisticas(*O, *J);
            return;
        }

        int fila, col;
        if (!convertirCoordenada(entrada, fila, col)) {
            cout << "Coordenada inválida.
";
            continue;
        }

        bool acierto = disparar(*TO, *T, fila, col);

        // Ganador
        if (TO->barcosRestantes == 0) {
            cout << "¡" << J->usuario << " gana la partida!
";
            actualizarEstadisticas(*J, *O);
            return;
        }

        // Si falló → cambio de turno
        if (!acierto) {
            turno = (turno == 1 ? 2 : 1);
            pausar();
        }
    }
}


// MENÚ PRINCIPAL Y FLUJO GLOBAL DEL PROGRAMA

int main() {

    // Crear Jugadores.txt si no existe

    if (!archivoExiste("Jugadores.txt")) {
        ofstream out("Jugadores.txt");
        out.close();
    }

    int menu = 0;
    Jugador j1, j2;

    // MENÚ INICIAL: Registrar / Iniciar sesión / Salir

    while (true) {
        cout << "
1. Registrar";
        cout << "
2. Iniciar sesión";
        cout << "
3. Salir";
        cout << "
> ";
        cin >> menu;

        if (menu == 1) registrarJugador();
        else if (menu == 2) break;
        else if (menu == 3) return 0;
    }

    // Iniciar sesión jugador 1

    while (!iniciarSesion(j1))
        cout << "Datos incorrectos. Intente de nuevo.
";

    // Pantalla de bienvenida según criterios del proyecto

    cout << "
Bienvenido " << j1.nombre << " (" << j1.usuario << ")
";
    cout << "ID: " << j1.id << "  -  Victorias: " << j1.victorias
         << "  Derrotas: " << j1.derrotas << "
";

    // Menú posterior al inicio de sesión

    int opc;
    cout << "
1. Iniciar juego
2. Salir
> ";
    cin >> opc;
    if (opc == 2) return 0;

    // Iniciar sesión jugador 2

    cout << "
Jugador 2, inicie sesión:
";
    while (!iniciarSesion(j2) || j2.usuario == j1.usuario)
        cout << "Credenciales inválidas o usuario repetido.
";

    // Inicializar tableros

    Tablero t1, t2;
    inicializarTablero(t1, j1.usuario);
    inicializarTablero(t2, j2.usuario);

    // Selección de archivos de posiciones

    int p1, p2;
    cout << "Archivo de posiciones J1 (1-10): "; cin >> p1;
    cout << "Archivo de posiciones J2 (1-10): "; cin >> p2;

    if (!cargarPosiciones(p1, t1) || !cargarPosiciones(p2, t2)) {
        cout << "Error cargando posiciones.
";
        return 0;
    }

    // INICIAR PARTIDA

    jugar(j1, j2, t1, t2);

    return 0;
}