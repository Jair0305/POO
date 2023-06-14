#include<iostream>
#include<stdlib.h>
using namespace std;

class Persona{
 private:
 int edad;
 string nombre;
 public:
 Persona(int,string);
 void MuestraD();
};
class Empleado : public Persona {
 private:
 float salario;
 string oficio;
 public:
 Empleado(int,string,float,string);
 void MdatosE();

};

class Estudiante : public Persona{
 private:
 string carreraU;
 int semestre;
 public:
 Estudiante(int,string,string,int);
 void MDatosE();
};
class Universitario : Estudiante{
 private:
 string universidad;
 public:
 Universitario(int,string,string,int,string);
 void MDDU();
};
Universitario::Universitario(int _edad ,string _nombre, string _carreraU ,int _semestre , string _universidad) : Estudiante(_edad,_nombre,_carreraU,_semestre){
 universidad= _universidad;
}
void Universitario::MDDU(){
 MDatosE();
 cout<<"Universidad: "<<universidad<<endl;
}

Estudiante::Estudiante(int _edad ,string _nombre ,string _carreraU ,int _semestre) : Persona(_edad,_nombre){
 carreraU=_carreraU;
 semestre=_semestre;
}
void Estudiante::MDatosE(){
 MuestraD();
 cout<<"Carrera Universitaria: "<<carreraU<<endl<< "Numero de semestre: "<<semestre<<endl;
}

Empleado::Empleado(int _edad ,string _nombre ,float _salario ,string _oficio) : Persona(_edad,_nombre){
 salario=_salario;
 oficio=_oficio;
}
void Empleado::MdatosE(){
 MuestraD();
 cout<<"Salario: "<<salario<<endl<<"Oficio: "<<oficio<<endl;
}


Persona::Persona(int _edad ,string _nombre){
 edad=_edad;
 nombre =_nombre;
}
void Persona::MuestraD(){
 cout<<"Nombre: "<<nombre<<endl<<"Edad: "<<edad<<endl;
}


int main(){
 Empleado e1=Empleado(19,"Jair",5000,"Ing.sistemas");
 Universitario u1=Universitario(20,"Jair","Ing.sistemas",3,"DICIS");
 cout<<"\nDatos universitario"<<endl;
 cout<<"\n";
 u1.MDDU();
 cout<<"\n";
 cout<<"\nDatos Empleado"<<endl;
 cout<<"\n";
 e1.MdatosE();

 system("pause");
 return 0;
}
