# Even I have no clue I wrote this code when I was in my 1st semester xD
import sys
import itertools as it
import math as mt
import collections as cc
I=lambda:list(map(int,input().split()))
def ch(a,b):
    if (b[0]>=a[0] and b[0]<=a[1] ) or (b[1]>=a[0] and b[1]<=a[1]):
        return 1
    else:
        return 0
left,right,up,down=[1,1,1,1]
def updown(arr):
    left,right,up,down=[1,1,1,1]
    le,re=arr[0]
    up=max(up,re-le+1)
    for i in range(1,len(arr)):
        nl,nr=arr[i]
 
        if nl<le:
            up=max(up,le-nl)
 
        if nr>re:
            up=max(up,nr-re)
        le,re=nl,nr
    return up
 
def leftright(arr):
    left,right,up,down=[1,1,1,1]
 
    nn=len(arr)
    cnt=1
    chh=arr[0][0]
    for i in range(1,nn):
 
        if arr[i][0]==chh:
            cnt+=1
        else:
            left=max(left,cnt)
            chh=arr[i][0]
            cnt=1
    left=max(cnt,left)
    cnt=1
    chh=arr[0][1]
    for i in range(1,nn):
        if arr[i][1]==chh:
            cnt+=1
        else:
            right=max(right,cnt)
            cnt=1
            chh=arr[i][1]
    right=max(cnt,right)
    return max(left,right)
 
for tc in range(int(input())):
    n,m=I()
    ar=[list(input().strip()) for i in range(n)]
    temp=[[] for i in range(n)]
    te=[[] for i in range(n)]
    for i in range(n):
        cnt=0
        l=-1
        r=-1
        for j in range(m):
            if ar[i][j]=='#':
                if l==-1:
                    l=j
                cnt+=1
                r=j
            else:
                if cnt:
                    temp[i].append((l,r))
                    te[i].append((l,r))
                    cnt=0
                    l=-1
                    r=-1
        if l!=-1:
            temp[i].append((l,r))
    cur=[]
    for i in range(n):
        if len(temp[i]):
            cur.append(temp[i])
    visi=[cc.defaultdict(int) for i in range(n)]
    row=[cc.defaultdict(int) for i in range(n)]
    for i in range(n):
        for j in temp[i]:
            row[i][j]=j
    for i in range(n-1):
        for j in temp[i]:
            for k in temp[i+1]:
                if (ch(k,j) or ch(j,k)) and not visi[i+1][j]:
                    visi[i+1][j]=1
                    row[i+1][k]=j;break
    compo=[]
    vis=[cc.defaultdict(int) for i in range(n)]
    for i in range(n-1,-1,-1):
        for j in temp[i]:
            if not vis[i][j]:
                vis[i][j]=1
                comp=[j]
                r=i
                while r>=0 and row[r][comp[-1]]!=comp[-1] or (r>0 and row[r-1][comp[-1]]==comp[-1]):
                    comp.append(row[r][comp[-1]])
                    vis[r-1][comp[-1]]=1
                    r-=1
                    if r<0:
                        break
 
                compo.append(comp)
    ans=0
    for i in compo:
        ans=max(ans,leftright(i),updown(i),updown(i[::-1]))
    print(ans)
