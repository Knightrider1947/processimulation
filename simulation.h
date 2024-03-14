#ifndef _simulation_h
#define _simulation_h

void createprocess(int priotity);
void fork();
void kill(int pid);
void exit();
void quantum();
void send(int pid, char *msg);
void receive();
void reply(int pid, char *msg);
void newSemaphore(int sid, int value);
void semaphoreP(int sid);
void semaphoreV(int sid);
void procinfo(int pid);
void totalinfo(); 
void init();

#endif