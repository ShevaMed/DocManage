# DocManage
DocManage is a Microsoft Word document management system written in Qt (C++) for the Windows platform. 

The system is designed to make it easy for users to upload, download and share documents. It provides features such as uploading, sharing, document commenting, and digital signatures. 

DocManage uses a MySQL database to store documents, signatures, user data, and parameters.

## Usage
Once the project is set up and running, you can perform the following actions:
- Upload and download documents: Users can upload their documents to the system and download documents shared with them
- Send documents: Users can send documents to other users
- View documents: Users can view documents shared with them
- Comment on documents: Users can leave comments on shared documents
- Upload signatures: Users can upload their signatures for document signing
- Digital signatures: Users can electronically sign the documents they receive

## Installation
To set up the project, follow these steps:
1. Clone the repository to your local machine.
2. Ensure you have a remote MySQL server.
3. On your remote MySQL server execute file `init_database.sql` to create database, tables and initialize some tables.
4. Configure the database connection parameters in the `DocManage/database.ini file`.
5. Install the necessary technologies and libraries specified in the project's [Dependencies](#dependencies).
6. Go to the `lib/sqldrivers` folder and copy files into your sqldrivers Qt folder following this path `../Qt/6.4.0/msvc2019_64/plugins/sqldrivers`.
7. Build a project with Qt Creator using the `DocManage/DocManage.pro` file.
8. Compile the project with the Desktop Microsoft Visual C++ Compiler (>= 17.3) 64-bit.
9. After compiling, go to the `lib` folder and copy the file `libmysql.dll` into the compiled file `.exe` folder.
10. Now you can run the program using Qt Creator or `.exe` file.

## Dependencies
- Qt (>= 6.4.0) in C++
- MySQL (>= 8.0) (if you are setting up a remote server): https://dev.mysql.com/downloads/installer/
- Microsoft Word (>= 16.0) Object Library (comes with Microsoft Office)
- Desktop Microsoft Visual C++ Compiler (>= 17.3) 64-bit
- Qt Creator (>= 8.0.2) or other IDE

To download Qt, Compiler and IDE, you need to follow the link: https://www.qt.io/download-open-source and download the Qt Online Installer or Qt Source Packages.

## Technologies Used
- Framework: Qt 6.4.0 in C++
- Database: MySQL 8.0
- MS Word document interaction: Microsoft Word 16.0 Object Library
- Compiler: Desktop Microsoft Visual C++ Compiler 17.3 64-bit
- IDE: Qt Creator 8.0.2

## Screenshots
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen1.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen2.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen3.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen4.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen5.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen6.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen7.png)
![screenshot](https://github.com/ShevaMed/DocManage/blob/main/screenshots/screen8.png)
