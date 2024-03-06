#include "apartamento.hpp"
#include "evento.hpp"
#include "encomendas.hpp"

#include <iostream>
#include <string>

using namespace std;

bool ehNumero(std::string& str) {
    int contador = 0;
    for (char c : str) {
        if('-' == c){
            contador++;
        }
        if (!isdigit(c)) {
            if(contador != 1){
            return false; // Se qualquer caractere não for um dígito, retorna falso
            }
            else{
            contador = 0;
            }
        }
    }
    return true; // Se todos os caracteres são dígitos, retorna verdadeiro
}

int main() {

// CONSTRUTORES E INICIALIZACAO =======================================================================================================================

    int max_Moradores, max_Visitantes, max_Pets, max_Veiculos;
    do{
    cout << "Informe o número máximo de moradores: ";
    cin >> max_Moradores;

    cout << "Informe o número máximo de visitantes: ";
    cin >> max_Visitantes;

    cout << "Informe o número máximo de pets: ";
    cin >> max_Pets;

    cout << "Informe o número máximo de veículos: ";
    cin >> max_Veiculos;

    if(max_Moradores == 0){
        cout << "\nO número máximo de moradores precisar ser maior que zero\n" << endl;
    }
    else if(max_Visitantes < 0 || max_Pets < 0 || max_Veiculos < 0 || max_Moradores < 0){
        cout << "\nO número máximo não pode ser negativo\n" << endl;
    }
    } while(!(max_Moradores > 0 && max_Visitantes >= 0 && max_Pets >= 0 && max_Veiculos >= 0));
    
    

    // Map que armazena os apartamentos com o número de cada
    map<int, Apartamento> aps; 

    // Variaveis que serao utilizadas para o armazenamento das informacoes dos eventos e encomendas
    Evento eventoManager;
    Encomendas encomendasManager;

    // Variavel que guarda o numero do apartamento
    int num_ap = 0;

// PAINEL INICIAL ====================================================================================================================

    while (true){
        cout << "Escolha uma opção:\n";
        cout << "1. Modificar Apartamentos\n";
        cout << "2. Modificar Eventos\n";
        cout << "3. Modificar Encomendas\n";
        cout << "4. Encerrar programa\n";
        int opcao;
        cin >> opcao;


        // Gerenciamento dos Apartamentos
        if (opcao == 1){

            // Estado que verifica se o numero do apartamento eh valido
            string num_ap_s;
            bool verifica_ap_valido = 1;
            while (verifica_ap_valido){
                Apartamento apartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
                cout << "Informe o número do apartamento: \n";
                cin >> num_ap_s; // lê o numero do apartamento como string para evitar o loop infinito
                verifica_ap_valido = 0;

                if (!ehNumero(num_ap_s)){
                    cout << "\nO número do apartamento precisa ser um número\n" << endl;
                    verifica_ap_valido = 1;
                }

                if(ehNumero(num_ap_s)){
                    num_ap = stoi(num_ap_s);
                    if(num_ap <= 0){
                        cout << "\nDigite um numero de apartamento válido\n" << endl;
                        verifica_ap_valido = 1;
                        }
                    else{
                    verifica_ap_valido = 0;
                    }
                }

                if(!verifica_ap_valido){    

                    // Se for valido, eh verificado se o apartamento ja foi criado
                    if (aps.find(num_ap)==aps.end()){
                        Apartamento novoApartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
                        aps[num_ap] = novoApartamento;
                    }
                }
            }    
        
            // MENU DE OPÇÕES APARTAMENTOS ====================================================================================================
            while (true){
                cout << "Escolha uma execução\n";
                cout << "1. Inserir\n";
                cout << "2. Editar\n";
                cout << "3. Excluir\n";
                cout << "4. Exibir Estatísiticas\n";
                cout << "5. Voltar\n";

                // Variavel que guarda a escolha
                int execucao;
                cin >> execucao;

                // Inserir =========================================================================================================
                if (execucao == 1){
                while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Inserir Pessoa\n";
                    cout << "2. Inserir Pet\n";
                    cout << "3. Inserir Veículo\n";
                    cout << "4. Voltar\n";

                    // Variavel que guarda a escolha
                    int escolha;
                    cin >> escolha;

                    // Inserir pessoa
                    if (escolha == 1) {
                        string nome, data_nascimento, tipo_pessoa;
                        cout << "Nome: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Data de Nascimento: ";
                        cin >> data_nascimento;
                        while (tipo_pessoa != "moradora" && tipo_pessoa != "visitante"){
                            cout << "Tipo de Pessoa (moradora ou visitante): ";
                            cin.ignore();
                            cin >> tipo_pessoa;
                            if(tipo_pessoa != "moradora" && tipo_pessoa != "visitante"){
                                cout << "\nTipo de pessoa inválido\n" << endl;
                            }
                        }
                        aps[num_ap].inserir_pessoa(nome, data_nascimento, tipo_pessoa);

                    // Inserir pet
                    } else if (escolha == 2) {
                        string nome, raca, tipo;
                        cout << "Nome do Pet: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Raça do Pet: ";
                        cin >> raca;
                        while (tipo != "cachorro" && tipo != "gato" && tipo != "passaro" && tipo != "outro"){
                            cout << "Tipo do Pet (cachorro, gato, passaro ou outro): ";
                            cin.ignore();
                            cin >> tipo;
                        }
                        aps[num_ap].inserir_pet(nome, raca, tipo);

                    // Inserir veículo
                    } else if (escolha == 3) {
                        string modelo, placa, tipo_veiculo;
                        cout << "Modelo do Veículo: ";
                        cin.ignore(); 
                        getline(cin, modelo);
                        cout << "Placa do Veículo: ";
                        cin >> placa;
                        cout << "Tipo de Veículo: ";
                        cin.ignore(); 
                        getline(cin, tipo_veiculo);
                        aps[num_ap].inserir_veiculo(modelo, placa, tipo_veiculo);
                    
                    // Encerram essa parte do programa
                    } else if (escolha == 4) {
                        break; 
                    } else {
                        break;
                    }
                }
                }

                // Editar ====================================================================================================================================
                if (execucao == 2){
                while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Editar Pessoa\n";
                    cout << "2. Editar Pet\n";
                    cout << "3. Editar Veículo\n";
                    cout << "4. Voltar\n";

                    // Variavel que guarda a escolha
                    int escolha;
                    cin >> escolha;

                    // Editar Pessoa
                    if (escolha == 1){ 
                        string nome_antigo, nome_novo, data_nascimento_nova, tipo_pessoa_novo;

                        cout << "Informe o nome da pessoa a ser alterada: ";
                        cin.ignore();
                        getline(cin, nome_antigo);

                        cout << "Informe os dados novos da pessoa\n";
                        cout << "Nome: ";
                        getline(cin, nome_novo);
                        cout << "Data de Nascimento: ";
                        cin >> data_nascimento_nova;
                        while (tipo_pessoa_novo != "moradora" && tipo_pessoa_novo != "visitante"){
                            cout << "Tipo (moradora ou visitante): ";
                            cin.ignore();
                            cin >> tipo_pessoa_novo;
                        }
                        aps[num_ap].editar_pessoa (nome_antigo, nome_novo, data_nascimento_nova, tipo_pessoa_novo);
                    
                    // Editar Pet
                    } else if (escolha == 2){
                        string nome_pet_antigo, nome_pet_novo, raca_nova, tipo_novo;

                        cout << "Informe o nome antigo do pet: ";
                        cin.ignore(); 
                        getline(cin, nome_pet_antigo);

                        cout << "Informe os dados novos do pet\n";
                        cout << "Nome: ";
                        getline(cin, nome_pet_novo);
                        cout << "Raca: ";
                        cin >> raca_nova;
                        cout << "Tipo: ";
                        cin >> tipo_novo;
                        aps[num_ap].editar_pet(nome_pet_antigo, nome_pet_novo, raca_nova, tipo_novo);
                    
                    // Editar Veiculo
                    } else if (escolha == 3){
                        string placa_antiga, placa_nova, modelo_novo, tipo_veiculo_novo;

                        cout << "Informe a placa antiga do veiculo\n";
                        cout << "Placa: ";
                        cin >> placa_antiga;

                        cout << "Informe os dados novos do veiculo\n";
                        cout << "Placa: ";
                        cin >> placa_nova;
                        cout << "Modelo: ";
                        cin >> modelo_novo;
                        cout << "Tipo: ";
                        cin >> tipo_veiculo_novo;
                        aps[num_ap].editar_veiculo(placa_antiga, placa_nova, modelo_novo, tipo_veiculo_novo);

                    // Voltar
                    } else if (escolha == 4){
                        break;
                    }
                }
                }

                // Excluir ============================================================================================================
                if (execucao == 3){
                while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Excluir Pessoa\n";
                    cout << "2. Excluir Pet\n";
                    cout << "3. Excluir Veículo\n";
                    cout << "4. Voltar\n";
                    int escolha;
                    cin >> escolha;

                    // Excluir Pessoa
                    if (escolha == 1){
                        string pessoa_excluida;
                        cout << "Informe o nome da pessoa a ser excluida: \n";
                        cout << "Nome: ";
                        cin.ignore();
                        getline(cin, pessoa_excluida);
                        aps [num_ap].excluir_pessoa(pessoa_excluida);
                    }

                    // Excluir Pet
                    if (escolha == 2){
                        string pet_excluido;
                        cout << "Informe o nome do pet a ser excluido:\n";
                        cin.ignore(); 
                        getline(cin, pet_excluido);
                        aps [num_ap].excluir_pet(pet_excluido);
                    }

                    // Excluir Veiculo
                    if (escolha == 3){
                        string veiculo_excluido;
                        cout << "Informe a placa do veiculo a ser excluido: \n";
                        cin >> veiculo_excluido;
                        aps [num_ap].excluir_veiculo(veiculo_excluido);
                    }

                    // Voltar
                    if (escolha == 4){
                        break;
                    }
                }
                }

                // Exibir Estatisticas ================================================================================================
                if (execucao == 4){
                    aps[num_ap].exibir_estatisticas();
                }

                // Voltar =============================================================================================================
                if (execucao == 5){
                    break;
                }
            }

        }

    // MENU DE OPÇÕES DOS EVENTOS ====================================================================================================
        if (opcao == 2){
        int choice;
        bool verifica_ap = 1;
        while (verifica_ap){
            cout << "Informe o número do apartamento para o Evento\n";
            cin >> num_ap;
            verifica_ap = 0;
            if (aps.find(num_ap) == aps.end()){
                verifica_ap = 1;
                cout << "Digite o número de um apartamento que ja existe\n";
            }
        }
            while (true) {
                cout << "Escolha uma ação:\n";
                cout << "1. Criar Evento\n";
                cout << "2. Adicionar Convidado\n";
                cout << "3. Exibir Eventos\n";
                cout << "4. Editar evento\n";
                cout << "5. Excluir Evento\n";
                cout << "6. Voltar\n";

                cin >> choice;

                // Criar Evento
                if (choice == 1) {
                    string responsavel, nome_evento, data_evento;
                    cout << "Responsável: ";
                    cin.ignore(); 
                    getline(cin, responsavel);
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);
                    cout << "Data do Evento: ";
                    cin >> data_evento;
                    eventoManager.criar_evento(aps[num_ap],responsavel, nome_evento, data_evento);
                
                // Adicionar Convidado
                } else if (choice == 2) {
                    string convidado, nome_evento;
                    cout << "Nome do Evento: ";
                    cin.ignore(); 
                    getline(cin, nome_evento);
                    cout << "Nome do Convidado: "; 
                    getline(cin, convidado);
                    eventoManager.adicionar_convidado(aps,nome_evento, convidado);
                
                // Exibir Eventos
                } else if (choice == 3) {
                    eventoManager.exibir_eventos();
                
                // Editar Evento
                } else if (choice == 4){
                    string responsavel, nome_evento;
                    cout << "Responsável do Evento: ";
                    cin.ignore(); 
                    getline(cin, responsavel);
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);
                    eventoManager.editar_evento(aps[num_ap],responsavel, nome_evento);

                // Excluir Evento
                } else if (choice == 5) {
                    string responsavel, nome_evento;
                    cout << "Responsável do Evento: ";
                    cin.ignore(); 
                    getline(cin, responsavel);
                    cout << "Nome do Evento: ";
                    getline(cin, nome_evento);
                    eventoManager.excluir_evento(responsavel, nome_evento);
                
                } else if (choice == 6) {
                    break; // Encerra o programa
                }
            }
        }

    // MENU OPÇÕES ENCOMENDAS ========================================================================================================= 
        if (opcao == 3){

        while (true) {
            cout << "Escolha uma ação:\n";
            cout << "1. Registrar Encomenda\n";
            cout << "2. Apagar Encomenda\n";
            cout << "3. Exibir Encomendas\n";
            cout << "4. Procurar Encomenda\n";
            cout << "5. Voltar\n";
            int choice;
            cin >> choice;

            // Registrar Encomenda
            if (choice == 1) {
                string id, destinatario, data_entrega;
                int num_ap;
                cout << "Número do apartamento do destinatário: ";
                cin >> num_ap;
                cout << "Destinatário: ";
                cin.ignore();
                getline(cin, destinatario);

                if(aps[num_ap].eh_morador(destinatario)){
                    cout << "ID da Encomenda: ";
                    cin >> id;
                    cout << "Data de Entrega: ";
                    cin >> data_entrega;
                    encomendasManager.registrar_encomenda(id, destinatario, data_entrega);
                } else {
                    cout << "Erro: O destinatário não é morador deste apartamento\n";
                }
            
            // Apagar Encomenda    
            } else if (choice == 2) {
                string id;
                cout << "ID da Encomenda a ser apagada: ";
                cin >> id;
                encomendasManager.apagar_encomenda(id); 
            
            // Exibir Encomendas
            } else if (choice == 3) {
                cout << "Encomendas Registradas:\n";
                encomendasManager.exibir_encomendas();
            
            // Procurar Encomenda    
            } else if (choice == 4) {
                string id;
                cout << "ID da Encomenda a ser procurada: ";
                cin >> id;
                encomendasManager.procurar_encomenda(id);
                
            } else if (choice == 5) {
                break; // encerra programa
            }   
        }
        }

    // FIM DO PROGRAMA ================================================================================================================
        if (opcao == 4){
            cout <<"Até mais!\n";
            break;
        }
    }
    return 0;
}
