///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      14-Dec-2025 1:15:10 AM
//  Original author: ASUS
///////////////////////////////////////////////////////////

#if !defined(EA_FC268E8B_4431_4758_9F18_19507D0783D0__INCLUDED_)
#define EA_FC268E8B_4431_4758_9F18_19507D0783D0__INCLUDED_


#include <string>

class User
{
protected:
    int userId;
    std::string username;
    std::string password;
    std::string role;

public:
    User();
    User(int inputUserId,
         const std::string& inputUsername,
         const std::string& inputPassword,
         const std::string& inputRole);

    virtual ~User();

    std::string getRole() const;
    bool login(const std::string& inputUsername,
               const std::string& inputPassword);
    void logout();
};

#endif
 // !defined(EA_FC268E8B_4431_4758_9F18_19507D0783D0__INCLUDED_)
