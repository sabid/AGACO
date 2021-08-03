#include <QCoreApplication>
#include <iostream>
#include <ctime>

using namespace std;

const int tamanoArreglo  = 5;

// Defición de arreglos
string fechaCompra[tamanoArreglo];
string descripcionSemillaPastoMejorada[tamanoArreglo];
int costoSemillaPastoMejorada[tamanoArreglo];
int cantidadSemillaPastoMejorada[tamanoArreglo];
int totalSemillaPastoMejorada[tamanoArreglo];

string agregarFecha(int dia, int mes, int year);

void agregarDescripcion();
void imprimir();

int posicionDescripcion = 0;

char menuPrincipal()
{
    char Option;
    cout<<"\t\t****Menu Principal****\n"
        <<"\tA.-> Imprimir \n"
        <<"\tB.-> Ingresar una semilla \n"
        <<"\tC.-> Eliminar una Semilla \n"
        <<"\tD.-> Exportar a Excel \n"
        <<"\tE.-> Consultar Cantidad Invertida en Semilla por Fecha \n"
        <<"\tF.-> Salir \n"
        <<"Su Eleccion Es: ";
    cin.get(Option);
    cin.ignore();
    Option = toupper(Option);//Convierte a Mayusculas

    if(Option<'A' || Option>'F'){
        cout<<"\n\tLa opcion ingresada es incorrecta!!!"
            <<"\n\tFavor vuelva a intentarlo!!!\n";
        Option = menuPrincipal();// Llamado Recursivo
    }

    return Option;
}

char menuSemilla()
{
    char Option;
    cout<<"\t\t****Menu Semilla****\n"
        <<"\tA.-> Agregar Fecha: \n"
        <<"\tB.-> Agregar Descripción: \n"
        <<"\tC.-> Agregar  Costo: \n"
        <<"\tD.-> Agregar Cantidad: \n"
        <<"\tE.-> Regresar al menú anterior. \n"
        <<"Su Eleccion Es: ";
    cin.get(Option);
    cin.ignore();
    Option = toupper(Option);//Convierte a Mayusculas

    if(Option<'A' || Option>'E'){
        cout<<"\n\tLa opcion ingresada es incorrecta!!!"
            <<"\n\tFavor vuelva a intentarlo!!!\n";
        Option = menuSemilla();// Llamado Recursivo
    }

    return Option;
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    char MenuPrincipal;
    char MenuSemilla;

    // Menu
    do {

        MenuPrincipal = menuPrincipal();


        switch (MenuPrincipal) {
            case 'A':
                // llamar a la funcion para imprimir
                cout << "\n\t Imprimir compras \n\n";
                break;

            case 'B':
                // llamar el menu para ingresar una semilla

                do {

                    MenuSemilla = menuSemilla();

                    time_t now = time(NULL);
                    tm * time = localtime(&now);

                    time_t fechaDia = time->tm_mday = 20;

                    switch (MenuSemilla) {
                        case 'A':
                            // llamar a la funcion para agregar Fecha
                            // cout << "\n\t Agregar fecha \n\n";
                            // agregarFecha("Hola");

                            cout << "\n\t dia: " << time->tm_mday << " mes: " << time->tm_mon + 1 << " year: " << ( 1900 + time->tm_year ) <<"\n\n";

                            cout << "\n\t dia modificado " << time << "\n\n";

                            break;
                        case 'B':
                            // llamar a la funcion para agregar Descripción
                            agregarDescripcion();

                            imprimir();

                            break;
                        case 'C':
                            // llamar a la funcion para agregar Costo
                            cout << "\n\t Agregar Costo \n\n";
                            break;
                        case 'D':
                            // llamar a la funcion para agregar Cantidad
                            cout << "\n\t Agregar Cantidad \n\n";
                            break;
                        case 'E':
                            // Regresar al menú anterior, llamando el menu
                            cout << "\n\t Regresar al menú anterior \n\n";
                            break;

                    }

                } while (MenuSemilla != 'E');


                // llamar a la funcion para Ingresar una Semilla


                // cout << "\n\t Agregar semilla \n\n";

                break;

            case 'C':
                // llamar a la funcion para Eliminar una Semilla

                cout << "\n\t Eliminar una Semilla \n\n";

                break;

            case 'D':
                // llamar a la funcion para Exportar a Excel

                cout << "\n\t Exportar a Excel \n\n";

                break;

            case 'E':
                // llamar a la funcion Consultar Cantidad Invertida en Semilla por Fecha

                cout << "\n\t Consultar Cantidad Invertida en Semilla por Fecha \n\n";

                break;

            case 'F':
                // salir
                cout<<"\n\tGracias por su Visita!!!\n\tLe Esperamos Pronto!!!\n";
                break;

            default:
                break;
        }

    } while (MenuPrincipal != 'F');


    return 0;

}


string agregarFecha(string fecha)
{

    //time_t now;
    //now = time(NULL);
    //now_tm = localtime(&now);

    return fecha;

}

void agregarDescripcion()
{
    string descripcion;

    cout << "\n\t Agregar Descripción: ";

    //cin >> input; // get user input from the keyboard

    getline(cin, descripcion);

    descripcionSemillaPastoMejorada[posicionDescripcion] = descripcion;

    posicionDescripcion++;

}

void imprimir() {


    for(int i = 0; i < tamanoArreglo; i++)
    {
        cout << "\t Descripcion: " << descripcionSemillaPastoMejorada[i] ;
    }

}



