SELECT INGREDIENT_TYPE , SUM(TOTAL_ORDER) 
from FIRST_HALF  a
JOIN ICECREAM_INFO b on a.FLAVOR = b.FLAVOR
group by b.INGREDIENT_TYPE