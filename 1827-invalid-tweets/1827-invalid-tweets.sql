# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
where char_length(content) > 15;