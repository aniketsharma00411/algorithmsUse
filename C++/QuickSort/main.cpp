#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List myList;
    int myInt;
    char op;

    myList.initialize();
    do
    {
        cout<<"Dame un entero a insertar"<<endl;
        cin>>myInt;

        myList.insertData(myList.getLastPos(),myInt);
        cout<<"Capturamos otro? (S/N): "<<endl;
        cin >>op;

    }
    while(op!='n');
    cout<<"El contenido de la lista es: "<<endl;
    myList.print();

    cout<<"Dame una posicion para eliminar"<<endl;
    cin>>myInt;

    try
    {
        myList.deleteData(myInt);
    }
    catch(ListException ex)
    {
        cout<<"Algo malo ha pasado,el sistema lanzo una excepcion de lista que dice:"<<ex.what()<<endl;
        cout<<"Si esto se repite informe al administrador de sistema"<<endl;
    }
    cout<<"El contenido de la lista es: "<<endl;
    myList.print();

    cout<<endl<<endl;

    cout<<"El elemto en la posicion 50 es"<<endl;
    try
    {
        cout<<myList.retrieve(50);
    }
    catch(ListException ex)
    {
        cout<<"DIIIIIIIIIIIIIIIIE"<<endl;
    }
    cout <<"Escribiendo al disco"<<endl;
    myList.writeToDisk("Entero.txt");

    cout<<"Ordenando"<<endl;
    myList.sortDataMerge();

    cout<<"Gracias por usar este programa"<<endl;
    return 0;
}
