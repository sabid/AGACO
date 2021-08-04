#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <iomanip> // setfill, setw
#include <fstream> //

using namespace std;

const int tamanoArreglo  = 8;

// Deficion de arreglos
string fechaCompra[tamanoArreglo];
string descripcionSemillaPastoMejorada[tamanoArreglo];
int costoSemillaPastoMejorada[tamanoArreglo];
int cantidadSemillaPastoMejorada[tamanoArreglo];
int totalSemillaPastoMejorada[tamanoArreglo];

// Deficion de procedimientos
void imprimir();
void agregarFecha();
void agregarDescripcion();
void AgregarCostos();
void AgregarCantidades();
void eliminarSemilla();
void cantidadInvertidaPorFecha();
void Predefinido();
void Exportar();
void Total();

char menuPrincipal()
{
    char Option;
    cout<<"\t\t****Menu Principal****\n"
        <<"\tA.-> Imprimir \n"
        <<"\tB.-> Ingresar una semilla \n"
        <<"\tC.-> Eliminar una Semilla \n"
        <<"\tD.-> Exportar a Excel \n"
        <<"\tE.-> Consultar cantidad invertida en semilla por fecha \n"
        <<"\tF.-> Salir \n"
        <<"Su eleccion es: ";
    cin.get(Option);
    cin.ignore();
    Option = toupper(Option);// Convierte a mayusculas

    if(Option<'A' || Option>'F'){
        cout<<"\n\tLa opcion ingresada es incorrecta!!!"
            <<"\n\tFavor vuelva a intentarlo!!!\n";
        Option = menuPrincipal();// Llamado recursivo
    }

    return Option;
}

char menuSemilla()
{
    char Option;
    cout<<"\t\t****Menu Semilla****\n"
        <<"\tA.-> Agregar Fecha \n"
        <<"\tB.-> Agregar Descripcion \n"
        <<"\tC.-> Agregar Costo \n"
        <<"\tD.-> Agregar Cantidad \n"
        <<"\tE.-> Regresar al menu anterior \n"
        <<"Su eleccion es: ";
    cin.get(Option);
    cin.ignore();
    Option = toupper(Option);// Convierte a mayusculas

    if(Option<'A' || Option>'E'){
        cout<<"\n\tLa opcion ingresada es incorrecta: "<<Option<<"\n"
            <<"\n\tFavor vuelva a intentarlo!!!\n";
        Option = menuSemilla();// Llamado recursivo
    }

    return Option;
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    char MenuPrincipal;
    char MenuSemilla;

    Predefinido();

    // Menu
    do {

        MenuPrincipal = menuPrincipal();


        switch (MenuPrincipal) {
            case 'A':
                // llamar a la funcion para imprimir
                imprimir();
                break;

            case 'B':
                // Ingresar una semilla
                do {

                    MenuSemilla = menuSemilla();



                    switch (MenuSemilla) {
                        case 'A':
                            // llamar a la funcion para agregar Fecha
                            agregarFecha();
                            imprimir();
                            break;
                        case 'B':
                            // llamar a la funcion para agregar Descripción
                            agregarDescripcion();
                            imprimir();
                            break;
                        case 'C':
                            // llamar a la funcion para agregar Costo
                            AgregarCostos();
                            imprimir();
                            break;
                        case 'D':
                            // llamar a la funcion para agregar Cantidad
                            AgregarCantidades();
                            Total();
                            imprimir();
                            break;
                        case 'E':
                            // Regresar al menu anterior, llamando el menu
                            cout << "\n\t Regresar al menu anterior \n\n";
                            break;

                    }

                } while (MenuSemilla != 'E');

                break;

            case 'C':

                // llamar a la funcion para Eliminar una Semilla

                imprimir();

                eliminarSemilla();

                imprimir();

                break;

            case 'D':
                // llamar a la funcion para Exportar a Excel
                Exportar();

                break;

            case 'E':
                // llamar a la funcion Consultar Cantidad Invertida en Semilla por Fecha

                cout << "\n\t Consultar Cantidad Invertida en Semilla por Fecha \n\n";

                cantidadInvertidaPorFecha();

                break;

            case 'F':
                // salir
                cout<<"\n\tGracias por su visita!!!\n\t Le esperamos pronto!!!\n";
                break;

            default:
                break;
        }

    } while (MenuPrincipal != 'F');


    return 0;

}


void agregarFecha()
{
    /*
    time_t now = time(NULL);
    tm * time = localtime(&now);

    time_t fechaDia = time->tm_mday = 20;

    cout << "\n\t dia: " << time->tm_mday << " mes: " << time->tm_mon + 1 << " year: " << ( 1900 + time->tm_year ) <<"\n\n";
    cout << "\n\t dia modificado " << time << "\n\n";
    */

    string fecha, dia, mes, anio;

    cout << "\n******* Fecha de la Compra ********\n";

    for(int i = 6; i < tamanoArreglo ; i++){

        cout << "Fecha " << i + 1 << ": \n";

        cout << "Dia: ";
        cin >> dia;
        cin.ignore();

        cout << "Mes: ";
        cin >> mes;
        cin.ignore();

        cout << "Anio: ";
        cin >> anio;
        cin.ignore();

        fecha.append(dia).append("/").append(mes).append("/").append(anio);

        fechaCompra[i] = fecha;

        fecha.clear();
    }

}

void agregarDescripcion()
{
    string descripcion;

    cout << "\n******* Descripcion de Semilla ********\n";

    for(int i = 6; i < tamanoArreglo ; i++){

        cout << "Descripcion " << i + 1 << ": ";
        getline(cin, descripcion);
        descripcionSemillaPastoMejorada[i] = descripcion;
    }

}

void AgregarCostos()
{

    int costo;

    cout << "\n******* Costo de semilla ********\n";

    for(int i = 6; i < tamanoArreglo ; i++){
        cout << "Costo " << i + 1 << ": ";
        cin >> costo;
        cin.ignore();
        costoSemillaPastoMejorada[i] = costo;
    }
}

void AgregarCantidades()
{

    int cantidad;

    cout << "\n******* Cantidad de semilla ********:\n";

    for(int i = 6; i < tamanoArreglo ; i++){
        cout << "Cantidad " << i + 1  << ": ";
        cin >> cantidad;
        cin.ignore();
        cantidadSemillaPastoMejorada[i] = cantidad;
     }

}

void Total()
{
    for(int i = 0; i < tamanoArreglo ; i++){
        totalSemillaPastoMejorada[i] = cantidadSemillaPastoMejorada[i] * costoSemillaPastoMejorada[i];
    }
}

/*
 * Eliminar una semilla
 */

void eliminarSemilla() {

    int index;

    cout << "\n Escriba el ID de la semilla a eliminar: ";
    cin >> index;
    cin.ignore();

    // TODO: validar que el indice existe y que contenga datos.
    fechaCompra[index - 1].clear();
    descripcionSemillaPastoMejorada[index - 1].clear();
    costoSemillaPastoMejorada[index - 1] = 0;
    cantidadSemillaPastoMejorada[index - 1] = 0;
    totalSemillaPastoMejorada[index - 1] = 0;
}

void cantidadInvertidaPorFecha()
{
    // Si una fecha es igual a otra sumar los totales

    //int comprasPorFecha[5];

    int suma = 0;

    for(int i = 0; i < tamanoArreglo ; i++)
    {

        for(int j = 0; j < tamanoArreglo ; j++)
        {
            //suma = totalSemillaPastoMejorada[i];

            if(fechaCompra[i] == fechaCompra[j] )
            {

               suma += totalSemillaPastoMejorada[j];

            }


        }


       cout << "Compras en la fecha: " << fechaCompra[i]  << " inversion: " << suma  << "\n";

       suma = 0;

    }

}

void Exportar(){

    string archivo = "compras_de_semillas_de_pasto_mejoradas.xls";
    ofstream Documento(archivo.data(),ios::out | ios::app);

    Documento<<"Fecha\t"<<"Descripcion\t"<<"Costo\t"<<"Cantidad\t"<<"Total"<<"\n";

    for(int i = 0; i < tamanoArreglo; i++)
    {
        Documento<< fechaCompra[i] << "\t"
                << descripcionSemillaPastoMejorada[i] << "\t"
                << costoSemillaPastoMejorada[i] << "\t"
                << cantidadSemillaPastoMejorada[i] << "\t"
                << totalSemillaPastoMejorada[i] <<"\n";
    }

    Documento.close();
    cout << "\n Documento exportado \n";
}

void Predefinido()
{

    fechaCompra[0].append("10/08/2021");
    fechaCompra[1].append("10/08/2021");
    fechaCompra[2].append("11/08/2021");
    fechaCompra[3].append("12/08/2021");
    fechaCompra[4].append("13/08/2021");
    fechaCompra[5].append("14/08/2021");

    for(int i = 0; i < 6 ; i++){
        descripcionSemillaPastoMejorada[i] = "Semilla Mejorada";
        cantidadSemillaPastoMejorada[i] = i + 1;
        costoSemillaPastoMejorada[i] = i + 1 * 2 ;
     }

    Total();

}

void imprimir()
{

    cout << "\n\t Registro de Compra de Semilla de Pasto Mejorada " << "\n\n";

    cout<<"+---+----------+----------------------+--------+--------+--------+\n"
        <<"|ID |Fecha     |Descripcion           |Costo   |Cantidad|Total   |\n"
        <<"+---+----------+----------------------+--------+--------+--------+\n";

    for(int i = 0; i < tamanoArreglo; i++)
    {
        cout<< "|" << setfill(' ')<< setw(3) << (i + 1)
            << "|" << setfill(' ')<< setw(10) << fechaCompra[i]
            << "|" << setfill(' ')<< setw(22) << left << descripcionSemillaPastoMejorada[i]
            << "|" << setfill(' ')<< setw(8) << right <<  costoSemillaPastoMejorada[i]
            << "|" << setfill(' ')<< setw(8) << right <<  cantidadSemillaPastoMejorada[i]
            << "|" << setfill(' ')<< setw(8) << right <<  totalSemillaPastoMejorada[i]
            << "|\n";
    }

    cout << "+---+----------+----------------------+--------+--------+--------+\n\n";

}



