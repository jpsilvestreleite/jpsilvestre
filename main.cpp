#include <iostream>
#include <string>

#include "lista.hpp"
int main()
{
  int sw=0;

  Agenda lista;
  std::cout<<" ********************************************"<<std::endl<<"                   AGENDA "<<std::endl;
  std::cout<< "          MENU :"<<std::endl;
  while(sw<=5)
  {
    std::cout<<std::endl;
  std::cout<<" 1- Inserir novo compromisso."<<std::endl;
  std::cout<<" 2- Remover compromisso."<<std::endl;
  std::cout<<" 3- Imprimir compromissos."<<std::endl;
  std::cout<<" 4- Verifica se existe compromisso."<<std::endl;
  std::cout<<" 5- Fecha Agenda."<<std::endl;
  std::cout<<std::endl;
  std::cin>>sw;

  switch (sw) {
    case 1:
      lista.insere_compromisso();
      break;
    case 2:
    lista.remove_compromisso();
    break;
    case 3:
    lista.imprime_agenda();
    break;
    case 4:
    lista.verifica_compromisso();
    break;
    case 5:
    lista.write();
    sw++;
    std::cout<<" As alterações foram realizadas."<<std::endl;
    break;
    default:
    std::cout<<" Opção inválida."<<std::endl;
    break;

  }
}




  return 0;
}
