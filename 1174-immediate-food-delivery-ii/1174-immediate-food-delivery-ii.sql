WITH firstOrder AS(SELECT customer_id,
        MIN(order_date) as order_date
FROM Delivery
GROUP BY customer_id),
sameDayDelivery AS(
    SELECT fo.customer_id
    FROM firstOrder AS fo
    JOIN Delivery d ON fo.customer_id=d.customer_id AND
        fo.order_date=d.order_date
        AND fo.order_date=d.customer_pref_delivery_date
)
SELECT ROUND((SELECT COUNT(*) FROM sameDayDelivery)/(SELECT COUNT(*) FROM firstOrder)*100,2) AS immediate_percentage;