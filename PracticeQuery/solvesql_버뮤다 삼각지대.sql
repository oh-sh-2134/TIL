Brazilian E-Commerce Public Dataset by Olist 데이터셋은 브라질의 이커머스 웹사이트인 Olist Store의 판매 데이터 입니다. 그 중 olist_orders_dataset 테이블에는 주문 ID, 고객 ID, 주문 상태, 구매 시각 등 주문 내역 데이터가 들어있습니다. Olist의 주문부터 배송까지 프로세스는 다음 단계를 통해 이루어지고, 각 단계마다 시각을 기록하고 있습니다.

고객의 구매
order_purchase_timestamp 컬럼에 구매 시점이 저장됨
판매자가 주문을 승인
order_approved_at 컬럼에 승인 시점이 저장됨
택배사에 도착하여 배송 시작
order_delivered_carrier_date 컬럼에 배송 시작 시점이 저장됨
배송 완료
order_delivered_customer_date 컬럼에 배송 완료 시점이 저장됨
종종 택배사에 물건을 보내 배송 시작이 되었는데, 고객에게 택배가 도착하지 않는 일이 있습니다. 이런 경우 order_delivered_carrier_date 컬럼에 택배사 도착 시각은 기록되지만, order_delivered_customer_date 컬럼의 값은 null으로 저장됩니다.

일단 원인을 파악하기 전에 이런 일들이 얼마나 발생하고 있는지 현황 파악을 해보려고 합니다. 2017년 1월 한 달 동안 택배사에 전달되었지만 배송 완료는 되지 않은 주문 건수를 택배사 도착일을 기준으로 집계하는 쿼리를 작성해주세요. 쿼리 결과는 택배사 도착일을 기준으로 오름차순 정렬되어야 하고, 아래 컬럼을 포함해야 합니다.

delivered_carrier_date - 택배사 도착 날짜 (예: 2017-01-16)
orders - 택배사에 도착했지만, 고객에게 배송되지 않은 주문 건 수

----------------------------------------------------------------------------------------------------------------------------------------------------------

table
olist_orders_dataset
stringorder_id
주문 ID
stringcustomer_id
소비자 ID
stringorder_status
주문 상태
datetimeorder_purchase_timestamp
구매 시각
datetimeorder_approved_at
주문 승인 시각
datetimeorder_delivered_carrier_date
배송 시작 시각
datetimeorder_delivered_customer_date
배송 완료 시각
datetimeorder_estimated_delivery_date

----------------------------------------------------------------------------------------------------------------------------------------------------------

select
  STRFTIME('%Y-%m-%d', order_delivered_carrier_date) as delivered_carrier_date,
  count(*) as orders
from
  olist_orders_dataset
where
  order_delivered_customer_date is null
group by
  STRFTIME('%Y%m%d', order_delivered_carrier_date)
having 
  STRFTIME('%Y%m', order_delivered_carrier_date) = '201701'
