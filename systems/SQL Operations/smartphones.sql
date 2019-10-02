--thought about using MySQL, but then changed my mind in the middle... idk
--create database smartphones;
--use smartphones;

create table smartphone_details(
  smartphone_id int primary key,
  model_name varchar(50),
  company_name varchar(30),
  price decimal(7,2),
  os varchar(7),
  release_date date
);

insert into smartphone_details (smartphone_id, model_name, company_name, price, os, release_date)
values
(1, 'Pixel 3', 'Google', 57000.00, 'Android', '2018-10-09'),
(2, 'iPhone XR', 'Apple', 49999.00, 'iOS', '2018-09-12'),
(3, 'iPhone 11 Pro', 'Apple', 99900.00, 'iOS', '2019-09-10'),
(4, 'Galaxy Note 10 Plus', 'Samsung', 85000.00, 'Android', '2019-08-07'),
(5, 'iPhone XS Max', 'Apple', 94999.00, 'iOS', '2018-09-12'),
(6, 'Galaxy A50s ', 'Samsung', 19949.00, 'Android', '2019-08-22'),
(7, 'Galaxy S9', 'Samsung', 44990.00, 'Android', '2018-03-16'),
(8, 'ROG Phone II', 'Asus', 37999.00, 'Android', '2019-09-23'),
(9, 'Mi A3', 'Xiaomi', 12999.00, 'Android', '2019-08-21'),
(10, 'Galaxy A10', 'Samsung', 7990.00, 'Android', '2019-03-02');

-- Task1
select * from [smartphone_details] where price < 60000;

-- Task2
select * from [smartphone_details] where release_date >= '2018-03-01' and release_date < '2018-12-31';

-- Task3
select * from [smartphone_details] where release_date > '2019-01-01' order by price limit 2
