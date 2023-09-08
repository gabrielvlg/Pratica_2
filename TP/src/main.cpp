#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <getopt.h>
#include "fatorial.h"
#include "fibonacci.h"
#include "msgassert.h"
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

// definicoes de operacoes a serem testadas
#define OPFATORIAL 1
#define OPFIBONACCI 2

typedef struct opt{
  int opescolhida;
  int numero;
} opt_tipo;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"OPCOES:\n");
  fprintf(stderr,"\t-t \t\t(fatorial) \n");
  fprintf(stderr,"\t-b \t\t(fibonacci) \n");
}


void parse_args(int argc,char ** argv, opt_tipo * opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
     // variaveis externas do getopt
     extern char * optarg;
     //extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opt->opescolhida = -1;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "t:b:")) != EOF){
       switch(c) {
         case 't':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPFATORIAL;
            opt->numero = atoi(optarg);
                  break;
         case 'b':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPFIBONACCI;
            opt->numero = atoi(optarg);
                  break;
         default:
                  uso();
                  exit(1);

       }
       // verificacao da consistencia das opcoes
       erroAssert(opt->opescolhida>0,"necessario escolher operacao");
     }
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao das operacoes
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
  clock_t time_req; //funcao para medir tempo de relógio
  opt_tipo opt;
  // avaliar linha de comando
  parse_args(argc,argv,&opt);

  //medicoes do tempo de sistema e de usuário
  struct rusage usage;
    struct timeval start_user, end_user, start_system, end_system;

    // 
    getrusage(RUSAGE_SELF, &usage);
    start_user = usage.ru_utime;
    start_system = usage.ru_stime;

  float utime, stime;
  // execucao dependente da operacao escolhida
  switch (opt.opescolhida){
    case OPFATORIAL:
         //inicia a contagem do relógio
         time_req = clock();
         cout << "FATORIAL\n";
         cout << "\tIterativo: " << Factorial_iterative(opt.numero) << endl; 
         //calcula a diferenca de tempo (tempo gasto pra executar)
         time_req = clock() - time_req;
         //imprime o tempo gasto em milisegundos
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;

        //imprime o tempo de usuario e de sistema
        utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
        stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
        cout << "\t\tTempo de sistema -> " << stime << endl;
        cout << "\t\tTempo de usuário -> " << utime << endl;


        getrusage(RUSAGE_SELF, &usage);
        start_user = usage.ru_utime;
        start_system = usage.ru_stime;
         //mesma coisa pro recursivo
         cout << "\tRecursivo: " << Factorial_recursive(opt.numero) << endl;
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
         time_req = clock();


        //imprime o tempo de usuario e de sistema
        utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
        stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
        cout << "\t\tTempo de sistema -> " << stime << endl;
        cout << "\t\tTempo de usuário -> " << utime << endl;

	 break;
    //repete o processo para a função de fibonacci
    case OPFIBONACCI:
         time_req = clock();
         cout << "FIBONACCI\n";
         cout << "\tIterativo: " << Fibonacci_iterative(opt.numero) << endl; 
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;

        utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
        stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
        cout << "\t\tTempo de sistema -> " << stime << endl;
        cout << "\t\tTempo de usuário -> " << utime << endl;

        getrusage(RUSAGE_SELF, &usage);
        end_user = usage.ru_utime;
        end_system = usage.ru_stime;

         cout << "\tRecursivo: " << Fibonacci_recursive(opt.numero) << endl; 
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
          time_req = clock();

        utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
        stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
        cout << "\t\tTempo de sistema -> " << stime << endl;
        cout << "\t\tTempo de usuário -> " << utime << endl;
	 break;
   default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
         uso();
	 exit(1);
  }

  return 0;
}