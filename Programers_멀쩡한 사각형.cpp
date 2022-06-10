using namespace std;

long long gcd(int w, int h) {
	int k;
	while (h != 0) {
		k = w % h;
		w = h;
		h = k;
	}
	return w;
}

long long solution(int w, int h) {
	long long answer = (long long)w*h - (w + h) + gcd(w, h);
	return answer;
}
/*
이 문제는 공식을 모르고서는 못푼다고 봐야함
잘려져 있는 사각형들의 패턴을 보고 문제를 풀어야 함
패턴이 동일한 사각형이 w, h의 최대공약수만큼 반복됨
하나의 사각형에서 잘려지는 개수는 (가로 + 세로 - 1) => (가로/최대공약수 + 세로/최대공약수 -1)
전체 공식은 (w*h) - (w/gcd + h/gcd - 1) => w*h - (w+h) + gcd
*/
//https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp
