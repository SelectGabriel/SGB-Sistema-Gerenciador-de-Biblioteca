# === Config ===
CXX       := g++
CXXFLAGS  := -std=c++17 -Wall -Wextra -Wpedantic -O2 -MMD -MP
# Inclui SRC e (opcionalmente) subpastas — se você padronizar includes como "classes/Livro.h", etc.
CPPFLAGS := -Isrc -Isrc/classes -Isrc/repositories -Isrc/facades -Isrc/handlers

# Pasta onde estão as fontes (usei "SRC" em MAIÚSCULO, como você disse)
SRC_DIR   := src

# Nome do executável
TARGET    := bin/biblioteca

# Encontra todos os .cpp recursivamente dentro de SRC (ignora build/bin)
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp' ! -path 'build/*' ! -path 'bin/*')
# Converte "SRC/foo/bar.cpp" -> "build/SRC/foo/bar.o"
OBJS := $(patsubst %.cpp,build/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean debug print

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Build com símbolos de debug (-g)
debug: CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -MMD -MP
debug: clean $(TARGET)

# Link final
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@

# Regra genérica de compilação: build/SRC/xxx.o a partir de SRC/xxx.cpp
build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf build bin

# Útil para depurar listas de arquivos encontrados
print:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"

# Inclui dependências geradas pelo -MMD -MP
-include $(DEPS)
