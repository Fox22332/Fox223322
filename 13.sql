SELECT DISTINCT p.name
FROM people p
JOIN movie_cast mc ON p.id = mc.person_id
JOIN movies m ON mc.movie_id = m.id
JOIN movie_cast mc_kb ON m.id = mc_kb.movie_id
JOIN people p_kb ON mc_kb.person_id = p_kb.id
WHERE p_kb.name = 'Кевин Бейкон' AND p_kb.birth_year = 1958
AND p.name != 'Кевин Бейкон';
