cmake_minimum_required(VERSION 3.0.0)
project(trabalho1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(trabalho1 main.c arquivos.c funcoes-fornecidas/fornecido.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
