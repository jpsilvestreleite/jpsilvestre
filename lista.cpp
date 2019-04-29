#include <iostream>
#include <string>
#include <sstream>

#include "lista.hpp"

Agenda::Agenda()
{
  _inicio=nullptr;
  _fim=nullptr;
}

 Agenda::~Agenda()
 {
   node_t *anterior= nullptr;
   node_t *proximo=_inicio;
    while (proximo!=nullptr)
    {
      anterior=proximo;
      proximo=proximo->proximo;
      delete anterior;
    }
 }

 void Agenda::insere_compromisso()
 {
   std::string aux,aux1,aux2,aux3,aux4,aux5,aux6;
   std::string dia,hora,compromisso,mes;
   std::cout<< "Inserir novo compromisso: "<<std::endl;
   std::cout<< "Entre com o dia/mês"<<std::endl;
   std::cin>>dia;
   std::cout<< "Entre com a hora"<<std::endl;
   std::cin>>hora;
   std::cin.ignore();
   std::cout<< "Entre com o compromisso"<<std::endl;
   getline(std::cin, compromisso);
   node_t *novo = new node_t();
   novo->_dia = dia;
   novo->_compromisso=compromisso;
   novo->_hora=hora;
   aux1=dia[0];
   aux2=dia[1];
   aux3=dia[3];
   aux4=dia[4];
   aux5=aux1+aux2;
   aux6=aux3+aux4;
   novo->_dia_aux=10*((int)aux5[0]-48)+(int)aux5[1]-48;
   novo->_mes_aux=10*((int)aux6[0]-48)+(int)aux6[1]-48;
   if(novo->_dia_aux > 31)
    novo->_dia_aux/=10;
    if(novo->_mes_aux >12)
    novo->_mes_aux/=10;

   if (_inicio == nullptr) {
     _inicio = novo;
     _fim = novo;
     novo->proximo = nullptr;
   } else {
     _fim->proximo = novo;
     _fim =novo;
     novo->proximo = nullptr;

   }
   num_elementos++;
 }

 void Agenda::imprime_agenda()
 {
   node_t *atual = _inicio;
   while (atual != nullptr) {
     std::cout << " Dia: "<< atual->_dia<<" Hora: "<<atual->_hora<<" Compromisso: "<<atual->_compromisso<<std::endl;
     std::cout<<std::endl;
     atual = atual->proximo;
   }
   std::cout << std::endl;
 }
  void Agenda::verifica_compromisso()
  {
    int cont=0;
    std::string _day,_hour;
    std::cout<<" Entre com o dia ''dd/mm'' "<<std::endl;
    std::cin>> _day;
    std::cout<<" Entre com a hora  ''XX:XX'' "<<std::endl;
    std::cin>> _hour;
    node_t *atual=_inicio;
    for(int i=0;i<num_elementos;i++)
    {
    if(_day==atual->_dia && _hour==atual->_hora)
    {
      std::cout<<" Compromisso: "<<atual->_compromisso<<std::endl;
      cont++;
    }
    atual=atual->proximo;
  }
      if(cont==0)
        std::cout<<" Nenhum compromisso encontrado. "<<std::endl;
}
  void Agenda::write()
  {
    FILE * pFile;
    pFile = fopen ("myfile.txt","w");
    node_t *atual = _inicio;
    while (atual != nullptr) {
      fprintf (pFile, "Dia: %s  Hora: %s Compromisso: %s \n ",atual->_dia.c_str(),atual->_hora.c_str(),atual->_compromisso.c_str());
      atual = atual->proximo;
   }
    fclose(pFile);
  }
void Agenda::remove_compromisso()
{
  std::string _day,_hour;
  std::cout<<" Entre com o dia ''dd/mm'' "<<std::endl;
  std::cin>> _day;
  std::cout<<" Entre com a hora  ''XX:XX'' "<<std::endl;
  std::cin>> _hour;
  node_t *ptr=_inicio;
  node_t *antes=_inicio;
  for(int i=0;i<num_elementos;i++)
  {
    if(ptr==nullptr)
    {
    break;
    }


         if(ptr->_dia==_day && ptr->_hora==_hour)
        {
          if(ptr==_inicio&&ptr->proximo==nullptr)
          {
            _inicio=nullptr;
              std::cout<<" Comprimsso a ser dlt: "<<antes->_compromisso<<std::endl;
            num_elementos--;
            break;
          }
          else  if(ptr==_inicio)
          {
          _inicio=_inicio->proximo;
            std::cout<<" Comprimsso a ser dlt: "<<antes->_compromisso<<std::endl;
            num_elementos--;
            break;
          }
          else {
            antes->proximo=ptr->proximo;
            std::cout<<" Comprimsso a ser dlt: "<<antes->_compromisso<<std::endl;
            delete ptr;
            num_elementos--;
            break;
          }
        }
          else
          {
            antes=ptr;
            ptr=ptr->proximo;
          }
   }

}
