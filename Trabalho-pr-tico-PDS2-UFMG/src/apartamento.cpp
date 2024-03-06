#include "apartamento.hpp"

#include <list>
#include <string>
#include <iostream>

using namespace std;

bool Apartamento::verifica_quantidade_restante(string tipo) 
{

    if (tipo == "moradora")
    {
        if (MAX_MORADORES > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "visitante")
    {
        if(MAX_VISITANTES > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "pet")
    {
        if(MAX_PETS > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "veiculo")
    {
        if(MAX_VEICULOS > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Apartamento::esta_vazio(string tipo)
{
    if(tipo == "pessoa")
    {
        if(pessoas_.size() == 0)
        {
            return true;
        }
        else
        return false;
    }
    else if(tipo == "pet")
    {
        if(pets_.size() == 0)
        {
            return true;
        }
        return false;
    }
    else if(tipo == "veiculo")
    {
        if(veiculos_.size() == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

/** 
    @brief verfica se a string contém apenas numero ou "/"
    @pre O parâmetro passado precisar ser uma string
**/
bool eh_numero(string& str) {
    int contador = 0;
    for (char c : str) {
        if (!isdigit(c) && c == '-') {
            contador ++;
        }
        if(contador > 0 && isdigit(c)){
            return false; // se for numero negativo, retorna false
        }
    }
    return true; // Se todos os caracteres são dígitos, retorna verdadeiro
}

bool Apartamento::ja_exite(string nome){
    for(auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if(it->nome == nome){
            return true;
        }
    }
    return false;
}

/**
    @brief verfica se a string está de acordo com o formato da data. dd/mm/aaaa, ddmmaaaa, ddmmaa ou dd/mm/aa
    @pre O parâmetro é uma string
**/
bool verifica_data_nascimento(string data_nascimento){
    if(eh_numero(data_nascimento)){
        return  true;
    }
    else{
        cout << "\nData de nascimento inválida\n" << endl;
        return false;
    }
}

Apartamento::Apartamento(int _Moradores, int _Visitantes, int _Pets, int _Veiculos)
    : MAX_MORADORES(_Moradores), MAX_VISITANTES(_Visitantes), MAX_PETS(_Pets), MAX_VEICULOS(_Veiculos){   
    }

Apartamento::Apartamento(){}

void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{   
    if(!ja_exite(nome)){
        Pessoa pessoa;
        pessoa.nome = nome;
        pessoa.data_nascimento = data_nascimento;
        if(!verifica_data_nascimento(data_nascimento)){
            return;
        }
        if (tipo_pessoa == "moradora")
        {
            if(verifica_quantidade_restante(tipo_pessoa)){
                pessoa.tipo_pessoa = "moradora";
                pessoas_.push_back(pessoa);
                MAX_MORADORES--;
                contador["Moradores"]++;
                cout << "\nMorador inserido com sucesso\n" << endl;
            } else {
                cout << "\nMorador não inserido, número máximo atingido\n" << endl;
            }
            return;
        }
        if (tipo_pessoa == "visitante")
        {
            if(verifica_quantidade_restante(tipo_pessoa) && eh_numero(data_nascimento)){
                pessoa.tipo_pessoa = "visitante";
                pessoas_.push_back(pessoa);
                MAX_VISITANTES--;
                contador["Visitantes"]++;
                cout << "\nVisitante inserido com sucesso\n" << endl;
            } else {
                if(!eh_numero(data_nascimento)){
                    cout << "\nFormato da data de nascimento inválido\n" << endl;
                }
                else{
                cout << "\nMorador não inserido, número máximo atingido\n" << endl;
                }
            }
            return;
        }
    } else {
        cout << "\nPessoa já existe!\n" << endl;
        return;
    }
}

void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;
    pet.nome = nome;
    pet.raca = raca;

    if(verifica_quantidade_restante("pet")){
        if (tipo == "cachorro")
        {
            pet.tipo_pet = "cachorro";
            cout << "\nPet inserido com sucesso\n" << endl;
        }
        else if (tipo == "gato")
        {
            pet.tipo_pet = "gato";
            cout << "\nPet inserido com sucesso\n" << endl;
        }
        else if (tipo == "passaro")
        {
            pet.tipo_pet = "passaro";
            cout << "\nPet inserido com sucesso\n" << endl;
        }
        else if (tipo == "outro")
        {
            pet.tipo_pet = "outro";
            cout << "\nPet inserido com sucesso\n" << endl;
        } else {
            cout << "Inserção Falhou\n";
        }

        pets_.push_back(pet);
        MAX_PETS--;
        contador["Pets"]++;
        return;
    } else {
        cout << "\nPet não inserido, número máximo atingido\n" << endl;
    }
}

void Apartamento::inserir_veiculo(string modelo, string placa, string tipo_veiculo)
{
    Veiculo veiculo;

    veiculo.modelo = modelo;
    veiculo.placa = placa;
    veiculo.tipo_veiculo = tipo_veiculo;

    if(verifica_quantidade_restante("veiculo")){
        veiculos_.push_back(veiculo);
        MAX_VEICULOS--;
        contador["Veiculos"]++;
        cout << "\nVeículo inserido com sucesso\n" << endl;
    } else {
        cout << "\nVeículo não inserido, número máximo atingido\n" << endl;
    }
}

void Apartamento::editar_pessoa(string nome_antigo,
                                string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome_antigo){
            if(it->tipo_pessoa == tipo_pessoa_novo || verifica_quantidade_restante(tipo_pessoa_novo)){ // se o tipo de pessoa nova for igual ao antigo, edita direto, se não verifica se ainda não atingiu o numero máximo do tipo novo

             if(!verifica_data_nascimento(data_nascimento_nova)){
                return;
            }

            it->nome = nome_novo;
            it->data_nascimento = data_nascimento_nova;

            if (tipo_pessoa_novo == "moradora"){
                if(it->tipo_pessoa == "visitante"){
                    it->tipo_pessoa = "moradora";
                    contador["Visitantes"]--;
                    contador["Moradores"]++;
                    cout << "\nEdição concluída com sucesso\n" << endl;
                    return;
                } else if (it->tipo_pessoa == "moradora") {
                    cout << "\nEdição concluída com sucesso\n" << endl;
                    return;
                }
            } else if (tipo_pessoa_novo == "visitante"){
                if(it->tipo_pessoa == "moradora"){
                    it->tipo_pessoa = "visitante";
                    contador["Moradores"]--;
                    contador["Visitantes"]++;
                    cout << "\nEdição concluída com sucesso\n" << endl;
                    return;
                } else if (it->tipo_pessoa == "visitante"){
                    cout << "\nEdição concluída com sucesso\n" << endl;
                    return;
                }
            }
            break;
            } else {
                cout << "\nEdição Falhou\n" << endl;
                return;
            }
        }
    }
    cout << "\nEdição Falhou, pessoa nao existe\n" << endl;
}

void Apartamento::editar_pet(string nome_pet_antigo,
                             string nome_pet_novo, string raca_nova, string tipo_novo){

    for (auto it = pets_.begin(); it != pets_.end(); it++){
        if (it->nome == nome_pet_antigo){
            it->nome = nome_pet_novo;
            it->raca = raca_nova;

            // Essa parte define o novo tipo de pet
            if (tipo_novo == "cachorro"){
                it->tipo_pet = "cachorro";
                cout << "\nEdição concluída com sucesso\n" << endl;
                return;
            } else if (tipo_novo == "gato"){
                it->tipo_pet = "gato";
                cout << "\nEdição concluída com sucesso\n" << endl;
                return;
            } else if (tipo_novo == "passaro"){
                it->tipo_pet = "passaro";
                cout << "\nEdição concluída com sucesso\n" << endl;
                return;
            } else if (tipo_novo == "outro"){
                it->tipo_pet = "outro";
                cout << "\nEdição concluída com sucesso\n" << endl;
                return;
            }
            break;
        }
    }
    cout << "\nEdição Falhou\n" << endl;
}

void Apartamento::editar_veiculo(string placa_antiga,
                                 string placa_nova, string modelo_novo, string tipo_veiculo_novo){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
        if (it->placa == placa_antiga){
            it->modelo = modelo_novo;
            it->placa = placa_nova;
            it->tipo_veiculo = tipo_veiculo_novo;
            cout << "\nEdição concluída com sucesso\n" << endl;
            return;
        }
    }
    cout << "\nEdição Falhou\n" << endl;
}

void Apartamento::excluir_pessoa(string nome_pessoa){
    if(!esta_vazio("pessoa")){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome_pessoa){
            if (it->tipo_pessoa == "moradora"){
                pessoas_.erase(it);
                contador["Moradores"]--;
                MAX_MORADORES++;
                cout << "\nPessoa excluida com sucesso\n" << endl;
                return;
                break;
            }
            else if (it->tipo_pessoa == "visitante"){
                pessoas_.erase(it);
                contador["Visitantes"]--;
                MAX_VISITANTES++;
                cout << "\nPessoa excluida com sucesso\n" << endl;
                return;
                break;
            }
        }
    }
}
else{
    cout << "\nNão há pessoas a serem excluídas\n" << endl;
    return;
}
    cout << "\nPessoa não encontrada\n" << endl;
}

void Apartamento::excluir_pet(string nome_pet){
    if(!esta_vazio("pet")){
    for (auto it = pets_.begin(); it != pets_.end(); it++){
            if (it->nome == nome_pet){
                pets_.erase(it);
                MAX_PETS++;
                contador["Pets"]--;
                cout << "\nPet excluido com sucesso\n" << endl;
                return;
            }
        break;
    }
    }
    else{
        cout << "\nNão há pet para ser excluído\n" << endl;
        return;
    }
    cout << "\nExclusão Falhou\n" << endl;
}

void Apartamento::excluir_veiculo(string placa){
    if(!esta_vazio("veiculo")){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
            if (it->placa == placa){
                veiculos_.erase(it);
                contador["Veiculos"]--;
                MAX_VEICULOS++;
                cout << "\nVeículo excluida com sucesso\n" << endl;
                return;
            }
        break;
    }
    }
    else{
        cout << "\nNão há veículo para ser excluído\n" << endl;
        return;
    }
    cout << "\nExclusão Falhou\n" << endl;
}

void Apartamento::exibir_estatisticas(){
    cout << endl;
    cout << "\nQuantidades de moradores: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << "\n" << endl;
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        cout <<"\tNome: "<< it->nome << endl <<"\tData de Nascimento: "<< it->data_nascimento << endl <<"\tTipo: "<< it->tipo_pessoa << "\n" << endl;
    }
    cout << "\nQuantidade de pets: " << contador["Pets"] << "\n" << endl;
    for (auto it = pets_.begin(); it != pets_.end(); it++){
        cout <<"\tNome: "<< it->nome << endl <<"\tRaca: "<< it->raca << endl <<"\tTipo Pet: "<< it->tipo_pet << "\n" << endl;
    }
    cout << "\nQuantidade de veículos: " << contador["Veiculos"] << "\n" << endl;
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
        cout <<"\tModelo: "<< it->modelo << endl <<"\tPlaca: "<< it->placa << endl <<"\tTipo Veiculo: "<< it->tipo_veiculo << "\n" << endl;
    }
}

int Apartamento::quantidade(string chave){
    return contador[chave];
}

bool Apartamento::eh_morador(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome && it->tipo_pessoa == "moradora"){
            return true;
        }
    }
    return false;
}

bool Apartamento::eh_visitante(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome && it->tipo_pessoa == "visitante"){
            return true;
        }
    }
    return false;
}