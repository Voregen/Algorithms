int fib(int n) {
    int a = 1, ta,
        b = 1, tb,
        c = 1, rc = 0,  tc,
        d = 0, rd = 1;

    while (n) {
        if (n & 1) {  // ���� ������� ��������
            // �������� ������ R �� ������� A
            tc = rc;
            rc = rc*a + rd*c;
            rd = tc*b + rd*d;
        }

        // �������� ������� A �� ���� ����
        ta = a;
        tb = b;
        tc = c;
        a = a*a  + b*c;
        b = ta*b + b*d;
        c = c*ta + d*c;
        d = tc*tb+ d*d;

        n >>= 1;  // ��������� ������� �����

    }
    return rc;
}
