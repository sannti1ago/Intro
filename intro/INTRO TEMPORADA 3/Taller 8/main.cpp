#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Libro {
    string titulo;
    string autor;
    int disponibilidad;
    int diasPrestamo;
    Fecha fechaPrestamo;
    float multaPorDia;
};

Libro biblioteca[MAX];
int totalLibros = 0;

void ingresarFecha(Fecha &f) {
    cout << "  Dia: ";   cin >> f.dia;
    cout << "  Mes: ";   cin >> f.mes;
    cout << "  Anio: ";  cin >> f.anio;
}

void imprimirFecha(Fecha f) {
    cout << (f.dia  < 10 ? "0" : "") << f.dia  << "/"
         << (f.mes  < 10 ? "0" : "") << f.mes  << "/"
         << f.anio;
}

int diasDesde(Fecha desde, Fecha hasta) {
    int d1 = desde.anio * 365 + desde.mes * 30 + desde.dia;
    int d2 = hasta.anio * 365 + hasta.mes * 30 + hasta.dia;
    return d2 - d1;
}

Fecha fechaDevolucionEsperada(Fecha prestamo, int dias) {
    Fecha dev = prestamo;
    dev.dia += dias;
    while (dev.dia > 30) { dev.dia -= 30; dev.mes++; }
    while (dev.mes > 12) { dev.mes -= 12; dev.anio++; }
    return dev;
}

int buscarLibro(string titulo) {
    for (int i = 0; i < totalLibros; i++) {
        if (biblioteca[i].titulo == titulo) return i;
    }
    return -1;
}

void ingresarLibro() {
    char seguir = 's';
    while (seguir == 's' || seguir == 'S') {
        if (totalLibros >= MAX) {
            cout << "Biblioteca llena." << endl;
            return;
        }
        Libro L;
        cout << "\nTitulo: ";       cin.ignore(); getline(cin, L.titulo);
        cout << "Autor: ";          getline(cin, L.autor);
        cout << "Dias de prestamo: "; cin >> L.diasPrestamo;
        cout << "Multa por dia ($): "; cin >> L.multaPorDia;
        L.disponibilidad = 0;
        L.fechaPrestamo  = {0, 0, 0};

        biblioteca[totalLibros] = L;
        totalLibros++;
        cout << "Libro ingresado correctamente." << endl;

        cout << "Desea ingresar otro libro? (s/n): ";
        cin >> seguir;
    }
}

void prestarLibro() {
    char seguir = 's';
    while (seguir == 's' || seguir == 'S') {
        string titulo;
        cout << "\nTitulo del libro a prestar: ";
        cin.ignore(); getline(cin, titulo);

        int idx = buscarLibro(titulo);
        if (idx == -1) {
            cout << "Libro no encontrado." << endl;
        } else if (biblioteca[idx].disponibilidad == 1) {
            cout << "El libro no esta disponible." << endl;
            cout << "Fecha esperada de devolucion: ";
            imprimirFecha(fechaDevolucionEsperada(
                biblioteca[idx].fechaPrestamo,
                biblioteca[idx].diasPrestamo));
            cout << endl;
        } else {
            cout << "Ingrese la fecha de prestamo:" << endl;
            ingresarFecha(biblioteca[idx].fechaPrestamo);
            biblioteca[idx].disponibilidad = 1;
            cout << "Prestamo realizado correctamente." << endl;
        }

        cout << "Desea solicitar otro libro? (s/n): ";
        cin >> seguir;
    }
}

void devolverLibro() {
    string titulo;
    cout << "\nTitulo del libro a devolver: ";
    cin.ignore(); getline(cin, titulo);

    int idx = buscarLibro(titulo);
    if (idx == -1) {
        cout << "Libro no encontrado." << endl;
        return;
    }
    if (biblioteca[idx].disponibilidad == 0) {
        cout << "Este libro no estaba en prestamo." << endl;
        return;
    }

    Fecha fechaDev;
    cout << "Ingrese la fecha de devolucion:" << endl;
    ingresarFecha(fechaDev);

    Fecha esperada = fechaDevolucionEsperada(
        biblioteca[idx].fechaPrestamo,
        biblioteca[idx].diasPrestamo);

    int diasExtra = diasDesde(esperada, fechaDev);

    if (diasExtra <= 0) {
        cout << "Devolucion a tiempo. Gracias!" << endl;
        biblioteca[idx].disponibilidad = 0;
        biblioteca[idx].fechaPrestamo  = {0, 0, 0};
    } else {
        float multa = diasExtra * biblioteca[idx].multaPorDia;
        cout << "Devolucion con " << diasExtra << " dia(s) de retraso." << endl;
        cout << "Multa: $" << multa << endl;

        float pagado = 0;
        while (pagado < multa) {
            cout << "Ingrese el pago (multa restante $"
                 << (multa - pagado) << "): ";
            float abono; cin >> abono;
            pagado += abono;
            if (pagado < multa)
                cout << "Pago insuficiente. Multa aumenta a $"
                     << multa << " (sigue acumulando)." << endl;
        }
        cout << "Multa pagada. Libro devuelto." << endl;
        biblioteca[idx].disponibilidad = 0;
        biblioteca[idx].fechaPrestamo  = {0, 0, 0};
    }
}

void visualizarLibros() {
    if (totalLibros == 0) {
        cout << "No hay libros registrados." << endl;
        return;
    }

    cout << "Titulo\t\tAutor\t\tDisp\tDias\tFecha\t\tMulta/dia" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < totalLibros; i++) {
        Libro L = biblioteca[i];
        cout << L.titulo << "\t"
             << L.autor  << "\t"
             << (L.disponibilidad == 0 ? "Disponible" : "Prestado") << "\t"
             << L.diasPrestamo << "\t";
        if (L.disponibilidad == 1) imprimirFecha(L.fechaPrestamo);
        else cout << "NA\t";
        cout << "\t$" << L.multaPorDia << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n====== BIBLIOTECA ======" << endl;
        cout << "1. Ingresar libro" << endl;
        cout << "2. Prestar libro"  << endl;
        cout << "3. Devolver libro" << endl;
        cout << "4. Ver libros"     << endl;
        cout << "5. Salir"          << endl;
        cout << "Opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: ingresarLibro();  break;
            case 2: prestarLibro();   break;
            case 3: devolverLibro();  break;
            case 4: visualizarLibros(); break;
            case 5: cout << "Hasta luego!" << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}