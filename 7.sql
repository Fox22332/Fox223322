SELECT AVG(energy) AS average_energy
FROM songs
JOIN artists ON songs.artist_id = artists.artist_id
WHERE artists.artist_name = 'Drake';
