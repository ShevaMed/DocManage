CREATE DATABASE IF NOT EXISTS doc_manage;
Use doc_manage;

CREATE TABLE IF NOT EXISTS users (
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    user_password VARCHAR(30) NOT NULL, 
    job_title VARCHAR(100) NOT NULL, 
    user_type VARCHAR(30) NOT NULL,
    signature LONGBLOB
);

CREATE TABLE IF NOT EXISTS documents (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    document_name VARCHAR(255) NOT NULL,
    author_id INT NOT NULL,
    download_date DATE NOT NULL,
    content LONGBLOB NOT NULL,
    note TEXT,
    FOREIGN KEY (author_id) REFERENCES users(id)
); 

CREATE TABLE IF NOT EXISTS document_user (
  document_id INT NOT NULL,
  user_id INT NOT NULL,
  check_signature BOOL NOT NULL,
  user_note VARCHAR(255),
  PRIMARY KEY (document_id, user_id),
  FOREIGN KEY (document_id) REFERENCES documents(id),
  FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE IF NOT EXISTS settings (
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  name_ VARCHAR(100) NOT NULL UNIQUE,
  value_ VARCHAR(255) NOT NULL
);

INSERT INTO settings (name_, value_) 
VALUES 
('Код для реєстрації менеджера', '102003'), 
('Ширина підпису', '77'),
('Висота підпису', '23');
 