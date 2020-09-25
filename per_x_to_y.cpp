string per(int n, int m, string s) {
    llong is = 1, nw = 1;
    llong sum = 0;
    for (int i(int(s.size() - 1)); i >= 0; --i){
        if (s[i] >= '0' && s[i] <= '9'){
            sum += (s[i] - '0') * is;
        } else {
            sum += (s[i] - 'a' + 10) * is;
        }
        is *= n;
    }
    string ans = "";
    while (sum > 0){
        llong h = sum % m;
        if (h >= 0 && h <= 9){
            ans += char(h + '0');
        } else {
            ans += char(h - 10 + 'a');
        }
        sum /= m;
    }
    if (ans == "") return "0";
    else return ans;
}
