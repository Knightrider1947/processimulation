#include "list.h"
#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>

#define max_char_msg 100
int pid_counter = 0;
enum ProcessState {
    READY,
    RUNNING,
    BLOCKED,
};
typedef struct Process {
    int pid;
    int priority;
    int state;
    List* messages;
} Process;

typedef struct semaphore {
    int value;
    List* waiting;
} semaphore;

List* ready_queue[3];
List* send_queue_waiting;
List* receive_queue_waiting;
semaphore* semaphores[5];

void init()
{
    ready_queue[0] = List_create();
    ready_queue[1] = List_create();
    ready_queue[2] = List_create();
    send_queue_waiting = List_create();
    receive_queue_waiting = List_create();
    for (int i = 0; i < 5; i++)
    {
        semaphores[i] = malloc(sizeof(semaphore));
        semaphores[i]->value = 0;
        semaphores[i]->waiting = List_create();
    }
}
int createprocess(int priotity) {
        
    Process* new_process = malloc(sizeof(Process));
    new_process->pid = pid_counter;
    pid_counter++;
    new_process->priority = priotity;
    new_process->state = READY;
    if (priotity == 0) {
        List_append(ready_queue[0], new_process);      
    } else if (priotity == 1) {
        List_append(ready_queue[1], new_process);
    } else if (priotity == 2) {
        List_append(ready_queue[2], new_process);
    }
    printf("Process created\n", new_process->pid);
    return new_process->pid;
}
void fork()
{
    
}