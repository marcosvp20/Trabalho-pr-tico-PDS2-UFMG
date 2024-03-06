#include "encomendas.hpp"
#include "apartamento.hpp"

#include <list>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// Verifica se o id é válido 
bool verifica_id(string id){
    if (id.size() < 6 || id.size() > 50){ 
        return false;
    }
    return true;
} 

void Encomendas::registrar_encomenda(string id, string destinatario, string data_entrega){
    Encomenda encomenda;
    if (verifica_id(id)){
        for(auto it = encomendas_.begin(); it != encomendas_.end(); it++){
            if(it->first == id){
                cout << "\nO ID fornecido já existe" << endl;
                return;
            }
        }
        encomenda.data_entrega = data_entrega;
        encomenda.destinatario = destinatario;
        encomendas_[id] = encomenda;
        cout << "\nEncomenda registrada!\n" << endl;
        return;
    }
    cout << "Registro de encomenda falhou, ID inválido :(\n" << endl;
}

void Encomendas::apagar_encomenda(string id){
    if(encomendas_.size()>0){
        for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
            if (it->first == id){
                encomendas_.erase(it);
                cout << "\nRegistro de encomenda apagado" << endl;
                return;
            }
        }
        cout << "\nEncomenda não encontrada\n" << endl;
    } else {
        cout << "\nNão existem encomendas a serem apagadas\n" << endl;
    }
}

void Encomendas::exibir_encomendas(){
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
        cout << "\nId: " << it->first << endl;
        cout << "Destinatario: " << it->second.destinatario << endl;
        cout << "Data de entrega: \n" << it->second.data_entrega << endl << endl;
    }
}

void Encomendas::procurar_encomenda(string id){
    if (verificar_encomenda(id)){
        for(auto it = encomendas_.begin(); it != encomendas_.end(); it++){
            if(it->first == id){
                cout << "\nDados da encomenda:\n" << "Id: " << it->first << "\nDestinatário: " << it->second.destinatario 
                << "\nData de entrega: " << it->second.data_entrega << "\n" << endl;
                return;
            }
        }
    } else {
        cout << "Essa encomenda não existe" << endl;
    }
}

bool Encomendas::verificar_encomenda(string id){
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
        if (it->first == id){
            return true;
        }
    }
    return false;
}
