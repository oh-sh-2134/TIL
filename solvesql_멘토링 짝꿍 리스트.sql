employees 테이블에는 어느 회사의 직원 정보가 들어있습니다. 각각의 데이터는 직원 ID, 직원의 이름, 입사일, 부서, 직속 상사의 ID로 구성되어있습니다.

회사에서 신규 입사자들의 빠른 적응을 돕기 위해 멘토링 프로그램을 운영하려고 합니다. 멘티가 될 신규 입사자들은 ‘2021년 12월 31일’을 기준으로 3개월 이내 입사한 인원 전체이며, 멘토는 ‘2021년 12월 31일’을 기준으로 재직한지 2년 이상이 된 직원들만 배정하려고 합니다. 또한 최대한 다양한 분야의 직원들이 서로 교류 할 수 있도록 서로 다른 부서에 속하는 직원끼리 멘토링을 진행하려고 합니다.

위 조건을 모두 만족하는 멘티-멘토 짝꿍 리스트를 계산하는 쿼리를 작성해주세요. 쿼리 결과에는 매칭 가능한 멘토가 없는 경우도 모두 포함되어야 합니다. 추가로 쿼리 결과는 멘티 ID를 기준으로 오름차순 정렬되어 있어야 하고, 멘티 1명에 대해 배정 가능한 멘토가 여러 명인 경우 멘토 ID로 오름차순 정렬되어 있어야 합니다.

mentee_id - 멘티 ID
mentee_name - 멘티 이름
mentor_id - 멘토 ID
mentor_name - 멘토 이름

------------------------------------------------------------------------------------------------------------------------------------------------------------
table
employees
integeremployee_id
직원 ID
stringname
이름
datejoin_date
입사일
stringdepartment
부서
integermanager_id
상사 직원 ID
------------------------------------------------------------------------------------------------------------------------------------------------------------


select
  mentee.employee_id as mentee_id,
  mentee.name as mentee_name,
  mentor.employee_id as mentor_id,
  mentor.name as mentor_name
from
  employees mentee,
  employees mentor
where
  STRFTIME('%Y%m%d', mentee.join_date) between '20210901' and '20211231'
  and STRFTIME('%Y%m%d', mentor.join_date) <= '20191231'
  and mentor.department != mentee.department
order by
  mentee_id