#include "evento.hpp"
#include "apartamento.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

Evento::Evento(){
}

void Evento::criar_evento(Apartamento& ap,string responsavel, string nome_evento, string data_evento){

    Agendamento novo_evento;
    bool PessoaEncontrada = false; 

    for(auto it = ap.pessoas_.begin(); it != ap.pessoas_.end(); it++){
        if(it->nome == responsavel){
            if(it->tipo_pessoa == "moradora"){
                novo_evento.responsavel = responsavel;
                novo_evento.nome_evento = nome_evento; 
                novo_evento.data_evento = data_evento;
                eventos_.push_back(novo_evento);
                cout << "\nEvento criado com sucesso\n" << endl;
            }
            else{
                cout << "\nO responsável precisa ser morador\n" << endl;
                return;
            }
            PessoaEncontrada = true;
        }
    }
    if(!PessoaEncontrada){
        cout << "\nPessoa não encontrada\n" << endl;
    }
    
    
};

void Evento::adicionar_convidado(map<int,Apartamento>& ap, string evento, string convidado){
    bool pessoa_encontrada = false;

    for(auto it = ap.begin(); it != ap.end(); it++){ 
        for(auto it2 = it->second.pessoas_.begin(); it2 != it->second.pessoas_.end(); it2++){
            if(it2 -> nome == convidado){
                pessoa_encontrada = true;
                for(auto it3 = eventos_.begin(); it3 != eventos_.end(); it3++){
                    if(it3->nome_evento == evento){
                     it3 ->convidados.push_back(convidado);
                     cout << "\nPessoa adicionada com sucesso\n" << endl;
                     return;   
                    }
                }
            }
        }
    }
    if(!pessoa_encontrada){
        cout << "\nPesssoa não encontrada\n" << endl;
    }
}

void Evento::editar_evento(Apartamento& ap, string responsavel, string nome_evento){
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        if ((*it).responsavel == responsavel && (*it).nome_evento == nome_evento){
            string responsavel_aux, nome_evento_aux;
            cout << "Informe o novo responsável: ";
            cin >> responsavel_aux;
            cout << "Informe o novo nome do evento: ";
            cin >> nome_evento_aux;
            if (ap.eh_morador(responsavel_aux)){
                (*it).responsavel = responsavel_aux;
                (*it).nome_evento = nome_evento_aux;
                cout << "Evento alterado\n" << endl;
                return;
            } else {
                cout << "O novo responsável não existe\n";
                return;
            }
        }
    }
    cout << "Evento não encontrado\n" << endl;
}

void Evento::excluir_evento(string responsavel, string nome_evento) {
    eventos_.remove_if([responsavel, nome_evento](const Agendamento& evento) {
        cout << "Evento excluído\n" << endl;
        return evento.responsavel == responsavel && evento.nome_evento == nome_evento;
    });
}

void Evento::exibir_evento(string responsavel, string nome_evento) {
    if (eventos_.size() > 0){    
        for (const auto& evento : eventos_) {
            if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
                cout << "\nResponsável: " << evento.responsavel << endl;
                cout << "Nome do evento: " << evento.nome_evento << endl;
                cout << "Data do evento: " << evento.data_evento << endl;
                cout << "Convidados: " << endl;
                for (const string& convidado : evento.convidados) {
                    cout << "  " << convidado << endl;
                }
                cout << endl; 
            }
        }
        return;
    } else {
        cout << "O evento não foi encontrado\n" << endl;
    }
}

void Evento::exibir_eventos(){
    if (eventos_.size() > 0){
        for (auto it = eventos_.begin(); it != eventos_.end(); it++){
            cout << "Responsável: " << (*it).responsavel << endl;
            cout << "Nome do evento: " << (*it).nome_evento << endl;
            cout << "Data do evento: " << (*it).data_evento << endl;
            cout << "Convidados:" << endl;
            for (auto it2 = (*it).convidados.begin(); it2 != (*it).convidados.end(); it2++){
                cout << (*it2) << " " << endl;
            }
            cout << "\n" << endl;
        }
    } else {
        cout << "Não há eventos a serem exibidos\n" << endl;
    }
}
