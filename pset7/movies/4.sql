SELECT COUNT(title) as numOfMoviesWithRating10
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating = 10.0;
-- SELECT COUNT(*) as numOfMoviesWithRatingAs10 FROM ratings WHERE rating = 10;