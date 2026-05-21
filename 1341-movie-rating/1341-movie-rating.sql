WITH highestRatings AS(
    SELECT name AS results
    FROM Users u
    LEFT JOIN MovieRating mr ON u.user_id=mr.user_id
    GROUP BY u.user_id,u.name
    ORDER BY COUNT(*) DESC,u.name
    LIMIT 1
),
averageRating AS(
    SELECT m.title AS results
    FROM Movies m
    JOIN MovieRating mr ON m.movie_id=mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id
    ORDER BY AVG(mr.rating) DESC,m.title
    LIMIT 1
)
SELECT results FROM highestRatings
UNION ALL
SELECT results FROM averageRating
