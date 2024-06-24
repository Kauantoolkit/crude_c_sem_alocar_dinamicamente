@echo off
echo Compilando o programa...
gcc main.c produtos.c servicos.c animal.c -o main -I.

echo.
echo Executando o programa...
.\main

echo.
echo Programa executado com sucesso!
pause
