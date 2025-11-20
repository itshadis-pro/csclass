// HADI ALMARZOOQ
// CS 212
// PROJECT_2G DUE 11/07/2025

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE* file = fopen(argv[1], "r");
    if(!file){
        fprintf(stderr, "\"%s\" is not a valid file.\n", argv[1]);
        return 1;
    }

    int* counter = malloc(sizeof(int)*argc);
    for (int i = 0; i < argc; i++){
        counter[i] = 0;
    }

    char buffer[51];
    char carry[50] = {0};
    int  carry_len = 0;
    size_t R = fread(buffer, 1, 50, file);

    while (R > 0) {

        buffer[R] = '\0';

        // ---- build work = carry + buffer (so split words are joined) ----
        char work[100];
        size_t N = 0;              // total bytes to scan this round
        for (int i = 0; i < carry_len; i++) work[N++] = carry[i];
        for (size_t i = 0; i < R; i++)       work[N++] = buffer[i];

        // turn delimiters into '\0' in work[]
        for (size_t i = 0; i < N; i++){
            if (work[i] == ' ' || work[i] == ',' || work[i] == '.' || work[i] == '\n'){
                work[i] = '\0';
            }
        }

        int last = (int)(N ? N-1 : 0);

        // compare tokens (same structure, just use work[] instead of buffer[])
        for (int j = 2; j < argc; j++){
            for (int k = 0; k <= last; k++) {

                if (work[k] != '\0' &&
                    strncmp(work + k, argv[j], strlen(argv[j])) == 0){

                    int next = k + (int)strlen(argv[j]);
                    if (next > last || work[next] == '\0') {
                        counter[j]++;
                    }
                }

                while (k <= last && work[k] != '\0'){
                    k++;
                }
            }
        }

        // ---- prepare carry for next chunk if the last token was cut off ----
        if (N > 0 && work[N-1] != '\0') {
            // find start of trailing run (walk back to previous '\0' or start)
            size_t s = N - 1;
            while (s > 0 && work[s-1] != '\0') s--;
            carry_len = 0;
            for (size_t i = s; i < N && carry_len < (int)sizeof(carry); i++){
                carry[carry_len++] = work[i];
            }
        } else {
            carry_len = 0;
        }

        // read next chunk
        R = fread(buffer, 1, 50, file);
    }

    // print result
    for (int j = 2; j < argc; j++) {
        printf("The word \"%s\" occurs %d times.\n", argv[j], counter[j]);
    }

    free(counter);
    fclose(file);
    return 0;
}
