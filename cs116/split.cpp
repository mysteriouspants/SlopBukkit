vector<string> split(const string& str, const char token) {
	vector<string> cuts();
	size_t term;
	for(size_t i=0; i<str.length();) {
		term = str.find(token, i);
		cuts.push_back(string(str.substr(i, term-i)));
		i=++term;
	}
	return cuts;
}
