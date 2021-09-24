/**
 * Question:
 * Given 2 strings, P and T, find the number of occurrences of P in T.
 */
 
void prefix_matching(vector<int>& lps, string pattern) {
	int len = 0, i = 1;
	while (i < pattern.size()) {
		if (pattern[i] == pattern[len]) {
			lps[i] = (len += 1);
			i++;
		} else {
			if (len == 0) {
				lps[i] = 0;
				i++;
			} else {
				len = lps[i-1];
			}
		}
	}
}

int KMPSearch(string pattern, string text) {
	vector<int> lps(pattern.size(), 0);
	prefix_matching(lps, pattern);
	int i=0, j=0;
	int count = 0;
	while (i < text.size()) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		} else {
			if (j > 0) j = lps[j-1];
			else i++;
		}
		if (j == pattern.size()) {
			count++;
			j = lps[j-1];
		}
	}
	return count;
}
