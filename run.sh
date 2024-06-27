#!/bin/bash

# Defina o PID do servidor
SERVER_PID=3438
MESSAGE="Teste do diabo"

# Verifique se o servidor está em execução
if ! ps -p $SERVER_PID > /dev/null; then
  echo "O servidor com PID $SERVER_PID não está em execução. Por favor, inicie o servidor primeiro."
  exit 1
fi

# Execute o cliente 20 vezes
for i in $(seq 1 20); do
  echo "Executando cliente $i..."
  ./clt $SERVER_PID "$MESSAGE $i" &
  sleep 1 # Pequena pausa para evitar sobrecarga no servidor
done

# Aguarde a conclusão de todos os clientes
wait

echo "Todos os clientes foram executados."

