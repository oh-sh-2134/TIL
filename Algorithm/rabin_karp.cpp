#include<iostream>
#include<vector>
using namespace std;


void rvcf(string pattern, string text) {
	int patternhash = 0, texthash = 0, var = 1;
	int patternsize = pattern.size();
	int textsize = text.size();
	for (int i = 0; i < textsize - patternsize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternsize; j++) {
				patternhash += pattern[patternsize - j - 1] * var;
				texthash += text[patternsize - j - 1] * var;
				if (j < patternsize - 1) var *= 2;
			}
		}
		else //if (patternhash != texthash) {
			texthash = 2 * (texthash - text[i - 1] * var) + text[patternsize - 1 + i];
		//}
		if (patternhash == texthash) {
			bool finded = true;
			for (int j = 0; j < patternsize; j++) {
				if (pattern[j] != text[i + j]) {
					finded = false;
					break;
				}
			}
			if (finded) { printf("%d 번쨰에서 출력 \n", i + 1); }
		}
	}
}
int main() {

	string pattern = "abacaba";
	string text = "abasdaseabacabaasee";

	rvcf(pattern, text);
	system("pause");
}