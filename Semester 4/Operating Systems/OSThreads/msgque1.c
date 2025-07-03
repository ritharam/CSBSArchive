#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
struct msg_buffer {
   long msg_type;
   char msg[100];
} message;
int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); //used to create a unique key
   msg_id = msgget(my_key, 0666|IPC_CREAT); // used to create message queue and return its id
   message.msg_type = 1;
   printf("Write Message : ");
   fgets(message.msg, 100, stdin);
   msgsnd(msg_id, &message, sizeof(message), 0); // used to send the message onto the queue
   printf("Sent message is : %s \n", message.msg);
}
