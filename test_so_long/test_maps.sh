#!/bin/bash

MAP_DIR="./maps"
BIN="./so_long"

if [ ! -f "$BIN" ]; then
	echo "🚨 Erro: binário '$BIN' não encontrado. Compile com 'make' primeiro."
	exit 1
fi

if [ ! -d "$MAP_DIR" ]; then
	echo "🚨 Erro: diretório de mapas '$MAP_DIR' não encontrado."
	exit 1
fi

echo "🔍 Iniciando testes com mapas em $MAP_DIR..."
echo "---------------------------------------------"

for map in "$MAP_DIR"/*.ber; do
	if [ -f "$map" ]; then
		echo -n "🧪 Testando $(basename "$map")... "
		$BIN "$map" > /dev/null 2>&1
		if [ $? -eq 0 ]; then
			echo "✅ PASSED"
		else
			echo "❌ FAILED"
		fi
	fi
done

echo "---------------------------------------------"
echo "✔️  Testes finalizados."
