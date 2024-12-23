SELECT DISTINCT p.name
FROM people p
JOIN movies m ON p.id = m.director_id
WHERE m.imdb_rating >= 9.0;
