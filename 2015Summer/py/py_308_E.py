#global 与c++不同
sp = 1
x = []
def cal(a):
    n = len(a)
    st = []
    while(len(st) > 0):
        st.pop()
    i = 0
    while(i < n):
        if(a[i] >= '0' and a[i] <= '9'):
            st.append((long)(a[i]))
        elif(a[i] == '*'):
            u = st[len(st)-1]
            st.pop()
            if(a[i+1] == 'x'):
                u *= sp
            else:
                u *= (long)(a[i+1])
            st.append(u)
            i += 1
        i += 1
    return sum(st)
def main():
    s = raw_input()
    s = '1*' + s + '*1'
    n = len(s)
    ans = cal(s)
    for i in xrange(n):
        if(s[i] == '*'):
            x.append(i)
    sz = len(x)
    for i in xrange(sz):
        for j in xrange(i+1,sz):
            l = x[i]
            r = x[j]
            if(l + 1 == r - 1):
                continue
            #需先声明global才可对全局变量赋值
            global sp
            sp = cal(s[l+1:r])
            ss = s[:l+1] + 'x' + s[r:]
            ans = max(ans,cal(ss))
    print(ans)
main()
