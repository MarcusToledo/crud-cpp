#include <iostream>
#include <mysql/mysql.h>

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

    mysql_query(connect, "SELECT * FROM crudcpp"); // Executa a query passada
    res_set = mysql_store_result(connect); // Armazena o resusltado da query no tipo apropriado MYSQL_RES.
    unsigned int numrowns = mysql_num_rows(res_set); // Armazena o número de rows retornadas no resultado em questão. Também pode ser utilizado mysql_affected_rows() para retonar o número de linhas afetadas pela query.

    while ( ( row = mysql_fetch_row(res_set ) ) != NULL) { // mysql_fetch_row retorna a proxima linha de um result_set (MYSQL_RES).
      std::cout << row[0] << " | " << row[1] << " | " << row[2] << std::endl; // Os campos de uma row são tratadas como um vetor
    }

    mysql_close(connect); // Finaliza a conexão com o bd.
    return 0;

  } catch (const std::exception &) {
    std::cout << "[ERRO] Falha ao conectar." << std::endl;
  }
}
