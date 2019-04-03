export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:lib/
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --gen-suppressions=all ./bin/Ejecutable  
#