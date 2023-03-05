/*
 * ВАРІАНТ №1
 */

-- 1.
SELECT * FROM `continents` WHERE population < 1000000000;

-- або

SELECT * FROM `continents` WHERE IFNULL(population, 0) < 1000000000;

-- 2.
SELECT name, area, capital FROM `countries` WHERE area > 100000 AND capital_population > 1000000;

-- або

SELECT name, area, capital FROM `countries` WHERE area > 100000 AND IFNULL(capital_population, 0) > 1000000;

-- 3.
SELECT countries.name,
       countries.capital,
       countries.population
FROM countries
INNER JOIN continents ON (
    countries.continent_id = continents.id
)
WHERE continents.name = 'Європа';

-- 4.
SELECT continents.name,
    COUNT(countries.id) AS count
FROM continents
INNER JOIN countries ON (
    continents.id = countries.continent_id
)
GROUP BY continents.name;

-- 5.
SELECT SUM(continents.population) AS population
FROM continents;

-- 6.
SELECT SUM(countries.area) AS area
FROM countries
INNER JOIN continents ON (
    countries.continent_id = continents.id
)
WHERE continents.name = 'Європа';

-- 7.
SELECT continents.name,
       continents.area,
       countries.name,
       countries.area,
       countries.capital
FROM countries
INNER JOIN continents ON (
    countries.continent_id = continents.id
)
WHERE countries.area BETWEEN 150000 AND 250000;

-- або

SELECT continents.name,
       continents.area,
       countries.name,
       countries.area,
       countries.capital
FROM countries
INNER JOIN continents ON (
    countries.continent_id = continents.id
)
WHERE countries.area >= 150000 AND countries.area <= 250000;

-- 8.
SELECT SUM(continents.area) AS area
FROM continents;

-- 9.
DELETE FROM countries
WHERE countries.capital_population < 3000000;