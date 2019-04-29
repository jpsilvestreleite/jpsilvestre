#ifndef AGENDA_H_
#define AGENDA_H_

#include <string>

struct node_t {
  std::string _dia;
  std::string _hora;
  std::string _compromisso;
  int _dia_aux;
  int _mes_aux;
  node_t *proximo;
};


struct Agenda {
  node_t *_inicio;
  node_t *_fim;

  int num_elementos=0;

  Agenda();
  ~Agenda();
  void insere_compromisso();
  void imprime_agenda();
  void verifica_compromisso();
  void write();
  void remove_compromisso();
};

  #endif
