# Document Manage System
Document Manage System is an electronic document management system designed to facilitate document uploading, downloading, and sharing among users. It provides features such as document commenting and digital signatures. The system utilizes a MySQL database to store documents, signatures, user data, and parameters.

## Installation
To set up the project, follow these steps:
1. Clone the repository to your local machine.
2. Ensure you have a remote MYSQL server.
3. On your remote MYSQL server execute file ```init_database.sql``` to create database, tables and initialize some tables.
4. Configure the database connection parameters in the ```database.ini file```.
5. Install the necessary technologies and libraries specified in the project's [Technologies Used](#technologies-used).
6. Build and compile the project using your preferred development environment.

## Usage
Once the project is set up and running, you can perform the following actions:
- Upload and download documents: Users can upload their documents to the system and download documents shared with them.
- Send documents: Users can send documents to other users.
- View documents: Users can view documents shared with them.
- Comment on documents: Users can leave comments on shared documents.
- Upload signatures: Users can upload their signatures for document signing.
- Digital signatures: Users can electronically sign the documents they receive.

## Technologies Used
- Languaes: C++17, SQL
- Frameworks: Qt 6.4.0
- Database: MySQL
- MS Word document interaction: Microsoft Word 16.0 Object Library
- IDE: Qt Creator 8.0.2, MySQL Workbench 8.0
- Compiler: Desktop MSVC2019 64bit
