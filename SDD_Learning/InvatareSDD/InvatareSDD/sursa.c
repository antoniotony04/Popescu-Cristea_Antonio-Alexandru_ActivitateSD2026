//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina {
//    int id;
//    int nrUsi;
//    float pret;
//    char* model;
//    char* numeSofer;
//    unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//struct Nod {
//    Masina info;
//    struct Nod* st;
//    struct Nod* dr;
//};
//typedef struct Nod Nod;
//
//Masina citireMasinaDinFisier(FILE* f) {
//    char sep[3] = ",\n";
//    char buffer[100];
//    Masina m1;
//    fgets(buffer, 100, f);
//    char* aux;
//    aux = strtok(buffer, sep);
//    m1.id = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    m1.nrUsi = atoi(aux);
//
//    aux = strtok(NULL, sep);
//    m1.pret = atof(aux);
//
//    aux = strtok(NULL, sep);
//    m1.model = malloc(strlen(aux) + 1);
//    strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//    aux = strtok(NULL, sep);
//    m1.numeSofer = malloc(strlen(aux) + 1);
//    strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//    m1.serie = *strtok(NULL, sep);
//
//    return m1;
//}
//
//void afisareMasina(Masina masina) {
//    printf("Id: %d\n", masina.id);
//    printf("Nr. usi : %d\n", masina.nrUsi);
//    printf("Pret: %.2f\n", masina.pret);
//    printf("Model: %s\n", masina.model);
//    printf("Nume sofer: %s\n", masina.numeSofer);
//    printf("Serie: %c\n\n", masina.serie);
//}
//
//
//int maxim(int a, int b) {
//    return (a > b ? a : b);
//}
//
//int calculeazaInaltimeArbore(Nod* rad) {
//    if (rad) {
//        return maxim(calculeazaInaltimeArbore(rad->st), calculeazaInaltimeArbore(rad->dr)) + 1;
//    }
//    return 0;
//}
//
//int calculDiferentaInaltimi(Nod* rad) {
//    if (rad != NULL) {
//        return calculeazaInaltimeArbore(rad->st) - calculeazaInaltimeArbore(rad->dr);
//    }
//    return 0;
//}
//
//void rotireLaStanga(Nod** rad) {
//    Nod* aux = (*rad)->dr;
//    (*rad)->dr = aux->st;
//    aux->st = (*rad);
//    (*rad) = aux;
//}
//
//void rotireLaDreapta(Nod** rad) {
//    Nod* aux = (*rad)->st;
//    (*rad)->st = aux->dr;
//    aux->dr = (*rad);
//    (*rad) = aux;
//}
//
//void adaugaMasinaInArbore(Nod** rad, Masina m1) {
//    if (*rad == NULL) {
//        Nod* nod = malloc(sizeof(Nod));
//        nod->info = m1;
//        nod->st = NULL;
//        nod->dr = NULL;
//        *rad = nod;
//    }
//    else {
//        if (m1.id < (*rad)->info.id) {
//            adaugaMasinaInArbore(&(*rad)->st, m1);
//        }
//        if (m1.id > (*rad)->info.id) {
//            adaugaMasinaInArbore(&(*rad)->dr, m1);
//        }
//    }
//
//    int diferentaInaltimi = calculDiferentaInaltimi(*rad);
//
//    if (diferentaInaltimi == 2) {
//        // Dezeechilibru pe partea stanga
//        if (calculDiferentaInaltimi((*rad)->st) == -1) {
//            rotireLaStanga(&(*rad)->st);
//        }
//        rotireLaDreapta(rad);
//    }
//
//    if (diferentaInaltimi == -2) {
//        // Dezechilibru pe partea dreapta
//        if (calculDiferentaInaltimi((*rad)->dr) == 1) {
//            rotireLaDreapta(&(*rad)->dr);
//        }
//        rotireLaStanga(rad);
//    }
//}
//
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//    Nod* rad = NULL;
//    FILE* f = fopen(numeFisier, "r");
//    while (!feof(f)) {
//        Masina m1 = citireMasinaDinFisier(f);
//        adaugaMasinaInArbore(&rad, m1);
//    }
//    fclose(f);
//    return rad;
//}
//
//void afisarePreordine(Nod* rad) {
//    if (rad) {
//        afisareMasina(rad->info);
//        afisarePreordine(rad->st);
//        afisarePreordine(rad->dr);
//
//    }
//}
//
//void afisareInordine(Nod* rad) {
//    if (rad) {
//        afisareInordine(rad->st);
//        afisareMasina(rad->info);
//        afisareInordine(rad->dr);
//    }
//}
//
//void dezalocareArbore(Nod** rad) {
//    if (*rad) {
//        dezalocareArbore(&(*rad)->st);
//        dezalocareArbore(&(*rad)->dr);
//        printf("Masina cu ID %d se dezalocheaza..\n", (*rad)->info.id);
//        free((*rad)->info.model);
//        free((*rad)->info.numeSofer);
//        free(*rad);
//        *rad = NULL;
//        printf("Dezalocata cu succes!\n");
//    }
//
//}
//
//
//
//
//
//
//int main() {
//    FILE* f = fopen("masini.txt", "r");
//    Nod* rad = citireArboreDeMasiniDinFisier("masini.txt");
//    afisarePreordine(rad);
//    dezalocareArbore(&rad);
//}