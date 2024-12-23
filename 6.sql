SELECT song_name
FROM songs
JOIN artists ON songs.artist_id = artists.artist_id
WHERE artists.artist_name = 'Post Malone';
