/**************************
SISTEMA DE CADASTRO DE ALUNOS
ALLAN BONTEMPO
MATRICULA 202002709316
***************************/
#include <iostream>
#include <locale.h>
#include <limits>
#include <stdlib.h>

using namespace std;
int pesquisarMatricula(int proximaPosicaoVagaNosVetores, int matricula);
bool validarNota(bool notaValida, int AV);
void mostrarNotas(int pesquisaMatricula);

struct Alunos
{
    string nome;
    int matricula;
    char sexo;
    bool matriculado;
    int celular;
    char turma;
};

Alunos alunos[100];
float mtzNotas[100][4]; // linha 0 -> AV1, linha 1 -> AV2, linha 2 -> AV3, linha 3 -> mediaFinal

int main()
{

    setlocale(LC_ALL, "Portuguese"); // Configura o sistema para aceitar acentuacoes em Portugues

    char turma;
    int matricula;
    bool pesquisaBemSucedida = false;
    int posicaoLocalizada;

    int vetFaltas[100];
    float AV1;
    float AV2;
    float AV3;
    float AV;

    int menu;
    int submenu;
    int proximaPosicaoVagaNosVetores = 0;

    alunos[0].matricula = 11;
    alunos[0].nome = "Joao";
    alunos[0].sexo = 'M';
    alunos[0].celular = 9999;
    alunos[0].matriculado = true;
    alunos[0].turma = 'A';
    proximaPosicaoVagaNosVetores++;

    alunos[1].matricula = 22;
    alunos[1].nome = "Maria";
    alunos[1].sexo = 'F';
    alunos[1].celular = 8888;
    alunos[1].matriculado = false;
    proximaPosicaoVagaNosVetores++;

    alunos[2].matricula = 33;
    alunos[2].nome = "Carla";
    alunos[2].sexo = 'F';
    alunos[2].celular = 7777;
    alunos[2].matriculado = false;
    proximaPosicaoVagaNosVetores++;

    do
    {
        system("cls");
        cout << "(" << proximaPosicaoVagaNosVetores << ") SISTEMA ACADEMICO\n";
        cout << "1. Alunos\n";
        cout << "2. Notas\n";
        cout << "3. Relatorios\n";
        cout << "4. Sair\n";
        cout << "   Digite uma opcao: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            do
            {
                system("cls");
                cout << "ALUNOS\n";
                cout << "1. Cadastrar alunos\n";
                cout << "2. Alterar dados do alunos\n";
                cout << "3. Excluir alunos\n";
                cout << "4. Consultar dados do alunos\n";
                cout << "5. Consultar alunos\n";
                cout << "6. Matricular o alunos\n";
                cout << "7. Retornar ao menu anterior\n";
                cout << "   Escolha uma opcao: ";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                {
                    cout << "CADASTRAR DADOS DO ALUNO\n\n";
                    // Permite a entrada apenas de matriculas validas, isto e, matriculas diferente de 0.
                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        cout << "Matricula ja cadastrada!!!\n";
                        system("pause");
                    }
                    else
                    {
                        alunos[proximaPosicaoVagaNosVetores].matricula = matricula;
                        cout << "Informe o nome.....: ";
                        cin >> alunos[proximaPosicaoVagaNosVetores].nome;
                        cout << "Informe o sexo.....: ";
                        cin >> alunos[proximaPosicaoVagaNosVetores].sexo;
                        cout << "Informe o celular..: ";
                        cin >> alunos[proximaPosicaoVagaNosVetores].celular;
                        alunos[proximaPosicaoVagaNosVetores].matriculado = false;
                        proximaPosicaoVagaNosVetores++;
                    }
                    break;
                }
                case 2:
                {
                    cout << "ALTERAR DADOS DO ALUNO\n\n";
                    do
                    {
                        cout << "Informe o numero de matricula a ser pesquisada: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        cout << "Informe os novos dados para o(a) aluno(a): " << alunos[pesquisaMatricula].nome << endl;
                        cout << "Informe o nome.....: ";
                        cin >> alunos[pesquisaMatricula].nome;
                        cout << "Informe o sexo.....: ";
                        cin >> alunos[pesquisaMatricula].sexo;
                        cout << "Informe o celular..: ";
                        cin >> alunos[pesquisaMatricula].celular;
                    }
                    else
                    {
                        cout << "Nao encontrei ninguem com a matricula: " << matricula << endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    cout << "EXCLUIR DADOS DO ALUNO\n\n";
                    do
                    {
                        cout << "Informe o numero de matricula a ser pesquisada: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        alunos[pesquisaMatricula].matricula = 0;
                        cout << alunos[pesquisaMatricula].nome << " foi excluido(a)!\n";
                        system("pause");
                    }
                    else
                    {
                        cout << "Nao encontrei ninguem com a matricula: " << matricula << endl;
                        system("pause");
                    }
                    break;
                }
                case 4:
                {
                    cout << "CONSULTAR DADOS DE UM ALUNO\n\n";
                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        cout << "Matricula...: " << alunos[pesquisaMatricula].matricula << endl;
                        cout << "Nome........: " << alunos[pesquisaMatricula].nome << endl;
                        cout << "Sexo........: " << alunos[pesquisaMatricula].sexo << endl;
                        cout << "Celular.....: " << alunos[pesquisaMatricula].celular << endl;
                        cout << "Matriculado?: " << ((alunos[pesquisaMatricula].matriculado) ? "Sim\n" : "Nao\n");
                        if (alunos[pesquisaMatricula].matriculado)
                        {
                            cout << "Turma.......: " << alunos[pesquisaMatricula].turma << endl;
                        }
                        system("pause");
                    }
                    else
                    {
                        cout << "Matricula nao encontrada!!!\n";
                        system("pause");
                    }
                    break;
                }
                case 5:
                {
                    cout << "CONSULTAR ALUNOS\n\n";
                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (alunos[i].matricula != 0)
                        {
                            cout << "<" << i << "> ";
                            cout << alunos[i].matricula << "\t";
                            cout << alunos[i].nome << "\t";
                            cout << alunos[i].sexo << "\t";
                            cout << alunos[i].celular << "\n";
                        }
                    }
                    system("pause");
                    break;
                }
                case 6:
                {
                    cout << "MATRICULAR ALUNOS\n\n";
                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        cout << "Informe a turma do(a) " << alunos[pesquisaMatricula].nome << ": ";
                        cin >> alunos[pesquisaMatricula].turma;
                        alunos[pesquisaMatricula].matriculado = true;
                        system("pause");
                    }
                    else
                    {
                        cout << "Matricula nao encontrada!!!\n";
                        system("pause");
                    }
                    break;
                }
                }
            } while (submenu != 7);
            break;
        }
        case 2:
        {
            do
            {
                system("cls");
                cout << "NOTAS\n\n";
                cout << "1. Lancar notas por turma\n";
                cout << "2. Lancar notas por aluno\n";
                cout << "3. Alterar notas do alunos\n";
                cout << "4. Excluir notas do alunos\n";
                cout << "5. Consultar notas do alunos\n";
                cout << "6. Retornar ao menu anterior\n";
                cout << "   Escolha uma opcao: ";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                {
                    cout << "LANCAR NOTAS POR TURMA\n\n";
                    cout << "Informe a turma desejada:";
                    cin >> turma;
                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (turma == alunos[i].turma)
                        {
                            cout << "Voce esta na turma '" << alunos[i].turma << "'\n";
                            cout << "Aluno(a):  " << alunos[i].nome << "\n";
                            mtzNotas[i][3] = 0.0;
                            bool notaValida = false;
                            for (int c = 0; c < 3; c++)
                            {
                                cout << "Digite a nota AV" << c + 1 << ":  ";
                                cin >> AV;
                                notaValida = validarNota(notaValida, AV);

                                if (notaValida == false)
                                {

                                    mtzNotas[i][c] = AV;
                                    mtzNotas[i][3] += AV;
                                }
                            }
                            mtzNotas[i][3] /= 3;
                            if (notaValida == false)
                            {
                                cout << "A media de " << alunos[i].nome << " e: " << mtzNotas[i][3] << "\n";
                                if (mtzNotas[i][3] < 7)
                                {
                                    cout << alunos[i].nome << " foi reprovado! \n\n";
                                }
                                else
                                {
                                    cout << alunos[i].nome << " foi aprovado! \n\n";
                                }
                                system("pause");
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout << "LANCAR NOTAS POR ALUNO\n\n";

                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    mtzNotas[pesquisaMatricula][3] = 0.0;
                    if (pesquisaMatricula != -1)
                    {
                        cout << "Aluno(a):  " << alunos[pesquisaMatricula].nome << "\n";
                        bool notaValida = false;
                        for (int c = 0; c < 3; c++)
                        {
                            cout << "Digite a nota AV" << c + 1 << ":  ";
                            cin >> AV;
                            notaValida = validarNota(notaValida, AV);

                            if (notaValida == false)
                            {
                                mtzNotas[pesquisaMatricula][c] = AV;
                                mtzNotas[pesquisaMatricula][3] += AV;
                            }
                        }
                        system("pause");
                        mtzNotas[pesquisaMatricula][3] /= 3;
                        cout << "A media de " << alunos[pesquisaMatricula].nome << " e: " << mtzNotas[pesquisaMatricula][3] << "\n";
                        if (mtzNotas[pesquisaMatricula][3] < 7)
                        {
                            system("cls");
                            mostrarNotas(pesquisaMatricula);
                            cout << alunos[pesquisaMatricula].nome << " foi reprovado com a media " << mtzNotas[pesquisaMatricula][3] << "\n\n";
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            mostrarNotas(pesquisaMatricula);
                            cout << alunos[pesquisaMatricula].nome << " foi aprovado com a media " << mtzNotas[pesquisaMatricula][3] << "\n\n";
                            system("pause");
                        }

                        break;
                    }
                    else
                    {
                        cout << "Matricula nao encontrada!!!\n";
                        system("pause");
                    }

                    break;
                }
                case 3:
                {
                    cout << "ALTERAR NOTAS DO ALUNO\n\n";
                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                            system("pause");
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    mtzNotas[pesquisaMatricula][3] = 0.0;
                    if (pesquisaMatricula != -1)
                    {

                        cout << endl;
                        cout << "Aluno(a):  " << alunos[pesquisaMatricula].nome << "\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "A nota AV" << i + 1 << " e: " << mtzNotas[pesquisaMatricula][i] << "\n";
                        }

                        cout << endl;
                        cout << "Deseja alterar? Digite 's' para alterar\n";
                        char alterarNota = 'n';
                        cin >> alterarNota;
                        cout << endl;
                        if (alterarNota == 's')
                        {
                            for (int c = 0; c < 3; c++)
                            {
                                cout << "Digite a nota AV" << c + 1 << ":  ";
                                cin >> AV;
                                mtzNotas[pesquisaMatricula][c] = AV;
                                mtzNotas[pesquisaMatricula][3] += AV;
                            }
                            mtzNotas[pesquisaMatricula][3] /= 3;

                            mostrarNotas(pesquisaMatricula);
                            system("pause");
                        }
                    }

                    break;
                }
                case 4:
                {
                    cout << "EXCLUIR NOTAS DO ALUNO\n\n";

                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);
                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);
                    mtzNotas[pesquisaMatricula][3] = 0.0;

                    if (pesquisaMatricula != -1)
                    {

                        cout << endl;
                        cout << "Aluno(a):  " << alunos[pesquisaMatricula].nome << "\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "A nota AV" << i + 1 << " e: " << mtzNotas[pesquisaMatricula][i] << "\n";
                        }

                        cout << endl;
                        cout << "Deseja excluir? Digite 's' para alterar\n";
                        char excluirNota = 'n';
                        cin >> excluirNota;
                        cout << endl;
                        if (excluirNota == 's')
                        {

                            cout << "Qual nota você deseja excluir?\n\n";
                            cout << "Digite '1' para AV1, '2' para AV2, '3' para AV3, '4' para todas\n\n";
                            char nota = '1';
                            cin >> nota;

                            if (nota == '1')
                            {
                                mtzNotas[pesquisaMatricula][0] = -1;
                            }
                            else if (nota == '2')
                            {
                                mtzNotas[pesquisaMatricula][1] = -1;
                            }
                            else if (nota == '2')
                            {
                                mtzNotas[pesquisaMatricula][2] = -1;
                            }
                            else if (nota == '4')
                            {
                                for (int c = 0; c < 3; c++)
                                {
                                    mtzNotas[pesquisaMatricula][c] = -1;
                                    mtzNotas[pesquisaMatricula][3] = 0;
                                }
                            }

                            mostrarNotas(pesquisaMatricula);

                            system("pause");
                        }
                    }
                    break;
                }
                case 5:
                {
                    cout << "CONSULTAR NOTAS DO ALUNO\n\n";

                    do
                    {
                        cout << "Informe a matricula: ";
                        cin >> matricula;
                        if (matricula == 0)
                        {
                            cout << "Matricula invalida!!!\n";
                        }
                    } while (matricula == 0);

                    int pesquisaMatricula = pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula);

                    if (pesquisaMatricula != -1)
                    {
                        mostrarNotas(pesquisaMatricula);

                        system("pause");
                    }

                    break;
                }
                }
            } while (submenu != 6);
            break;
        }
        case 3:
        {
            do
            {
                system("cls");
                cout << "RELATORIOS\n\n";
                cout << "1. Aprovados\n";
                cout << "2. Reprovados\n";
                cout << "3. Dados cadastrais\n";
                cout << "4. Alunos por turma\n";
                cout << "5. Retornar ao menu anterior\n";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                {
                    cout << "RELACAO DE ALUNOS APROVADOS\n\n";
                    for (int i = 0; i <= proximaPosicaoVagaNosVetores; i++)
                    {
                        bool aprovados = false;
                        if (mtzNotas[i][3] >= 7)
                        {
                            aprovados = true;
                            cout << alunos[i].nome << " foi aprovado com a media " << mtzNotas[i][3] << endl;
                        }
                        else if (aprovados == false && i == proximaPosicaoVagaNosVetores)
                        {
                            cout << "Nenhum aluno foi aprovado\n\n";
                            break;
                        }
                    }
                    system("pause");

                    break;
                }
                case 2:
                {
                    cout << "RELACAO DE ALUNOS REPROVADOS\n\n";

                    for (int i = 0; i <= proximaPosicaoVagaNosVetores; i++)
                    {
                        bool reprovados = false;
                        if (mtzNotas[i][3] < 7)
                        {
                            reprovados = true;
                            cout << alunos[i].nome << " foi reprovado com a media " << mtzNotas[i][3] << endl;
                        }
                        else if (reprovados == false && i == proximaPosicaoVagaNosVetores)
                        {
                            cout << "Nenhum aluno foi aprovado\n\n";
                            break;
                        }
                    }
                    system("pause");

                    break;
                }
                case 3:
                {
                    cout << "DADOS CADASTRAIS DO ALUNO\n\n";
                    break;
                }
                case 4:
                {
                    cout << "RELACAO DE ALUNOS POR TUMRA\n\n";
                    break;
                }
                }
            } while (submenu != 5);
            break;
        }
        }
    } while (menu != 4);
    return 0;
}

int pesquisarMatricula(int proximaPosicaoVagaNosVetores, int matricula)
{
    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
    {
        if (alunos[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
}

bool validarNota(bool notaValida, int AV)
{
    if (AV < 0 || AV > 10)
    {
        cout << "Nota invalida!\n";
        return notaValida = true;
    }
    else
    {
        return notaValida = false;
    }
}

void mostrarNotas(int pesquisaMatricula)
{
    cout << "NOTAS: \n\n";
    cout << "AV1: " << mtzNotas[pesquisaMatricula][0] << "\n";
    cout << "AV2: " << mtzNotas[pesquisaMatricula][1] << "\n";
    cout << "AV3: " << mtzNotas[pesquisaMatricula][2] << "\n";
}