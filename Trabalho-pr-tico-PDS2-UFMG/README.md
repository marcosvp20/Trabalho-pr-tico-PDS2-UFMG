# Administração de Dados, Eventos e Encomendas Simplificada para o Condomínio

*Introdução:*

Na administração de condomínios, o controle de dados e informações é um desafio constante para os gestores. Muitas vezes, garantir um processo eficiente de controle de informações é uma tarefa difícil. É nesse contexto que buscamos simplificar e facilitar a gestão de dados com segurança e praticidade. 

Imagine um sistema projetado para desembaraçar a complexidade da administração condominial, permitindo que os administradores adicionem, editem e removam informações sobre moradores, seus animais de estimação, visitantes e veículos. Além disso, oferece a capacidade de organizar eventos e rastrear encomendas destinadas aos moradores. Com essa solução, as operações do condomínio fluem de maneira mais suave, tornando o manuseio de dados mais eficiente e descomplicado. 

Este sistema representa a união perfeita entre tecnologia e gestão condominial, atendendo à necessidade de tornar a administração mais prática e eficaz. É um novo começo, onde a inovação é a força que simplifica o complexo universo da administração condominial, tornando-o mais acessível e seguro para todos.


*User Story:*

Administração de Dados, Eventos e Encomendas Simplificada para o Condomínio
Como administrador do condomínio desejo ter um sistema eficiente de organização de informações sobre os moradores, os eventos e as encomendas do condomínio
Critérios de Aceitação:
- Posso inserir, editar, exibir e remover dados de pessoas, de animais de estimação e de veículos atrelados a um apartamento;
- Posso criar, mostar, editar ou apagar eventos de em uma data específica solicitados pelos moradores, podendo convidar outras pessoas;
- Posso ter o controle das encomendas recebidas, podendo registrá-las, escrever o remetente da entrega e exebir um relatório dos últimos cadastros feitos.


*_Cartões CRC:_*

== Classe: Apartamento ==


Responsabilidades:
- Inserir pessoas no apartamento;
- Inserir carros no apartamento;
- Inserir animais no apartamento;
- Adicionar visitantes ao apartamento;
- Editar pessoas no apartamento;
- Editar carros no apartamento ;
- Editar animais no apartamento;
- Apagar pessoas no apartamento;
- Apagar carros no apartamento;
- Apagar animais no apartamento.
- Exibir estatísiticas de um apartamento;
- Verificar se uma pessoa é moradora;
- Verificar se uma pessoa é visitante;
- Retornar algo em específico da classe;


Colaboradores:
- list Pessoas
- list Pets
- list Veiculos
- map<string,int>
- struct Pessoa
- struct Pet
- struct Veiculo


== Classe: Encomendas ==

Responsabilidades:
- Inserir novas encomendas;
- Exibir encomendas;
- Apagar encomendas.
- Verificar se uma encomenda existe;

Colaboradores:
- struct Encomenda
- map<string, Encomenda>

== Classe: Evento ==

Responsabilidades:
- Criar um evento;
- Exibir eventos programados;
- Apagar e Editar um evento;
- Adicionar convidados em um evento;
- Listar pessoas de um evento.

Colaboradores:
- struct Agendamento
- list Agendamento

*_Instruções de Instalação e de Uso:_*

A compilação do código pode ser feita de forma rápida e eficiente através do arquivo makefile, digitando apenas
"make" no terminal. Caso um novo código seja criado, apenas o nome do "main.cpp" deverá ser alterado.

A execução do programa pode ser realizada escrevendo no terminal "./tp-execution".

As observações de cada biblioteca estão destacadas nos comentários, com suas devidas pré condições.

Para a utilização do código, é recomendado que seja criado um map da classe para que assim os números de cada apartamento sejam enumerados de acordo com o interesse do usuário e que seja passado para as funções relacionadas e Evento e Encomendas o apartamento que está relacionado com a devida operação.

Para o uso de todo o potencial do código, é recomendado que um código que integre todas a bibliotecas seja criado, pois elas são capazes de conversar entre si.