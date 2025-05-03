#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//Correspondencia Directa?
struct Persona{
    int key;
    string tenaciousd;
};

struct PersonaIndex{
    int key;
    int pos;
};

void createIndex(const vector<Persona>& file, vector<PersonaIndex>& index){
    index.clear();
    for (int i = 0; i < file.size(); i++){
        index.push_back({file[i].key});
    }
    sort(index.begin(), index.end(), [](const PersonaIndex& a, const PersonaIndex& b){
        return a.key < b.key;
    });
}

void addPersona(vector <Persona>& file, vector<PersonaIndex>& index, const Persona& newPersona){
    file.push_back(newPersona);
    createIndex(file, index);
}

void showoffStand(const vector<Persona>& dataFile){
    cout<<"PERSONA: Enseñando los registros añadidos hasta el momento:"<<endl;
    for (const auto& persona : dataFile){
        cout<<"Key: "<< persona.key <<" Dato Asociado: "<< persona.tenaciousd <<endl;
    }
}


//Correspondencia por Calculo
struct P3Reload{
    string key;
    string stand;
};

int hashFunction(const string &key, int tableSize) {
    int suma = 0;
    for (char c : key) // Itera sobre cada carácter de la cadena.
    suma += c; // Acumula el valor ASCII de cada carácter.
    return suma % tableSize; // Retorna la posición calculada dentro del tamaño de la tabla.
}

void tatskete(const vector<P3Reload>& dataFileReloaded){
    cout<<"PERSONA2: Enseñando los registros añadidos hasta el momento:"<<endl;
    for (const auto& pers : dataFileReloaded){
        cout<<"Key: "<< pers.key <<" Dato Asociado: "<< pers.stand <<endl;
    }
}

//Ahora tratare de hacer un void para la correspondecia por calculo, si no lo logro, dejare este comentario.

int main(){
   
   //Variables variablemente variables 
    int optusr = 0;
    int case1;
    int fineline=0;
    const int TAM =10;
    vector <Persona> dataFile;
    vector <PersonaIndex> indexFile;
    Persona persona;
    vector <P3Reload> tabla(TAM, {"", ""});
    string key, stand;
    map<string, string> P4Royal;

    do{
    cout<<"\n----Spinning Satellite----"<<endl;
    cout<<"\nBienvenido, por favor, elija una actividad:"<<endl;
    cout<<"1. Agregar registros por Correspondencia Directa"<<endl;
    cout<<"2. Agregar registros por Correspondencia por Calculo"<<endl;
    cout<<"3. Agregar registros por Correspondencia por Asociacion"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>optusr;
    
        switch(optusr){
            case 1:
            
            do{
            cout<<"\nPERSONA: Correspondencia Directa"<<endl;
            cout<<"Ingrese un numero (key) para su dato:";
            cin>>persona.key;
            cout<<"\nIngrese el dato que quiere asociar:";
            cin>>persona.tenaciousd;
            //Este par de funciones hacen que el dato se ingrese al registro
            getline(cin, persona.tenaciousd);
            dataFile.push_back(persona);
            //Ahora este indexFile hace que se actualice el index por la key
             indexFile.push_back({persona.key, static_cast<int>(dataFile.size() - 1)});
             cout<<"Desea agregar otro registro? 1. Si 2. No"<<endl;
             cin>>case1;
             }while (case1 !=2);
             cout<<"A continuacion, mostraremos los registros, desea continuar? 1. Si 2. No"<<endl;
             cin>>fineline;
                if(fineline == 1){
                showoffStand(dataFile);
                }else
                cout<<"Regresando al menu principal"<<endl;
            break;
            
            case 2:
            cout << "\nPERSONA: Correspondencia por Calculo" << endl;
            cout << "Insertar registro (clave y datos). Escriba 'fin' para terminar:" << endl;
            // Bucle para leer entradas hasta que se escriba "fin".
            while (cin >> key && key != "fin") {
                cin >> stand;
                int pos = hashFunction(key, TAM); 
                tabla[pos] = {key, stand}; 
                cout << "Registro insertado en la posición " << pos << endl;
                cout << "Insertar registro (clave y datos) o 'fin' para terminar:" << endl;
            }
            
            cout << "\nRegistros almacenados:" << endl;
            for (int i = 0; i < TAM; i++) {
                if (!tabla[i].key.empty()) { 
                    cout << "Posición " << i << ": Clave " << tabla[i].key
                         << " - Datos: " << tabla[i].stand << endl; 
                }
            }
            break;

            
            case 3:
            cout<<"\nPERSONA: Correspondencia por asociacion"<<endl;
            cout << "Al terminar de ingresar sus datos, escriba 'fin'.\n";
            while (true) {
            cout << "\nIngrese la key: ";
            cin >> key;
            if (key == "fin") { 
            break;
            }
            cout << "Ingrese el dato a asociar: ";
            cin.ignore();             
            getline(cin, stand);      
            P4Royal[key] = stand; 
            cout << "Asociación guardada: [" << key << "] -> [" << stand << "]\n";
            }
            
            cout << "Registros almacenados:" << endl;
            for (const auto& entry : P4Royal) {
            cout << "Clave: " << entry.first << " - Valor: " << entry.second << endl;
            }
            break;
            
            case 4:
            cout<<"\nPERSONA: Finalizando programa. Hasta luego"<<endl;
            break;
            
            default:
            cout<<"\nOpcion invalida, por favor, elija otra opcion (del 1 al 4)."<<endl;
            break;
        }
    
    }while(optusr != 4);
    
    return 0;
}

   