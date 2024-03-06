#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <list>
#include <string>
#include <vector>

#include "apartamento.hpp"

using namespace std;

/**
 * @class Evento
 * Classe que organiza as operações realizadas nos Eventos
*/


class Evento {
    public:

    /**
     * @brief Construtor do tipo evento
     * 
    */
    Evento();
    
    /**
     * @brief Cria um evento, informando o nome do responsavel, o nome do evento e sua data
     * @pre Um responsavel nao pode ter em seu nome dois eventos com o mesmo nome
     * @pre Visitantes nao podem criar eventos
    */
    void criar_evento (Apartamento& ap,string responsavel, string nome_evento, string data_evento);

    /**
     * @brief Adiciona um convidado ao evento 
     * @pre O nome do evento deve estar associado a um evento existente
     * @pre O nome do convidado deve estar associado a um morador ou visitante
    */
    void adicionar_convidado (map<int,Apartamento>& ap, string nome_evento, string convidado);

    /**
     * @brief Permite editar um evento
    */ 
    void editar_evento (Apartamento& ap, string responsavel, string nome_evento);

    /**
     * @brief Permite exluir um evento da lista de evento
    */
    void excluir_evento (string responsavel, string nome_evento);

    /**
     * @brief Exibe todas a informacoes do evento, como data e lista de convidados
    */
    void exibir_evento (string responsavel, string nome_evento);

    /**
     * @brief Exibe todos os eventos ja criados
    */
    void exibir_eventos ();

    private:

    /**
     * Variáveis que serão utilizadas nas funções
    */
   
    struct Agendamento {
        string responsavel;
        string nome_evento;
        string data_evento;
        vector <string> convidados;
    };

    list <Agendamento> eventos_;
    
};

#endif

