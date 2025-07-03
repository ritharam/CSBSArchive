/*#include <stdio.h>
#include <stdlib.h> // for rand
#include <string.h> // for strcmp
#include <sys/ipc.h> // IPC_CREAT
#include <sys/shm.h>
#include <time.h> // for time()

#define SHM_SIZE 2052
#define SHM_KEY 2345

int main() {
    int shm_id;
    char* shm_ptr;
    char* sender;
    char* msg;
    char me[3];

    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    shm_ptr = shmat(shm_id, NULL, 0);

    srand(time(0));
    sprintf(me, "%03d", rand() % 1000);

    sender = shm_ptr;
    sender[3] = '\0';
    msg = shm_ptr + 4;

    printf("I am %s\n", me);

    while (1) {
        if (!strcmp(sender, me)) continue;

        printf("Sender %s: %s", sender, msg);
        printf("Reply: ");
        fgets(msg, SHM_SIZE - 4, stdin);
        sprintf(sender, "%s", me);
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the structure of the message
struct Message {
    long messageType; // Message type (must be greater than 0)
    char messageText[100]; // Message data
};

// Function to create a message queue
int createMessageQueue() {
    /*key_t key = ftok("/home/kali", 'A'); // You may replace "keyfile" and 'A' with your own values
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }*/

    int msgqid = msgget((key_)2345, IPC_CREAT | 0666); // Create the message queue
    if (msgqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    return msgqid;
}

// Function for the sender process
void senderProcess(int msgqid, struct Message* message) {
    // Prepare the message
    message->messageType = 1; // Message type must be greater than 0
    strcpy(message->messageText, "Hello from sender!");

    // Send the message to the queue
    if (msgsnd(msgqid, message, sizeof(struct Message), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent by sender: %s\n", message->messageText);
}

// Function for the receiver process
void receiverProcess(int msgqid, struct Message* message) {
    // Receive the message from the queue
    if (msgrcv(msgqid, message, sizeof(struct Message), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Message received by receiver: %s\n", message->messageText);
}

int main() {
    struct Message message;
    int msgqid = createMessageQueue();

    pid_t pid = fork(); // Create a child process

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process (sender)
        senderProcess(msgqid, &message);
    } else {
        // Parent process (receiver)
        receiverProcess(msgqid, &message);

        // Remove the message queue after use
        if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)2345, 1024, 0666);
	printf("Key of shared memory : %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Proces attached at %p\n", shared_memory);
	printf("Data read from shared memory is : %s\n", (char*)shared_memory);
}*/

