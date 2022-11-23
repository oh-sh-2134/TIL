Waiter's Tips 데이터셋에는 식사 금액, 팁, 결제자 성별, 결제 요일 등 레스토랑 손님들의 계산 정보가 들어있습니다. 이 레스토랑에 근무하는 서버는 팁을 많이 받을 수 있는 날 하루를 골라 근무하고 싶습니다.

요일별로 팁 총액을 집계하고 팁이 가장 많았던 요일과 그날의 팁 총액을 출력하는 쿼리를 작성해주세요.

결과 데이터는 아래 컬럼을 포함해야 합니다.

day - 요일
tip_daily - 요일 별 팁 총액

----------------------------------------

table
tips
numbertotal_bill
식사 금액 ($)
numbertip
팁 ($)
stringsex
결제자 성별
stringsmoker
일행 중 흡연자 존재 여부
stringday
요일
stringtime
시간대
integersize
일행 수 (명)

----------------------------------------
select day, max(tip_daily) as tip_daily
from
(select
  day, sum(tip) as tip_daily
from
  tips
  group by day
) as result

//https://solvesql.com/problems/best-working-day/
