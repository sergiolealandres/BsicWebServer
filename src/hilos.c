#include "../includes/procesar.h"
#include "../includes/hilos.h"
#include "../includes/lib_socketlib.h"

void * thread_main(void *arg){
    int connfd;
    Request *request=request_create();
    socklen_t clilen;
    struct sockaddr *cliaddr;
    cliaddr = malloc(addrlen);
    //printf("thread %d starting\n", (int) arg);
    for ( ; ; ){
        clilen = addrlen;
        printf("hoola222\n");
        pthread_mutex_lock(&mlock);
        connfd = accept_connection(listenfd);
        printf("in mutex\n");
        pthread_mutex_unlock(&mlock);
        tptr[*((int*) arg)].thread_count++;
        parsear_conexion(connfd,request);
        printf("hoola2\n");
    
    //launch_service(connfd);
    procesar_conexion(connfd);
    close(connfd);
    }
/* process request */
}
void thread_make(int i){

    pthread_create(&tptr[i].thread_tid, NULL, &thread_main, (void *) &i); 
    return;
}
