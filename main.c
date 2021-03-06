#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    FILE *fp;
    
    char tmp[1024];  //The size may be different
    char *split;
    char *substring;
    
    int string = 1;
    int position = 0;
    int found = 0;
    int word = 0;
    
    //Check number of input arguments
    if(argc < 3 || argc > 3){
        printf("Input error\n");
        exit(1);
    }
    
    //Looking for file
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("File not found\n");
        return(0);
    }
    
    while(fgets(tmp, 1024, fp) != NULL){
        //Share the string with spaces
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
    
    //Nothing found
    if(!found){
        printf("No matches\n\n");
    }
    
    //Close the file
    if(fp){
        fclose(fp);
    }
    
    return(0);
}
