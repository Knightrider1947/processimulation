#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




int main()
{
    char input[1];
    while(1)
    {
        printf("Enter a command: ");
        scanf("%s", input);
        switch (input[0])
        {
        case 'C':
            int priority;
            printf("Enter the priority of the process: ");
            scanf("%d", &priority);
            createprocess(priority);
            break;
        case 'F':
            fork();
            break;
        case 'K':
            int pid;
            printf("Enter the pid of the process: ");
            scanf("%d", &pid);
            kill(pid);
            break;
        case 'E':
            exit();
            break;
        case 'Q':
            quantum();
            break;
        case 'S':
            int pid;
            char msg[100];
            printf("Enter the pid of the process: ");
            scanf("%d", &pid);
            printf("Enter the message: ");
            scanf("%s", msg);
            send(pid, msg);
            break;
        case 'R':
            receive();
            break;
        case 'Y':
            int pid;
            char msg[100];
            printf("Enter the pid of the process: ");
            scanf("%d", &pid);
            printf("Enter the message: ");
            scanf("%s", msg);
            reply(pid, msg);
            break;
        case 'N':  
            int sid;
            int value;
            printf("Enter the sid of the semaphore: ");
            scanf("%d", &sid);
            printf("Enter the value of the semaphore: ");
            scanf("%d", &value);
            newSemaphore(sid, value);
            break;
        case 'P':
            int sid;
            printf("Enter the sid of the semaphore: ");
            scanf("%d", &sid);
            semaphoreP(sid);
            break;
        case 'V':
            int sid;
            printf("Enter the sid of the semaphore: ");
            scanf("%d", &sid);
            semaphoreV(sid);
            break;
        case 'I':
            int pid;
            printf("Enter the pid of the process: ");
            scanf("%d", &pid);
            procinfo(pid);
            break;
        case 'T':
            totalinfo();
            break;
        case 'X':
            init();
            break;    
        default:
            
            break;
        }

    }
}