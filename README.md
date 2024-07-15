# Hotel Management System

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Code Explanation](#code-explanation)
7. [Database Schema](#database-schema)
8. [Contribution Guidelines](#contribution-guidelines)
9. [License](#license)

## Introduction
The Hotel Management System is a C++ application designed to manage the operations of a hotel. It uses Object-Oriented Programming (OOP) principles and integrates with a MySQL database to store and manage data. This project provides functionalities such as booking rooms, checking availability, managing customer information, and handling billing.

## Features
- Room booking and availability check
- Customer information management
- Billing and invoicing
- Room service management
- User authentication

## Technologies Used
- **Programming Language:** C++
- **Database:** MySQL
- **IDE:** Visual Studio Code
- **Extensions:** MySQL DB Client

## Installation
To set up and run this project locally, follow these steps:

1. **Clone the Repository**
    ```sh
    git clone https://github.com/your-username/hotel-management-system.git
    cd hotel-management-system
    ```

2. **Install MySQL Server**
    Follow the instructions for your operating system to install MySQL server.

3. **Set Up the Database**
    - Open MySQL command line or a MySQL client.
    - Create a new database:
        ```sql
        CREATE DATABASE hotel_management;
        ```
    - Import the provided SQL script to set up tables:
        ```sh
        mysql -u your-username -p hotel_management < database/schema.sql
        ```

4. **Configure Database Connection**
    - Update the database connection parameters in your C++ code:
        ```cpp
        const char* server = "localhost";
        const char* user = "your-username";
        const char* password = "your-password";
        const char* database = "hotel_management";
        ```

5. **Compile and Run the Project**
    - Open the project folder in Visual Studio Code.
    - Compile the code:
        ```sh
        g++ -o hotel_management main.cpp -lmysqlclient
        ```
    - Run the executable:
        ```sh
        ./hotel_management
        ```

## Usage
Once the application is running, you can perform the following operations:

- **Book a Room:** Input customer details and room preferences to book a room.
- **Check Room Availability:** Check if a room is available for booking.
- **Manage Customer Information:** Add, update, or delete customer information.
- **Generate Bill:** Generate and print bills for customers.

## Code Explanation
### Main Function
The main function initializes the application and displays the main menu:
```cpp
int main() {
    HotelManagementSystem hms;
    hms.run();
    return 0;
}
