#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct {
    int registration;
    char name[50];
    ServiceTree serviceTree;
} User;

void registerUser(User *users, int *numUsers);
void registerService(Service *services, User *users, int numUsers, int *numServices, Heap *heap);
void listAllUsersServices(User *users, int numUsers);
void listUserServices(User *users, int numUsers);
void modifyUserRegistration(User *users, int numUsers);
void modifyServiceStatus(User *users, int numUsers);
void performServiceHandling(Heap *heap);

#endif // USER_H_INCLUDED
