# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <locale.h>
# include <math.h>
# include <time.h>
# include <string.h>
# include <ctype.h>

#define P 100


struct cadastro_funcionario{
	
   char nome_fun[P];  //nome do funcionario
   char rua[P];      //endereço do funcionario
   char cargo[P];   //cargo do funcionario
   int tel[P];    //telefone do funcionario
   int dt_dia[P];    //dia de nascimento
   int dt_mes[P];   //mes de nascimento
   int dt_ano[P];  //ano de nascimento 
   long long int cpf[P];   //CPF DO FUNCIONARIO  /long para numeros inteiros grandes
   long long int rg[P];    //RG do funcionario   /long para numeros inteiros grandes
   int num[P];  //numero da residencia
   int hr_ent[P]; //hora de entra no serviço
   int hr_sai[P];  //hora de saida do serviço
   float salario[P];  //salario do funcionario
   	
} cad_fun[P];


struct cadastro_cliente  //VARIAVEIS PARA CADASTRO DE CLIENTE //
{
   char  nome_cli[P];//nome do cliente
   char rua[P];//endereço do cliente
   char email[P];//e-mail do cliente
   char tel[P];//telefone do cliente
   int idade[P];//idade do cliente
   long long int cpf[P];//cpf do cliente /long para numeros inteiros grandes
   long long int rg[P];// rf do cliente /long para numeros inteiros grandes
   int num[P];//numero da casa do cliente
   int cep[P];//cep da rua cliente
   
}  cad_cli[P];

struct cadastro_empresa
{
   int fon[P];//telefone da empresa
   long long int cnpj[P];//cnpj da empresa   /long para numeros inteiros grandes
   long long int in_municipal[P];//inscrição municipal da empresa  /long para numeros inteiros grandes
   long long int in_estadual[P];//inscrição estatual da empresa   /long para numeros inteiros grandes
   int num[P];//nuemro da empresa
   int cep[P];//cep da empresa
   char e_mail[P];//e-mail  da empresa
   char endereco[P];//endereço da empresa
   char	nome[P];//nome da empresa
   
} empresa[P];


struct cadastro_produto
{
//VARIAVEIS PARA CADASTRO DE PRODUTOS//
   char dis[P];//discrição do produto
   int cod_interno[P];//codigo do fabricante 
   int ref_cod[P];//codigo da loja
   int quant_P[P];//quantidade do tamanho p
   int quant_M[P];//quantidade do tamanho m
   int quant_G[P];//quantidade do tamanho g
   float vl[P];//recebe um novo valor do produto
   float des[P];//desconto do produto
   float valor_prod[P];//valor do produto
   float custo[P];//valor de custodo produto
   
}cad_prod[P];

struct frete{
	
  float	alt[P];//altura
  float	lar[P];//largura
  float	compr[P];//comprimento
  float peso[P];//peso
  float valor[P];//valor do frete
	
} frete[P];


	//LOG DE USUARIO
	char usuario, *pont;
	int senha;


	//opçao global
	long long int op;//op = opçao 
	float n; //retira a quantidade do estoque total


	//data e hora
	struct tm *data;
	time_t temp;
    
	//prototipo das funçoes
	void cadastro();
	void cadastro_funcionario();
	void cadastro_prod();
	void consulta();
	void cadastro_fornedor();
	void consulta_cad_empresa();
	void dataehora();
	void ESTOQUE();
	void list_cli();
	void list_fun();
	void servico();
	void calculo_frete();
	void pre_vendas();


 int main(){
  setlocale(LC_ALL, "Portuguese");

	printf(" ==============================================================\n");
	printf(" ||                    PLURAL-UP                             ||\n");
	printf(" ||              dê um up no seu negócio                     ||\n");
	printf(" ==============================================================\n\n");

	printf(" ==============================================================\n");
	printf(" ||                    BEM VINDO                             ||\n" );
	printf(" ==============================================================\n");

	printf("\t USUARIO: ");scanf("%s",&usuario);
	printf("\n\t SENHA: ");scanf("%d",&senha);
	
	//ponteiro para exibir o nome de usuario
	pont = &usuario; 
	
	printf(" ==============================================================\n");

	dataehora();
  do{
	system("cls");
	printf(" ==============================================================\n");
	printf(" ||                        MENU                              ||\n" );
	printf(" ==============================================================\n");

	printf("\t1.CADASTRO de CLIENTE \t"); printf("\t 5.OUTROS SERVIÇO\n");
	printf("\t2.CADASTRO de PRODUTOS \t");    printf("\t 6.PRE-VENDA \n");
	printf("\t3.LISTA DE CLIENTES   \t");   printf("\t 7.SAIR \n");
	printf("\t4.ESTOQUE \n");
	printf("   ESCOLHA UMA OPCAO ACIMA ENTRE 1 E 7:  "); scanf("%d",&op);




	switch(op){
		case 1:
	     cadastro();
		break;

		case 2:
		 cadastro_prod();
		 break;
 
		case 3:
		 list_cli();
 		break;
 
		case 4:
		 ESTOQUE();
		 break;
 
		case 5:
		 servico();
		 break;
		 
		case 6:
		 pre_vendas();
		 break;
		 
		case 7:
		break;
			
		default :
		 printf("OPÇÃO DIGITA INVALIDA !!!\n\n");  
	}

 }while(op != 7 );

 getch();
return 0;
}

	void cadastro()
{
	system("cls");
	static int id=1;
 
 do{

	dataehora();
	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t1.CADASTRO de CLIENTE \n");
	printf(" ==============================================================\n");
	printf(" NOME: ");
	fflush(stdin);//limpa o teclado 
	gets(cad_cli[id].nome_cli);//gets lÊ ate que o usuario aperte o enter
	printf("\n==============================================================\n");

	printf(" TELEFONE: "); scanf("%s",&cad_cli[id].tel);
	printf("\n==============================================================\n");

	printf(" IDADE: "); scanf("%d",&cad_cli[id].idade[id]);
	printf("\n==============================================================\n");

	printf(" CPF: "); scanf("%lld",&cad_cli[id].cpf[id]);//LL para especificar que e um numero inteiro grande
	printf("\n==============================================================\n");

	printf(" RG: "); scanf("%lld",&cad_cli[id].rg[id]);//LL para especificar que e um numero inteiro grande
	printf("\n==============================================================\n");

	printf(" ENDEREÇO: ");
	fflush(stdin);
	gets(cad_cli[id].rua);
	printf("\tN°:");
	scanf("%d",&cad_cli[id].num[id]);
	printf("\n==============================================================\n");
	
	printf("\tCEP: "); scanf("%ld",&cad_cli[id].cep[id]);
	printf("\n==============================================================\n");
	
	printf(" E-MAIL: ");
	fflush(stdin);
	gets(cad_cli[id].email);  
	printf("\n==============================================================\n");


	printf("Cadastro salvo...\n");
  		 id++;
	printf("digite 1 para continuar ou 2 para Sair\t"); scanf("%d",&op);


	}while(op != 2);


}
   
   
	void dataehora()
{
	//CODIGO PEGO NA WEB:
	//PARA DATA E HORA:
	time (&temp);
	data = localtime(&temp);
	printf(" ==============================================================\n");
	printf(" DATA: %d/%d/%d \t  ", data->tm_mday, data->tm_mon+1, data->tm_year+1900);
	printf(" HORA: %d:%d:%d \n", data->tm_hour ,data->tm_min ,data->tm_sec);
	printf(" USUARIO ATIVO: %s \n",pont);  
	printf(" ==============================================================\n");
}
   

	void cadastro_prod()
{
	system("cls");

	static int j1=1;
 do{

	dataehora();
	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t2.CADASTRO de PRODUTO \n");
	printf("==============================================================\n");
	printf(" descriçao: ");
	fflush(stdin);
	gets(cad_prod[j1].dis);
	printf("\n==============================================================\n");

	printf(" CODIGO INTERNO: "); scanf("%ld",&cad_prod[j1].cod_interno[j1]);
	printf("\n==============================================================\n");

	printf(" REFERENCIA: "); scanf("%ld",&cad_prod[j1].ref_cod[j1]);
	printf("\n==============================================================\n");

	printf(" QUANTIDADE POR TAMANHO:P: M: G:"); 
	scanf("%d",&cad_prod[j1].quant_P[j1]);
	 scanf("%d",&cad_prod[j1].quant_M[j1]);
	  scanf("%d",&cad_prod[j1].quant_G[j1]);
	printf("\n==============================================================\n");

	printf(" VALOR de CUSTO: "); scanf("%f",&cad_prod[j1].custo[j1]);
	printf("\n==============================================================\n");

	printf(" PREÇO:R$: "); scanf("%f",&cad_prod[j1].valor_prod[j1]);
	printf("\n==============================================================\n");

	printf("Cadastro salvo...");
		j1++;

	printf("digite 1 para continuar ou 2 para Sair"); scanf("%d",&op);

	}while(op != 2);
}


	void list_cli()
{
  system("cls");
  
  int i=1;
	dataehora();
	printf("LISTA DE CLIENTES:\n");

  for(i=1;i<P;i++){
   if(cad_cli[i].idade[i] > 0){	
	printf("|Nome do Cliente:%s |\t",cad_cli[i].nome_cli);
	  printf("|Idade: %d|\n",cad_cli[i].idade[i]);
    	printf("|CPF:%lld|\t",cad_cli[i].cpf[i]);
	     printf("|RG:%lld|\n",cad_cli[i].rg[i]);
	      printf("|Tel:%s|\n",cad_cli[i].tel);
           printf("|Endereço:%s |N°:%d \n", cad_cli[i].rua, cad_cli[i].num[i]);
            printf("|CEP:%d \n",cad_cli[i].cep[i]);
	         printf("|E-mail:%s|\n\n",cad_cli[i].email);
   }else{
   	
   	break; 
   }
  }
}

	void ESTOQUE()
{
	int n;
	float valor[P];
	system("cls");
    static int j;


	dataehora();
    printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t 4.LISTA DE PRODUTOS:\n");

    for(j=1;j<P;j++){

	n = (cad_prod[j].quant_P[j] + cad_prod[j].quant_M[j] + cad_prod[j].quant_G[j]);

	valor[j] = (n * cad_prod[j].custo[j]);
	if(cad_prod[j].ref_cod[j] > 0){
	  printf("||DISCRIÇÃO:%s \n",cad_prod[j].dis);
    	printf("||CODIGO FABRICANTE:%ld \t REFERENCIA:%ld \n",cad_prod[j].cod_interno[j], cad_prod[j].ref_cod[j]);
     	 printf("||TAMANHOS:P:%d|M:%d|G:%d \n",cad_prod[j].quant_P[j], cad_prod[j].quant_M[j], cad_prod[j].quant_G[j]);
	      printf("||TOTAL DO ESTOQUE: %d\n",n);
        	printf("||CUSTO UNITARIO: %.2f\n",cad_prod[j].custo[j]);
             printf("||CUSTO TOTAL:R$:%.2lf \n",valor[j]);
  	          printf("||PREÇO:R$:%.2f||\n",cad_prod[j].valor_prod[j]);
    }else{
     break;
      }
   }
}

	void pre_vendas()//AS PRE-VENDAS SÃO AS VENDAS DA LOJA FISICA 
{
	system("cls");
	dataehora();
  int ops,j ,pc ,m1[P],qtd;
  float valor[P],troco;

   static int l=1;
 do{
	printf("OPÇAO ESCOLHIDA: \t\t  "); printf("6.PRE-VENDA \n");

	printf("DIGITE A REFERENCIA: "); scanf("%d",&op);
		if(cad_prod[l].ref_cod[l] == op){
    printf("ID:%d",rand() % 1000); //numero aleatorio para simular, um numero de venda
	 
    printf("|%d|DISCRIÇÃO: %s \n",l,cad_prod[l].dis);
    
    printf("%.2f ",cad_prod[l].valor_prod[l]);
    
    printf("TAMANHOS:");
    printf("DIGITE 1 PARA P, 2 PARA M, 3 PARA G: "); scanf("%d",&ops);
     if(ops == 1){
     	printf("QUANTIDADE:");scanf("%d",&qtd);
     	valor[l] = (qtd * cad_prod[l].valor_prod[l]);
     	cad_prod[l].quant_P[l] = (cad_prod[l].quant_P[l] - qtd);
     	
	 }else if(ops == 2){
	 	printf("QUANTIDADE:");scanf("%d",&qtd);
     	valor[l] = (qtd* cad_prod[l].valor_prod[l] );
     	cad_prod[l].quant_M[l] = (cad_prod[l].quant_M[l] - qtd);
     	
	 }else if(ops == 3){
	 	printf("QUANTIDADE:");scanf("%d",&qtd);
     	valor[l] = (qtd * cad_prod[l].valor_prod[l] );
     	cad_prod[l].quant_G[l] = (cad_prod[l].quant_G[l] - qtd);
     }
   
	printf("\n VALOR.R$:%.2f \n",valor[l]);
	
	printf("DESCONTO:%% "); scanf("%d",&m1[l]);//m1 recebe o desconto
    cad_prod[l].des[l] =  valor[l] - (m1[l] * valor[l])/100;
    printf("INTEM ADICIONADO.. \n");
    
    printf("DIGITE 1 PARA ADICIONAR MAIS ITEMS OU 2 PARA FINALIZAR: \n"); scanf("%d",&pc);
    
    printf("\nVALOR PAGO PELO CLIENTE:R$: "); scanf("%f",&troco);
    troco = (troco - cad_prod[l].des[l]);
    
    
	   l++;
   }
   n = (op - n);//retira a quantidade do estoque total
   
   }while( pc != 2);
   
   
   
   
   
  for(j=1;j < P;j++){ 
   if(cad_prod[j].des[j] > 0){

   printf("VENDA FINALIZADA:  \n"); 
   printf("PRODUTO: %s \n",cad_prod[j].dis);
   printf("TROCO DO CLIENTE:R$: %.2f \n",troco);
   printf("DESCONTO:%% %ld  \n",m1[j]);  
   printf("VALOR.R$: %.2lf \n",cad_prod[j].des[j]);
   
   printf("\t OBRIGADO VOLTE SEMPRE!!!\n\n");
   }else{
   	break;
   }
  }
}

	void servico()
{
  system("cls");
  int ops;
  do{

	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t5.SERVIÇOS  \n");
	dataehora();
	printf("\t1.CONSULTAR PEDIDOS\n");
	printf("\t2.CADASTRO DE FORNECEDOR\n");
	printf("\t3.CONSULTAR CADASTRO DA EMPRESA\n");
	printf("\t4.FRETE\n");
	printf("\t5.CADASTRO DE FUNCIONARIO \n");
	printf("\t6.LISTA DE FUNCIONARIO\n");
	printf("\t7.VOLTAR AO INICIO \n");
	printf("\tDIGITE SUA OPÇAO: ");scanf("%d",&ops);

  switch(ops){
	case 1:
	consulta();
	break;
	
	case 2:
	cadastro_fornedor();
    break;
    
    case 3:
	consulta_cad_empresa();
	break;
	
	case 4:
		calculo_frete();
	break;	
	
	case 5:
		cadastro_funcionario();
	break;
	
	case 6:
	    list_fun();
	break;
	
	case 7:
	break;
	
	default :
    printf("OPÇÃO DIGITA INVALIDA !!!\n\n");
   }
   
  }while(ops != 7);
}

		//ESSA FUNÇAO RECEBE OS PEDIDOS FEITOS ONLYNE // ELA CRIA UMA SIMULAÇAO DE UM PEDIDO FEITO COM PRODUTOS CADASTRADOS
  void consulta()//consulta os pedidos
  {  
  system("cls");
 
  dataehora();
  do{
 
  printf("DIGITE O CPF CLIENTE:"); scanf("%lld",&op);
    if(cad_cli[1].cpf[1] == op){
  printf("PEDIDO: %d \n", rand() % 100);
  printf("NOME:%s \t\t CPF:%lld \n",cad_cli[1].nome_cli,cad_cli[1].cpf[1]);
  printf("PRODUTO:%s \t\t REFERENCIA:%d \n",cad_prod[1].dis,cad_prod[1].ref_cod[1]);
  printf("ENDEREÇO:%s N°:%d \n",cad_cli[1].rua, cad_cli[1].num[1]);
  printf("QUANTIDA:%d \t\t VALOR:R$:%.2f\n",cad_prod[1].quant_P[1],cad_prod[1].valor_prod[1]);
  printf("PEDIDO A SER PROCESSADO!!!\n");
 
    }else if(cad_cli[2].cpf[2] == op){
    system("cls");
  printf("PEDIDO: %d \n", rand() % 100);
  printf("NOME:%s \t\t CPF:%lld \n",cad_cli[2].nome_cli,cad_cli[2].cpf[2]);
  printf("PRODUTO:%s \t\t REFERENCIA:%d \n",cad_prod[2].dis,cad_prod[2].ref_cod[2]);
  printf("ENDEREÇO:%s N°:%d \n",cad_cli[2].rua,  cad_cli[2].num[2]);
  printf("QUANTIDA:%d \t\t VALOR:R$:%.2f\n",cad_prod[2].quant_P[2],cad_prod[2].valor_prod[2]);
  printf("PEDIDO A SER PROCESSADO!!!\n");
 
   }else if(cad_cli[3].cpf[3] == op){
    system("cls");
  printf("PEDIDO: %d \n", rand() % 100);
  printf("NOME:%s \t\t CPF:%lld \n",cad_cli[3].nome_cli,cad_cli[3].cpf[3]);
  printf("PRODUTO:%s \t\t REFERENCIA:%d \n",cad_prod[3].dis,cad_prod[3].ref_cod[3]);
  printf("ENDEREÇO:%s N°:%d \n",cad_cli[3].rua,cad_cli[3].num[3]);
  printf("QUANTIDA:%d \t\t VALOR:R$:%.2f\n",cad_prod[3].quant_P[3],cad_prod[3].valor_prod[3]);
  printf("PEDIDO A SER PROCESSADO!!!\n");
 
   }else if(cad_cli[4].cpf[4] == op){
    system("cls");
  printf("PEDIDO: %d \n", rand() % 100);
  printf("NOME:%s \t\t CPF:%lld \n",cad_cli[4].nome_cli,cad_cli[4].cpf[4]);
  printf("PRODUTO:%s \t\t REFERENCIA:%d \n",cad_prod[4].dis,cad_prod[4].ref_cod[4]);
  printf("ENDEREÇO:%s N°:%d \n",cad_cli[4].rua, cad_cli[4].num[4]);
  printf("QUANTIDA:%d \t\t VALOR:R$:%.2f\n",cad_prod[4].quant_P[4],cad_prod[4].valor_prod[4]);
  printf("PEDIDO A SER PROCESSADO!!!\n");
 
   }else if(cad_cli[5].cpf[5] == op){
    system("cls");
  printf("PEDIDO: %d \n", rand() % 100);
  printf("NOME:%s \t\t CPF:%lld \n",cad_cli[5].nome_cli,cad_cli[5].cpf[5]);
  printf("PRODUTO:%s \t\t REFERENCIA:%d \n",cad_prod[5].dis,cad_prod[5].ref_cod[5]);
  printf("ENDEREÇO:%s N°:%d \n",cad_cli[5].rua, cad_cli[5].num[5]);
  printf("QUANTIDA:%d \t\t VALOR:R$:%.2f\n",cad_prod[5].quant_P[5],cad_prod[5].valor_prod[5]);
  printf("PEDIDO A SER PROCESSADO!!!\n");
   }
    printf("DIGITE 1 PARA NOVA CONSULTA 2 PARA SAIR: "); scanf("%d",&op);
  }while(op != 2);
}
   
   
	void cadastro_fornedor()
{
	system("cls");
	static int id=1;
 
  do{

	dataehora();
	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t2.CADASTRO de FORNECEDOR \n");
	printf(" ==============================================================\n");
	printf(" RAZÃO SOCIAL: ");
	fflush(stdin);
	gets(empresa[id].nome);
	printf("\n==============================================================\n");

	printf(" CNPJ: "); scanf("%lli",&empresa[id].cnpj[id]);
	printf("\n==============================================================\n");

	printf(" TELEFONE: "); scanf("%s",&empresa[id].fon[id]);
	printf("\n==============================================================\n");

	printf(" INSCRIÇAO ESTADUAL: "); scanf("%lli",&empresa[id].in_estadual[id]);
	printf("\n==============================================================\n");

	printf(" INSCRIÇAO MUNICIPAL: "); scanf("%lli",&empresa[id].in_municipal[id]);
	printf("\n==============================================================\n");

	printf(" ENDEREÇO: ");
	fflush(stdin);
	gets(empresa[id].endereco); 
	printf("\tN°:");
	scanf("%d",&empresa[id].num[id]);
	printf("\n==============================================================\n");

	printf(" E-MAIL: ");
	fflush(stdin);
	gets(empresa[id].e_mail);  
	printf("\n==============================================================\n");


	printf("Cadastro salvo...\n");
 	  id++;
	printf("digite 1 para continuar ou 2 para Sair\t"); scanf("%d",&op);

  }while(op != 2);
}   


	void consulta_cad_empresa()
{
	 system("cls");
	int n1;
	dataehora();
	static int i=1;
 	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t3.CONSULTA de EMPRESA \n");
 do{
 	printf("DIGITE O CNPJ:"); scanf("%d",&n1);
    printf("\n==============================================================\n");
    if( empresa[i].cnpj[i] == n1){
    	printf("RAZAO SOCIAL: %s\t",empresa[i].nome); printf("CNJP: %lld\n",empresa[i].cnpj[i]);
    	printf("TELEFONE: %ld\t",empresa[i].fon[i]); printf("E-MAIL: %s\n",empresa[i].e_mail);
    	printf("INSCRIÇAO MUNICIPAL: %lld\n",empresa[i].in_municipal[i]);
		printf("INSCRIÇAO ESTADUAL: %lld\t\n",empresa[i].in_estadual[i]);
		printf("ENDEREÇO: %s ",empresa[i].endereco); printf("N°: %d\n",empresa[i].num[i]);  
	}else{
		printf("CNPJ NAO LOCALIZADO OU EMPRESA NAO CADASTRADA.\n");
	break;
	}
 	printf("digite 1 para continuar ou 2 para Sair\t\n"); scanf("%d",&op);
 	i++;
 	
    }while(op !=2);		
}

void calculo_frete(){
	system("cls");
	int j=1;
	float taxa[P];
	printf("\t  OPÇÃO ESCOLHIDA:"); printf("\t4.FRETE\n");
	do{
    printf("SELECIONE A REGIAO:\n");
      printf("\t1.NORTE \n");
       printf("\t2.NORDESTE \n");
        printf("\t3.CENTRO-OESTE \n");
         printf("\t4.SUDESTE \n");
          printf("\t5.SUL \n");
          
     printf("DIGITE A OPÇÃO: "); scanf("%d",&op);
	      switch(op){
	      	case 1:
	      		
	      	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t1.NORTE \n");
	      	printf("DIGITE AS MEDIDAS DO PACOTE EM CENTIMETROS:\n");
	      	printf("ALTURA:CM: ");scanf("%f",&frete[j].alt[j]);
	      	printf("\nLARGURA:CM: ");scanf("%f",&frete[j].lar[j]);
	      	printf("\nCOMPRIMENTO:CM: ");scanf("%f",&frete[j].compr[j]);
	      	printf("\n DESEJA A ADCIONAR O PESO: \n");
	      	
			  printf("DIGITE 1 PARA SIM , 2 PARA NAO "); scanf("%i",&op);
			  if(op == 1){
			  printf("\n PESO:KG: ");scanf("%f",&frete[j].peso[j]);
			  
		      }else if(op == 2){
		      	
		      	frete[j].peso[j] = (frete[j].compr[j] * frete[j].lar[j] * frete[j].alt[j])/6.000; //6.000  coeficiente definido conforme padrões internacionais.
			  }
	      	
	      	
	      		frete[j].valor[j] =  (frete[j].peso[j] * 4000);//4.000 KM VALOR REFERENTE DISTANCIA ENTRE SAO PAULO E MANAUS EM KM;
	      		printf("\n PESO:KG: %.3f \n",frete[j].peso[j]);
	      		printf("O VALOR DO FRETE PARA REGIÃO NORTE. R$: %.2f \n",frete[j].valor[j]);
			  
	      	break;
	      	
	      		case 2:
	      	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t1.NORDESTE \n");
	      	printf("DIGITE AS MEDIDAS DO PACOTE EM CENTIMETROS:\n");
	      	printf("ALTURA:CM: ");scanf("%f",&frete[j].alt[j]);
	      	printf("\nLARGURA:CM: ");scanf("%f",&frete[j].lar[j]);
	      	printf("\nCOMPRIMENTO:CM: ");scanf("%f",&frete[j].compr[j]);
	      	printf("\n DESEJA A ADCIONAR O PESO: \n");
			  printf("DIGITE 1 PARA SIM , 2 PARA NAO "); scanf("%i",&op);
			  if(op == 1){
			  printf("\n PESO:KG: ");scanf("%f",&frete[j].peso[j]);
			  
		       }else if(op == 2){
		        	frete[j].peso[j] = (frete[j].compr[j] * frete[j].lar[j] * frete[j].alt[j])/6.000; //6.000  coeficiente definido conforme padrões internacionais.
			   }
	      		      	
	      		frete[j].valor[j] =  (frete[j].peso[j] * 2500);//2.500 KM VALOR REFERENTE DISTANCIA ENTRE SAO PAULO E PARAIBA EM KM;
	      		printf("\n PESO:KG: %.3f \n",frete[j].peso[j]);
	      		printf("O VALOR DO FRETE PARA REGIÃO NORDESTE. R$: %.2f \n",frete[j].valor[j]);
			  
	      	break;
	      	
	      		case 3:
	      	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t1.CENTRO OESTE \n");
	      	printf("DIGITE AS MEDIDAS DO PACOTE EM CENTIMETROS:\n");
	      	printf("ALTURA:CM: ");scanf("%f",&frete[j].alt[j]);
	      	printf("\nLARGURA:CM: ");scanf("%f",&frete[j].lar[j]);
	      	printf("\nCOMPRIMENTO:CM: ");scanf("%f",&frete[j].compr[j]);
	      	printf("\n DESEJA A ADCIONAR O PESO: \n");
			  printf("DIGITE 1 PARA SIM , 2 PARA NAO "); scanf("%i",&op);
			   if(op == 1){
			     printf("\n PESO:KG: ");scanf("%f",&frete[j].peso[j]);
		        }else if(op == 2){
		        frete[j].peso[j] = (frete[j].compr[j] * frete[j].lar[j] * frete[j].alt[j])/6.000; //6.000  coeficiente definido conforme padrões internacionais.
			    }
	      	
	      		frete[j].valor[j] =  (frete[j].peso[j] * 1500);//1.500 KM VALOR REFERENTE DISTANCIA ENTRE SAO PAULO E CUIABA EM KM;
	      		printf("\n PESO:KG: %.3f \n",frete[j].peso[j]);
	      		printf("O VALOR DO FRETE PARA REGIÃO CENTRO OESTE. R$: %.2f \n",frete[j].valor[j]);
			  
	      	break;
	      	
	      		case 4:
	      	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t4.SULDESTE \n");
	      	printf("DIGITE AS MEDIDAS DO PACOTE EM CENTIMETROS:\n");
	      	printf("ALTURA:CM: ");scanf("%f",&frete[j].alt[j]);
	      	printf("\nLARGURA:CM: ");scanf("%f",&frete[j].lar[j]);
	      	printf("\nCOMPRIMENTO:CM: ");scanf("%f",&frete[j].compr[j]);
	      	printf("\n DESEJA A ADCIONAR O PESO: \n");
			  printf("DIGITE 1 PARA SIM , 2 PARA NAO "); scanf("%i",&op);
			   if(op == 1){
			     printf("\n PESO:KG: ");scanf("%f",&frete[j].peso[j]);
			     
		        }else if(op == 2){
		        frete[j].peso[j] = (frete[j].compr[j] * frete[j].lar[j] * frete[j].alt[j])/6.000; //6.000  coeficiente definido conforme padrões internacionais.	
			    }
	      	
	      		frete[j].valor[j] =  (frete[j].peso[j] * 600);//600 KM VALOR REFERENTE DISTANCIA ENTRE SAO PAULO E BELO HORIZONTE EM KM;
	      		printf("\n PESO:KG: %.3f \n",frete[j].peso[j]);
	      		printf("O VALOR DO FRETE PARA REGIÃO SULDESTE. R$: %.2f \n",frete[j].valor[j]);
			  
	      	break;
	      	
	      		case 5:
	      	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t1.SUL \n");
	      	printf("DIGITE AS MEDIDAS DO PACOTE EM CENTIMETROS:\n");
	      	printf("ALTURA:CM: ");scanf("%f",&frete[j].alt[j]);
	      	printf("\nLARGURA:CM: ");scanf("%f",&frete[j].lar[j]);
	      	printf("\nCOMPRIMENTO:CM: ");scanf("%f",&frete[j].compr[j]);
	      	
	      	printf("\n DESEJA A ADCIONAR O PESO: \n");
			  printf("DIGITE 1 PARA SIM , 2 PARA NAO "); scanf("%i",&op);
			   if(op == 1){
			     printf("\n PESO:KG: ");scanf("%f",&frete[j].peso[j]);
			     
		        }else if(op == 2){
		        frete[j].peso[j] = (frete[j].compr[j] * frete[j].lar[j] * frete[j].alt[j])/6.000; //6.000  coeficiente definido conforme padrões internacionais.
			    }
	      
	      		frete[j].valor[j] =  (frete[j].peso[j] * 1200);//1.200 KM VALOR REFERENTE DISTANCIA ENTRE SAO PAULO E PORTO ALEGRE EM KM; 
	      		printf("\n PESO:KG: %.3f \n",frete[j].peso[j]);
	      		printf("O VALOR DO FRETE PARA REGIÃO SUL. R$: %.2f \n",frete[j].valor[j]);
			  
	      	break;
	      	
	      	
	      	
		  }
		  j++;
	 printf("digite 1 para continuar ou 2 para Sair\t\n"); scanf("%d",&op);
		  
      }while(op != 2);	
	
}
	
void  cadastro_funcionario()
 {
 	system("cls");
 	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t5.CADASTRO DE FUNCIONARIO \n");
 	 int f=1;
 	
 	do{
 	printf(" ==============================================================\n");
	 printf(" NOME DO FUNCIONARIO: ");
    	fflush(stdin);//limpa o teclado 
        	gets(cad_fun[f].nome_fun);//gets lÊ ate que o usuario aperte o enter
	printf("\n==============================================================\n");

	printf(" DATA DE NASCIMENTO: "); 
      scanf("%i",&cad_fun[f].dt_dia[f]); 
	    scanf("%i",&cad_fun[f].dt_mes[f]); 
	     scanf("%i",&cad_fun[f].dt_ano[f]);
	printf("\n==============================================================\n");

	 printf(" CPF: "); scanf("%lli",&cad_fun[f].cpf[f]);//ll para indicar que  numero interio e grande
	printf("\n==============================================================\n");

	 printf(" RG: "); scanf("%lli",&cad_fun[f].rg[f]);//ll para indicar que  numero interio e grande
	printf("\n==============================================================\n");
	
	 printf(" TELEFONE: "); scanf("%i",&cad_fun[f].tel[f]);
	printf("\n==============================================================\n");

	printf(" ENDEREÇO: ");
	  fflush(stdin);//limpa o teclado
	    gets(cad_fun[f].rua);
        	printf("\tN°:");
            	scanf("%d",&cad_fun[f].num[f]);
	printf("\n==============================================================\n");
	
	printf("\tCARGO: "); 
	  fflush(stdin);
    	gets(cad_fun[f].cargo);
	printf("\n==============================================================\n");
	
	printf("HORARIO DE SERVIÇO: \n"); 
    	printf("\t ENTRADA : "); scanf("%i",&cad_fun[f].hr_ent[f]);
	    	printf("\t SAIDA : "); scanf("%i",&cad_fun[f].hr_sai[f]);
	printf("\n==============================================================\n");
	
	printf("SALARIO: "); scanf("%f",&cad_fun[f].salario[f]);
	
	printf("Cadastro salvo...\n");
	
	printf("digite 1 para continuar ou 2 para Sair\t\n"); scanf("%d",&op);
  		 f++;
  		 
  		 
	 }while( op != 2);
 	
	
 }

void list_fun()
{
	system("cls");
 	int f=1;
	printf("\t  OPÇÃO ESCOLHIDA:");  printf("\t6.LISTA DE FUNCIONARIO \n");
	for(f=1;f<P;f++){
		if( cad_fun[f].cpf[f] > 0){
		printf("NOME DO FUNCIONARIO: %s \t",cad_fun[f].nome_fun);
		 printf("DATA de NASCIMENTO: %i/%i/%i \n",cad_fun[f].dt_dia[f], cad_fun[f].dt_mes[f], cad_fun[f].dt_ano[f]);
		  printf("CPF: %lli \t",cad_fun[f].cpf[f]); printf("RG: %lli \n",cad_fun[f].rg[f]);
		   printf("TELEFONE: %li \n",cad_fun[f].tel[f]); 
		    printf("ENDEREÇO: %s N°%li\n",cad_fun[f].rua, cad_fun[f].num[f]);
		     printf("CARGO: %s\t",cad_fun[f].cargo);
			  printf("HORARIO DE SERVIÇO:\n");
			  printf("ENTRADA: %i:00 & SAIDA:%i:00 \n",cad_fun[f].hr_ent[f], cad_fun[f].hr_sai[f]);
			   printf("SALARIO R$: %.2f\n",cad_fun[f].salario[f]);
		}else if(cad_fun[f].cpf[f] == 0){
			printf("NAO FORAM ENCONTRADO MAIS CADASTROS !!!\n");
			break;
		}
	
	}
		f++;
}



