-- MySQL dump 10.13  Distrib 8.0.31, for Linux (x86_64)
--
-- Host: localhost    Database: geography
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `geography`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `geography` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `geography`;

--
-- Table structure for table `continents`
--

DROP TABLE IF EXISTS `continents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `continents` (
  `id` tinyint unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `area` int unsigned NOT NULL DEFAULT '1000',
  `population` bigint unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_id` (`id`),
  UNIQUE KEY `unique_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `continents`
--

LOCK TABLES `continents` WRITE;
/*!40000 ALTER TABLE `continents` DISABLE KEYS */;
INSERT INTO `continents` VALUES (1,'Північна Америка',24250000,528720100),(2,'Південна Америка',18280000,382000000),(3,'Антарктида',13970000,1000),(4,'Африка',30300000,922011000),(5,'Європа',10186000,747636045),(6,'Австралія',7687000,32000000),(7,'Азія',44614500,4164252000);
/*!40000 ALTER TABLE `continents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `countries`
--

DROP TABLE IF EXISTS `countries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `countries` (
  `id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `continent_id` tinyint unsigned NOT NULL,
  `name` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `area` int unsigned NOT NULL,
  `population` int unsigned DEFAULT NULL,
  `capital` varchar(25) COLLATE utf8mb4_unicode_ci NOT NULL,
  `capital_population` mediumint unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_id` (`id`),
  KEY `foreign_key_continent_id` (`continent_id`),
  CONSTRAINT `foreign_key_continent_id` FOREIGN KEY (`continent_id`) REFERENCES `continents` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `countries`
--

LOCK TABLES `countries` WRITE;
/*!40000 ALTER TABLE `countries` DISABLE KEYS */;
INSERT INTO `countries` VALUES (1,5,'Австрія',83871,8219743,'Відень',1911191),(2,5,'Бельгія',32547,10438353,'Брюссель',163210),(3,5,'Ліхтенштейн',160,36713,'Вадуц',5450),(4,5,'Монако',2,30510,'Монако',30510),(5,5,'Нідерланди',41526,16730632,'Амстердам',863315),(6,5,'Німеччина',357578,81305856,'Берлін',3664088),(7,5,'Україна',603700,35000000,'Київ',2952301),(8,2,'Аргентина',2766890,40677348,'Буенос-Айрес',2891082),(9,2,'Болівія',1098580,8857870,'Сукре',225000),(10,2,'Бразилія',8514877,191908598,'Бразиліа',3039444),(11,2,'Венесуела',912050,26414815,'Каракас',2245744),(12,2,'Гаяна',214970,770794,'Джорджтаун',1796),(13,2,'Колумбія',1138910,45013674,'Богота',8550000),(14,2,'Парагвай',406750,6347884,'Асунсьйон',637249),(15,2,'Перу',1285220,27925628,'Ліма',9674755),(16,1,'Канада',9984670,33573000,'Оттава',934243),(17,1,'Мексика',1964375,112322757,'Мехіко',8918653),(18,4,'Алжир',2381741,43851044,'Алжир',1519570),(19,4,'Судан',1886068,43849260,'Хартум',639598),(20,6,'Австралія',7688287,25250000,'Канберра',381448);
/*!40000 ALTER TABLE `countries` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-02-01 12:35:38
