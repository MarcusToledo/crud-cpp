#include <cstring>
#include <iostream>
#include <mysql/mysql.h>
#include <string>

int main(int argc, char *argv[]) {
  MYSQL *connect =
      mysql_init(NULL); // mysql_init valida a inicialização do banco.

  if (!connect) {
    std::cout << "[ERRO] MYSQL não foi inicializado!" << std::endl;
    return 1;
  }

  connect =
      mysql_real_connect(connect, "127.0.0.1", "root", "root", "cpp", 3325,
                         NULL, 0); // Method que retorna um objeto MYSQL caso
                                   // consiga se conectar ao banco.

  try {

    if (!connect) {
      throw connect;
      return 1;
    }

    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::string nome, email;
    std::string insert_query = {};

    // std::cout << "Informe o nome: ";
    // std::getline( std::cin, nome);

    // std::cout << "Informe o email: ";
    // std::getline( std::cin, email);

    // Passando os dados via arg.

    if (argc > 2) {
      nome = argv[1];
      email = argv[2];
    } else {
      std::cout << "Use: " << argv[0] << " '[nome]' [email]" << std::endl;
      return 1;
    }

    insert_query =
        "INSERT INTO crudcpp VALUES(NULL, '" + nome + "', '" + email + "' )";

    bool query_state =
        mysql_query(connect, insert_query.c_str()); // Executa a query passada

    if (!query_state) {
      std::cout << "Dados inseridos com sucesso!" << std::endl;
    } else {
      std::cout << "[ERRO] Erro ao inserir os dados:" << mysql_error(connect)
                << std::endl;
    }

    mysql_close(connect); // Finaliza a conexão com o bd.
    return 0;

  } catch (const std::exception &) {
    std::cout << "[ERRO] Falha ao conectar." << std::endl;
  }
}
