///////////////////////////////////////////////////////////
//  User.cpp
//  Implementation of the Class User
//  Created on:      14-Dec-2025
//  Original author: ASUS
///////////////////////////////////////////////////////////

#include "User.h"

// Default constructor
User::User()
    : userId(0), username(""), password(""), role("")
{
}

// Parameterized constructor
User::User(int inputUserId,
           const std::string& inputUsername,
           const std::string& inputPassword,
           const std::string& inputRole)
    : userId(inputUserId),
      username(inputUsername),
      password(inputPassword),
      role(inputRole)
{
}

// Destructor
User::~User()
{
}

// Get user role
std::string User::getRole() const
{
    return role;
}

// Get user ID
int User::getId() const
{
    return userId;
}

// Get username
std::string User::getUsername() const
{
    return username;
}

// Get password
std::string User::getPassword() const
{
    return password;
}

// Login validation
bool User::login(const std::string& inputUsername,
                 const std::string& inputPassword)
{
    if (this->username == inputUsername &&
        this->password == inputPassword)
    {
        return true;
    }
    return false;
}

// Logout (simple version)
void User::logout()
{
    // Untuk versi sederhana, tidak ada state yang disimpan
    // Bisa dikembangkan nanti
}
