Brazilian E-Commerce Public Dataset by Olist 데이터셋은 브라질의 이커머스 웹사이트인 Olist Store의 판매 데이터 입니다. 그 중 olist_orders_dataset 테이블에는 주문 ID, 고객 ID, 주문 상태, 구매 시각 등 주문 내역 데이터가 들어있습니다. olist_order_payments_dataset 테이블에는 주문 ID, 결제 방법, 결제 금액 등 각 주문의 결제와 관련된 정보가 저장되어 있습니다. 두 테이블을 이용해 2018년 1월 1일 이후 쇼핑몰의 일일 매출액을 계산하는 쿼리를 작성해주세요.

주문 각각에 대해 매출이 일어나는 시점은 olist_orders_dataset 테이블의 order_purchase_timestamp 컬럼에 기록되고, 주문 금액은 olist_order_payments_dataset 테이블의 payment_value 컬럼에 기록됩니다.

쿼리 결과는 아래 두 컬럼을 포함해야 하고, 매출 날짜 기준으로 오름차순 정렬되어 있어야 합니다. 매출액은 반올림 해 소수점 둘째자리까지 출력해주세요.

dt - 매출 날짜 (예: 2018-01-01)
revenue_daily - 해당 날짜의 매출액


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

table
olist_order_payments_dataset
stringorder_id
주문 ID
integerpayment_sequential
연속 결제 횟수
stringpayment_type
결제 방법
integerpayment_installments
할부 개월 수
numberpayment_value
결제 금액


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
배송 예정 시각

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

select
  STRFTIME('%Y-%m-%d', sd.order_purchase_timestamp) as dt,
  round(sum(pd.payment_value), 2) as revenue_daily
from
  olist_order_payments_dataset pd
  inner join olist_orders_dataset sd on pd.order_id = sd.order_id
where
  STRFTIME('%Y-%m-%d', sd.order_purchase_timestamp) >= '2018-01-01'
group by
  STRFTIME('%Y-%m-%d', sd.order_purchase_timestamp)
order by
  dt