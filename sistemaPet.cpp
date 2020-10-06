// Centro Universitário Estácio de Brasilia
// Disciplina.: Estrutura de Dados
// Professor..: Cristiano
// Alunos.....: Nome: Allan Bontempo Taveira Siqueira
//  Matrícula: 202002709316
// Sistema....: Sistema para clínicas veterinárias
// Data.......: 02/10/2020// Versão.....: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#define SIZE 100
using namespace std;

struct Donos
{
    int id;
    string nome;
    string telefone;
};

struct Pet
{
    int id;
    string especie; //(ex. cão, gato, pássaro, etc.)
    string raca;
    string nome;
    int idade;
    float peso;
    string porte; //(ex. pequeno, médio, grande)
    char sexo;
    int idDono; // (precisa ser vinculado ao cadastro de donos, chave estrangeira)
};

struct Cadastro
{
    int id;
    string dataHora; // Digitar a data e a Hora
    int idPet;       // (vincular com o cadastro do pet, chave estrangeira)
    string queixa;   // O porque o animal foi levado ao consultório
    string diagnostico;
    string tratamento;
};

int pesquisarIdDonos(Donos *donos, int posicaoVagaDono, int id);
Donos cadastroDono(string nome, string telefone, int id);
void mostrarDonos(int posicaoVagaDono, Donos *donos);
int procurarID(int id);
Pet cadastrarPet(string nome, string porte, string especie,
                 char sexo, int idPet, int idDono, int idade, float peso,
                 int posicaoVagaDono, Donos *donos);
int pesquisaIdPet(Pet *pets, int posicaoVagaPet, int idPet);

int main()
{
    Donos donos[100];
    Pet pets[100];

    int menu;
    int subMenu;
    int posicaoVagaDono = 0;
    int posicaoVagaPets = 0;
    int idDono = 1;
    int idPet = 1;
    int pesquisaId;
    int pesquisaBemSucedida;
    string porte;
    string especie;
    int idade;
    char sexo;
    float peso;
    string nome;
    string telefone;
    char confirmacao = 'n';

    donos[posicaoVagaDono].nome = "Carlos";
    donos[posicaoVagaDono].id = idDono;
    donos[posicaoVagaDono].telefone = "9999-9999";
    posicaoVagaDono++;
    idDono++;

    donos[posicaoVagaDono].nome = "Rita";
    donos[posicaoVagaDono].id = idDono;
    donos[posicaoVagaDono].telefone = "8888-8888";
    posicaoVagaDono++;
    idDono++;

    pets[posicaoVagaPets].id = idPet;
    pets[posicaoVagaPets].especie = "Ilhaza";
    pets[posicaoVagaPets].nome = "Bebel";
    pets[posicaoVagaPets].sexo = 'F';
    pets[posicaoVagaPets].porte = "médio";
    pets[posicaoVagaPets].idDono = 1;
    pets[posicaoVagaPets].idade = 7;
    pets[posicaoVagaPets].peso = 7;
    idPet++;
    posicaoVagaPets++;

    pets[posicaoVagaPets].id = idPet;
    pets[posicaoVagaPets].especie = "Pit Bull";
    pets[posicaoVagaPets].nome = "Sadan";
    pets[posicaoVagaPets].sexo = 'M';
    pets[posicaoVagaPets].porte = "grande";
    pets[posicaoVagaPets].idDono = 0;
    pets[posicaoVagaPets].idade = 3;
    pets[posicaoVagaPets].peso = 13.5;
    idPet++;
    posicaoVagaPets++;

    do
    {
        system("cls");
        cout << "1. Donos/Pets\n";
        cout << "2. Consultas\n";
        cout << "3. Sair\n";
        cout << "   Digite uma opcao: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {

            do
            {
                system("cls");
                cout << "1. Cadastro de Donos\n";
                cout << "2. Alterar dados dos Donos\n";
                cout << "3. Excluir dados de Donos\n";
                cout << "4. Cadastrar Pets\n";
                cout << "5. Alterar dados do pet\n";
                cout << "6. Excluir dados do pet\n";
                cout << "7. Retornar ao menu anterior\n";
                cout << "   Digite uma opcao: \n";
                cin >> subMenu;

                switch (subMenu)
                {
                case 1:
                {
                    system("cls");
                    cout << "CADASTRO DE DONOS:\n\n";
                    donos[posicaoVagaDono] = cadastroDono(nome, telefone, idDono);
                    cout << donos[posicaoVagaDono].nome << " cadastrado com sucesso!\n\n";
                    system("pause");
                    posicaoVagaDono++;
                    break;
                }

                case 2:
                {

                    system("cls");
                    cout << "ALTERAR DADOS DO DONO\n\n";
                    pesquisaId = procurarID(idDono);

                    pesquisaBemSucedida = pesquisarIdDonos(donos, posicaoVagaDono, pesquisaId);

                    if (pesquisaBemSucedida != -1)
                    {
                        cout << "Voce deseja alterar esses dados de " << donos[pesquisaBemSucedida].nome << endl;
                        cout << "Digite 's' para confirmar\n";
                        cin >> confirmacao;
                        if (confirmacao == 's')
                        {
                            system("cls");
                            cout << "Digite os novos dados do dono:\n\n";
                            cout << "Nome:\n";
                            cin >> donos[pesquisaBemSucedida].nome;
                            cout << "Telefone:\n";
                            cin >> donos[pesquisaBemSucedida].telefone;
                            cout << donos[pesquisaBemSucedida].nome << " alterado com sucesso!\n";
                        }

                        system("pause");
                    }
                    else
                    {
                        cout << "Id nao encontrado\n";
                        system("pause");
                    }
                    break;
                }

                case 3:
                {

                    cout << "EXCLUIR DADOS DO DONO\n\n";
                    pesquisaId = procurarID(idDono);
                    pesquisaBemSucedida = pesquisarIdDonos(donos, posicaoVagaDono, pesquisaId);
                    cout << "Voce deseja excluir o(a) " << donos[pesquisaBemSucedida].nome << endl;
                    cout << "Digite 's' para confirmar\n";
                    cin >> confirmacao;
                    if (confirmacao == 's')
                    {
                        system("cls");
                        donos[pesquisaBemSucedida].nome = "Esse dono foi excluido!";
                        donos[pesquisaBemSucedida].id = 0;
                        donos[pesquisaBemSucedida].telefone = "Esse dono foi excluido!";

                        cout << "Esse dono nao existe mais!\n";
                        system("pause");
                    }
                    break;
                }
                case 4:
                {
                    cout << "CADASTRAR PETS\n\n";

                    pets[posicaoVagaPets] = cadastrarPet(nome, porte, especie, sexo, idPet, idDono,
                                                         idade, peso, posicaoVagaDono, donos);

                    if (pets[posicaoVagaPets].idDono == posicaoVagaDono)
                    {
                        cout << pets[posicaoVagaPets].nome << " cadastrado com sucesso\n";
                        system("pause");
                        break;
                    }
                    break;
                }
                case 5:
                {
                    cout << "ALTERAR PET\n\n";

                    pesquisaId = procurarID(idPet);
                    pesquisaBemSucedida = pesquisaIdPet(pets, posicaoVagaPets, pesquisaId);

                    if (pesquisaBemSucedida != -1)
                    {
                        cout << "Voce deseja alterar esses dados de " << pets[pesquisaBemSucedida].nome << endl;
                        cout << "Digite 's' para confirmar\n";
                        cin >> confirmacao;
                        if (confirmacao == 's')
                        {
                            system("cls");
                            cout << "Digite os novos dados do pet:\n\n";
                            cout << "Nome:\n";
                            cin >> pets[pesquisaBemSucedida].nome;
                            cout << "Peso:\n";
                            cin >> pets[pesquisaBemSucedida].peso;
                            cout << "Porte:\n";
                            cin >> pets[pesquisaBemSucedida].porte;
                            cout << "Sexo:\n";
                            cin >> pets[pesquisaBemSucedida].sexo;
                            cout << "Especie:\n";
                            cin >> pets[pesquisaBemSucedida].especie;
                            cout << "Raca:\n";
                            cin >> pets[pesquisaBemSucedida].raca;
                            cout << "Idade:\n";
                            cin >> pets[pesquisaBemSucedida].idade;
                            cout << endl;
                            system("pause");
                            system("cls");
                            cout << pets[pesquisaBemSucedida].nome << " alterada(o) com sucesso\n!";
                            system("pause");
                        }
                    }
                    else
                    {
                        cout << "Id nao encontrado\n";
                        system("pause");
                    }
                    break;
                }
                case 6:
                {
                    cout << "EXCLUIR PET\n\n";
                    pesquisaId = procurarID(idPet);
                    pesquisaBemSucedida = pesquisaIdPet(pets, posicaoVagaPets, pesquisaId);

                    cout << "Voce deseja excluir o(a) " << pets[pesquisaBemSucedida].nome << endl;
                    cout << "Digite 's' para confirmar\n";
                    cin >> confirmacao;
                    if (confirmacao == 's')
                    {
                        pets[pesquisaBemSucedida].nome = "Esse pet foi excluido!";
                        pets[pesquisaBemSucedida].peso = 0;
                        pets[pesquisaBemSucedida].porte = "Esse pet foi excluido!";
                        pets[pesquisaBemSucedida].sexo = 'n';
                        pets[pesquisaBemSucedida].especie = "Esse pet foi excluido!";
                        pets[pesquisaBemSucedida].raca = "Esse pet foi excluido!";
                        pets[pesquisaBemSucedida].idade = 0;
                        pets[pesquisaBemSucedida].id = 0;
                        pets[pesquisaBemSucedida].idDono = -1;
                        system("cls");
                        cout << "Esse pet nao existe mais!\n";
                        system("pause");
                    }
                    break;
                }
                }

            } while (subMenu != 7);

            break;
        }
        case 2:{
            cout << "CONSULTAS\n\n";

            

            break;
            
        }
        break;
        }

    } while (menu != 3);

    return 0;
}

Donos cadastroDono(string nome, string telefone, int id)
{
    Donos donos;
    cout << "Digite o nome do Dono\n";
    cin >> nome;
    donos.nome = nome;
    cout << "Digite telefone do dono.  EX: 9999-9999\n";
    cin >> telefone;
    donos.telefone = telefone;
    donos.id = id;
    id++;
    return donos;
}

int pesquisarIdDonos(Donos *donos, int posicaoVagaDono, int idDono)
{
    for (int i = 0; i < posicaoVagaDono; i++)
    {
        if (donos[i].id == idDono)
        {
            return i;
        }
    }
    return -1;
}

int pesquisaIdPet(Pet *pets, int posicaoVagaPet, int idPet)
{
    for (int i = 0; i < posicaoVagaPet; i++)
    {
        if (pets[i].id == idPet)
        {
            return i;
        }
    }
    return -1;
}

Pet cadastrarPet(string nome, string porte, string especie,
                 char sexo, int idPet, int idDono, int idade, float peso,
                 int posicaoVagaDono, Donos *donos)
{
    Pet pets;
    cout << "Digite o id do dono ao qual pertence o pet\n";
    cin >> idDono;
    for (int i = 0; i < posicaoVagaDono; i++)
    {
        if (donos[i].id == idDono)
        {
            cout << "O dono e: " << donos[i].nome << "\n\n";
            pets.idDono = idDono;
            cout << "Digite o nome do pet:\n";
            cin >> nome;
            pets.nome = nome;
            cout << "Porte do pet: (Ex. pequeno, medio, grande)\n";
            cin >> porte;
            pets.porte = porte;
            cout << "Especie do pet:\n";
            cin >> especie;
            pets.especie = especie;
            cout << "Sexo do pet: (Ex. 'F' ou 'M')\n";
            cin >> sexo;
            pets.sexo = sexo;
            cout << "Qual o peso do pet?\n";
            cin >> peso;
            pets.peso = peso;
            pets.id = idPet;
            idPet++;
            return pets;
        }
        else if (idDono > posicaoVagaDono)
        {
            cout << "Dono nao cadastrado no sistema!\n Por Favor, voltar ao menu anterior e cadastra-lo\n\n";
            system("pause");
            break;
        }
    }
}

void mostrarDonos(int posicaoVagaDono, Donos *donos)
{
    system("cls");
    cout << "DADOS DO DONO CADASTRADO:\n\n";
    cout << " __________________   "
            " ___________       "
            "_________________ "
         << endl;
    cout << "|      NOME:      |    |   ID      |     |   TELEFONE      |"
         << "\n";

    for (int i = 0; i < posicaoVagaDono; i++)

    {
        if (donos[i].id != 0)
        {
            cout << "|" << donos[i].nome << "          |";
            cout << "   |   " << donos[i].id << "          |";
            cout << "     |" << donos[i].telefone << "      |" << endl;
        }
    }
}

int procurarID(int id)
{
    do
    {
        cout << "Digite o id do Dono/Pet:\n";
        cin >> id;
        if (id == 0)
        {
            cout << "ID invalido!\n";
            system("pause");
        }
        return id;
    } while (id == 0);
}
