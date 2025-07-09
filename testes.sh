#!/bin/bash

SERVER_PID=$1

echo "-> ASCII simples"
./client $SERVER_PID "Hello World!"

echo "-> ASCII simples 2"
./client $SERVER_PID "42 Porto"

echo "-> ASCII simples 2"
./client $SERVER_PID "Testando strings curtas"

echo "-> Unicode"
./client $SERVER_PID "Olá 👋"

echo "-> Chinês"
./client $SERVER_PID "你好，世界"

echo "-> Russo"
./client $SERVER_PID "Привет мир"

echo "-> Emojis com texto"
./client $SERVER_PID "Café ☕ com pão 🥖 e queijo 🧀"

echo "-> Emojis longos"
./client $SERVER_PID "😃👍🔥❤️🎉🎯💡"

echo "-> Emojis longos"
./client $SERVER_PID "👋🌍🚀🔥❤️🧠"

echo "-> String vazia"
./client $SERVER_PID ""

echo "-> Stress"
python3 -c 'print("A" * 10000)' | xargs ./client $SERVER_PID

echo "-> PID inválido"
./client 999999 "Deve falhar"
