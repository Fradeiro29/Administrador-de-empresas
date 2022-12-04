#include <iostream>
#include <string>
using namespace std;

class Pyme{

    private:
        //Variables privadas
        string nombreEmp;
        string razon_social;
        string direccion;
        string nomb_director;
        int num_trabajadores;
        float ing_anual;

    public:
        //Setters
        void setNombreEmp(string nEmp){
            nombreEmp = nEmp;
        }
        void setRazonSocial(string rs){
            razon_social = rs;
        }
        void setDireccion(string dire){
            direccion = dire;
        }
        void setNombDirecor(string nDire){
            nomb_director = nDire;
        }
        void setNumTrabajadores(int numT){
            num_trabajadores = numT;
        }
        void setIngAnual(float iAnual){
            ing_anual = iAnual;
        }

        //Getters
        string getNombreEmp(){
            return nombreEmp;
        }
        string getRazonSocial(){
            return razon_social;
        }
        string getDireccion(){
            return direccion;
        }
        string getNombDirector(){
            return nomb_director;
        }
        int getNumTrabajadores(){
            return num_trabajadores;
        }
        float getIngAnual(){
            return ing_anual;
        }

        Pyme() : nombreEmp(""), razon_social(""), direccion(""), nomb_director(""), num_trabajadores(0), ing_anual(0) {} //Constructor default sin parámetros
        Pyme(string nEmp, string rs, string dire, string nDire, int numT, float iAnual) : nombreEmp(nEmp), razon_social(rs), direccion(dire), nomb_director(nDire), num_trabajadores(numT), ing_anual(iAnual) {} //Constructor con parámetros

};


class Trabajador: public Pyme{
    private:
        string nombreTrab;
        int edad;
        string puesto;
        float sueldo;
        Pyme pym;
    
    public:
        //Setters
        void setNombreTrab(string nTrab){
            nombreTrab = nTrab;
        }
        void setEdad(int ed){
            edad = ed;
        }
        void setPuesto(string puest){
            puesto = puest;
        }
        void setSueldo(float sueld){
            sueldo = sueld;
        }

        //Getters
        string getNombreTrab(){
            return nombreTrab;
        }
        int getEdad(){
            return edad;
        }
        string getPuesto(){
            return puesto;
        }
        float getSueldo(){
            return sueldo;
        }

        Trabajador() : nombreTrab(""), edad(0), puesto(""), sueldo(0), Pyme() {} //Constructor default sin parámetros
        Trabajador(string nTrab, int ed, string puest, float sueldm, Pyme py) : nombreTrab(nTrab), edad(ed), puesto(puest), sueldo(sueldm), pym(py) {}
};



int main()
{
    int opcion, num_trabajadores, edad, opcion2;
    string nombreEmp, razon_social, direccion, nomb_director, nombreTrab, puesto;
    float ing_anual, sueldo;
    string ignora;
    int cant_pymes = 0;
    int cant_trabajadores = 0;
    Pyme empresas[100];
    Trabajador trabajadores[100];

    while (true){

        cout << "------------------------------Menú------------------------------" << "\n\n" << "Bienvenido" << endl << "Escribe el número de la opción deseada:" << "\n\n" << "1) Agregar PYME" << endl << "2) Agregar trabajador" << endl << "3) Consultar PYME" << endl << "4) Consultar trabajador" << endl << "5) Cerrar" << endl;
        cin >> opcion;

//Opción 1
        if (opcion == 1){
            cout << "----------Agregar PYME----------" << "\n\n";
            getline(cin, ignora);
            cout << "Introduce el nombre de la empresa: ";
            getline(cin, nombreEmp);
            cout << endl;
            cout << "Introduce la razón social de la empresa: ";
            getline(cin, razon_social);
            cout << endl;
            cout << "Introduce la dirección de la empresa: ";
            getline(cin, direccion);
            cout << endl;
            cout << "Introduce el nombre del director de la empresa: ";
            getline(cin, nomb_director);
            cout << endl;
            cout << "Introduce la cantidad de trabajadores en la empresa: ";
            cin >> num_trabajadores;
            cout << endl;
            cout << "Introduce el ingreso anual de la empresa: ";
            cin >> ing_anual;
            cout << endl;

            empresas[cant_pymes] = Pyme(nombreEmp, razon_social, direccion, nomb_director, num_trabajadores, ing_anual);

            cant_pymes++;

        }

//Opción 2
        else if (opcion == 2){
            if (cant_pymes > 0){
                cout << "----------Agregar trabajador----------" << "\n\n" << "Elige la PYME del trabajador: " << endl;
                for (int i = 0; i < cant_pymes; i++)
                {
                    cout << i+1 << ") " << empresas[i].getNombreEmp() << endl;
                }
                cout << "Número de PYME: ";
                cin >> opcion2;
                if ((opcion2 >= 1) && (opcion2 <= cant_pymes))
                {
                    if (cant_trabajadores < empresas[opcion2-1].getNumTrabajadores())
                    {
                        getline(cin, ignora);
                        cout << "Introduce el nombre del trabajador: ";
                        getline(cin, nombreTrab);
                        cout << endl;
                        cout << "Introduce la edad del trabajador: ";
                        cin >> edad;
                        cout << endl;
                        cout << "Introduce el puesto del trabajador: ";
                        getline(cin, ignora);
                        getline(cin, puesto);
                        cout << endl;
                        cout << "Introduce el sueldo del trabajador: ";
                        cin >> sueldo;
                        trabajadores[cant_trabajadores] = Trabajador(nombreTrab, edad, puesto, sueldo, empresas[opcion2-1]);
                        cant_trabajadores++;
                    }

                    else{
                        cout << "Se excedió el número de trabajadores permitidos para esta empresa." << endl;
                    }
                }
                else{
                    cout << "Pyme no existente" << endl;
                }
            }

            else{
                cout << "No existe ninguna PYME, vuelve al menú." << endl;
            }

        }

//Opción 3
        else if (opcion == 3){
            if (cant_pymes > 0)
            {
                int coincidencias = 0;
                int lista_coincidencias[] = {};
                cout << "----------Consultar PYME----------" << "\n\n";
                getline(cin, ignora);
                cout << "Introduce el nombre de la PYME que quieres buscar: ";
                getline(cin, nombreEmp);
                for (int h = 0; h < cant_pymes; h++)
                {
                    if (nombreEmp == empresas[h].getNombreEmp()){
                        coincidencias++;
                        lista_coincidencias[coincidencias-1] = h;

                    }
                }
                if (coincidencias == 1){
                    cout << "Nombre de la empresa: " << empresas[lista_coincidencias[0]].getNombreEmp() << endl;
                    cout << "Razón social de la empresa: " << empresas[lista_coincidencias[0]].getRazonSocial() << endl;
                    cout << "Dirección de la empresa: " << empresas[lista_coincidencias[0]].getDireccion() << endl;
                    cout << "Director de la empresa: " << empresas[lista_coincidencias[0]].getNombDirector() << endl;
                    cout << "Número de trabajadores en la empresa: " << empresas[lista_coincidencias[0]].getNumTrabajadores() << endl;
                    cout << "Ingreso anual de la empresa: " << empresas[lista_coincidencias[0]].getIngAnual() << endl;
                }

                else if (coincidencias > 1){
                    cout << "Se han encontrado " << coincidencias << " empresas con el mismo nombre.\nEscribe el número de la empresa que deseas consultar: " << endl;
                    for (int p = 0; p < coincidencias; p++)
                    {
                        cout << p+1 << ") " << empresas[lista_coincidencias[p]].getNombreEmp() << endl;
                    }
                    
                    cout << "Empresa: ";
                    cin >> opcion2;
                    cout << endl;
                    cout << "Nombre de la empresa: " << empresas[lista_coincidencias[opcion2-1]].getNombreEmp() << endl;
                    cout << "Razón social de la empresa: " << empresas[lista_coincidencias[opcion2-1]].getRazonSocial() << endl;
                    cout << "Dirección de la empresa: " << empresas[lista_coincidencias[opcion2-1]].getDireccion() << endl;
                    cout << "Director de la empresa: " << empresas[lista_coincidencias[opcion2-1]].getNombDirector() << endl;
                    cout << "Número de trabajadores en la empresa: " << empresas[lista_coincidencias[opcion2-1]].getNumTrabajadores() << endl;
                    cout << "Ingreso anual de la empresa: " << empresas[lista_coincidencias[opcion2-1]].getIngAnual() << endl;
                }

                else if (coincidencias == 0){
                    cout << "No se encontraron empresas con este nombre." << endl;
                }
            }

            else {
                cout << "No existen PYMES." << endl;
            }


        }

        else if (opcion == 4){
            if (cant_trabajadores > 0){
                int coincidencias2 = 0;
                int lista_coincidencias2[] = {};
                cout << "----------Consultar trabajador----------" << "\n\n";
                getline(cin, ignora);
                cout << "Introduce el nombre del trabajador que quieres buscar: ";
                getline(cin, nombreTrab);
                for (int g = 0; g < cant_trabajadores; g++)
                {
                    if (nombreTrab == trabajadores[g].getNombreTrab()){
                        coincidencias2++;
                        lista_coincidencias2[coincidencias2-1] = g;

                    }
                }
                if (coincidencias2 == 1){
                    cout << "Nombre del trabajador: " << trabajadores[lista_coincidencias2[0]].getNombreTrab() << endl;
                    cout << "Edad del trabajador: " << trabajadores[lista_coincidencias2[0]].getEdad() << endl;
                    cout << "Puesto del trabajador: " << trabajadores[lista_coincidencias2[0]].getPuesto() << endl;
                    cout << "Sueldo del trabajador: " << trabajadores[lista_coincidencias2[0]].getSueldo() << endl;
                    cout << "Empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[0]].getNombreEmp() << endl;
                    cout << "Dirección de la empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[0]].getDireccion() << endl;
                    cout << "Razón social de la empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[0]].getRazonSocial() << endl;
                }

                else if (coincidencias2 > 1){
                    cout << "Se han encontrado " << coincidencias2 << " trabajadores con el mismo nombre.\nEscribe el número del trabajador que deseas consultar: " << endl;
                    for (int y = 0; y < coincidencias2; y++)
                    {
                        cout << y+1 << ") " << trabajadores[lista_coincidencias2[y]].getNombreTrab() << endl;
                    }
                    
                    cout << "Trabajador: ";
                    cin >> opcion2;
                    cout << endl;
                    cout << "Nombre del trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getNombreTrab() << endl;
                    cout << "Edad del trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getEdad() << endl;
                    cout << "Puesto del trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getPuesto() << endl;
                    cout << "Sueldo del trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getSueldo() << endl;
                    cout << "Empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getNombreEmp() << endl;
                    cout << "Dirección de la empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getDireccion() << endl;
                    cout << "Razón social de la empresa donde trabaja el trabajador: " << trabajadores[lista_coincidencias2[opcion2-1]].getRazonSocial() << endl;
                }

                else if (coincidencias2 == 0){
                    cout << "No se encontraron trabajadores con este nombre." << endl;
                }
            }

            else{
                cout << "No existen trabajadores." << endl;
            }
        }

        if (opcion == 5){
            cout << "El programa se ha cerrado de forma exitosa." << endl;
            exit(1);
        }

        else{
            cout << "Opción no válida" << endl;
        }

    }
    return 0;
}