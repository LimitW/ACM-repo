# CF#309 DIV2
# RE maximum recursion depth exceeded
maxn = 100005
mod = 1000000007
e = [[] for i in range(maxn)]
vis = [0 for i in range(maxn)]
def dfs(u):
    sz = len(e[u])
    ok = True
    for i in range(sz):
        v = e[u][i][0]
        c = e[u][i][1]
        if(vis[v] == 0):
            if(c == True):
                vis[v] = vis[u]
            else:
                vis[v] = -vis[u]
            ok = dfs(v)
        if(c == 1 and vis[v] != vis[u]):
            return False
        if(c == 0 and vis[v] != -vis[u]):
            return False
    return ok
def main():
    #map
    n,m = map(int,raw_input().split())
    for i in range(m):
        u,v,c = map(int,raw_input().split())
        u -= 1
        v -= 1
        e[u].append([v,c])
        e[v].append([u,c])
    cnt = 0
    for i in range(n):
        if(vis[i] == 0):
            vis[i] = 1
            cnt += 1
            if(dfs(i) == False):
                cnt = 0
                break
    ans = 1
    if(cnt == 0):
        ans = 0
    for i in range(1,cnt):
        ans *= 2
        ans %= mod
    print(ans)
main()
