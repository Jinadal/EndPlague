export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:lib/
valgrind --tool=memcheck --leak-check=full ./bin/Ejecutable