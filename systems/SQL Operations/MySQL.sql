-- MySQL dump 10.13  Distrib 5.7.27, for Linux (x86_64)
--
-- Host: localhost    Database: smartphones
-- ------------------------------------------------------
-- Server version	5.7.27-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `smartphone_details`
--

DROP TABLE IF EXISTS `smartphone_details`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `smartphone_details` (
  `smartphone_id` int(10) unsigned NOT NULL,
  `model_name` varchar(50) NOT NULL,
  `company_name` varchar(30) NOT NULL,
  `price` decimal(64,2) NOT NULL,
  `os` varchar(10) NOT NULL,
  `release_date` date NOT NULL,
  PRIMARY KEY (`smartphone_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `smartphone_details`
--

LOCK TABLES `smartphone_details` WRITE;
/*!40000 ALTER TABLE `smartphone_details` DISABLE KEYS */;
INSERT INTO `smartphone_details` VALUES (1,'Pixel 3','Google',57000.00,'Android','2018-10-09'),(2,'iPhone XR','Apple',49999.00,'iOS','2018-09-12'),(3,'iPhone 11 Pro','Apple',99900.00,'iOS','2019-09-10'),(4,'Galaxy Note 10 Plus','Samsung',85000.00,'Android','2019-08-07'),(5,'iPhone XS Max','Apple',94999.00,'iOS','2018-09-12'),(6,'Galaxy A50s','Samsung',19499.00,'Android','2019-08-22'),(7,'Galaxy S9','Samsung',44990.00,'Android','2018-03-16'),(8,'ROG Phone II','Asus',37999.00,'Android','2019-09-23'),(9,'Mi A3','Xiaomi',12999.00,'Android','2019-08-21'),(10,'Galaxy A10','Samsung',7990.00,'Android','2019-03-12');
/*!40000 ALTER TABLE `smartphone_details` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-02 17:37:29
