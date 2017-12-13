//
//  main.c
//  FindContent
//
//  Created by Алексей Баринов on 07.12.2017.
//  Copyright © 2017 Era Company. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    FILE *fp;
    
    char tmp[1024];             /* Размер может отличаться */
    char *split;
    char *substring;
    
    int string = 1;
    int position = 0;
    int found = 0;
    int word = 0;
    
    /* Проверяем кол-во введённых аргументов*/
    if(argc < 3 || argc > 3){
        printf("Ошибка ввода\n\n");
        exit(1);
    }
    
    /* Ищем файл */
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("Файл не найден \n\n");
        return(0);
    }
    
    while(fgets(tmp, 1024, fp) != NULL){
        /* Разделяем строки пробелами */
        split = strtok (tmp, " ");
        word = 0;
        
        
        while((split != NULL)){
            substring = strstr(split, argv[2]);
            if(substring != NULL){
                position = (int) ((strlen(tmp) - strlen(substring)) + (word * (strlen(substring)+1)));
                printf("%4d:%4d %s\n", string, position, argv[2]);
                found = 1;
            }
            
            split = strtok(NULL, " ");
            word++;
        }
        
        string++;
    }
    
    /* Ничего не найденр */
    if(!found){
        printf("Нет совпадений\n\n");
    }
    
    /* Закрыть файл*/
    if(fp){
        fclose(fp);
    }
    
    return(0);
}
