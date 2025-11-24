#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    int n;
    printf("Inserisci il numero che rappresenta il numero di processi da creare\n");
    scanf("%d",&n);
    for (int i = 1; i<=n; i++) {
        pid_t ritorno = fork();
        if (ritorno == -1) {
            printf("Errore fork\n");
            exit(-1);
        }
        if (ritorno == 0) {
            printf("Processo figlio numero %d\n",i);
            printf("PID figlio: %d\n",getpid());
            printf("PID di mio padre: %d\n",getppid());
            //exit(0);
        }
        else {
            wait(NULL);
            //printf("Processo padre numero: %d\n",i);
            //printf("PID padre: %d\n",getpid());
            //printf("PID di mio figlio: %d\n",ritorno);
            exit(0);
        }
    }
    return 0;
}