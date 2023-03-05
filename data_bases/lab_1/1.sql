/*
 * ВАРІАНТ №1
 */

-- 1.
CREATE DATABASE geography COLLATE utf8mb4_0900_ai_ci;

USE geography;

-- 2.
CREATE TABLE `continents`
(
    `id`         int,
    `name`       varchar(30) COLLATE utf8mb4_unicode_ci,
    `area`       int,
    `population` int
) ENGINE = InnoDB
  DEFAULT CHARSET = utf8mb4
  COLLATE = utf8mb4_unicode_ci;

CREATE TABLE `countries`
(
    `id`                 int,
    `continent_id`       int,
    `name`               varchar(20) COLLATE utf8mb4_unicode_ci,
    `area`               int,
    `population`         int,
    `capital`            varchar(25) COLLATE utf8mb4_unicode_ci,
    `capital_population` int
) ENGINE = InnoDB
  DEFAULT CHARSET = utf8mb4
  COLLATE = utf8mb4_unicode_ci;

-- 3.
ALTER TABLE `continents` ADD CONSTRAINT PRIMARY KEY (`id`);
ALTER TABLE `continents` ADD CONSTRAINT `unique_id` UNIQUE (`id`);
ALTER TABLE `continents` ADD CONSTRAINT `unique_name` UNIQUE (`name`);
ALTER TABLE `continents` MODIFY `id` tinyint unsigned AUTO_INCREMENT;
ALTER TABLE `continents` MODIFY `name` varchar(30) NOT NULL;
ALTER TABLE `continents` MODIFY `area` int unsigned NOT NULL DEFAULT 1000;
ALTER TABLE `continents` MODIFY `population` bigint unsigned;

-- 4.
INSERT INTO `continents` (id, name, area, population) VALUES (1, 'Північна Америка', 24250000, 528720100);
INSERT INTO `continents` (id, name, area, population) VALUES (2, 'Південна Америка', 18280000, 382000000);
INSERT INTO `continents` (id, name, area, population) VALUES (3, 'Антарктида', 13970000, 1000);
INSERT INTO `continents` (id, name, area, population) VALUES (4, 'Африка', 30300000, 922011000);
INSERT INTO `continents` (id, name, area, population) VALUES (5, 'Європа', 10186000, 747636045);
INSERT INTO `continents` (id, name, area, population) VALUES (6, 'Австралія', 7687000, 32000000);
INSERT INTO `continents` (id, name, area, population) VALUES (7, 'Азія', 44614500 , 4164252000);

SELECT * FROM `continents` ORDER BY population ASC;

-- 5.
ALTER TABLE `countries` ADD CONSTRAINT PRIMARY KEY (`id`);
ALTER TABLE `countries` ADD CONSTRAINT `unique_id` UNIQUE (`id`);
ALTER TABLE `countries` MODIFY `id` smallint unsigned AUTO_INCREMENT;
ALTER TABLE `countries` MODIFY `name` varchar(30) NOT NULL;
ALTER TABLE `countries` MODIFY `area` int unsigned NOT NULL;
ALTER TABLE `countries` MODIFY `population` int unsigned;
ALTER TABLE `countries` MODIFY `capital` varchar(25) NOT NULL;
ALTER TABLE `countries` MODIFY `capital_population` mediumint unsigned;

-- 6.
ALTER TABLE `countries` MODIFY `continent_id` tinyint unsigned NOT NULL;
ALTER TABLE `countries` ADD CONSTRAINT `foreign_key_continent_id` FOREIGN KEY (`continent_id`) REFERENCES `continents` (`id`) ON DELETE CASCADE;


-- 7.
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Австрія', 83871, 8219743, 'Відень', 1911191);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Бельгія', 32547, 10438353, 'Брюссель', 163210);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Ліхтенштейн', 160, 36713, 'Вадуц', 5450);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Монако', 2, 30510, 'Монако', 30510);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Нідерланди', 41526, 16730632, 'Амстердам', 863315);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Німеччина', 357578, 81305856, 'Берлін', 3664088);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (5, 'Україна', 603700, 35000000, 'Київ', 2952301);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Аргентина', 2766890, 40677348, 'Буенос-Айрес', 2891082);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Болівія', 1098580, 8857870, 'Сукре', 225000);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Бразилія', 8514877, 191908598, 'Бразиліа', 3039444);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Венесуела', 912050, 26414815, 'Каракас', 2245744);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Гаяна', 214970, 770794, 'Джорджтаун', 1796);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Колумбія', 1138910, 45013674, 'Богота', 8550000);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Парагвай', 406750, 6347884, 'Асунсьйон', 637249);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (2, 'Перу', 1285220, 27925628, 'Ліма', 9674755);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (1, 'Канада', 9984670, 33573000, 'Оттава', 934243);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (1, 'Мексика', 1964375, 112322757, 'Мехіко', 8918653);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (4, 'Алжир', 2381741, 43851044, 'Алжир', 1519570);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (4, 'Судан', 1886068, 43849260, 'Хартум', 639598);
INSERT INTO `countries` (continent_id, name, area, population, capital, capital_population) VALUES (6, 'Австралія', 7688287, 25250000, 'Канберра', 381448);

-- 8.
CREATE USER 'geography'@'localhost' IDENTIFIED BY 'secret';
GRANT INSERT, SELECT, UPDATE, DELETE ON geography.* TO 'geography'@'localhost';
