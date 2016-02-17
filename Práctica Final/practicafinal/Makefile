SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
HDRS = $(INC)/Conjunto.h $(INC)/VectorDinamico.h $(INC)/SetConjuntos.h

all: $(BIN)/constructivo


# ************ Compilación de módulos ************
$(BIN)/constructivo: $(OBJ)/constructivo.o $(OBJ)/VectorDinamico.o $(OBJ)/Conjunto.o $(OBJ)/SetConjuntos.o
	$(CXX) $(CPPFLAGS2) $^ -o $@

$(OBJ)/constructivo.o: $(SRC)/constructivo.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/SetConjuntos.o: $(SRC)/SetConjuntos.cpp  $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Conjunto.o: $(SRC)/Conjunto.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/VectorDinamico.o: $(SRC)/VectorDinamico.cpp  $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
