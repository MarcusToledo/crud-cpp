#include <iostream>
#include <mysql/mysql.h>


int main (int argc, char *argv[])
{
  MYSQL* connect = mysql_init(NULL); // mysql_init valida a inicialização do banco.

  if (!connect) {
    std::cout << "[ERRO] MYSQL não foi inicializado!" << std::endl;
    return 1;  
  }
  
  connect = mysql_real_connect( connect, "127.0.0.1", "root", "root", "cpp", 3325, NULL, 0 ); //Method que retorna um objeto MYSQL caso consiga se conectar ao banco.
  if (connect) {
    std::cout << "Conectado com sucesso ao MySQL." << std::endl;
  }else {
  std::cout << "[ERRO] Falha ao conectar ao banco de dados." << std::endl;
  }

  mysql_close( connect ); // Finaliza a conexão com o bd.

  return 0;
}  
