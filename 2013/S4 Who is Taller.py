N, M = map(int, input().split())
N = int(N)
M = int(M)

def bfs(gragh, start, target):
    visit=[]
    queue=[]
    queue.append(start)

    while queue:
        nxt=queue.pop(0)

        if nxt==target:
            return True

        elif nxt not in visit:
            visit.append(nxt)
            queue.extend(gragh[nxt])
    return False


g = {}

for n in range(1, N + 1):
    g.setdefault(n, [])

for m in range(1, M + 1):
    x, y = map(int, input().split())
    g[x].append(y)

S, T = map(int, input().split())

if bfs(g,S,T):
    print('yes')

elif bfs(g,T,S):
    print('no')

else:
    print('unkwoun')
    


