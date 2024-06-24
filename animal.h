#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <stdio.h> 

typedef struct {
    char nome[20];
    float peso;
    char dono[50];
} Animal;

extern Animal animais[50];
extern int contador_de_animais;

void cadastro_animal();
void listar_animais();
void editar_animal();
void excluir_animal();





#endif // ANIMAL_H_INCLUDED
