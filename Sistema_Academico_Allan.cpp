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
int pesquisarMatricula(int proximaPosicaoVagaNosVetores, int matricula, bool pesquisaBemSucedida);
int vetMatricula[100];

int main()
{

    setlocale(LC_ALL, "Portuguese"); // Configura o sistema para aceitar acentuacoes em Portugues

    string vetNome[100];
    int vetCelular[100];
    char vetSexo[100];
    bool vetMatriculado[100];
    char vetTurma[100];
    char turma;
    int lengthTurma = sizeof(vetTurma) / sizeof(vetTurma[0]);
    int lengthNome = sizeof(vetNome) / sizeof(vetNome[0]);

    int matricula;
    bool pesquisaBemSucedida = false;
    int posicaoLocalizada;

    int vetFaltas[100];
    float mtzNotas[100][4]; // linha 0 -> AV1, linha 1 -> AV2, linha 2 -> AV3, linha 3 -> mediaFinal
    float AV1;
    float AV2;
    float AV3;
    float AV;

    int menu;
    int submenu;
    int proximaPosicaoVagaNosVetores = 0;

    vetMatricula[0] = 11;
    vetNome[0] = "Joao";
    vetSexo[0] = 'M';
    vetCelular[0] = 9999;
    vetMatriculado[0] = true;
    vetTurma[0] = 'A';
    proximaPosicaoVagaNosVetores++;

    vetMatricula[1] = 22;
    vetNome[1] = "Maria";
    vetSexo[1] = 'F';
    vetCelular[1] = 8888;
    vetMatriculado[1] = false;
    proximaPosicaoVagaNosVetores++;

    vetMatricula[2] = 33;
    vetNome[2] = "Carla";
    vetSexo[2] = 'F';
    vetCelular[2] = 7777;
    vetMatriculado[2] = false;
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

                    pesquisaBemSucedida = false;
                    pesquisarMatricula(proximaPosicaoVagaNosVetores, matricula, pesquisaBemSucedida);

                    if (pesquisaBemSucedida)
                    {
                        cout << "Matricula ja cadastrada!!!\n";
                        system("pause");
                    }
                    else
                    {
                        vetMatricula[proximaPosicaoVagaNosVetores] = matricula;
                        cout << "Informe o nome.....: ";
                        cin >> vetNome[proximaPosicaoVagaNosVetores];
                        cout << "Informe o sexo.....: ";
                        cin >> vetSexo[proximaPosicaoVagaNosVetores];
                        cout << "Informe o celular..: ";
                        cin >> vetCelular[proximaPosicaoVagaNosVetores];
                        vetMatriculado[proximaPosicaoVagaNosVetores] = false;
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {
                        cout << "Informe os novos dados para o(a) aluno(a): " << vetNome[posicaoLocalizada] << endl;
                        cout << "Informe o nome.....: ";
                        cin >> vetNome[posicaoLocalizada];
                        cout << "Informe o sexo.....: ";
                        cin >> vetSexo[posicaoLocalizada];
                        cout << "Informe o celular..: ";
                        cin >> vetCelular[posicaoLocalizada];
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {
                        vetMatricula[posicaoLocalizada] = 0;
                        cout << vetNome[posicaoLocalizada] << " foi excluido(a)!\n";
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {
                        cout << "Matricula...: " << vetMatricula[posicaoLocalizada] << endl;
                        cout << "Nome........: " << vetNome[posicaoLocalizada] << endl;
                        cout << "Sexo........: " << vetSexo[posicaoLocalizada] << endl;
                        cout << "Celular.....: " << vetCelular[posicaoLocalizada] << endl;
                        cout << "Matriculado?: " << ((vetMatriculado[posicaoLocalizada]) ? "Sim\n" : "Nao\n");
                        if (vetMatriculado[posicaoLocalizada])
                        {
                            cout << "Turma.......: " << vetTurma[posicaoLocalizada] << endl;
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
                        if (vetMatricula[i] != 0)
                        {
                            cout << "<" << i << "> ";
                            cout << vetMatricula[i] << "\t";
                            cout << vetNome[i] << "\t";
                            cout << vetSexo[i] << "\t";
                            cout << vetCelular[i] << "\n";
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {
                        cout << "Informe a turma do(a) " << vetNome[posicaoLocalizada] << ": ";
                        cin >> vetTurma[posicaoLocalizada];
                        vetMatriculado[posicaoLocalizada] = true;
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
                        if (turma == vetTurma[i])
                        {
                            cout << "Voce esta na turma '" << vetTurma[i] << "'\n";
                            cout << "Aluno(a):  " << vetNome[i] << "\n";
                            mtzNotas[i][3] = 0.0;
                            for (int c = 0; c < 3; c++)
                            {
                                cout << "Digite a nota AV" << c + 1 << ":  ";
                                cin >> AV;
                                mtzNotas[i][c] = AV;
                                mtzNotas[i][3] += AV;
                            }
                            mtzNotas[i][3] /= 3;

                            cout << "A media de " << vetNome[i] << " e: " << mtzNotas[i][3] << "\n";
                            if (mtzNotas[i][3] < 7)
                            {
                                cout << vetNome[i] << " foi reprovado! \n\n";
                            }
                            else
                            {
                                cout << vetNome[i] << " foi aprovado! \n\n";
                            }
                            system("pause");
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                    }
                    mtzNotas[posicaoLocalizada][3] = 0.0;
                    if (pesquisaBemSucedida)
                    {
                        cout << "Aluno(a):  " << vetNome[posicaoLocalizada] << "\n";
                        for (int c = 0; c < 3; c++)
                        {
                            cout << "Digite a nota AV" << c + 1 << ":  ";
                            cin >> AV;
                            mtzNotas[posicaoLocalizada][c] = AV;
                            mtzNotas[posicaoLocalizada][3] += AV;
                        }
                        mtzNotas[posicaoLocalizada][3] /= 3;

                        cout << "A media de " << vetNome[posicaoLocalizada] << " e: " << mtzNotas[posicaoLocalizada][3] << "\n";
                        if (mtzNotas[posicaoLocalizada][3] < 7)
                        {
                            cout << vetNome[posicaoLocalizada] << " foi reprovado! \n\n";
                        }
                        else
                        {
                            cout << vetNome[posicaoLocalizada] << " foi aprovado! \n\n";
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
                        }
                    } while (matricula == 0);

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                        else
                        {
                            cout << "Matricula invalida\n";
                            system("pause");
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {

                        cout << endl;
                        cout << "Aluno(a):  " << vetNome[posicaoLocalizada] << "\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "A nota AV" << i + 1 << " e: " << mtzNotas[posicaoLocalizada][i] << "\n";
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
                                mtzNotas[posicaoLocalizada][c] = AV;
                                mtzNotas[posicaoLocalizada][3] += AV;
                            }
                            mtzNotas[posicaoLocalizada][3] /= 3;

                            cout << "NOTAS: \n\n";
                            cout << "AV1: " << mtzNotas[posicaoLocalizada][0] << "\n";
                            cout << "AV2: " << mtzNotas[posicaoLocalizada][1] << "\n";
                            cout << "AV3: " << mtzNotas[posicaoLocalizada][2] << "\n";
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                        else
                        {
                            cout << "Matricula invalida\n";
                            system("pause");
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {

                        cout << endl;
                        cout << "Aluno(a):  " << vetNome[posicaoLocalizada] << "\n";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "A nota AV" << i + 1 << " e: " << mtzNotas[posicaoLocalizada][i] << "\n";
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
                                mtzNotas[posicaoLocalizada][0] = -1;
                            }
                            else if (nota == '2')
                            {
                                mtzNotas[posicaoLocalizada][1] = -1;
                            }
                            else if (nota == '2')
                            {
                                mtzNotas[posicaoLocalizada][2] = -1;
                            }
                            else if (nota == '4')
                            {
                                for (int c = 0; c < 3; c++)
                                {
                                    mtzNotas[posicaoLocalizada][c] = -1;
                                    mtzNotas[posicaoLocalizada][3] = 0;
                                }
                            }

                            cout << "NOTAS: \n\n";
                            cout << "AV1: " << mtzNotas[posicaoLocalizada][0] << "\n";
                            cout << "AV2: " << mtzNotas[posicaoLocalizada][1] << "\n";
                            cout << "AV3: " << mtzNotas[posicaoLocalizada][2] << "\n";
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

                    pesquisaBemSucedida = false;

                    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
                    {
                        if (vetMatricula[i] == matricula)
                        {
                            pesquisaBemSucedida = true;
                            posicaoLocalizada = i;
                            break;
                        }
                        else
                        {
                            cout << "Matricula invalida\n";
                            system("pause");
                            break;
                        }
                    }
                    if (pesquisaBemSucedida)
                    {
                        cout << "NOTAS: \n\n";
                        cout << "AV1: " << mtzNotas[posicaoLocalizada][0] << "\n";
                        cout << "AV2: " << mtzNotas[posicaoLocalizada][1] << "\n";
                        cout << "AV3: " << mtzNotas[posicaoLocalizada][2] << "\n";
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
                    break;
                }
                case 2:
                {
                    cout << "RELACAO DE ALUNOS REPROVADOS\n\n";
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

int pesquisarMatricula(int proximaPosicaoVagaNosVetores, int matricula, bool pesquisaBemSucedida)
{
    for (int i = 0; i < proximaPosicaoVagaNosVetores; i++)
    {
        if (vetMatricula[i] == matricula)
        {
            pesquisaBemSucedida = true;
            break;
        }
    }
}