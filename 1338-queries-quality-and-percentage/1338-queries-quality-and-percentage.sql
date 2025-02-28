SELECT
    query_name,
    round(AVG(rating / position),2) AS quality,
    round(SUM(IF(rating < 3, 1, 0)) * 100 / COUNT(rating),2) AS poor_query_percentage
FROM
    Queries
GROUP BY
    query_name;
