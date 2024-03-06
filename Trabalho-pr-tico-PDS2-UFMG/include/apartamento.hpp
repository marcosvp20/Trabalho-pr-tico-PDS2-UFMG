#ifndef APARTAMENTO_HPP
#define APARTAMENTO_HPP

#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;

using std::list;
using std::string;
using std::map;

/**
 * @class Apartamento 
 * Classe que organiza as operações realizadas nos Apartamentos
*/
class Apartamento {
public:
    /**
     * @brief Construtor que permite definir limites máximos para diferentes tipos de
    pessoas, pets e veículos
     * @pre O número máximo de moradores não pode ser menor ou igual a 0, os restantes 
    não podem ser menores que 0.
    */
    Apartamento(int max_Moradores, int max_Visitantes,
                int max_Pets, int max_Veiculos);
    
    Apartamento();
    
    /**
     * @brief Insere uma pessoa
     * @pre Não há uma pessoa com o mesmo nome dentro de um mesmo apartamento
     * @pre O numero máximo do tipo da pessoa não foi atingido
     * @pre A data de nascimento é um número positivo.
     * @pre O tipo da pessoa é "morador" ou "visitante"
    */
    void inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa);

    /**
     * @brief Insere um pet
     * @pre Não há um pet com o mesmo nome dentro de um mesmo apartamento (associado ao número)
     * @pre O número máximo de pets não foi atingido
    */
    void inserir_pet(string nome, string raca, string tipo);

    /**
     * @brief Insere um veiculo
     * @pre Não há outro veículo com a mesma placa cadastrada em nenhum outro apartamento
     * @pre O número máximo de veículos não foi atingido
    */
    void inserir_veiculo(string modelo, string placa, string tipo_veiculo);

    /**
     * @brief Edita uma pessoa
     * @pre Essa pessoa deve existir de acordo com os dados passados
     * @pre O número máximo do novo tipo de pessoa não foi atingido
     * @pre A data de nascimento é um número inteiro
     * @pre O novo tipo da pessoa é "morador" ou "visitante"
    */
    void editar_pessoa(string nome_antigo,
                       string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo);

    /**
     * @brief Edita um pet
     * @pre Esse pet deve existir de acordo com os dados passados
    */
    void editar_pet(string nome_pet_antigo,
                    string nome_pet_novo, string raca_nova, string tipo_novo);

    /**
     * @brief Edita um veiculo
     * @pre Esse veículo deve existir de acordo com os dados passados
    */
    void editar_veiculo(string placa_antiga,
                        string placa_nova, string modelo_novo, string tipo_veiculo_novo);

    /**
     * @brief Exclui uma pessoa
     * @pre Essa pessoa deve existir de acordo com os dados passados
     * @pre A lista de pessoas não está vazia
    */
    void excluir_pessoa(string nome_pessoa);

    /**
     * @brief Exclui um pet
     * @pre Esse pet deve existir de acordo com os dados passados
     * @pre A lista de pets não está vazia
    */
    void excluir_pet(string nome_pet);

    /**
     * @brief Exclui um veiculo
     * @pre Esse veículo deve existir de acordo com os dados passados
     * @pre A lista de veículos não está vazia
    */
    void excluir_veiculo(string placa);

    /**
     * @brief Exibe, de um modo geral as informações de cada objeto
    */
    void exibir_estatisticas();

    /**
     * @brief Função que retorna a quantidade de algo específico dentro das classes desde o número de 
     * pessoas, visitantes, moradores, pets, tipos de pets...
     * @pre O objeto especificado deve existir de acordo com os dados passados
     * @return Quantidade de itens, a partir da chave passada do contador
    */    
    int quantidade(string objeto);

    /**
    * @brief Função que retorna true se a o nome passado corresponde ao de um morador do prédio e
    * false caso contrário
    */
    bool eh_morador(string nome);

    /**
    * @brief Função que retorna true se a o nome passado corresponde ao de um visitante do prédio e
    * false caso contrário
    */
    bool eh_visitante(string nome);

private:

    /**
     * Variáveis que serão utilizadas nas funções
    */ 

    struct Pessoa
    {
        string nome;
        string data_nascimento;
        string tipo_pessoa;
    };

    struct Pet
    {
        string nome;
        string raca;
        string tipo_pet;
    };

    struct Veiculo
    {
        string modelo;
        string placa;
        string tipo_veiculo;
    };

    int numero_apartamento;
    list <Pessoa> pessoas_;
    list <Pet> pets_;
    list <Veiculo> veiculos_;
    map <string , int> contador;
    
    friend class Evento;
    friend class Encomendas;

    /**
     * @brief Verifica se o numero máximo de cada tipo foi atingido
     * @return true caso não e false caso sim
    */
    bool verifica_quantidade_restante(string tipo);

    /**
     * @brief Verifica se a lista de pessoas, veiculos ou pets está vazia
     * @return True se sim e false caso contrário
     * @pre O tipo passado precisa existir
    */
    bool esta_vazio(string tipo);

    /**
     * @brief verifica se a pessoa já existe no apartamento
     * @return True se sim e false caso contrário 
    */
    bool ja_exite(string nome);

    // As variaveis abaixo sao limitadores de pessoas, pets e veiculos e serão utilizadas nos construtores

    int MAX_MORADORES = 0;
    int MAX_VISITANTES = 0;
    int MAX_PETS = 0;
    int MAX_VEICULOS = 0;


};

#endif