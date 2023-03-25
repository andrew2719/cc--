#include <iostream>
// usecase of namespace 
// for organization of code
namespace user {
    struct UserData {
        std::string name;
        int age;
        std::string email;
    };

    void printUserData(UserData data) {
        std::cout << "Name: " << data.name << std::endl;
        std::cout << "Age: " << data.age << std::endl;
        std::cout << "Email: " << data.email << std::endl;
    }
}

namespace admin {
    struct AdminData {
        std::string username;
        std::string password;
        std::string email;
    };

    void printAdminData(AdminData data) {
        std::cout << "Username: " << data.username << std::endl;
        std::cout << "Password: " << data.password << std::endl;
        std::cout << "Email: " << data.email << std::endl;
    }
}

int main() {
    user::UserData userData = {"John Doe", 25, "johndoe@gmail.com"};
    user::printUserData(userData);

    admin::AdminData adminData = {"admin", "password123", "admin@example.com"};
    admin::printAdminData(adminData);

    return 0;
}
